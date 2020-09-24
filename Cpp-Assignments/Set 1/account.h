#include<string>
class Account {
  int m_accNumber; // ideally to be of string type
  std::string m_accName;
  double m_balance;

public:
  Account();
  Account(int, std::string, double);
  Account(int , int);
  Account(const Account &);
  void credit(double);
  void debit(double);
  double getBalance() const;
  void display();
};
