#include<iostream>
#include<cstdlib>
#include<math.h>
#include "avls.h"
using namespace std;
template<class T>
AVL<T>::AVL()
{ 
root = NULL; 
}

template<class T>
void AVL<T>::insert(const T &x)
{
insert1(x, root);
}

template<class T>
void AVL<T>::display()
{
print(root);
}

template<class T>
int AVL<T>::height (node *&t)
{
return (t==NULL? -1:t->height);
}

template<class T> 
int AVL<T>::max(int lhs,int rhs)const
{
return lhs>rhs?lhs:rhs;
}

template<class T>
void AVL<T>::print(node *t)const
{
    if( t != NULL )
    {
    	cout<<t->element<<endl;
        print(t->left);
        print(t->right);
	}
}

template<class T>
void AVL<T>::insert1( const T & x, node * & t )                
{
    if( t == NULL )
        t = new node( x, NULL, NULL,0 );                  
    else if( x < t->element )
    {
        insert1( x, t->left );
        if( height( t->left ) - height( t->right ) == 2 )
            if( x < t->left->element )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
    }
    else if( t->element < x )                                            
    {
        insert1( x, t->right );                                             
        if( height( t->right ) - height( t->left ) == 2 )            
            if( t->right->element < x )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
    }
    else; 
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

template<class T>
void AVL<T>::rotateWithLeftChild( node * & k2 )
{
    node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

template<class T>
void AVL<T>::rotateWithRightChild( node * & k1 )
{
    node *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;
    k1 = k2;
}

template<class T>
void AVL<T>::doubleWithLeftChild( node * & k3 )
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
} 

template<class T>
void AVL<T>::doubleWithRightChild( node * & k1 )
{
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
}

template<class T>
struct AVL<T>::node* AVL<T>::findMax( node *t ) const
{
    if( t != NULL )
        while( t->right != NULL )
        {    
		    t = t->right; 
		}
    return t;
}

template<class T>
struct AVL<T>::node* AVL<T>::findMin( node *t ) const
{
	if( t != NULL )
        while( t->left != NULL )
            t = t->left;
    return t;
}

template<class T>
struct AVL<T>::node* AVL<T>::search(struct node* root, T key)
{
    if (root == NULL || root->element == key)
       return root;
    if (root->element < key)
       return search(root->right, key);
    return search(root->left, key);
}

template <class T>
void AVL<T>::balance(node*& t)
{
	if(t==NULL)
	  return;
	if(height(t->left) - height(t->right) >=2 )
	{
		if(height(t->left->left) >= height(t->left->right) )
		rotateWithLeftChild(t);
		else
		doubleWithLeftChild(t);
	}
	else if(height(t->right) - height(t->left) >=2 )
	{
		if(height(t->right->left) >= height(t->right->right) )
		doubleWithRightChild(t);
		else
		rotateWithRightChild(t);
	}
	t->height=max(height(t->left),height(t->right)) + 1;
}

template<class T>
int AVL<T>::getLevelUtil(node *t,int data, int level)
{
    if (t == NULL)
        return 0;
    if (t->element == data)
        return level;
    int downlevel = getLevelUtil(t->left,data, level+1);
    if (downlevel != 0)
        return downlevel;
    downlevel = getLevelUtil(t->right,data, level+1);
    return downlevel;
}


template<class T>
void AVL<T>::printGivenLevel(node*t , int level)
{
    if (t == NULL)
        return;
    if (level== 1)
        cout<<t->element<<" ";
    else if (level > 1)
    {
        printGivenLevel(t->left, level-1);
        printGivenLevel(t->right, level-1);
    }
}

template<class T>
void AVL<T>::addvalofnode(node* root)
{
    if (root == NULL)
	return;
    else 
	{
        if (root->left != NULL && root->right != NULL) 
		{
            if (root->left->left != NULL || root->left->right != NULL || root->right->left != NULL || root->right->right != NULL) 
			{
                cout<<root->element<<" "<<root<<endl;
            }
        }
        else if (root->left != NULL) 
		{
		    if (root->left->left != NULL || root->left->right != NULL) 
			{
                cout<<root->element<<" "<<root<<endl;
            }
        }
        else if (root->right != NULL) 
		{
            if (root->right->left != NULL || root->right->right != NULL) 
			{
                cout<<root->element<<" "<<root<<endl;
            }
        }
        addvalofnode(root->left);
        addvalofnode(root->right);
    }
}