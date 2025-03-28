#include <iostream>
#include <string>

using namespace std;


struct Person{

    string name;
    int age;

};
//세미콜론 필수
int main(){

    Person me;
    me.name = "홍길동";
    me.age = 20;

    cout << me.name << endl;
    cout << me.age << endl;

    Person *avatar = &me;
    avatar->name = "김길동";
    avatar->age = 21;


    cout << avatar->name << endl;
    cout << avatar->age << endl;
    return 0;
}