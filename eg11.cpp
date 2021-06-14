#include<iostream>
using namespace std;
class Test
{
private:
int x;
int y;
public:
Test () 
{ x = 0;
  y = 0; }
void setX(int a) 
{ x = a;}
void setY(int b) 
{ y = b; }
void print() { cout << "x = " << x << " y = " << y << endl; }
};
int main()
{
Test obj1;
obj1.setX(10);
obj1.setY(20);
obj1.print();
return 0;
}
