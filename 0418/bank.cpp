#include<iostream>
#include<string>
using namespace std;

class bank{
  private:
    int safe;  
  public:
    bank();// �̸��� ���� �ؾ��� ������
    void use_counter(int _in, int _out);
};

void bank :: use_counter(int _in, int _out){
    safe += _in;
    safe -= _out;

    cout << "�Ա�: "<< _in<<endl;
    cout << "���: "<< _out<<endl;
    cout << "�ݰ�: "<< safe<<endl;
}

bank :: bank(){
    safe = 0;

    cout <<"���� �ݰ�: "<<safe << endl;
    cout<<endl;
}

int main(){
    bank my_bank;//��ü ���� �ν��Ͻ� �Ҵ�

    my_bank.use_counter(100, 20);
    
    return 0;
}