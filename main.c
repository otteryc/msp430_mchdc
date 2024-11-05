#include "hdc.h"
#include <msp430.h>

extern const unsigned char class_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern const unsigned char level_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern const unsigned char position_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern unsigned char input_image[IMG_SIZE];

#define DMA_CHANNEL_0  (0x00)

#pragma LOCATION(LEVELHV_SRAM, 0x1E40)
#pragma PERSISTENT(LEVELHV_SRAM)
static unsigned char LEVELHV_SRAM[3][512] = {0};

static uint16_t level_index[3]={0, 1, 2};
static uint16_t bitmap;

ballot_box_t *bx = 0x20000;
//#pragma LOCATION(bx, 0x20000)
//#pragma PERSISTENT(bx)
//static ballot_box_t bx[512] = {0};

ballot_box_t *bx_SRAM = 0x2C00;
//#pragma LOCATION(bx_SRAM, 0x2C00)
//#pragma PERSISTENT(bx_SRAM)
//static ballot_box_t bx_SRAM[256] = {0};

//hv_t inferencing = {(uint8_t *)0x3400};
hv_t inferencing = {(uint8_t *)0x2640};

void *dma_load(unsigned char *hypervector_FRAM, unsigned char *hypervector_SRAM, uint16_t n) {
    // transfer level_HV from FRAM to SRAM
    __data16_write_addr((unsigned short)(__MSP430_BASEADDRESS_DMA__ + DMA_CHANNEL_0 + OFS_DMA0SA), hypervector_FRAM);
    __data16_write_addr((unsigned short)(__MSP430_BASEADDRESS_DMA__ + DMA_CHANNEL_0 + OFS_DMA0DA), hypervector_SRAM);
    DMA0SZ = n;
    DMA0CTL = DMADT_5 | DMASRCINCR_3 | DMADSTINCR_3; // Rpt, inc
    DMA0CTL |= DMAEN;                                // Enable DMA0
    DMA0CTL |= DMAREQ;

}

void *dma_load_box(uint16_t *ballot_box_source, uint16_t *ballot_box_dest, uint16_t n) {//    // transfer ballot_box from FRAM to SRAM
    __data16_write_addr((unsigned short)(__MSP430_BASEADDRESS_DMA__ + DMA_CHANNEL_0 + OFS_DMA0SA), ballot_box_source);
    __data16_write_addr((unsigned short)(__MSP430_BASEADDRESS_DMA__ + DMA_CHANNEL_0 + OFS_DMA0DA), ballot_box_dest);
    DMA0SZ = n;
    DMA0CTL = DMADT_5 | DMASRCINCR_3 | DMADSTINCR_3; // Rpt, inc
    DMA0CTL |= DMAEN;                                // Enable DMA1
    DMA0CTL |= DMAREQ;

}

void init() {
  WDTCTL = WDTPW | WDTHOLD;
  PM5CTL0 &= ~LOCKLPM5;
  bzero(bx, DIMENSION * 2);
  bzero(bx_SRAM, DIMENSION);
}

void encoding() {
  uint16_t iter = IMG_SIZE, feature, feature_bitmap = 0b0000000000;
  uint8_t victim = 0, j = 0;
  uint16_t *box_iter = bx;
  unsigned char *img_iter = input_image;
  while (--iter) {
//      if (iter == 600)
//          iter = 600;
    feature = (*img_iter) / 26;
    feature_bitmap = 1 << feature;
    if ((feature_bitmap & bitmap) == 0) { //SRAM miss
        bitmap = (bitmap | feature_bitmap) & (~(1 << level_index[victim]));
        dma_load(level_hypervectors[feature], LEVELHV_SRAM[victim], ((DIMENSION / BITS_IN_BYTE)/2));
        level_index[victim] = feature;
        bind_hypervector(inferencing, (hv_t){position_hypervectors[0]}, (hv_t){LEVELHV_SRAM[victim]});
        permute_by_byte((hv_t){position_hypervectors[0]});
        victim++;
    }
    else { // SRAM hit
        for(j = 0; j < 3; j ++) {
            if (level_index[j] == feature) {
                bind_hypervector(inferencing, (hv_t){position_hypervectors[0]}, (hv_t){LEVELHV_SRAM[j]});
                permute_by_byte((hv_t){position_hypervectors[0]});
                break;
            }
        }
    }
//    bind_hypervector(inferencing, (hv_t){position_hypervectors[0]}, (hv_t){level_hypervectors[feature]});
//    permute_by_byte((hv_t){position_hypervectors[0]});
//    voting(bx, inferencing);
      dma_load_box(box_iter, bx_SRAM, DIMENSION / 2);
      voting(bx_SRAM, inferencing);
      dma_load_box(bx_SRAM, box_iter, DIMENSION / 2);

      box_iter += 2048;
      inferencing.hv += 256;

      dma_load_box(box_iter, bx_SRAM, DIMENSION / 2);
      voting(bx_SRAM, inferencing);
      dma_load_box(bx_SRAM, box_iter, DIMENSION / 2);

      box_iter -= 2048;
      inferencing.hv -= 256;


    img_iter += 1;
    if (victim >= 3)
        victim = 0;
  }

  open_ballot_box(inferencing, bx);
}

uint8_t classification() {
  uint8_t result = 255;
  uint16_t min = 0xFFFF, cur;
  for (uint8_t i = 0; i < 10; i++) {
    if (cur = hamming(inferencing, (hv_t){class_hypervectors[i]}), min > cur) {
      min = cur;
      result = i;
    }
  }
  return result;
}

int main() {

    init();

        uint8_t i;
        bitmap = 0b0000000111; // load level_HV 0~2 from FRAM to SRAM
    for (i = 0; i < 3; i++)
    {
       dma_load(level_hypervectors[i], LEVELHV_SRAM[i], ((DIMENSION / BITS_IN_BYTE)/2));
    }
//        dma_load(level_hypervectors[1], LEVELHV_SRAM[0], ((DIMENSION / BITS_IN_BYTE)/2));
//        dma_load(level_hypervectors[0], LEVELHV_SRAM[1], ((DIMENSION / BITS_IN_BYTE)/2));
//        dma_load(level_hypervectors[2], LEVELHV_SRAM[2], ((DIMENSION / BITS_IN_BYTE)/2));
  encoding();
  volatile uint8_t result = classification();
  /* The LED on the board while start blinking if the inference completed.*/
  volatile int x = 30000;
  P1DIR |= 0x03;
  P1OUT = 0x01;

  while (1) {
    while (--x)
      ;
    P1OUT ^= 0x3;
  }
}
