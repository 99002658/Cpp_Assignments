#include <iostream>
#include "distance.h"
#include "currency.h"
#include "fraction.h"
#include "mytime.h"
#include "complex_num.h"
using namespace std;

//Distance
Distance::Distance():
    m_feets(0), m_inches(0) {
}
Distance::Distance(int foot, int inch):
    m_feets(foot), m_inches(inch) {

}
Distance Distance::operator+(const Distance &ref) {
    int temp=0,temp1=0;
    int tfeet= m_feets+ref.m_feets;
    int tinch= m_inches+ref.m_inches;
    if(tinch>12) {
        temp = tinch/12;
        tinch= tinch%12;
    }
    tfeet+=temp;
    return Distance(tfeet,tinch);
}
Distance Distance::operator-(const Distance &ref) {
    int temp=0,temp1=0;
    int tfeet= m_feets-ref.m_feets;
    int tinch= m_inches-ref.m_inches;
    temp1=tinch;
    if(tinch<0) {
        if(tfeet>0)
            tfeet-=1;
        else
            tfeet=0;
        tinch=12+temp1;
    }
    if(temp1>12) {
        temp = tinch/12;
        tinch= tinch%12;
    }
    if(tfeet<0)
        tfeet=0;
    tinch=temp1;
    tfeet+=temp;
    return Distance(tfeet,tinch);
}
Distance Distance::operator+(int inch) {
    int temp=0,temp1=0,tfeet=0;
    int tinch = m_inches+inch;
    if(tinch>12) {
        temp = tinch/12;
        tinch= tinch%12;
    }
    tfeet+=temp+m_feets;
    return Distance(tfeet,tinch);
}
Distance Distance::operator-(int inch) {
    int temp=0,temp1=0,tfeet=0;
    int tinch = m_inches-inch;
    if(tinch>12) {
        temp = tinch/12;
        tinch= tinch%12;
        m_feets+=temp;
    }
    tfeet+=temp+m_feets;
    if(tinch<0) {
        m_feets-=1;
        m_inches=12-tinch;
    }
    return Distance(tfeet,tinch);
}
Distance& Distance::operator++() {
    int temp=0;
    ++m_inches;
    if(m_inches>12) {
        temp = m_inches/12;
        m_inches= m_inches%12;
        m_feets+=temp;
    }
    ++m_feets;
    return *this;
}
Distance Distance::operator++(int dummy) {
    Distance orig(*this);
    int temp=0;
    ++m_inches;
    if(m_inches>12) {
        temp = m_inches/12;
        m_inches= m_inches%12;
        m_feets+=temp;
    }
    ++m_feets;
    return orig;
}
bool Distance::operator==(int feet) {
    bool temp;
    temp = (m_feets==feet);
    return temp;
}
bool Distance::operator<(int feet) {
    bool temp;
    temp = (m_feets<feet);
    return temp;
}
bool Distance::operator>(int feet) {
    bool temp;
    temp = (m_feets>feet);
    return temp;
}
void Distance::display () {
    std::cout <<"Feet: "<< m_feets << " Inches: " << m_inches << "\n";
}

//End of Distance
//Currency
Currency::Currency():
    m_rupees(0),m_paise(0) {}
Currency::Currency(int r, int p) : m_rupees(r), m_paise(p) {}
Currency::Currency(int r) : m_rupees(r),m_paise(0) {}
Currency Currency::operator+(const Currency &ref) {
    int tpaise = m_paise + ref.m_paise;
    int trupees = m_rupees + ref.m_rupees;
    return Currency(trupees,tpaise);
}
Currency Currency::operator-(const Currency &ref) {
    int tpaise = m_paise - ref.m_paise;
    int trupees = m_rupees - ref.m_rupees;
    return Currency(trupees,tpaise);
}
Currency Currency::operator+(int npaise) {
    int tpaise = m_paise + npaise;
    int trupees = m_rupees;
    return Currency(trupees,tpaise);
}
Currency Currency::operator-(int npaise) {
    int tpaise = m_paise - npaise;
    int trupees = m_rupees;
    return Currency(trupees,tpaise);
}
Currency Currency:: operator++() {
    ++m_paise;
    if (m_paise==100) {
        m_rupees+=1;
        m_paise=0;
    }

    ++m_rupees;
    cout<<m_paise<<endl;
}
Currency Currency:: operator++(int dummy) {
    Currency orig(*this);
    int temp=0;
    ++m_paise;
    if(m_paise==100) {
        m_rupees+=1;
        m_paise=0;
    }
    ++m_rupees;
    return orig;
}
bool Currency:: operator==(const Currency &ref) {
    return m_rupees == ref.m_rupees && m_paise == ref.m_paise;
}
bool Currency::operator< (const Currency &ref) {
    return (m_rupees<ref.m_rupees);
}
bool Currency::operator> (const Currency &ref) {
    return (m_rupees>ref.m_rupees);
}
void Currency:: display() {
    std::cout << m_rupees << ":" << m_paise << "\n";
}
//End of Currency
//Fraction
Fraction::Fraction() :
    m_numerator(0), m_denominator(1) {

}

