#include "distance.h"
#include "currency.h"
#include "fraction.h"
#include "mytime.h"
#include "complex_num.h"
#include <gtest/gtest.h>
namespace {
//Distance Unit Testing
TEST(Distance,DefaultConstructor) {
    Distance d1;
    std::string ExpectedOut = "Feet: 0 Inches: 0\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,ParameterizedConstructor) {
    Distance d1(6,1);
    std::string ExpectedOut = "Feet: 6 Inches: 1\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,Operatorplus) {
    Distance d1(3,4);
    Distance d2(3,1);
    Distance d3;
    d3=d1+d2;
    std::string ExpectedOut = "Feet: 6 Inches: 5\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,Operatorminus) {
    Distance d1(3,5);
    Distance d2(4,1);
    Distance d3;
    d3=d1-d2;
    std::string ExpectedOut = "Feet: 0 Inches: 4\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,Operatorplusnum) {
    Distance d1(3,5);
    Distance d3;
    d3=d1+(5);
    std::string ExpectedOut = "Feet: 3 Inches: 10\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,Operatorminusnum) {
    Distance d1(3,5);
    Distance d3;
    d3=d1-(5);
    std::string ExpectedOut = "Feet: 3 Inches: 0\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,Operatorplusplus) {
    Distance d1(3,5);
    Distance d2(3,1);
    Distance d3;
    d3=d1+d2;
    ++d3;
    std::string ExpectedOut = "Feet: 7 Inches: 7\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Distance,Operatorpluspluspost) {
    Distance d1(5,5);
    Distance d2(3,1);
    Distance d3;
    d3=d1+d2;
    d3++;
    std::string ExpectedOut = "Feet: 9 Inches: 7\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Distance,Operatorequals) {
    Distance d1(5,5);
    EXPECT_EQ(0, d1==4);
    EXPECT_EQ(1, d1==5);
}

TEST(Distance,OperatorLessThan) {
    Distance d1(5,5);
    EXPECT_EQ(0, d1<4);
    EXPECT_EQ(1, d1<10);
}
TEST(Distance,OperatorGreaterThan) {
    Distance d1(5,5);
    EXPECT_EQ(1, d1>4);
    EXPECT_EQ(0, d1>10);

}
//End of Distance Unit Testing
//Currency Unit Testing
TEST(Currency,DefaultConstructor) {
    Currency c1;
    std::string ExpectedOut = "0:0\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,ParameterizedConstructor) {
    Currency c1(6,10);
    std::string ExpectedOut = "6:10\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Currency,ParameterizedConstructorsingle) {
    Currency c1(6);
    std::string ExpectedOut = "6:0\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorplus) {
    Currency d1(3,4);
    Currency d2(3,1);
    Currency d3;
    d3=d1+d2;
    std::string ExpectedOut = "6:5\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorminus) {
    Currency d1(3,5);
    Currency d2(4,1);
    Currency d3;
    d3=d1-d2;
    std::string ExpectedOut = "-1:4\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorplusnum) {
    Currency d1(3,5);
    Currency d3;
    d3=d1+(5);
    std::string ExpectedOut = "3:10\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorminusnum) {
    Currency d1(3,5);
    Currency d3;
    d3=d1-(5);
    std::string ExpectedOut = "3:0\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorplusplus) {
    Currency d1(3,5);
    Currency d2(3,1);
    Currency d3;
    d3=d1+d2;
    ++d3;
    std::string ExpectedOut = "7:7\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorpluspluspost) {
    Currency d1(5,5);
    Currency d2(3,1);
    Currency d3;
    d3=d1+d2;
    d3++;
    std::string ExpectedOut = "9:7\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Currency,Operatorequals) {
    Currency d1(5,5);
    Currency d2(4,6);
    EXPECT_EQ(0, d1==d2);
}

TEST(Currency,OperatorLessThan) {
    Currency d1(5,5);
    Currency d2(4,5);
    EXPECT_EQ(0, d1<d2);
    EXPECT_EQ(1, d2<d1);
}

TEST(Currency,OperatorGreaterThan) {
    Currency d1(5,5);
    Currency d2(6,3);
    EXPECT_EQ(0, d1>d2);
    EXPECT_EQ(1, d2>d1);

}
//End of Currency Unit Testing
//Fraction Unit Testing

TEST(Fraction,DefaultConstructor) {
    Fraction c1;
    std::string ExpectedOut = "0/1\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,ParameterizedConstructor) {
    Fraction c1(6,10);
    std::string ExpectedOut = "6/10\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,ParameterizedConstructorsingle) {
    Fraction c1(6);
    std::string ExpectedOut = "6/1\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,Operatorplus) {
    Fraction d1(3,4);
    Fraction d2(3,1);
    Fraction d3;
    d3=d1+d2;
    std::string ExpectedOut = "15/4\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,Operatorminus) {
    Fraction d1(3,5);
    Fraction d2(4,1);
    Fraction d3;
    d3=d1-d2;
    std::string ExpectedOut = "-17/5\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,Operatorplusnum) {
    Fraction d1(3,5);
    Fraction d3;
    d3=d1+(5);
    std::string ExpectedOut = "28/5\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,Operatorminusnum) {
    Fraction d1(3,5);
    Fraction d3;
    d3=d1-(5);
    std::string ExpectedOut = "-22/5\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Fraction,Operatorequals) {
    Fraction d1(5,5);
    Fraction d2(4,6);
    EXPECT_EQ(0, d1==d2);
}

TEST(Fraction,OperatorLessThan) {
    Fraction d1(5,5);
    Fraction d2(4,5);
    EXPECT_EQ(0, d1<d2);
    EXPECT_EQ(1, d2<d1);
}

TEST(Fraction,OperatorGreaterThan) {
    Fraction d1(5,5);
    Fraction d2(6,3);
    EXPECT_EQ(0, d1>d2);
    EXPECT_EQ(1, d2>d1);

}
TEST(Fraction,Simplify) {
    Fraction d1(1,2);
    testing::internal::CaptureStdout();
    d1.simplify();
    std::string ExpectedOut = "Simplified value is 0.5\n";
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Fraction,IsSimplest) {
    Fraction d1(3,3);
    testing::internal::CaptureStdout();
    d1.isSimplest();
    std::string ExpectedOut = "Simplest\n";
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
//End of Fraction Unit Testing
//MyTime Unit Testing

TEST(MyTime,DefaultConstructor) {
    MyTime c1;
    std::string ExpectedOut = "Time is: 0:0:0\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,ParameterizedConstructor) {
    MyTime c1(6,10,5);
    std::string ExpectedOut = "Time is: 6:10:5\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,ParameterizedConstructordouble) {
    MyTime c1(6,10);
    std::string ExpectedOut = "Time is: 6:10:0\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorplus) {
    MyTime d1(3,4,5);
    MyTime d2(3,6,0);
    MyTime d3;
    d3=d1+d2;
    std::string ExpectedOut = "Time is: 6:10:5\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorminus) {
    MyTime d1(3,5,10);
    MyTime d2(4,1,11);
    MyTime d3;
    d3=d1-d2;
    std::string ExpectedOut = "Time is: 0:3:59\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorplusnum) {
    MyTime d1(3,55,55);
    MyTime d3;
    d3=d1+(5);
    std::string ExpectedOut = "Time is: 4:0:55\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorminusnum) {
    MyTime d1(3,4,10);
    MyTime d3;
    d3=d1-(5);
    std::string ExpectedOut = "Time is: 2:1:10\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorplusplus) {
    MyTime d1(3,5,10);
    ++d1;
    std::string ExpectedOut = "Time is: 3:6:11\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorpluspluspost) {
    MyTime d1(5,5,10);
    d1++;
    std::string ExpectedOut = "Time is: 5:6:11\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorplusequals) {
    MyTime d1(5,12,10);
    d1+=2;
    std::string ExpectedOut = "Time is: 5:24:20\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(MyTime,Operatorequals) {
    MyTime d1(5,5,5);
    MyTime d2(4,6,5);
    EXPECT_EQ(0, d1==d2);
}

TEST(MyTime,OperatorLessThan) {
    MyTime d1(5,5,10);
    MyTime d2(4,5,10);
    EXPECT_EQ(1, d2<d1);
}

TEST(MyTime,OperatorGreaterThan) {
    MyTime d1(5,5);
    MyTime d2(6,3);
    EXPECT_EQ(0, d1>d2);
    EXPECT_EQ(1, d2>d1);

}
//End of MyTime Unit Testing
//Complex Unit Testing

TEST(Complex,DefaultConstructor) {
    Complex c1;
    std::string ExpectedOut = "0\n0\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,ParameterizedConstructor) {
    Complex c1(6,10);
    std::string ExpectedOut = "6\n10\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,ParameterizedConstructorsingle) {
    Complex c1(6);
    std::string ExpectedOut = "6\n0\n";
    testing::internal::CaptureStdout();
    c1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,Operatorplus) {
    Complex d1(3,4);
    Complex d2(4,5);
    Complex d3;
    d3=d1+d2;
    std::string ExpectedOut = "7\n9\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,Operatorminus) {
    Complex d1(3,4);
    Complex d2(4,5);
    Complex d3;
    d3=d1-d2;
    std::string ExpectedOut = "-1\n-1\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,Operatormul) {
    Complex d1(3,4);
    Complex d2(4,5);
    Complex d3;
    d3=d1*d2;
    std::string ExpectedOut = "-8\n31\n";
    testing::internal::CaptureStdout();
    d3.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,Operatorplusplus) {
    Complex d1(3,5);
    ++d1;
    std::string ExpectedOut = "4\n6\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,Operatorpluspluspost) {
    Complex d1(4,6);
    d1++;
    std::string ExpectedOut = "5\n7\n";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Complex,Operatorequals) {
    Complex d1(5,5);
    Complex d2(4,6);
    EXPECT_EQ(0, d1==d2);
}
}
