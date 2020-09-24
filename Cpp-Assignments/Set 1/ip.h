#include <iostream>
#include <stdio.h>
using namespace std;

enum IPClass {A='A', B='B', C='C', D='D' };
class IPAddress{
private:
    std::string ipval;
public:
    IPAddress();
    IPAddress(int,int,int,int);
    bool isLoopBack();
    int getIPClass();
    void display();
};
