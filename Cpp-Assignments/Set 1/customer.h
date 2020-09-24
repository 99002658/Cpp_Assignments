#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include <iostream>
#include<string>
using namespace std ;
class Customer {
  private:
    int m_custId, m_type ,m_balance;
    string m_phone, m_custName  ;
  public:
    Customer () ;
    Customer( int , string , string , double );
    Customer(int , int , int ) ;
    Customer( const Customer & );
    void credit (double) ;
    void makeCall (int) ;
    double getBalance() ;
    void display () ;
    void init(int , string ,string , double );
};
#endif
