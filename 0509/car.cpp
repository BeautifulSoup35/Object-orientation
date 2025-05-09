#include <iostream>
#include <string.h>

using namespace std;

class Engin;

class Car{
    private:
        string brand;
    public:
        Car(string b) : brand(b){
            Engin e("전기", 150);
        };
        class Engin{
    private:
        string type;
        int power;
    public:
        Engin(string t, int p): type(t), power(p){};
    };
};


void printInfo(){
    cout <<0 <<endl;
}
 //하나의 변수를 가진 경우와 충돌해 주석 처리 했다
// void printInfo(int data){
//     cout <<1 <<endl;
// } 

void printInfo(int data1, int data2 = 0){
    cout << data1 + data2 <<endl;
} 


int main(){
    Car :: Engin e("전기", 150);

    printInfo();
    printInfo(2);
    printInfo(2, 3);
    return 0;
}