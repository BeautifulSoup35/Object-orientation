#include<iostream>
#include<string>
using namespace std;
int cnt = 0;

class A{
    private:
        //int cnt = 0;//������� �ν��Ͻ��� ī��Ʈ ���� -> ������ �ȵǤ��� ���簡 �Ǵ� ��Ȳ
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
            cout << "aa�θ�"<<endl;
           
        };
};
A ::A() : data(100), data1(100), data2(100){
    // data = 100;
    // data1 = 100;
    // data2 = 100;
    cout << "������ ����"<<endl;
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
    j.printInfo();//500 350032848 536-> ����� ������ �ƴ� ���ο� �޸� �Ҵ���� �˼�������
    AA a;//�θ��� AŬ���� ������ AAŬ���� �ҷ�����
    a.printInfo();
    return 0;
}

// PS C:\Users\user\Desktop\04\chap7> cd "c:\Users\user\Desktop\04\chap7\" ; if ($?) { g++ construct.cpp -o construct } ; if ($?) { .\construct }
// ������ ����
// aa�θ�
// PS C:\Users\user\Desktop\04\chap7>