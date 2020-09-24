#include <iostream>
#include <math.h>
#include "polygon.h"
#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "employee.h"
#include "engineer.h"
#include "trainee.h"
#include "manager.h"
#include "account.h"
#include "credit.h"
#include "saving.h"
#include "customer.h"
#include "postpaid.h"
#include "prepaid.h"
#define PERDAYSAL 300;
const static double PI = 22.0/7.0;
const double CALL_RATE = 1.0;
using namespace std;

//Employee
void Employee::payroll() {}
void Employee::appraisal() {}
void Employee::setBalance(double var) {
    m_salary=var;
}
double Employee::getBalance() {
    return m_salary;
}
int Employee::getExp() {
    return m_exp;
}
void Employee::display() {
    cout<<"Name: "<<m_name<<"  Emp ID: "<<m_empid<<" Salary: "<<m_salary<<" Exp: "<<m_exp<<endl;
}



Employee::Employee(std::string id, std::string name, double salary,int exp):
    m_empid(id),m_name(name),m_salary(salary),m_exp(exp) {}



Employee::Employee(std::string id, std::string name, double salary): m_empid(id),m_name(name),m_salary(salary) {}



Engineer::Engineer(std::string id, std::string name, double salary,int exp,int code):Employee(id,name,salary,exp),m_projCode(code) {}



void Engineer::payroll() {
    cout<<"Payroll : ";
    double sal=Employee::getExp()*PERDAYSAL;
    cout<<sal<<endl;
    Employee::setBalance(sal);
}
void Engineer::appraisal() {
    cout<<"Appraisal by 10% : ";
    double var2=Employee::getBalance();
    var2=var2+var2*10/100;
    cout<<var2<<endl;
    Employee::setBalance(var2);



}
void Engineer::display() {
    Employee::display();
    cout<<"\nProject code: "<<m_projCode<<endl;



}



Manager::Manager(std::string id, std::string name, double salary,int exp,int code,int reprtees):Employee(id,name,salary,exp),m_projCode(code),m_reportees(reprtees) {}



void Manager::payroll() {
    cout<<"Payroll: ";
    int pi=m_reportees*PERDAYSAL;
    cout<<pi<<endl;
    Employee::setBalance(pi);
}
void Manager::appraisal() {
    cout<<"Appraisal by 10%: ";
    int temp =Employee::getBalance();
    temp=temp+temp*10/100;
    cout<<temp<<endl;
    Employee::setBalance(temp);
}
void Manager::display() {
    Employee::display();
    cout<<"\nProject code: "<<m_projCode<<endl;
    cout<<"\nReporting days :"<<m_reportees<<endl;
}
Trainee ::Trainee(std::string id, std::string name, double salary,std::string track_code,double score): Employee( id,name,salary),m_track(track_code),score(score) {}



void Trainee::payroll() {
    cout<<"Payroll: ";
    int rr=1000*(score/100);
    cout<<rr<<endl;
    Employee::setBalance(rr);
}
void Trainee::appraisal() {
    cout<<"Appraisal by 10%: ";
    int tr=Employee::getBalance();
    tr=tr+tr*10/100;
    cout<<tr<<endl;
    Employee::setBalance(tr);
}
void Trainee::display() {
    Employee::display();
    cout<<"Track: "<<m_track;
    cout<<"\nScore: "<<score<<endl;
}
//End of Employee

//Banking Account
AccountBase::AccountBase() :
    m_accNumber(""), m_accName(""),m_balance(0.0) {

}

AccountBase::AccountBase(string a,string b,double c) :
    m_accNumber(a), m_accName(b),m_balance(c) {

}

void AccountBase::display() {
    double m=AccountBase::getBalance();

    cout << "Your Balance is: " << m<<endl;
}

CreditAccount::CreditAccount(string a, string b, double c):AccountBase( a, b, c) {
}

SavingsAccount::SavingsAccount(string a, string b, double c) :AccountBase(a,b,c) {

}

AccountBase::AccountBase(string a,string b) :
    m_accNumber(a), m_accName(b) {

}

CreditAccount::CreditAccount(string a, string b) : AccountBase(a,b) {

}

SavingsAccount::SavingsAccount(string a, string b) :AccountBase(a,b) {

}

AccountBase::AccountBase(const AccountBase &ref) :
    m_accNumber(ref.m_accNumber), m_accName(ref.m_accName), m_balance(ref.m_balance) {

}

void CreditAccount::debit(double amount) {
    double m=AccountBase::getBalance();

    cout << "Your Balance is: " << m-amount<<endl;
}

void SavingsAccount::debit(double amount) {
    double m=AccountBase::getBalance();

    cout << "Your Balance is: " << m-amount<<endl;
}

void CreditAccount::credit(double amount) {
    double m=AccountBase::getBalance();

    cout << "Your Balance is: " << m+amount<<endl;
}

void SavingsAccount::credit(double amount) {
    double m=AccountBase::getBalance();

    cout << "Your Balance is: " << m+amount<<endl;
}

void CreditAccount::display() {
    double m=AccountBase::getBalance();

    cout << "Your Balance is: " << m<<endl;
}

