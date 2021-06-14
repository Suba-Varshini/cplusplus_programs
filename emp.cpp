#include<iostream>
#include "emp1.h"
using namespace std;
int main()
{
	parttimeemployee pt;
	fulltimeemployee ft;
	dailywages dw;
	cout<<"***PART TIME EMPLOYEE**\n";
	pt.getdetails();
	cout<<"\n***FULL TIME EMPLOYEE**\n";
	ft.getdetails();
	cout<<"\n***DAILY WAGES EMPLOYEE**\n";
	dw.getdetails();
	cout<<"\n***PART TIME EMPLOYEE DETAIL**";
	pt.printdetails();
	pt.printsalary();
	cout<<"\n\n***FULL TIME EMPLOYEE DETAIL**";
	ft.printdetails();
	ft.printsalary();
	cout<<"\n\n***DAILY WAGES EMPLOYEE DETAIL**";
	dw.printdetails();
	dw.printsalary();
}