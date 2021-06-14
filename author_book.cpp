#include<iostream>
#include<cstring>
using namespace std;
class Author {
private:
string name;
string email;
char gender; 
public:
//Author():
//name(NULL),email(NULL),gender(' '){}
void setAuthor(string n, string e, char g)
{
name=n;
email=e;
gender=g; }
string getName() const
{return name;}
string getEmail() const
{return email;}
void setEmail(string email)
{this->email=email;}
char getGender() const
{return gender;}
void aprint() const
{cout<<name<<"("<<gender<<")"<<" at "<<email<<endl;}
};
class Book {
private:
string bname;// data member author is an instance of class Author
double price;
int qtyInStock;
public:
Author auth;
//Book():
//bname(NULL),price(0),qtyInStock(0){}
Book(string n,double p, int q)
{
bname=n;
price=p;
qtyInStock=q;
}
// To recieve an instance of class Author as argument
string getName() const
{return bname;}
Author getAuthor(Author a) const
{return a;} // Returns an instance of the class Author
double getPrice() const
{return price;}
void setPrice(double price)
{ this->price=price;}
int getQtyInStock() const
{return qtyInStock;}
void setQtyInStock(int qtyInStock)
{this->qtyInStock=qtyInStock;}
void bprint() const
{cout<<bname<<" "<<price<<" "<<qtyInStock<<endl;}
string getAuthorName() const
{return bname;}
};
int main()
{
    char ch='f';
    Book b("Adventure",45.67,7);
    b.auth.setAuthor("suba","gmail",ch);
    b.auth.aprint();
    b.bprint();
    return 0;
}