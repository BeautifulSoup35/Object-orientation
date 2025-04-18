#include<iostream>
#include<string>
using namespace std;

class bank{
  private:
    int safe;  
  public:
    bank();// 이름이 동일 해야함 생성자
    void use_counter(int _in, int _out);
};

void bank :: use_counter(int _in, int _out){
    safe += _in;
    safe -= _out;

    cout << "입금: "<< _in<<endl;
    cout << "출금: "<< _out<<endl;
    cout << "금고: "<< safe<<endl;
}

bank :: bank(){
    safe = 0;

    cout <<"최초 금고: "<<safe << endl;
    cout<<endl;
}

int main(){
    bank my_bank;//객체 선언 인스턴스 할당

    my_bank.use_counter(100, 20);
    
    return 0;
}