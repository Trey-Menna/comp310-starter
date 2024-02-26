#include <stdio.h>
#include <stdlib.h>

#include "point.h"

int main(int argc, char *argv[]) {
    point_t p1, p2, p3, p4, p5, p6, p7, p8;

    point_new(&p1);
    point_init(&p1, 3.0, 0);
    point_new(&p2);
    point_init(&p2, 0, 4.0);

    printf("p1 = ");
    point_print(&p1, stdout);
    printf(" p2 = ");
    point_print(&p2, stdout);
    printf(" distance = %lf\n", point_distance(&p1, &p2));

    // Test point_mod
    point_init(&p3, 5.0, 3.0);
    point_mod(&p3, &p1);
    assert(p3.x == 2.0);
    assert(p3.y == 3.0);

    // Test point_div_mod
    point_init(&p4, 11.0, 7.0);
    point_init(&p5, 3.0, 2.0);
    point_div_mod(&p4, &p5, &p6, &p7);
    assert(p6.x == 3.0);
    assert(p7.x == 2.0);
    assert(p6.y == 3.0);
    assert(p7.y == 1.0);

    // Test point_swap
    point_init(&p8, 8.0, 6.0);
    point_swap(&p3, &p8);
    assert(p3.x == 8.0);
    assert(p3.y == 6.0);
    assert(p8.x == 2.0);
    assert(p8.y == 3.0);

    printf("All tests passed!\n");
}