void SavingsAccount::display() {
    double m=AccountBase::getBalance();
    cout << "Your Balance is: " << m<<endl;
}

double AccountBase::getBalance() {
    return m_balance;
}
//End of Banking Account

//Customer
CustomerBase::CustomerBase() :
    m_custId(NULL), m_custName(NULL),m_phone(NULL),m_balance(0.0),m_type() {

}

CustomerBase::CustomerBase(string a,string b,string c,double d) :
    m_custId(a), m_custName(b),m_phone(c),m_balance(d) {

}

PostpaidCustomer::PostpaidCustomer(string a, string b, string c, double d, int e):CustomerBase(a,b,c,d),m_billDate(e) {
}

PrepaidCustomer::PrepaidCustomer(string a, string b, string c, double d):CustomerBase(a,b,c,d) {
}

CustomerBase::CustomerBase(string a, string b, string c):
    m_custId(a),m_custName(b),m_phone(c) {
}

PostpaidCustomer::PostpaidCustomer(string a, string b, string c):CustomerBase(a,b,c) {
}

PrepaidCustomer::PrepaidCustomer(string a, string b, string c):CustomerBase(a,b,c) {
}

CustomerBase::CustomerBase(const CustomerBase &ref) :
    m_custId(ref.m_custId), m_custName(ref.m_custName),m_phone(ref.m_phone),m_balance(ref.m_balance),m_type(ref.m_type) {

}

void PostpaidCustomer::credit(double amt) {
    double m=CustomerBase::getBalance();
    cout<<" Your Postpaid phone has been recharged by: "<<amt<<endl;
    cout<<" Your current Postpaid balance is: "<<m+amt;
}

void PrepaidCustomer::credit(double amt) {
    double m=CustomerBase::getBalance();
    cout<<" Your Prepaid phone has been recharged by: "<<amt<<endl;
    cout<<" Your current Prepaid balance is: "<<m+amt;
}

void PostpaidCustomer::makeCall(double nmins) {
    double m=CustomerBase::getBalance();
    m -= nmins * CALL_RATE;
    cout<<"Call time: "<<nmins<<"mins"<<endl;
    cout<<"Remaining recharge balance: "<<m<<endl;
}

void PrepaidCustomer::makeCall(double nmins) {
    double m=CustomerBase::getBalance();
    m -= nmins * CALL_RATE;
    cout<<"Call time: "<<nmins<<"mins"<<endl;
    cout<<"Remaining recharge balance: "<<m<<endl;
}

void PostpaidCustomer::display() {
    cout<<"Type of Account : PostPaid"<<endl;
    cout<<"Due date: "<<m_billDate;
}

void PrepaidCustomer::display() {
    cout<<"Type of Account : PrePaid"<<endl;
    cout<<"Recharge soon to avoid network connection breakage";
}
double PostpaidCustomer::getBalance() {
    double m = CustomerBase::getBalance();
    return m;
}

double PrepaidCustomer::getBalance() {
    double m = CustomerBase::getBalance();
    return m;
}

double CustomerBase::getBalance() {
    return m_balance;
}
//End of Customer

//Shapes
Polygon::Polygon(int s) :IShape() {
}

Circle::Circle(int r) :IShape(), m_radius(r) {
}
double Circle::area() {
    double ar = PI*m_radius*m_radius;
    cout << "Area of the Circle::" << ar << endl;
}
double Circle::circumference() {
    double crcm = PI*m_radius*2;
    cout << "Circumference of the Circle::" << crcm << endl;
}
Rectangle::Rectangle(int l, int b) : Polygon(2),m_length(l),m_breadth(b) {
}
double Rectangle::area() {
    double ar = m_length*m_breadth;
    cout << "Area of the Rectangle::" << ar << endl;
}
double Rectangle::circumference() {
    double crcm = 2*(m_length+m_breadth);
    cout << "Circumference of the Rectangle::" << crcm << endl;
}
Triangle::Triangle(int x, int y, int z) : Polygon(3),m_a(x),m_b(y),m_c(z) {
}
double Triangle::area() {
    double s = (m_a+m_b+m_c)/2;
    double ar = sqrt(s*(s-m_a)*(s-m_b)*(s-m_c));
    cout << "Area of the Triangle::" << ar << endl;
}
double Triangle::circumference() {
    double crcm = m_a+m_b+m_c;
    cout << "Circumference of the Triangle::" << crcm << endl;
}
/*
int main()
{
    CreditAccount c1("123456789", "Sam", 10000.00);
    c1.display();

    PostpaidCustomer po("123456789","Sam","8885994995",500.00,20);
    PrepaidCustomer pr("123456789","Sam","8885994995",800.00);
    cout<<"Balance of your Postpaid mobile is: "<<po.getBalance()<<endl;
    cout<<"Balance of your Prepaid mobile is: "<<pr.getBalance()<<endl;
    po.makeCall(20);
    po.makeCall(10);
    pr.makeCall(30);

    Circle c(10);
    c.area();
    c.circumference();
    Rectangle r(10,10);
    r.area();
    r.circumference();
    Triangle t(3,4,5);
    t.area();
    t.circumference();

    return 0;
}
*/
