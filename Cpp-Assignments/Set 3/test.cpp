#include <iostream>
#include "account.h"
#include "credit.h"
#include "saving.h"
#include "shape.h"
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "customer.h"
#include "postpaid.h"
#include "prepaid.h"
#include "employee.h"
#include "engineer.h"
#include "manager.h"
#include "trainee.h"
#include <gtest/gtest.h>
namespace{
TEST(AccountBase,SavingsBalanceDisplay){
    SavingsAccount a("1001","Sam",1000.0);
    std::string ExpectedOut="Your Balance is: 1000\n";
    testing::internal::CaptureStdout();
    a.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(AccountBase,CreditedSavingsDisplay){
    SavingsAccount a("1001","Sam",1000.0);
    std::string ExpectedOut="Your Balance is: 1100\n";
    testing::internal::CaptureStdout();
    a.credit(100);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(AccountBase,DebitedSavingsDisplay){
    SavingsAccount a("1001","Sam",1000.0);
    std::string ExpectedOut="Your Balance is: 900\n";
    testing::internal::CaptureStdout();
    a.debit(100);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(AccountBase,CreditBalanceDisplay){
    CreditAccount a("1001","Sam",1000.0);
    std::string ExpectedOut="Your Balance is: 1000\n";
    testing::internal::CaptureStdout();
    a.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(AccountBase,CreditedCreditAccDisplay){
    CreditAccount a("1001","Sam",1000.0);
    std::string ExpectedOut="Your Balance is: 1100\n";
    testing::internal::CaptureStdout();
    a.credit(100);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(AccountBase,DebitedCreditAccDisplay){
    CreditAccount a("1001","Sam",1000.0);
    std::string ExpectedOut="Your Balance is: 900\n";
    testing::internal::CaptureStdout();
    a.debit(100);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}

TEST(ISShape,Circle_area_test){
    Circle c1(10);
    std::string ExpectedOut="Area of the Circle::314.286\n";
    testing::internal::CaptureStdout();
    c1.area();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}

TEST(Polygon,Rectangle_area_test){
    Rectangle r1(4,2);
    std::string ExpectedOut="Area of the Rectangle::8\n";
    testing::internal::CaptureStdout();
    r1.area();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Polygon,Circle_circumference_test){
    Circle c1(10);
    std::string ExpectedOut="Circumference of the Circle::62.8571\n";
    testing::internal::CaptureStdout();
    c1.circumference();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Polygon,Rectangle_circumference_test){
    Rectangle r1(4,2);
    std::string ExpectedOut="Circumference of the Rectangle::12\n";
    testing::internal::CaptureStdout();
    r1.circumference();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Polygon,Triangle_area_test){
    Triangle t1(10,10,10);
    std::string ExpectedOut="Area of the Triangle::43.3013\n";
    testing::internal::CaptureStdout();
    t1.area();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Polygon,Triangle_circumference_test){
    Triangle t1(3,2,4);
    std::string ExpectedOut="Circumference of the Triangle::9\n";
    testing::internal::CaptureStdout();
    t1.circumference();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(CustomerBase,PostpaidDisplayParameterized) {
    PostpaidCustomer d1("1001","Sam","123456789",500.0,24);
    std::string ExpectedOut = "Type of Account : PostPaid\nDue date: 24";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PrepaidDisplayParameterized) {
    PrepaidCustomer d1("1001","Sam","123456789",500.0);
    std::string ExpectedOut = "Type of Account : PrePaid\nRecharge soon to avoid network connection breakage";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PostpaidDisplay3ParameterConstructor) {
    PostpaidCustomer d1("1001","Sam","123456789");
    std::string ExpectedOut = "Type of Account : PostPaid\nDue date: 0";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PrepaidDisplay3ParameterConstructor) {
    PrepaidCustomer d1("1001","Sam","123456789");
    std::string ExpectedOut = "Type of Account : PrePaid\nRecharge soon to avoid network connection breakage";
    testing::internal::CaptureStdout();
    d1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PostpaidGetBalance) {
    PostpaidCustomer d1("1001","Sam","123456789",500.0,24);
    EXPECT_EQ(500.0, d1.getBalance());
}
TEST(CustomerBase,PrepaidGetBalance) {
    PrepaidCustomer d1("1001","Sam","123456789",500.0);
    EXPECT_EQ(500.0, d1.getBalance());
}
TEST(CustomerBase,PostpaidMakeCall) {
    PostpaidCustomer d1("1001","Sam","123456789",500.0,24);
    std::string ExpectedOut = "Call time: 10mins\nRemaining recharge balance: 490\n";
    testing::internal::CaptureStdout();
    d1.makeCall(10.0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PrepaidMakeCall) {
    PrepaidCustomer d1("1001","Sam","123456789",500.0);
    std::string ExpectedOut = "Call time: 20mins\nRemaining recharge balance: 480\n";
    testing::internal::CaptureStdout();
    d1.makeCall(20.0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PostpaidRecharge) {
    PostpaidCustomer d1("1001","Sam","123456789",500.0,24);
    std::string ExpectedOut = " Your Postpaid phone has been recharged by: 150\n Your current Postpaid balance is: 650";
    testing::internal::CaptureStdout();
    d1.credit(150.0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(CustomerBase,PrepaidRecharge) {
    PrepaidCustomer d1("1001","Sam","123456789",500.0);
    std::string ExpectedOut = " Your Prepaid phone has been recharged by: 150\n Your current Prepaid balance is: 650";
    testing::internal::CaptureStdout();
    d1.credit(150.0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(IEmployee,EngineerPayrollTest) {
    Engineer a1("1AF","Shrawani",10000,2,3);
    std::string ExpectedOut = "Payroll : 600\n";
    testing::internal::CaptureStdout();
    a1.payroll();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(IEmployee,EngineerAppraisalTest) {
    Engineer a1("1AF","Shrawani",10000,2,3);
    std::string ExpectedOut = "Appraisal by 10% : 11000\n";
    testing::internal::CaptureStdout();
    a1.appraisal();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(IEmployee,ManagerAppraisalTest) {
    Manager a1("1AF","Shrawani",10000,2,3,5);
    std::string ExpectedOut = "Appraisal by 10%: 11000\n";
    testing::internal::CaptureStdout();
    a1.appraisal();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(IEmployee,ManagerPayrollTest) {
    Manager a1("1AF","Shrawani",10000,2,3,5);
    std::string ExpectedOut = "Payroll: 1500\n";
    testing::internal::CaptureStdout();
    a1.payroll();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(IEmployee,TraineePayrollTest) {
    Trainee a1("1AF","Shrawani",10000,"2A",10);
    std::string ExpectedOut = "Payroll: 100\n";
    testing::internal::CaptureStdout();
    a1.payroll();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(IEmployee,TraineeAppraisalTest) {
    Trainee a1("1AF","Shrawani",10000,"2A",10);
    std::string ExpectedOut = "Appraisal by 10%: 11000\n";
    testing::internal::CaptureStdout();
    a1.appraisal();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
}
