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
    virtual void take_order(){cout << "주문 받습니다" <<endl;}
    virtual void make_coffee(){cout << "커피를 만듭니다" <<endl;}
    virtual void serve_coffee(){cout << "커피 서빙" <<endl;}

};

class Friend : public all_coffee_shop{
    //직원수가 랜덤
    int elmpoy  = random_number;
    void make_coffee() override{cout << elmpoy <<"명 의 직원이 주문 받겠습니다" <<endl;}
};

class Instar : public all_coffee_shop{
    //인스타 감성 커피점은 본계정, 이벤트계정을 가지고 있습니다. 
    //계정은 동적할당 
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
    cout << "커피점 번호를 입력하세요 {1. 커피 프렌차이즈, 2. 인스타 감성 커피점 3. 무인커피점} : ";
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