#ifndef __ENGINEER_H
#define __ENGINEER_H

#include "employee.h"

class Engineer : public Employee {
  int m_projCode;
  public:
  Engineer(std::string , std::string , double ,int,int );
  void payroll();
  void appraisal();
  void display();
};

#endif
