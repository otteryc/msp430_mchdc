#include "hdc.h"
#include <msp430.h>
#include "DriverLib/driverlib.h"

extern const unsigned char class_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern const unsigned char level_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern const unsigned char position_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern unsigned char input_image[IMG_SIZE];

ballot_box_t *bx = 0x20000;
hv_t inferencing = {(uint8_t *)0x3400};

void init() {
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR = 0xff;
    P1OUT = 0x00;
    P2DIR = 0xff;
    P2OUT = 0x00;
    P3DIR = 0xff;
    P3OUT = 0x00;
    P4DIR = 0xff;
    P4OUT = 0x00;
    P5DIR = 0xff;
    P5OUT = 0x00;
    P6DIR = 0xff;
    P6OUT = 0x00;
    P7DIR = 0xff;
    P7OUT = 0x00;
    P8DIR = 0xff;
    P8OUT = 0x00;
    PADIR = 0xff;
    PAOUT = 0x00;
    PBDIR = 0xff;
    PBOUT = 0x00;
    PCDIR = 0xff;
    PCOUT = 0x00;
    PDDIR = 0xff;
    PDOUT = 0x00;
    P8DIR = 0xfd;
    P8REN = GPIO_PIN1;
    setFrequency(8);
    CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);

    // Clock System Setup
    CSCTL0_H = CSKEY_H; // Unlock CS registers
    CSCTL1 = DCOFSEL_0; // Set DCO to 1MHz
    // Set SMCLK = MCLK = DCO, ACLK = VLOCLK
    CSCTL2 = SELA__VLOCLK | SELS__DCOCLK | SELM__DCOCLK;
    // Per Device Errata set divider to 4 before changing frequency to
    // prevent out of spec operation from overshoot transient
    //    CSCTL3 = DIVA__4 | DIVS__4 | DIVM__4;   // Set all corresponding clk
    //    sources to divide by 4 for errata
    CSCTL1 = DCOFSEL_4 | DCORSEL; // Set DCO to 16MHz
    // Delay by ~10us to let DCO settle. 60 cycles = 20 cycles buffer + (10us /
    // (1/4MHz))
    __delay_cycles(60);
    CSCTL3 = DIVA__1 | DIVS__1 |
             DIVM__1; // Set all dividers to 1 for 16MHz operation
    CSCTL0_H = 0;

    PMM_unlockLPM5();
    bzero(bx, DIMENSION * 2);
}

void encoding() {
  uint16_t iter = IMG_SIZE, feature;
  unsigned char *img_iter = input_image;
  while (--iter) {
    feature = *img_iter++ / 25;
    bind_hypervector(inferencing, (hv_t){position_hypervectors[0]},
                     (hv_t){level_hypervectors[feature]});
    permute_by_byte((hv_t){position_hypervectors[0]});
    voting(bx, inferencing);
  }

  open_ballot_box(inferencing, bx);
}


uint8_t classification() {
  uint8_t result = 255;
  uint16_t min = 0xFFFF, cur;
  for (uint8_t i = 0; i < 10; i++) {
    if (cur = hamming_table(inferencing, (hv_t){class_hypervectors[i]}), min > cur) {
      min = cur;
      result = i;
    }
  }
  return result;
}

void inference()
{
    bzero(bx, DIMENSION * 2);
    P3OUT = 0x00;
    P1OUT |= 0x01;
    encoding();
    P3OUT = 0x02;
    uint8_t result = classification();
    
    P1OUT |= 0x03;
    P3OUT = 0x03;
}


int main() {
  init();

  while (1)
    inference();
}
