#include "account.h"
#include "color.h"
#include "image.h"
#include "box.h"
#include "customer.h"
#include "ip.h"
#include "point.h"
#include <gtest/gtest.h>
namespace {
TEST(Account,DefaultConstructor) {
    Account a1;
    EXPECT_EQ(0.0,a1.getBalance());

}
TEST(Account,ParameterizedConstructor) {
    Account a1(1001,"Lippman",5000.0);
    EXPECT_EQ(5000.0,a1.getBalance());

}
TEST(Account,CopyConstructor) {
    Account a1(1001,"Lippman",5000.0);
    Account a2(a1);
    EXPECT_EQ(5000.0,a2.getBalance());

}
TEST(Account,CreditTest) {
    Account a1(1001,"Lippman",5000.0);
    a1.credit(3000);
    EXPECT_EQ(8000.0,a1.getBalance());

}
TEST(Account,DebitTest) {
    Account a1(1001,"Lippman",5000.0);
    a1.debit(1200);
    EXPECT_EQ(3800.0,a1.getBalance());
}
TEST(Account,DisplayTest) {
    Account a1(1001,"Lippman",5000.0);
    std::string ExpectedOut="1001,Lippman,5000\n";
    testing::internal::CaptureStdout();
    a1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Image, Default_constructor) {
    Image img;
    std::string ExpectedOut="0,0\n";
    testing::internal::CaptureStdout();
    img.scale(0,0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Image, Parametrised_constructor) {
    Image img(5,5,20,20);
    std::string ExpectedOut="5,6\n";
    testing::internal::CaptureStdout();
    img.scale(5,6);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Image, Copy_constructor) {
    Image img(5,5,20,20);
    std::string ExpectedOut="4,5\n";
    testing::internal::CaptureStdout();
    Image img1(img);
    img1.scale(4,5);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Image,MoveImage) {
    Image img(5,5,20,20);
    std::string ExpectedOut="Image has been moved to second quadrant and now the position is5,6\n";
    testing::internal::CaptureStdout();
    img.move(2,5,6);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Image,ScaleImage){
    Image img(5,5,20,20);
    std::string ExpectedOut="5,6\n";
    testing::internal::CaptureStdout();
    img.scale(5,6);
    std::string ActualOut=testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Image,ResizeImage){
    Image img(5,5,20,20);
    std::string ExpectedOut="7,7\n";
    testing::internal::CaptureStdout();
    img.resize(2,2);
    std::string ActualOut=testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Image,DisplayImage){
    Image img(5,5,20,20);
    std::string ExpectedOut="5,5,20,20\n";
    testing::internal::CaptureStdout();
    img.display();
    std::string ActualOut=testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST( Color, Inversion_Test ) {
    Color C1(254,254,254);
    std::string ExpectedOut="The Color has been inverted 1,1,1\n";
    testing::internal::CaptureStdout();
    C1.invert();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Color , Default_Constructor){
    Color C1;
    std::string ExpectedOut="The Color has been inverted 255,255,255\n";
    testing::internal::CaptureStdout();
    C1.invert();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Color, Parameterised_Constructor ) {
    Color C1(100,100,100);
    std::string ExpectedOut="The Color has been inverted 155,155,155\n";
    testing::internal::CaptureStdout();
    C1.invert();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Color, color_t_test) {
    std::string ExpectedOut="Red";
    testing::internal::CaptureStdout();
    Color C1(red);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Color, Display_Test ) {
    Color C1(254,254,254);
    std::string ExpectedOut="The Color composition is as follows: \nRed: 254, Green: 254,Blue: 254\n";
    testing::internal::CaptureStdout();
    C1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Box, Parameterised_Constructor) {
    Box b1(10,10,10);
    std::string ExpectedOut="Volume is: 1000\n";
    testing::internal::CaptureStdout();
    b1.volume(10,10,10);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Box, Default_Constructor) {
    Box b1;
    std::string ExpectedOut="Volume is: 0\n";
    testing::internal::CaptureStdout();
    b1.volume(0,0,0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Box , Copy_Constructor){
    Box b1(10,10,10);
    std::string ExpectedOut="Volume is: 1000\n";
    testing::internal::CaptureStdout();
    Box b2(b1);
    b2.volume(10,10,10);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}

TEST(Box,Volume_Test) {
    Box b1(10,10,10);
    std::string ExpectedOut="Volume is: 1000\n";
    testing::internal::CaptureStdout();
    b1.volume(10,10,10);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}

TEST (Box, Length_Test) {
    Box b1(10,10,10);
    std::string ExpectedOut="Length is: 20\n";
    testing::internal::CaptureStdout();
    b1.length(20);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Box, Height_Test) {
    Box b1(10,10,10);
    std::string ExpectedOut="Height is: 30\n";
    testing::internal::CaptureStdout();
    b1.height(30);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Box, Breadth_Test) {
    Box b1(10,10,10);
    std::string ExpectedOut="Breadth is: 40\n";
    testing::internal::CaptureStdout();
    b1.breadth(40);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(Customer,Default_Constructor) {
    Customer c;
    EXPECT_EQ(100,c.getBalance());
}
TEST(Customer,Parameterized_Constructor) {
    Customer c;
    c.init(1511, "Sam", "123456789", 5000.0);
    EXPECT_EQ(5000.0,c.getBalance());

}
TEST(Customer,Copy_Constructor) {
    Customer c;
    c.init(1511, "Sam", "123456789", 5000.0);
    Customer c2(c);
    EXPECT_EQ(5000.0,c2.getBalance());

}
TEST(Customer,Call_Test) {
    Customer c;
    c.init(1511, "Sam", "123456789", 5000.0);
    c.makeCall(30);
    EXPECT_EQ(4700.0,c.getBalance());

}
TEST(Customer,Credit_Test) {
    Customer c;
    c.init(1511, "Sam", "123456789", 5000.0);
    c.credit(1200);
    EXPECT_EQ(6200.0,c.getBalance());

}
TEST(Customer,Display_Test) {
    Customer c;
    c.init(1511, "Sam", "123456789", 5000.0);
    string ExpectedOut="1511,Sam,5000,123456789\n";
    testing::internal::CaptureStdout();
    c.display();
    string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(IPAddress,Default_Constructor){
    IPAddress ip;
    EXPECT_EQ(true, ip.isLoopBack());

}
TEST(IPAddress,Parameterized_Constructor){
    IPAddress ip(4,4,4,4);
    EXPECT_EQ(false, ip.isLoopBack());

}
TEST(IPAddress,Loopback_Check){
    IPAddress ip(127,0,0,1) ;
    EXPECT_EQ(true, ip.isLoopBack());

}
TEST(IPAddress,IP_Class){
    IPAddress ip(127,0,0,1);
    std::string ExpectedOut="IP Class::A\n";
    testing::internal::CaptureStdout();
    ip.getIPClass();
    std::string ActualOut=testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST(IPAddress,IP_Display){
    IPAddress ip(12,12,12,12);
    std::string ExpectedOut="IP Address::12.12.12.12\n";
    testing::internal::CaptureStdout();
    ip.display();
    std::string ActualOut=testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Point , Parameterised_Constructor ) {
    Point p(2,4);
    std::string ExpectedOut="Point is not on the Origin\n";
    testing::internal::CaptureStdout();
    p.isOrigin(2,4);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST (Point , Default_Constructor ) {
    Point p;
    std::string ExpectedOut="Point is on the Origin\n";
    testing::internal::CaptureStdout();
    p.isOrigin(0,0);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());

}
TEST (Point , Copy_Constructor ) {
    Point p1(2,4);
    std::string ExpectedOut="Point is not on the Origin\n";
    testing::internal::CaptureStdout();
    Point p2(p1);
    p2.isOrigin(2,4);
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Point,Distance_from_Origin) {
    Point p(1,2);
    string ExpectedOut="distance from Origin is1\n";
    testing::internal::CaptureStdout();
    p.distanceFromOrigin(1,2);
    string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Point,ON_x_axis) {
    Point p(1,2);
    string ExpectedOut="Point does not lie on X axis\n";
    testing::internal::CaptureStdout();
    p.isOnXAxis(1,2);
    string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

TEST(Point,ON_y_axis) {
    Point p(1,2);
    string ExpectedOut="Point does not lie on Y axis\n";
    testing::internal::CaptureStdout();
    p.isOnYAxis(1,2);
    string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Point,ON_origin) {
    Point p(1,2);
    string ExpectedOut="Point is not on the Origin\n";
    testing::internal::CaptureStdout();
    p.isOrigin(1,2);
    string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
TEST(Point,Display_Point) {
    Point p(1,2);
    string ExpectedOut="1,2\n\n";
    testing::internal::CaptureStdout();
    p.display();
    string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
}





