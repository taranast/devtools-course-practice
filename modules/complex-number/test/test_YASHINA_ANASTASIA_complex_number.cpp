// Copyright 2023 Yashina Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Yashina_Anastasia_ComplexNumberTest, add) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber num(re, im);

    EXPECT_EQ(re, num.getRe());
    EXPECT_EQ(im, num.getIm());
}

TEST(Yashina_Anastasia_ComplexNumberTest, sum) {
    double re1 = 1.5;
    double im1 = 0.3;
    double re2 = 4.5;
    double im2 = 0.7;

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);
    ComplexNumber num3 = num1 + num2;

    EXPECT_EQ(6, num3.getRe());
    EXPECT_EQ(1, num3.getIm());
}

TEST(Yashina_Anastasia_ComplexNumberTest, substract) {
    double re1 = 4.0;
    double im1 = 4.0;
    double re2 = 5.0;
    double im2 = 2.0;

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);
    ComplexNumber num3 = num1 - num2;

    EXPECT_EQ(-1, num3.getRe());
    EXPECT_EQ(2, num3.getIm());
}

TEST(Yashina_Anastasia_ComplexNumberTest, multiply) {
    double re1 = 2.0;
    double im1 = 1.0;
    double re2 = 3.0;
    double im2 = 2.0;

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);
    ComplexNumber num3 = num1 * num2;

    EXPECT_EQ(4, num3.getRe());
    EXPECT_EQ(7, num3.getIm());
}

TEST(Yashina_Anastasia_ComplexNumberTest, division) {
    double re1 = 2.0;
    double im1 = 1.0;
    ComplexNumber c1(re1, im1);
    double re2 = 2.0;
    double im2 = 1.0;
    ComplexNumber c2(re2, im2);

    ComplexNumber num = c1 / c2;

    EXPECT_EQ(1, num.getRe());
    EXPECT_EQ(0, num.getIm());
}

TEST(Yashina_Anastasia_ComplexNumberTest, compare) {
    double re1 = 4.0;
    double im1 = 4.0;
    double re2 = 4.0;
    double im2 = 4.0;

    ComplexNumber num1(re1, im1);
    ComplexNumber num2(re2, im2);

    EXPECT_EQ(num1, num2);
}
