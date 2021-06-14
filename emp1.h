 #include<iostream>
#include "emp.h"
using namespace std;
void employee::getdetails()
{
	cout<<"Enter employee name: ";
	cin>>name;
	cout<<"Enter the basic amount: ";
	cin>>basic;
	cout<<"Enter the DA: ";
	cin>>da;
	cout<<"Enter the income tax: ";
	cin>>it;
}
void employee::printdetails()
{
	cout<<"\nEmployee name: "<<name;
	cout<<"\nBasic amount: "<<basic;
	cout<<"\nDA: "<<da;
	cout<<"\nIncome tax: "<<it;
	cout<<"\nSalary: ";
}
void parttimeemployee::printsalary()
{
	cout<<basic+da-it;
}
void fulltimeemployee::printsalary()
{
	cout<<basic+da-it;
}
void dailywages::printsalary()
{
	cout<<basic+da-it;
}
 