#include <iostream>
#include<cmath>
#include "complex.h"
#include "array.h"
#include "stack.h"
#include "point.h"
using namespace std;


//First Class - Complex
template<typename T>
Complex<T>::Complex():m_real{0},m_image{0} {}
template<typename T>
Complex<T>::Complex(T r,T i):m_real(r),m_image(i) {}

template<typename T>
void Complex<T>::display() {
    cout<<m_real<<"+"<<m_image<<"i"<<"\n";
}



template<typename T>
MyArray<T>::MyArray():
    m_arr(NULL),m_len(0) {
}
template<typename T>
MyArray<T>::MyArray(T len):m_len(len) {}
template<typename T>
MyArray<T>::~MyArray() {}
template<typename T>
void MyArray<T>::append(T val) {
}
template<typename T>
T MyArray<T>::at(int index) {
    return index;
}
template<typename T>
bool MyArray<T>::search(T key) const {
    if(key==1) {
        return true;
    } else {
        return false;
    }
}
template<typename T>
T MyArray<T>::sum() const {
    for(int i=0; i<=m_len; i++) {
        sum=sum+m_arr;
        return sum;
    }
}
template<typename T>
T MyArray<T>::min() const {
    min(m_arr);
}
template<typename T>
T MyArray<T>::max() const {
    max(m_arr);
}
template<typename T>
void MyArray<T>::reverse() {
    reverse(m_arr);
}
template<typename T>
void MyArray<T>::sort() {
    sort(m_arr);
}



//Third Class -Point
template<typename T>
Point<T>::Point():m_x(0),m_y(0) {}
template<typename T>
Point<T>::Point(T x,T y):m_x(x),m_y(y) {}

template<typename T>
void Point<T>::distanceFromOrigin() {
    T d;
    d=sqrt((m_x*m_x)+(m_y*m_y));
    cout<<"Distance from Origin:"<<d<<"\n";
}
template<typename T>
Quadrant Point<T>::quadrant() {

    if((m_x>0)&&(m_y>0)) {
        cout<<"Quadrant is:"<<"Q1";
    } else if((m_x<0)&&(m_y>0)) {
        cout<<"Quadrant is:"<<"Q2";
    } else if((m_x<0)&&(m_y<0)) {
        cout<<"Quadrant is:"<<"Q3";
    } else {
        cout<<"Quadrant is:"<<"Q4";
    }


}
template<typename T>
void Point<T>::display() {
    cout<<"X axis is:"<<m_x<<"\n"<<"Y axis is:"<<m_y<<"\n";
}



//Stack Class


template<typename T>
MyStack<T>::MyStack():m_top(0) {}
template<typename T>
MyStack<T>::MyStack(T len):m_maxlen(50) {}
template<typename T>
MyStack<T>::MyStack(T len,T to):m_maxlen(50),m_top(0) {}
template<typename T>
void MyStack<T>::push(T val) {
    if(m_top>=m_maxlen-1)
        cout<<"Stack Overflow"<<endl;
    else {
        m_top++;
        m_arr[m_top]=val;
    }

}

template<typename T>
int MyStack<T>::pop() {

    if(m_top<=-1)
        cout<<"Stack Underflow"<<endl;
    else {
        cout<<"The popped element is "<< m_arr[m_top] <<endl;
        m_top--;
    }
}

template<typename T>
int MyStack<T>::peek() {
    for(int i=0; i<m_maxlen; i++) {
        cout<<m_arr[i]<<",";
    }
}

template<typename T>
bool MyStack<T>::isEmpty() const {

    if(m_top<=-1) {
        return true;
    } else {
        return false;

    }
}

template<typename T>
bool MyStack<T>::isFull() const {
    if(m_top>=m_maxlen-1) {

        return true;
    } else {
        return false;

    }
}



int main() {


    Complex<int> c(0,0);
    Complex<float> c1(1.2,2.4);
    c.display();
    c1.display();





    Point<float> p(2,-3);
    p.display();
    p.distanceFromOrigin();
    p.quadrant();
    return 0;


    MyStack<int> m(10,0);
    m.peek();
    m.push(10);
    m.push(20);
    m.push(30);
    m.push(40);
    m.pop();
    m.peek();
    bool j,k;
    j=m.isFull();
    k=m.isEmpty();
    cout<<"\n";
    if(j==true) {
        cout<<"Stack Overflow"<<endl;
    } else {
        cout<<"No Overflow"<<"\n";
    }

    j=m.isEmpty();
    if(k==true) {
        cout<<"\n"<<"Stack Underflow"<<endl;
    } else {
        cout<<"No Underflow"<<"\n";
    }


}
