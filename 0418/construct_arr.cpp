#include<iostream>
#include<string>
using namespace std;
int cnt = 0;

class A{
    private:
        int data;
        int data1;
        int data2;
        int *p ;
    public:
        A();
        A(int _data);
        A(int _data, int _data1);
        A(const A &ref);
        ~A();
        void printInfo();
};
class AA : public A{
    public:
        AA(){
            cout << "aa부름"<<endl;
           
        };
};
A ::A() : data(100), data1(100), data2(100){
    // data = 100;
    // data1 = 100;
    // data2 = 100;
    cout << "생성자 생성"<<endl;
    p = new int [100];//반드시 free해야하는 동적할당당
    cout <<data<<" "<<data1<<" "<<data2<<endl;
}
A ::A(int _data) : A(){
    A();
    data = _data;

}
A ::A(int _data, int _data1) : A(_data){
    data1 = _data1;
}

A :: A(const A &ref){
    data = ref.data;
    data1 = ref.data1;
    data2 = ref.data2;
    // p = ref.p
    p = new int[100];
    for(int i =0; i , 100; i++){
        p[i] = ref.p[i];
    }
}
A :: ~A(){
    if(p != nullptr){
        delete[]p;
        p = nullptr;
    }
}

void A:: printInfo(){
    cout <<data<<" "<<data1<<" "<<data2<<endl;

}

int main(){                                 
    A a; 
    A b = a;



    return 0;
}