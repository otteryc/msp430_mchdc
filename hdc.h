#ifndef LIB_HDC_H_
#define LIB_HDC_H_

#include "common.h"

#ifndef DIMENSION
#define DIMENSION 4096
#endif

#ifndef IMG_SIZE
/* 28 x 28 */
#define IMG_SIZE 784
#endif

/* Intentionally, for future extensibility. */
typedef struct Hypervector {
    union {
        uint8_t *hv;
        uint16_t *hv16;
        uint32_t *hv32;
    };
} hv_t ;

typedef uint16_t ballot_box_t;
#define ITER_HV(iter)                                 \
    for (iter = 0; iter < DIMENSION / BITS_IN_BYTE; iter++)

#define ITER_HV_16(iter)                              \
    for (iter = 0; iter < DIMENSION / (BITS_IN_BYTE * 2); iter++)

#define ITER_HV_32(iter)                              \
    for (iter = 0; iter < DIMENSION / (BITS_IN_BYTE * 4); iter++)

void negate_hypervector(hv_t hv);

#define hvops(name)                                                        \
    void name##_hypervector(hv_t dest, hv_t src1, hv_t src2);

hvops(xor);
hvops(or);
hvops(and);
hvops(bind);

#undef hvops

void permute_by_byte(hv_t);
double cosine_similarity(hv_t, hv_t);
void voting(ballot_box_t *, hv_t);
void open_ballot_box(hv_t dest, ballot_box_t *box);

void bzero(void *, uint32_t);
#endif /* LIB_HDC_H_ */
