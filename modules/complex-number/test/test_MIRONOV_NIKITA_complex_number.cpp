// Copyright 2023 Mironov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mironov_Nikita_ComplexNumberTest, zero_args_constructor_returns_zero) {
    // Arrange
    ComplexNumber zeroComplexNumber;

    // Assert
    EXPECT_DOUBLE_EQ(zeroComplexNumber.getRe(), 0.0);
    EXPECT_DOUBLE_EQ(zeroComplexNumber.getIm(), 0.0);
}

TEST(Mironov_Nikita_ComplexNumberTest, constructor_with_args_works) {
    // Arrange
    double re = 2.0, im = 3.3;

    // Assert
    EXPECT_NO_THROW(ComplexNumber a(re, im));
}

TEST(Mironov_Nikita_ComplexNumberTest, divide_by_zero_is_prohibited) {
    // Arrange
    ComplexNumber complexDivisible(2.0, 3.1);
    ComplexNumber zeroComplexDivider(0.0, 0.0);
    ComplexNumber result;

    // Assert
    ASSERT_ANY_THROW(result = complexDivisible / zeroComplexDivider);
}

TEST(Mironov_Nikita_ComplexNumberTest, sum_works) {
    // Arrange
    ComplexNumber firstSummand(3.0, 3.1);
    ComplexNumber secondSummand(2.0, 1.3);
    ComplexNumber result;
    ComplexNumber expect(5.0, 4.4);

    // Act
    result = firstSummand + secondSummand;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Mironov_Nikita_ComplexNumberTest, sub_works) {
    // Arrange
    ComplexNumber complexReduced(2.0, 3.1);
    ComplexNumber complexDeductible(3.0, 1.5);
    ComplexNumber result;
    ComplexNumber expect(-1.0, 1.6);

    // Act
    result = complexReduced - complexDeductible;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Mironov_Nikita_ComplexNumberTest, mul_works) {
    // Arrange
    ComplexNumber complexMultiplied(6.3, 2.1);
    ComplexNumber complexMultiplier(1.1, 1.3);
    ComplexNumber result;
    ComplexNumber expect(4.2, 10.5);

    // Act
    result = complexMultiplied * complexMultiplier;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Mironov_Nikita_ComplexNumberTest, div_works) {
    // Arrange
    ComplexNumber complexDivisible(-2.0, 1.0);
    ComplexNumber complexDivider(1.0, -1.0);
    ComplexNumber result;
    ComplexNumber expect(-1.5, -0.5);

    // Act
    result = complexDivisible / complexDivider;

    // Assert
    ASSERT_EQ(expect.getIm(), result.getIm());
    ASSERT_EQ(expect.getRe(), result.getRe());
}

TEST(Mironov_Nikita_ComplexNumberTest, equality_works) {
    // Arrange
    double re = 2.0, im = -1.0;
    ComplexNumber firstOfEqual(re, im);
    ComplexNumber secondOfEqual(re, im);

    // Assert & Act
    EXPECT_TRUE(firstOfEqual == secondOfEqual);
}

TEST(Mironov_Nikita_ComplexNumberTest, inequality_works) {
    // Arrange
    ComplexNumber firstOfInequal(3.0, 2.0);
    ComplexNumber secondOfInequal(2.0, -1.0);

    // Assert & Act
    EXPECT_TRUE(firstOfInequal != secondOfInequal);
}
