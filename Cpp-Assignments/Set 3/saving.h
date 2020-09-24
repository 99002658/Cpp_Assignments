#ifndef __SAVINGS_ACCOUNT_H
#define __SAVINGS_ACCOUNT_H

#include<string>
#include"account.h"

class SavingsAccount : public AccountBase {
  public:
    SavingsAccount();
    SavingsAccount(std::string,std::string,double);
    SavingsAccount(std::string,std::string);
    void debit(double);
    void credit(double);
    void display() ;

};

#endif
