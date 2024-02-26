#include "point.h"

#include <math.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

point_t *point_allocate() {
    return (point_t *) malloc(sizeof(point_t));
}

void point_new(point_t *point) {
    point->x = 0;
    point->y = 0;
}

void point_init(point_t *point, double x, double y) {
    point->x = x;
    point->y = y;
}

void point_add(point_t *point, point_t *another) {
    point->x += another->x;
    point->y += another->y;
}

void point_subtract(point_t *point, point_t *another) {
    point->x -= another->x;
    point->y -= another->y;
}

void point_multiply(point_t *point, point_t *another) {
    point->x *= another->x;
    point->y *= another->y;
}

void point_mod(point_t *point, point_t *another) {
    point->x = fmod(point->x, another->x);
    point->y = fmod(point->y, another->y);
}

void point_div_mod(point_t *dividend, point_t *divisor, point_t *quotient, point_t *remainder) {
    quotient->x = dividend->x / divisor->x;
    remainder->x = fmod(dividend->x, divisor->x);

    quotient->y = dividend->y / divisor->y;
    remainder->y = fmod(dividend->y, divisor->y);
}

void point_swap(point_t *a, point_t *b) {
    point_t temp;
    memcpy(&temp, a, sizeof(point_t));
    memcpy(a, b, sizeof(point_t));
    memcpy(b, &temp, sizeof(point_t));
}

void point_dup(point_t *point) {
    point_t *new_point = point_allocate();
    point_init(new_point, point->x, point->y);
}

void point_over(point_t *a, point_t *b) {
    point_t *new_point = point_allocate();
    point_init(new_point, a->x, a->y);
}

void point_rot(point_t *a, point_t *b, point_t *c) {
    point_t temp;
    memcpy(&temp, a, sizeof(point_t));
    memcpy(a, b, sizeof(point_t));
    memcpy(b, c, sizeof(point_t));
    memcpy(c, &temp, sizeof(point_t));
}

void point_drop(point_t *point) {
    free(point);
}

void point_2swap(point_t *a, point_t *b, point_t *c, point_t *d) {
    point_swap(a, b);
    point_swap(c, d);
}

void point_2dup(point_t *a, point_t *b) {
    point_dup(a);
    point_dup(b);
}

void point_2over(point_t *a, point_t *b, point_t *c, point_t *d) {
    point_over(a, b);
    point_over(c, d);
}

void point_2drop(point_t *a, point_t *b) {
    point_drop(a);
    point_drop(b);
}

double point_distance(point_t *point, point_t *another) {
    double x0 = point->x, y0 = point->y;
    double x1 = another->x, y1 = another->y;
    return sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
}

double point_x(point_t *point) {
    return point->x;
}

double point_y(point_t *point) {
    return point->y;
}

extern void point_print(point_t *point, FILE *stream) {
    fprintf(stream, "point(%lf, %lf)", point->x, point->y);
}

