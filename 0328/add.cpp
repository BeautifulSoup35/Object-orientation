#include <iostream>
#include <string>

using namespace std;
int add(int _x, int _y);
void swap (int num1, int num2);
void swap_pointer (int *num1, int *num2);

int main(){
    int num1 =1;
    int num2 =2;
    cout << add(10, 20)<< endl;//error: expected unqualified-id before numeric constant
    swap(num1, num2);
    swap_pointer(&num1, &num2);
    return 0;
}

int add(int _x, int _y){
    return _x + _y;
}

void swap (int num1, int num2){
    int temp = num1;
    num1 =num2;
    num2 = temp;

}

void swap_pointer (int *num1, int *num2){
    int temp = *num1;
    *num1 =*num2;
    *num2 = temp;

}