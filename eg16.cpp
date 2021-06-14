#include<iostream>
using namespace std;
class Point {
public:
Point() { cout << "Normal Constructor calledn"; }
Point(const Point &t) { cout << "Copy constructor calledn"; }
};
int main()
{
Point *t1, *t2;
t1 = new Point();
t2 = new Point(*t1);
Point t3 = *t1;
Point t4;
t4 = t3;
return 0;
}
