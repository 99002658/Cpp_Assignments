#ifndef __PREPAID_H
#define __PREPAID_H

#include<string>
#include<cstdint>

#include "customer.h"

class PrepaidCustomer : public CustomerBase {
    void recharge(double);
  public:
    PrepaidCustomer();
    PrepaidCustomer(std::string,std::string,std::string,double);
    PrepaidCustomer(std::string,std::string,std::string);
    void credit(double);
    void makeCall(double);
    void display();
    double getBalance() ;
};

#endif
