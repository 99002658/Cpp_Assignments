#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <string>

//using namespace std;

class IEmployee {
  public:
  virtual void payroll()=0;
  virtual void appraisal()=0;
};

class Employee:public IEmployee {

  std::string m_empid;
  std::string m_name;
  double m_salary;
  int m_exp;
public:
    Employee(std::string , std::string , double ,int );
    Employee(std::string , std::string , double );
    void payroll();
    void appraisal();
    void setBalance(double var);
    double getBalance();
    int getExp();
    void display();
};

#endif
