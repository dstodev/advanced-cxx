#include <gtest/gtest.h>

#include <shear.hxx>
#include <utilities.hxx>

using namespace project;

TEST(Utilities, index_2d_to_1d_zeroes)
{
	index_2d_to_1d(0, 0, 0);
}

TEST(Utilities, index_2d_to_1d_horizontal_rectangle)
{
	/*
	      0 1 2 3 4    a b c d e f g h i j
	    0 a b c d e    0 1 2 3 4 5 6 7 8 9
	    1 f g h i j
	 */
	ASSERT_EQ(7 /* h */, index_2d_to_1d(5, 1, 2));
}

TEST(Utilities, index_2d_to_1d_vertical_rectangle)
{
	/*
	      0 1    a b c d e f g h i j
	    0 a b    0 1 2 3 4 5 6 7 8 9
	    1 c d
	    2 e f
	    3 g h
	    4 i j
	 */
	ASSERT_EQ(5 /* f */, index_2d_to_1d(2, 2, 1));
}