#include <iostream>
#include <string>
using namespace std;

#include <random>

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(2, 10);

    int random_number = dis(rd);

class all_coffee_shop{
    public:
    virtual void take_order(){cout << "�ֹ� �޽��ϴ�" <<endl;}
    virtual void make_coffee(){cout << "Ŀ�Ǹ� ����ϴ�" <<endl;}
    virtual void serve_coffee(){cout << "Ŀ�� ����" <<endl;}

};

class Friend : public all_coffee_shop{
    //�������� ����
    int elmpoy  = random_number;
    void make_coffee() override{cout << elmpoy <<"�� �� ������ �ֹ� �ްڽ��ϴ�" <<endl;}
};

class Instar : public all_coffee_shop{
    //�ν�Ÿ ���� Ŀ������ ������, �̺�Ʈ������ ������ �ֽ��ϴ�. 
    //������ �����Ҵ� 
    char *real = new char[100];
    char *event = new char[100];
    

};

class Nonperson : public all_coffee_shop{

};
class Person{};
class account{};

int main(){
    int num = 0;
    all_coffee_shop *num_ = nullptr;
    cout << "Ŀ���� ��ȣ�� �Է��ϼ��� {1. Ŀ�� ����������, 2. �ν�Ÿ ���� Ŀ���� 3. ����Ŀ����} : ";
    cin >> num;
    
    switch (num)
    {
    case 1:
        num_ = new Friend;
        break;
    case 2:
        num_ = new Instar;
        break;
    case 3:
        num_ = new Nonperson;
        break;
    default:
        break;
    }
    num_->make_coffee();
    num_->serve_coffee();
    num_->take_order();

    delete num_;
    
    return 0;
}