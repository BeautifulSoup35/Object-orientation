#include <iostream>
using namespace std;

int main(){
   int int_value = 123;
   int *int_pointer_value = &int_value;

   cout << int_value << endl;
   cout << int_pointer_value << endl;//주소
   cout << *int_pointer_value << endl;//주소의 값 || 역참조

   //다중포인터
   //배열
   int arr[3] = {1,2,3 };
   int *arr_pointer = arr;//첫번째 배열 주소 저장
   //arr는 이미 포인터이기에 *arr는 이중 포인터 이다
   //&arr[0] != *arr
   cout << arr[0]<< endl;
   cout << arr[1]<< endl;
   cout << arr[2]<< endl;
//주소 
   cout << &arr[0]<< endl;
   cout << &arr[1]<< endl;
   cout << &arr[2]<< endl;
//포인터로 주소 표현현
   cout << arr_pointer[0] << " / "<< arr_pointer + 0 << " / "<< *(arr_pointer +0)<< endl;//1
   cout << arr_pointer[1]  << " / "<< arr_pointer +1<< " / "<< *(arr_pointer +1)<< endl;//2
   cout << arr_pointer[2]  << " / "<< arr_pointer +2<<  " / "<< *(arr_pointer +2)<< endl;//3




//    return 0;
}
