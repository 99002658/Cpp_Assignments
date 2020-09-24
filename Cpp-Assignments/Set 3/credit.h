#ifndef __BANKING_H
#define __BANKING_H

#include<string>
#include"account.h"

class CreditAccount : public AccountBase {
  public:
    CreditAccount();
    CreditAccount(std::string,std::string,double);
    CreditAccount(std::string,std::string);
    void debit(double);
    void credit(double);
    void display();

};

#endif
