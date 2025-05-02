#include <iostream>
#include <string>
using namespace std;

class A{
    public:
    A(){cout << "A"<<endl;}
     ~A(){cout << "~A"<<endl;}
     
};

class AA:public A{
     AA(){cout << "AA"<<endl;}
     ~AA(){cout << "~AA"<<endl;}

};

class AB:public A{
    AB(){cout << "AB"<<endl;}
    ~AB(){cout << "~AB"<<endl;}
    

};

int main(){

    
    
}