/*
 * config.h
 *
 *  Created on: December 2, 2024
 *      Author: otteryc
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define DIMENSION 256
#define IMG_SIZE 28
#define FEATURES (IMG_SIZE * IMG_SIZE)
// #define DEBUG

/* Set to 1 if hypervectors are not fft-ed at training time. */
#define NEED_FFT 0
#define NUM_LEVEL_CACHE 4

/* === DO NOT MODIFY BELOW === */
#define NULL (void *)0
#define LEA_ALIGNMENT 4
#define BYTES_IN_WORD 2

#ifndef DEBUG
#define MSP_DISABLE_DIAGNOSTICS
#endif

/* === DO NOT MODIFY ABOVE === */

#endif /* CONFIG_H_ */
