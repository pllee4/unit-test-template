/*
 * union.h
 * Created on: Aug 21, 2021 09:22
 * Description:
 *
 * Copyright (c) 2021 Pin Loon Lee (pllee4)
 */

#ifndef UNION_H
#define UNION_H

#include <stdint.h>

#define BIT_MASK(num) (1 << num)

typedef union {
  struct {
    uint8_t bit0 : 1;
    uint8_t bit1 : 1;
    uint8_t bit2 : 1;
    uint8_t bit3 : 1;
    uint8_t bit4 : 1;
    uint8_t bit5 : 1;
    uint8_t bit6 : 1;
    uint8_t bit7 : 1;
  } valueof;
  uint8_t input;
} UnionInput;

#endif /* UNION_H */
