/*
 * This example is often seen in OOP books.
 * It is to represent a 2D point. We start with double x, y.
 */

#ifndef _POINT_H_
#define _POINT_H_

#include <stdio.h>

typedef struct _point_t
{
    double x, y;
} point_t;

extern point_t* point_allocate();

extern void point_new(point_t* point);

extern void point_init(point_t* point, double x, double y);

extern void point_add(point_t* point, point_t* another);

extern void point_subtract(point_t *point, point_t *another);

extern void point_multiply(point_t *point, point_t *another);

extern void point_mod(point_t *point, point_t *another);

extern void point_div_mod(point_t *dividend, point_t *divisor, point_t *quotient, point_t *remainder);

extern void point_swap(point_t *a, point_t *b);

extern void point_dup(point_t *point);

extern void point_over(point_t *a, point_t *b);

extern void point_rot(point_t *a, point_t *b, point_t *c);

extern void point_drop(point_t *point);

extern void point_2swap(point_t *a, point_t *b, point_t *c, point_t *d);

extern void point_2dup(point_t *a, point_t *b);

extern void point_2over(point_t *a, point_t *b, point_t *c, point_t *d);

extern void point_2drop(point_t *a, point_t *b);

extern double point_distance(point_t* point, point_t* another);

extern double point_x(point_t* point);

extern double point_y(point_t* point);

extern void point_print(point_t* point, FILE* stream);

#endif
