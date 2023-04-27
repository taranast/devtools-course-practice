// Copyright 2023 Tarasova Anastasiya
#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Tarasova_Anastasiya_ComplexNumberTest, Squaring_Im) {
	ComplexNumber num1(0, 1);
	ComplexNumber num2(-1, 0);
	ASSERT_EQ(num1*num1, num2);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Fourth_D_Im) {
	ComplexNumber num1(0, 1);
	ComplexNumber num2(1, 0);
	ASSERT_EQ(num1*num1*num1*num1, num2);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Fifth_D_Im) {
	ComplexNumber num1(0, 1);
	ComplexNumber num2(0, 1);
	ASSERT_EQ(num1 * num1 * num1 * num1*num1, num2);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Cubing_Im) {
	ComplexNumber num1(0, 1);
	ComplexNumber num2(0, -1);
	ASSERT_EQ(num1 * num1 * num1, num2);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Sum_Conjugate) {
	ComplexNumber num1(42, 24);
	ComplexNumber num2(42, -24);
	ComplexNumber num3(84, 0);
	ASSERT_EQ(num1 + num2, num3);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Mult_Conjugate) {
	ComplexNumber num1(42, 24);
	ComplexNumber num2(42, -24);
	ComplexNumber num3(2340, 0);
	ASSERT_EQ(num1 * num2, num3);
}

TEST(Tarasova_Anastasiya_ComplexNumberTest, Div_And_Mult) {
	ComplexNumber num1(42, 24);
	ComplexNumber num2(42, 13);
	ComplexNumber num3 = num1*num2;
	ASSERT_EQ(num1, num3/num2);
}
