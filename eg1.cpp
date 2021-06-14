#include<iostream>
using namespace std;
int fun(int &x)
{
return x;
}
int main()
{
int x=10;
cout << fun(x)<<endl;
return 0;
}
