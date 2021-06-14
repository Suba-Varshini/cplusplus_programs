#include<iostream>
using namespace std;
class weight
{
int kg;
int g;
public:
weight()
{
        kg=0;
        g=0;
} 
void getdata ()
{
     cout<<"enter kg"<<endl;
     cin>>kg;
     cout<<"enter g"<<endl;
     cin>>g;
     if(g>1000)
     {int i=g/1000;
     kg=kg+i;
     g=g-(i*1000);}
}
void putdata ()
{
     cout<<"The weight in kg  : "<<kg<<endl;
     cout<<"The weight in g   : "<<g<<endl;
     cout<<"total weight is "<<kg<<"."<<g<<endl;
}
void sum_weight (weight w1,weight w2)
{
     cout<<"total : "<<w1.kg+w2.kg<<"."<<w1.g+w2.g<<endl;
}      
weight(const weight &w)
{kg=w.kg;
g=w.g;
}
};
int main()
{
    weight w1;
    w1.getdata();
    w1.putdata();
    weight w2;
    w2.getdata();
    w2.putdata();
    weight w3(w1);
    w3.putdata();    
    return 0;
}
