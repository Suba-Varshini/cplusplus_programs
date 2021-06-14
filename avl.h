#include<iostream>
using namespace std;
template<class T>
class avl
{
      private:
              struct node
              {
                     T element;
                     node *left;
                     node *right;
                     int height;
                     node(const T &theelement,node *p,node *n,int h):element(theelement),left(p),right(n),height(h)
                     {
                     }

              };
              node *root;
      public:
            avl()
             {
                  root = NULL;
             }
             void insert(const T &x)
             {
                  insert(x,root);
             }
            /* void remove(const T &x)
             {
                  remove(x,root);
             }
             node * findmin(node *t)const
              {
                 if(t==NULL)
                            return NULL;
                 if(t->left==NULL)
                                  return t;
                 return  findmin(t->left);
             }*/
             int height(node *t)const
             {
                 return (t==NULL)? -1 : t->height;
             }
             void insert(const T &x,node *&t)    // *& reference to a pointer
             {
                  if(t==NULL)
                             t=new node(x,NULL,NULL,-1);
                  else if(x<t->element)
                  {
                       insert(x,t->left);
                       if(height(t->left)-height(t->right)==2)
                       {
                       if(x< t->left->element)
                                             singlerotatewithleft(t);
                       else
                                             doublerotatewithleft(t);
                       }
                  }
                  else if(t->element<x)
                  {
                       insert(x,t->right);
                       if(height(t->right)-height(t->left)==2)
                       {
                       if(t->right->element<x)
                       
                                              singlerotatewithright(t);
                       
                       else
                       
                                              doublerotatewithright(t);
                       }
                  }
                  else
                  ;   // not inserting duplicates
                  t->height=max(height(t->left),height(t->right))+1;  
             }
             void singlerotatewithleft(node *&k2)
             {
                  node *k1=k2->left;
                  k2->left=k1->right;
                  k1->right=k2;
                  k2->height=max(height(k2->left),height(k2->right))+1;
                  k1->height=max(height(k1->left),k2->height)+1;
                  k2=k1;
             }
             void singlerotatewithright(node *&k2)
             {
                  node *k1=k2->right;
                  k2->right=k1->left;
                  k1->left=k2;
                  k2->height=max(height(k2->right),height(k2->left))+1;
                  k1->height=max(height(k1->right),k2->height)+1;
                  k2=k1;
             }
             void doublerotatewithleft(node *&k3)
             {
                  singlerotatewithright(k3->left);
                  singlerotatewithleft(k3);
             }
             void doublerotatewithright(node *&k3)
             {
                  singlerotatewithleft(k3->right);
                  singlerotatewithright(k3);
             }
             int max(int a,int b)
             {
                 if(a>=b)
                         return a;
                 else 
                         return b;
                 
             }
             void display()
             {
                  cout<<"\n";
                  print(root);
             }
             void print(node *&t)
             {
                if(t!=NULL)
     			{
     			cout<<t->element<<endl;
                print(t->left);
                print(t->right);
               // cout<<endl<<t->element;
     			}
             }
             
             void remove( const T &x )
             {
       			 remove( x, root );
       			
   			 }
   			 
   			 void remove( const T &x, node *& t )
   			 {
        			if( t == NULL )
            		return;   // Item not found; do nothing
        
        			if( x < t->element )
            			remove( x, t->left );
        			else if( t->element < x )
            			remove( x, t->right );
        			else if( t->left != NULL && t->right != NULL ) // Two children
       				 {
            			t->element = findMin( t->right )->element;
            			remove( t->element, t->right );
        			}
        			else
       				 {
                            node *oldNode = t;
            			t = ( t->left != NULL ) ? t->left : t->right;
            			delete oldNode;
       				 }
        
        		balance( t );
    		}
    		
    		void balance( node *& t )
    			{
        			if( t == NULL )
            		return;
        
        			if( height( t->left ) - height( t->right ) ==2 )
            			if( height( t->left->left ) >= height( t->left->right ) )
                			singlerotatewithleft( t );
           				 else
               				 doublerotatewithleft( t );
        			else
        				if( height( t->right ) - height( t->left ) ==2 )
            				if( height( t->right->right ) >= height( t->right->left ) )
                				singlerotatewithright( t );
            				else
                				doublerotatewithright( t );
                
   	     			t->height = max( height( t->left ), height( t->right ) ) + 1;
    			}
    
    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    node * findMin( node *t ) const
    {
        if( t == NULL )
            return NULL;
        if( t->left == NULL )
            return t;
        return findMin( t->left );
    }

   			 
}; 