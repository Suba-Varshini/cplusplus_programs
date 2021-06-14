#include<iostream>
using namespace std;
#include "avl.h"

int main()
{
    avl<char>a;
    int i;
    a.insert('a');
    a.insert(2);
    a.insert(1);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(16);
    a.insert(15);
    a.insert(14);
    a.insert(13);
    a.insert(12);
    a.insert(11);
    a.insert(10);
    a.display();
    a.remove(4);
    cout<<endl ;
    a.display();
    return 0;
}
    