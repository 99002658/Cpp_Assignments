#include <iostream>
#include <stdio.h>
#include <string>                   //to_string(str)
using namespace std;

enum IPClass { A, B, C, D };
class IPAddress{
private:
    string ipval;
public:
    int a;
    int b;
    int c;
    int d;
    IPAddress(string ip){ipval = ip;}
    IPAddress(int w, int x, int y, int z){a=w, b=x, c=y, d=z;}
    //IPAddress(int);
    bool isLoopBack(){
        string temp_ip;
        temp_ip = (to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d));
        if ((ipval == "127.0.0.1")||(temp_ip == "127.0.0.1")){
            cout<<"Loopback IP"<<endl;
            return true;
        }
        else{
            cout<<"Not Loopback IP"<<endl;
            return false;
        }
    }
    int getIPClass(){
        string temp_ip;
        temp_ip = (to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d));
        string temp_str;
        int ip_num;
        int i = 0;
        ipval = temp_ip;
        while (ipval[i]!='.'){
            temp_str = temp_str + ipval[i];
            i++;
        }
        ip_num = stoi(temp_str);
        if (ip_num>=1 && ip_num<=127){
            IPClass cls = IPClass::A;
            cout<<"IP Class::"<<cls<<endl;
        }
        else if (ip_num>=128 && ip_num<=191){
            IPClass cls = IPClass::B;
            cout<<"IP Class::"<<cls<<endl;
        }
        else if (ip_num>=192 && ip_num<=223){
            IPClass cls = IPClass::C;
            cout<<"IP Class::"<<cls<<endl;
        }
        else if (ip_num>=224 && ip_num<=239){
            IPClass cls = IPClass::D;
            cout<<"IP Class::"<<cls<<endl;
        }
        return 0;
    }
    void display(){
        cout<<"IP-Address::"<<ipval<<endl;
    }
};
