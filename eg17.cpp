#include<iostream>
#include<stdlib.h>
using namespace std;
class DEPOSIT
{
long int principal;
int time;
float rate;
float totalamount;
public:
DEPOSIT()
{principal=10000;rate=10;time=5;} // #1

DEPOSIT(long int p, int t, float r)
{principal=p;time=t;rate=r;} // #2

DEPOSIT(long int p, int t) 
{principal=p;time=t;rate=10;}// #3

DEPOSIT(long int p,float r,int t) 
{principal=p;rate=r;time=2;}// #4

DEPOSIT(const DEPOSIT &d)
{principal=d.principal;
rate=d.rate;
time=d.time;
}// #5

~DEPOSIT(){};
void calculateamount()
{ totalamount=(principal*time*rate)/100;}
void display()
{cout<<"Amount : "<<totalamount<<endl;}
};
int main()
{
    DEPOSIT d;
    d.display();
    DEPOSIT d1(10000,2,3.5);
    d1.display();
    DEPOSIT d2(20000,3);
    d2.display();
    DEPOSIT d3(20000,5.6,2);
    d3.display();
    DEPOSIT d4(d1);
    d4.display();
    return 0;
}
