#include <gtest/gtest.h>

#include <shear.hxx>

using namespace project;

TEST(Shear, zero_magnitudes)
{
	Point point {1.0f, 2.0f};
	Point const expected {1.0f, 2.0f};
	shear(point, 0, 0);
	ASSERT_EQ(expected, point);
}

TEST(Shear, x_magnitude_2)
{
	Point point {1.0f, 2.0f};

	// x' = x + shear[x] * y
	//    = 1 + 2        * 2
	//    = 5
	Point const expected {5.0f, point.y()};
	shear(point, 2, 0);
	ASSERT_EQ(expected, point);
}

TEST(Shear, y_magnitude_2)
{
	Point point {1.0f, 2.0f};

	// y' = y + shear[y] * x
	//    = 2 + 2        * 1
	//    = 4
	Point const expected {point.x(), 4.0f};
	shear(point, 0, 2);
	ASSERT_EQ(expected, point);
}

TEST(Shear, both_magnitudes_2)
{
	Point point {1.0f, 2.0f};
	// x' = 5
	// y' = 4
	Point const expected {5.0f, 4.0f};
	shear(point, 2, 2);
	ASSERT_EQ(expected, point);
}
