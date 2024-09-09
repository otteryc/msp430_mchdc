#ifndef LIB_COMMON_H_
#define LIB_COMMON_H_

#include <stdint.h>
#include <stdbool.h>

#define BITS_IN_BYTE 8

/*
 * The most significant bit is assign as the seventh bit.
 */
static inline bool get_bit_in_byte(uint8_t byte, uint8_t index) {
    return (byte & (1 << index)) >> index;
}

static inline void set_bit_in_byte(uint8_t *byte, uint8_t index) {
    *byte |= 1 << index;
}

#endif /* LIB_COMMON_H_ */
