#include <string>
using namespace std;
class Author {
private:
string name;
string email;
char gender; 
public:
Author(string name, string email, char gender)
{this.name=name;
this.email=email;
this.gender=gender; }
string getName() const
{return name;};
string getEmail() const
{return email;};
void setEmail(string email)
{this.email=email;};
char getGender() const
{return gender;};
void print() const
{cout<<name<<"("<<gender<<")"<<" at "<<email<<endl;};
};