Fraction::Fraction(int x, int y) :
    m_numerator(x), m_denominator(y) {

}

Fraction::Fraction(int x):m_numerator(0),m_denominator(1) {
    m_numerator+=(x*m_denominator);
}

Fraction Fraction::operator+(const Fraction &ref) {
    int num,den;
    if(m_denominator==ref.m_denominator) {
        num=m_numerator + ref.m_numerator;
        den=ref.m_denominator;
    } else {
        num=(m_numerator*ref.m_denominator)+(m_denominator*ref.m_numerator);
        den=(m_denominator*ref.m_denominator);
    }
    return Fraction(num,den);
    cout << "Numerator is " << num <<"," << "Denominator is "<< den<<endl;
}

Fraction Fraction::operator-(const Fraction &ref) {
    int num,den;
    if(m_denominator==ref.m_denominator) {
        num=m_numerator - ref.m_numerator;
        den=ref.m_denominator;
    } else {
        num=(m_numerator*ref.m_denominator)-(m_denominator*ref.m_numerator);
        den=(m_denominator*ref.m_denominator);
    }
    return Fraction(num,den);
    cout <<"Numerator is " << num <<"," << "Drnominator is "<< den<<endl;
}

Fraction Fraction::operator*() {
    int num=m_numerator * m_denominator; ;
    cout << "Multiplication of numerator and denominator is " << num<<endl ;
}

Fraction Fraction::operator+(int x) {
    int num=(x*m_denominator)+m_numerator ;
    int den = m_denominator;
    return Fraction(num,den);
    cout << "Addition is " << num/den<<endl;

}

Fraction Fraction::operator-(int x) {
    int num=-(x*m_denominator)+m_numerator ;
    int den = m_denominator;
    return Fraction(num,den);
    cout << "Subtraction is " << num/den<<endl;
}

