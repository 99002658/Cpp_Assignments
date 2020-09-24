#ifndef __POSTPAID_H
#define __POSTPAID_H

#include<string>
#include<cstdint>

#include "customer.h"

class PostpaidCustomer : public CustomerBase {
    void billPay(double);
    int m_billDate;
  public:
    PostpaidCustomer();
    PostpaidCustomer(std::string,std::string,std::string,double,int);
    PostpaidCustomer(std::string,std::string,std::string);
    void credit(double);
    void makeCall(double);
    void display();
    double getBalance() ;

};

#endif
