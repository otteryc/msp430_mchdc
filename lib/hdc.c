#include "common.h"
#include "hdc.h"

static inline uint8_t popcount32(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

/* `n` should be multiple of 4 */
void bzero(void *mem, uint32_t n){
    uint32_t *iter = (uint32_t *)mem;
    while (n > 4){
        *(uint32_t *)iter++ = 0;
        n -= 4;
    }
}


void negate_hypervector(hv_t hv){
    uint16_t iter;
    ITER_HV_32(iter) {
        hv.hv32[iter] = ~hv.hv32[iter];
    }
}

#define hvops(name, op)                                                        \
    void name##_hypervector(hv_t dest, hv_t src1, hv_t src2)                   \
    {                                                                          \
        uint16_t i;                                                            \
        ITER_HV_16 (i) {                                                       \
            dest.hv16[i] = src1.hv16[i] op src2.hv16[i];                       \
        }                                                                      \
    }

hvops(xor, ^);
hvops(or, |);
hvops(and, &);
hvops(bind, ^);
#undef hvops

void permute_by_byte(hv_t hv)
{
    /* Last byte in hypervector. */
    uint16_t n = DIMENSION / BITS_IN_BYTE - 1;
    uint8_t tmp = hv.hv[n];
    while (--n) {
        hv.hv[n] = hv.hv[n - 1];
    }
    *hv.hv = tmp;
}

/* Naive method */
double cosine_similarity(hv_t hv1, hv_t hv2)
{
    uint16_t iter;
    uint32_t dot_product = 0, len_hv1 = 0, len_hv2 = 0;
    ITER_HV_32(iter) {
        dot_product += popcount32(hv1.hv32[iter] ^ hv2.hv32[iter]);
        len_hv1 += popcount32(hv1.hv32[iter]);
        len_hv2 += popcount32(hv2.hv32[iter]);
    }
    /* Avoid square root here. */
    return (double) dot_product * dot_product / (double) len_hv1 * len_hv2;
}

void voting(ballot_box_t *ballot_box, hv_t vote)
{
    uint16_t iter;
    ITER_HV(iter) {
        /* Should be automatically unrolled. */
        uint16_t i = BITS_IN_BYTE;
        while (i--) {
            *ballot_box++ += get_bit_in_byte(vote.hv[iter], i);
        }
    }
}

void open_ballot_box(hv_t dest, ballot_box_t *box)
{
    uint16_t iter;
    ITER_HV(iter) {
        uint16_t i = BITS_IN_BYTE;
        while(i--) {
            if (*box++ >= IMG_SIZE / 2) {
                set_bit_in_byte(dest.hv + iter, i);
            }
        }
    }
}





