#include <msp430.h>
#include "hdc.h"

extern const unsigned char class_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern const unsigned char level_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern const unsigned char position_hypervectors[][DIMENSION / BITS_IN_BYTE];
extern unsigned char input_image[IMG_SIZE];

ballot_box_t *bx = 0x20000;
hv_t inferencing = {(uint8_t *) 0x3400};

void init() {
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;
    bzero(bx, DIMENSION * 2);
}

void encoding() {
    uint16_t iter = IMG_SIZE, feature;
    unsigned char *img_iter = input_image;
    while (--iter) {
        feature = *img_iter++ / 25;
        if (feature == 10)
            feature = 9;
        bind_hypervector(inferencing, (hv_t) {position_hypervectors[0]}, (hv_t) {class_hypervectors[feature]});
        permute_by_byte((hv_t) {position_hypervectors[0]});
        voting(bx, inferencing);
    }

    open_ballot_box(inferencing, bx);
}

uint8_t classification(){
    uint8_t result = 255;
    double max = 0.0, cur = 0;
    for (uint8_t i = 0; i < 10; i++) {
        if (cur = cosine_similarity(inferencing, (hv_t) {class_hypervectors[i]}), cur > max) {
            max = cur;
            result = i;
        }
    }
    return result;
}


int main(){
    init();
    encoding();
    volatile uint8_t result = classification();

    /* The LED on the board while start blinking if the inference completed.*/
    volatile int x = 30000;
    P1DIR |= 0x03;
    P1OUT = 0x01;

    while (1) {
        while (--x);
        P1OUT ^= 0x3;
    }
}

