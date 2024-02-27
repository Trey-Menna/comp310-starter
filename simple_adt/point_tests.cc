/* test cases */

#include <gtest/gtest.h>

#include "point.hh"

TEST(PointTest, Initialization)
{
    point_t p1, p2, p3;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_new(&p3);

    ASSERT_FLOAT_EQ( point_x(&p1), 3.0);
    ASSERT_FLOAT_EQ( point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ( point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ( point_y(&p2), 4.0);

    ASSERT_FLOAT_EQ( point_x(&p3), 0.0);
    ASSERT_FLOAT_EQ( point_y(&p3), 0.0);

}


TEST(PointTest, Add)
{
    point_t p1, p2, p3;

    point_new(&p3);
    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_add(&p3, &p1);
    ASSERT_FLOAT_EQ( point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ( point_y(&p3), 0.0);
    point_add(&p3, &p2);
    ASSERT_FLOAT_EQ( point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ( point_y(&p3), 4.0);
}

TEST(PointTest, Subtract)
{
    point_t p1, p2, p3;

    point_new(&p3);
    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_subtract(&p3, &p1);
    ASSERT_FLOAT_EQ( point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ( point_y(&p3), 0.0);
    point_subtract(&p3, &p2);
    ASSERT_FLOAT_EQ( point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ( point_y(&p3), 4.0);
}

TEST(PointTest, Distance)
{
    point_t p1, p2, p3;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    ASSERT_FLOAT_EQ( point_distance(&p1, &p2), 5.0);
}

TEST(PointTest, Mod)
{
    point_t p1, p2, p3;

    point_init(&p1, 8, 5);
    point_init(&p2, 3, 2);
    point_mod(&p1, &p2);

    ASSERT_FLOAT_EQ(p1.x, 2.0);
    ASSERT_FLOAT_EQ(p1.y, 1.0);
}

TEST(PointTest, DivMod)
{
    point_t p1, p2, quotient, remainder;

    point_init(&p1, 11, 7);
    point_init(&p2, 3, 2);
    point_div_mod(&p1, &p2, &quotient, &remainder);

    ASSERT_FLOAT_EQ(quotient.x, 3.0);
    ASSERT_FLOAT_EQ(remainder.x, 2.0);
    ASSERT_FLOAT_EQ(quotient.y, 3.0);
    ASSERT_FLOAT_EQ(remainder.y, 1.0);
}

TEST(PointTest, Swap)
{
    point_t p1, p2;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);

    point_swap(&p1, &p2);

    ASSERT_FLOAT_EQ(point_x(&p1), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 4.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 0.0);
}

TEST(PointTest, Dup)
{
    point_t p1, p2;

    point_init(&p1, 3, 0);
    point_dup(&p1);
    point_init(&p2, 0, 0);

    ASSERT_FLOAT_EQ(point_x(&p1), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 0.0);
}

TEST(PointTest, Over)
{
    point_t p1, p2, p3;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_over(&p1, &p2);
    point_init(&p3, 3, 0);

    ASSERT_FLOAT_EQ(point_x(&p1), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 4.0);

    ASSERT_FLOAT_EQ(point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p3), 0.0);
}

TEST(PointTest, Rot)
{
    point_t p1, p2, p3, p4;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_init(&p3, 5, 6);
    point_rot(&p1, &p2, &p3);
    point_init(&p4, 0, 4);

    ASSERT_FLOAT_EQ(point_x(&p1), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 4.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 5.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 6.0);

    ASSERT_FLOAT_EQ(point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p3), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p4), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p4), 4.0);
}

TEST(PointTest, Drop)
{
    point_t p1, p2;

    point_init(&p1, 3, 0);
    point_drop(&p1);
    point_init(&p2, 0, 0);

    ASSERT_FLOAT_EQ(point_x(&p1), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 0.0);
}

TEST(PointTest, TwoSwap)
{
    point_t p1, p2, p3, p4;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_init(&p3, 5, 6);
    point_init(&p4, 7, 8);

    point_2swap(&p1, &p2, &p3, &p4);

    ASSERT_FLOAT_EQ(point_x(&p1), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 4.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 5.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 6.0);

    ASSERT_FLOAT_EQ(point_x(&p3), 7.0);
    ASSERT_FLOAT_EQ(point_y(&p3), 8.0);

    ASSERT_FLOAT_EQ(point_x(&p4), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p4), 0.0);
}

TEST(PointTest, TwoDup)
{
    point_t p1, p2, p3, p4;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_2dup(&p1, &p2);
    point_init(&p3, 3, 0);
    point_init(&p4, 0, 4);

    ASSERT_FLOAT_EQ(point_x(&p1), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 4.0);

    ASSERT_FLOAT_EQ(point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p3), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p4), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p4), 4.0);
}

TEST(PointTest, TwoOver)
{
    point_t p1, p2, p3, p4;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_2over(&p1, &p2, &p3, &p4);
    point_init(&p3, 3, 0);
    point_init(&p4, 0, 4);

    ASSERT_FLOAT_EQ(point_x(&p1), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 4.0);

    ASSERT_FLOAT_EQ(point_x(&p3), 3.0);
    ASSERT_FLOAT_EQ(point_y(&p3), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p4), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p4), 4.0);
}

TEST(PointTest, TwoDrop)
{
    point_t p1, p2, p3, p4;

    point_init(&p1, 3, 0);
    point_init(&p2, 0, 4);
    point_2drop(&p1, &p2);
    point_init(&p3, 0, 0);
    point_init(&p4, 0, 0);

    ASSERT_FLOAT_EQ(point_x(&p1), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p1), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p2), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p2), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p3), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p3), 0.0);

    ASSERT_FLOAT_EQ(point_x(&p4), 0.0);
    ASSERT_FLOAT_EQ(point_y(&p4), 0.0);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