bool Fraction::operator==(const Fraction &ref) {
    return m_numerator==ref.m_numerator && m_denominator==ref.m_denominator;
}
bool Fraction::operator<(const Fraction &ref) {
    float num1=float(m_numerator/m_denominator);
    float num2=float(ref.m_numerator/ref.m_denominator);
    if(num1<num2)
        return true;
    else
        return false;
}
bool Fraction::operator>(const Fraction &ref) {
    float num1=float(m_numerator/m_denominator);
    float num2=float(ref.m_numerator/ref.m_denominator);
    if(num1>num2)
        return true;
    else
        return false;
}
void Fraction::simplify() {
    float num1=float(m_numerator)/float(m_denominator);
    cout << "Simplified value is " << num1<<endl;
}
void Fraction::isSimplest() {
    if (m_numerator==m_denominator)
        cout << "Simplest"<<endl;
    else
        cout << "Not Simplest"<<endl;
}
void Fraction::display() {
    cout << m_numerator << "/"<<m_denominator<<endl;
}
//End of Fraction
//MyTime
MyTime::MyTime():m_hours(0),m_minutes(0), m_seconds(0) { }
MyTime::MyTime(int h, int m, int s) : m_hours(h), m_minutes(m), m_seconds(s) {
}
MyTime::MyTime(int h, int m) : m_hours(h), m_minutes(m), m_seconds(0) {}
MyTime MyTime::operator+(const MyTime &ref) {
    int tmins=0,thrs=0;
    int tsec = m_seconds + ref.m_seconds;
    if (tsec>60) {
        tmins+=(tsec/60);
        tsec = tsec%60;
    } else if(tsec==60)
        tmins+=1;
    tmins+=m_minutes + ref.m_minutes;
    if(tmins>60) {
        thrs+=(tmins/60);
        tmins = tmins%60;

    }
    thrs+=m_hours + ref.m_hours;
    return MyTime(thrs, tmins, tsec);
}
MyTime MyTime::operator-(const MyTime &ref) {
    int tmins=0,thrs=0;
    int tsec = m_seconds - ref.m_seconds;
    if(tsec<0) {
        tmins-=1;
        tsec=60+tsec;
    }
    if (tsec>60) {
        tmins+=(tsec/60);
        tsec = tsec%60;
    } else if(tsec==60)
        tmins+=1;
    tmins+=m_minutes - ref.m_minutes;
    if(tmins>60) {
        thrs+=(tmins/60);
        tmins = tmins%60;

    }
    thrs+=m_hours - ref.m_hours;
    if(thrs<0)
        thrs=0;
    return MyTime(thrs, tmins, tsec);
}
MyTime MyTime::operator+(int nmins) {
    int thrs=0;
    int tsec=m_seconds;
    int tmins = m_minutes + nmins;
    if(tmins>=60) {
        thrs+=(tmins/60);
        tmins = tmins%60;

    }
    thrs+=m_hours;
    return MyTime(thrs, tmins,tsec);

}
MyTime MyTime::operator-(int nmins) {
    int thrs=0;
    int tsec=m_seconds;
    int tmins = m_minutes - nmins;
    if(tmins>60) {
        thrs+=(tmins/60);
        tmins = tmins%60;

    } else if(tmins<0) {
        thrs-=1;
        tmins=abs(tmins);

    }
    thrs+=m_hours;
    return MyTime(thrs, tmins,tsec);

}
MyTime& MyTime::operator++() {
    ++m_seconds;
    if(m_seconds>60) {
        m_minutes+=(m_seconds/60);
        m_seconds = m_seconds%60;
    }
    ++m_minutes;
    if(m_minutes>60) {
        m_hours+=(m_minutes/60);
        m_minutes = m_minutes%60;
    }
    return *this;
}
MyTime MyTime::operator++(int d) {
    MyTime orig(*this);
    ++m_seconds;
    if(m_seconds>60) {
        m_minutes+=(m_seconds/60);
        m_seconds = m_seconds%60;
    }
    ++m_minutes;
    if(m_minutes>60) {
        m_hours+=(m_minutes/60);
        m_minutes = m_minutes%60;
    }
    return orig;
}
MyTime MyTime::operator+=(int d) {
    MyTime orig(*this);
    m_seconds+=orig.m_seconds;
    if(m_seconds>60) {
        m_minutes+=(m_seconds/60);
        m_seconds = m_seconds%60;
    }
    m_minutes+=orig.m_minutes;
    if(m_minutes>60) {
        m_hours+=(m_minutes/60);
        m_minutes = m_minutes%60;
    }
    return MyTime(m_hours,m_minutes,m_seconds);
}
bool MyTime::operator==(const MyTime &ref) {
    return m_hours == ref.m_hours && m_minutes == ref.m_minutes && m_seconds == ref.m_seconds;
}
bool MyTime::operator<(const MyTime &ref) {
    if( m_hours < ref.m_hours)
        return true;
    else if(m_hours > ref.m_hours)
        return false;
    else if(m_minutes < ref.m_minutes)
        return true;
    else if(m_minutes > ref.m_minutes)
        return false;
    else if(m_seconds < ref.m_seconds)
        return true;
}
bool MyTime::operator>(const MyTime &ref) {
    if( m_hours > ref.m_hours)
        return true;
    else if(m_hours < ref.m_hours)
        return false;
    else if(m_minutes > ref.m_minutes)
        return true;
    else if(m_minutes < ref.m_minutes)
        return false;
    else if(m_seconds > ref.m_seconds)
        return true;
}
void MyTime::display () {
    std::cout << "Time is: " << m_hours <<":" <<m_minutes << ":" <<m_seconds<< "\n";
}
//Complex
Complex::Complex() :
    m_real(0), m_imag(0) {

}
Complex::Complex(int rl, int ig) :
    m_real(rl), m_imag(ig) {

}
Complex::Complex(int rl):
    m_real(rl),m_imag(0) {

}

Complex Complex::operator+(const Complex &ref) {
    int treal = m_real + ref.m_real;
    int timg = m_imag + ref.m_imag;
    return Complex(treal,timg);
}

Complex Complex::operator-(const Complex &ref) {
    int treal = m_real - ref.m_real;
    int timg = m_imag - ref.m_imag;
    return Complex(treal,timg);
}

Complex Complex::operator*(const Complex &ref) {
    int real = (m_real*ref.m_real) - (m_imag*ref.m_imag);
    int imag = (m_real*ref.m_imag)+(m_imag*ref.m_real);
    return Complex(real, imag);
}

Complex Complex::operator++() {
    ++m_real;
    ++m_imag;
    return Complex(m_real,m_imag);
}
Complex Complex::operator++(int d) {
    Complex orig(*this);
    ++m_real;
    ++m_imag;
    return orig;
}
bool Complex::operator==(const Complex &ref) {
    if((ref.m_real==m_real)&&(ref.m_imag==m_imag)) {
        return 1;
    } else {
        return 0;
    }
}

void Complex::display() {
    cout<<m_real<<endl;
    cout<<m_imag<<endl;
}
//End of Complex
/*
int main() {
    //Distance objects and Constructors, Function Usage
    Distance t1(10,5);
    Distance t2(12,25);
    Distance t3;
    t3 = t1 + t2;//t3=t1.operator(t2)
    t3.display();
    t3 = t1 - t2;
    t3.display();
    t3=t3+7;
    t3.display();
    t3=t3-4;
    t3.display();
    ++t3;
    t3.display();
    ++t3+2;
    t3.display();
    //Mytime objects and constructors, functions
    MyTime s1(2,20,10);
    MyTime s2(3,40,15);
    MyTime s3;
    s3=s1+s2;
    s3.display();
    MyTime s4;
    s4=s1-s2;
    s4.display();
    return 0;
}
*/
