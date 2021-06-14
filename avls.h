using namespace std; 
template<class T>
class AVL
{
struct node
{
T element;
node *left;
node *right;
int height;
node( const T& ele, node* lt, node* rt, int h = 0 ){element=ele; left=lt;right=rt;height=h; } 
};
public:
node *root;
AVL();
void insert(const T&);
void insert1(const T&,node*&);
void display();
int height(node *&);
int max(int,int)const;
void print(node*)const;
void rotateWithLeftChild( node * &  );
void rotateWithRightChild( node * &  );
void doubleWithLeftChild( node * &  );
void doubleWithRightChild( node * & );
struct node* findMax( node *) const;
struct node* findMin( node *) const;
struct node* search(struct node*, T);
void balance( node *&);
void printGivenLevel(node*,int);
int getLevelUtil(node *t,int data, int level);
void addvalofnode(node*);
};