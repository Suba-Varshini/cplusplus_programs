#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;


struct avl_node

{

    string data;

    struct avl_node *left;

    struct avl_node *right;

}*root;


class avlTree

{

    public:

        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, string );
        avl_node* findMax(avl_node * );
        avl_node* findMin(avl_node *);
        void preorder(avl_node *);
        void findParent1(avl_node* , string ,string );
        void findParent2(avl_node* , string ,string );
        avlTree()
        {

            root = NULL;

        }

};

int main()

{

    int choice;
    string item,sk,p1,p2;

    avlTree avl;

    while (1)

    {

        cout<<"\n---------------------"<<endl;

        cout<<"AVL Tree Implementation"<<endl;

        cout<<"\n---------------------"<<endl;

        cout<<"1.Insert Element into the tree"<<endl;

        cout<<"2.PreOrder traversal"<<endl;

        cout<<"3.Search key "<<endl;

        cout<<"4.Same level children"<<endl;

        cout<<"5.Exit"<<endl;

        cout<<"Enter your Choice: ";

        cin>>choice;

        switch(choice)

        {

        case 1:

            cout<<"Enter value to be inserted: ";

            cin>>item;

            root = avl.insert(root, item);

            break;

        case 2:

            cout<<"Preorder Traversal:"<<endl;

            avl.preorder(root);

            cout<<endl;

            break;

        case 3:

            cout<<"enter the search key :";
            cin>>sk;
            avl.findParent1(root,sk,root->data);
            avl.findParent2(root,sk,root->data);
            break;

        case 4:

            break;

        case 5:

            exit(1);    

            break;

        default:

            cout<<"Wrong Choice"<<endl;

        }

    }

    return 0;

}

int avlTree::height(avl_node *temp)

{

    int h = 0;

    if (temp != NULL)

    {

        int l_height = height (temp->left);

        int r_height = height (temp->right);

        int max_height = max (l_height, r_height);

        h = max_height + 1;

    }

    return h;

}

int avlTree::diff(avl_node *temp)

{

    int l_height = height (temp->left);

    int r_height = height (temp->right);

    int b_factor= l_height - r_height;

    return b_factor;

}


avl_node *avlTree::rr_rotation(avl_node *parent)

{

    avl_node *temp;

    temp = parent->right;

    parent->right = temp->left;

    temp->left = parent;

    return temp;

}


avl_node *avlTree::ll_rotation(avl_node *parent)

{

    avl_node *temp;

    temp = parent->left;

    parent->left = temp->right;

    temp->right = parent;

    return temp;

}


avl_node *avlTree::lr_rotation(avl_node *parent)

{

    avl_node *temp;

    temp = parent->left;

    parent->left = rr_rotation (temp);

    return ll_rotation (parent);

}


avl_node *avlTree::rl_rotation(avl_node *parent)

{

    avl_node *temp;

    temp = parent->right;

    parent->right = ll_rotation (temp);

    return rr_rotation (parent);

}



avl_node *avlTree::balance(avl_node *temp)

{

    int bal_factor = diff (temp);

    if (bal_factor > 1)

    {

        if (diff (temp->left) > 0)

            temp = ll_rotation (temp);

        else

            temp = lr_rotation (temp);

    }

    else if (bal_factor < -1)

    {

        if (diff (temp->right) > 0)

            temp = rl_rotation (temp);

        else

            temp = rr_rotation (temp);

    }

    return temp;

}


avl_node *avlTree::insert(avl_node *root, string value)

{

    if (root == NULL)

    {

        root = new avl_node;

        root->data = value;

        root->left = NULL;

        root->right = NULL;

        return root;

    }

    else if (value < root->data)

    {

        root->left = insert(root->left, value);

        root = balance (root);

    }

    else if (value >= root->data)

    {

        root->right = insert(root->right, value);

        root = balance (root);

    }

    return root;

}

void avlTree::preorder(avl_node *tree)

{

    if (tree == NULL)

        return;

    cout<<tree->data<<"  ";

    preorder (tree->left);

    preorder (tree->right);

 
}
avl_node *avlTree::findMin(avl_node* t)
        {
            if(t == NULL)
                return NULL;
            else if(t->left == NULL)
                return t;
            else
                return findMin(t->left);
        }
    
avl_node *avlTree:: findMax(avl_node* t)
        {
            if(t == NULL)
                return NULL;
            else if(t->right == NULL)
                return t;
            else
                return findMax(t->right);
        }
 
void avlTree::findParent1(avl_node* node, string val,string parent)
{
    if (node == NULL)
        cout<<"no sibling"<<endl;

    if (node->data == val) 
	{
        cout<<"sibling is "<<parent;
    }
    else 
	{
        findParent1(node->right, val, node->data); 
    }
}

void avlTree::findParent2(avl_node* node, string val,string parent)
{
    if (node == NULL)
    {
        cout<<"no sibling"<<endl;
        break;
    }

    if (node->data == val) 
	{
        cout<<"sibling is "<<parent;
    }
    else 
	{
    	findParent2(node->left, val, node->data);   
    }
}
