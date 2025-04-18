#include<iostream>
#include<string>
using namespace std;
int cnt = 0;

class A{
    private:
        //int cnt = 0;//만들어진 인스턴스수 카운트 변수 -> 공유가 안되ㅏ고 복사가 되는 상황
        int data;
        int data1;
        int data2;
    public:
        A();
        A(int _data);
        A(int _data, int _data1);
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
    cout <<data<<" "<<data1<<" "<<data2<<endl;
}
A ::A(int _data) : A(){
    A();
    data = _data;

}
A ::A(int _data, int _data1) : A(_data){
    data1 = _data1;
}

void A:: printInfo(){
    cout <<data<<" "<<data1<<" "<<data2<<endl;

}

int main(){
    A j(500);
    j.printInfo();//500 350032848 536-> 결과값 수정이 아닌 새로운 메모리 할당됨을 알수있음음
    AA a;//부모인 A클래스 다음에 AA클래스 불러짐짐
    a.printInfo();
    return 0;
}

// PS C:\Users\user\Desktop\04\chap7> cd "c:\Users\user\Desktop\04\chap7\" ; if ($?) { g++ construct.cpp -o construct } ; if ($?) { .\construct }
// 생성자 생성
// aa부름
// PS C:\Users\user\Desktop\04\chap7>