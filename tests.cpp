#include <gtest/gtest.h>
#include "triangle.h"
#include "square.h"
#include "octagon.h"
#include "figure.h"

TEST(TriangleTest, AreaAndCenter) {
    Triangle t(
        Point(0, 0),
        Point(4, 0),
        Point(0, 3)
    );

    EXPECT_NEAR(t.Area(), 6.0, 1e-9);
    Point c = t.Center();
    EXPECT_NEAR(c.x, 4.0 / 3.0, 1e-9);
    EXPECT_NEAR(c.y, 1.0, 1e-9);
}

TEST(TriangleTest, Equality) {
    Triangle t1(Point(0, 0), Point(4, 0), Point(0, 3));
    Triangle t2(Point(0, 0), Point(4, 0), Point(0, 3));
    Triangle t3(Point(1, 1), Point(2, 2), Point(3, 3));

    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(SquareTest, AreaAndCenter) {
    Square s(
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(0, 2)
    );

    EXPECT_NEAR(s.Area(), 4.0, 1e-9);
    Point c = s.Center();
    EXPECT_NEAR(c.x, 1.0, 1e-9);
    EXPECT_NEAR(c.y, 1.0, 1e-9);
}

TEST(SquareTest, Equality) {
    Square s1(
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(0, 2)
    );
    Square s2(
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(0, 2)
    );
    Square s3(
        Point(1, 1),
        Point(3, 1),
        Point(3, 3),
        Point(1, 3)
    );

    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(OctagonTest, AreaAndCenter) {
    Point p[8] = {
        {1, 0}, {std::sqrt(2)/2, std::sqrt(2)/2}, {0, 1},
        {-std::sqrt(2)/2, std::sqrt(2)/2}, {-1, 0},
        {-std::sqrt(2)/2, -std::sqrt(2)/2}, {0, -1},
        {std::sqrt(2)/2, -std::sqrt(2)/2}
    };
    Octagon o(p);

    EXPECT_NEAR(o.Center().x, 0.0, 1e-9);
    EXPECT_NEAR(o.Center().y, 0.0, 1e-9);
    EXPECT_GT(o.Area(), 2.0);
}

TEST(PolymorphismTest, VirtualDispatch) {
    Figure* f1 = new Triangle(Point(0, 0), Point(4, 0), Point(0, 3));
    Figure* f2 = new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1));

    EXPECT_NEAR(f1->Area(), 6.0, 1e-9);
    EXPECT_NEAR(f2->Area(), 1.0, 1e-9);

    delete f1;
    delete f2;
}