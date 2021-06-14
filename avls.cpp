#include<iostream>
#include "avl2.h"
using namespace std;
int main()
{
	AVL<char> A;
	int i=1,j;
	char x,a,d;
	while(i==1)
	{
		cout<<"*********AVL TREE**********";
		cout<<"\n1.INSERT A NODE\n2.DISPLAY AVL TREE\n3.SIBLINGS OF PARENT OF GIVEN NODE";
		cout<<"\n4.VALUE AND ADDRESS OF NODE WHOSE GRANDCHILDREN IS LEAF NODE\n5.EXIT";
		cout<<"\nYOUR CHOICE IS...";
		cin>>j;
		if(j==1)
		{
			cout<<"Enter a character to insert: ";
			cin>>a;
			A.insert(a);
		}
		else if(j==2)
		A.display();
		else if(j==3)
		{
			cout<<"Enter the search key to find and display siblings of the parent: ";
			cin>>a;
		    cout<<"The sibling of parent of the key in the tree is: "<<"\n";
		    A.printGivenLevel(A.root,A.getLevelUtil(A.root,a,1)-1);
		    cout<<"\n";
		}
		else if(j==4)
		{
			cout<<"The value and address of node which have grandchildren as leaf node are: ";
			A.addvalofnode(A.root);
		}
		else if(j==5)
		{
			cout<<"EXIT....";
			exit(0);
		}
		cout<<"Would You Like To Continue.....0/1";
		cin>>i;
	}
}