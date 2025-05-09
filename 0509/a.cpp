#include <iostream>
#include <string.h>

using namespace std;

class A{
    private:
        int data;
        friend class B;// Bclass에서 pirvate에 접근 가능 -> like 예외
    public:
        // A(int data) { data = data;};// 로 할 수 있는 방법
        A(int data) { this ->data = data;};
        A* operator+(const A& a){//"+ "중요 없으면 오류남
            int value =  this -> data + a. data; 
            return new A(value);
        };

};

class B{
    private:
        A a;
    public:
        void print(){a.data;};
};

int main(){
    A a1(10), a2(20);
    //cout << a1 <<endl;
    cout <<a1 + a2<< endl;
}