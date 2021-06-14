#include <iostream>
using namespace std;
class car
{
      private:
                int liters ;
                double consumption ;
      public:
             car()
             {
                  liters=40;
                  consumption=0.1;
                  cout<<"Car created "<<endl;
                  cout<<"Liters = "<<liters<<endl;
                  cout<<"Consumption = "<<consumption<<endl;
             }
             car(int l,double c)
             {
                  liters=l;
                  consumption=c;
                  cout<<"Car created "<<endl;
                  cout<<"Liters = "<<liters<<endl;
                  cout<<"Consumption = "<<consumption<<endl;
             }
             ~car()
             {
                   cout<<"destructed"<<endl;
             }
             void maxdist();
};
