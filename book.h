#include <string>
#include "author.h" 
using namespace std;
class Book {
private:
string name;
Author author; // data member author is an instance of class Author
double price;
int qtyInStock;
public:
Book(string name, Author author, double price, int qtyInStock = 0);
// To recieve an instance of class Author as argument
string getName() const
{return name;};
Author getAuthor(Author a) const
{return a;}; // Returns an instance of the class Author
double getPrice() const
{return price;};
void setPrice(double price)
{ this.price=price;};
int getQtyInStock() const
{return qtyInStock;};
void setQtyInStock(int qtyInStock)
{this.qtyInStock=qtyInStock;};
void print() const
{cout<<name<<" "<<author<<" "<<price<<" "<<qtyInStock<<endl};
string getAuthorName() const
{return name;};
};
