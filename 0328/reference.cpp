#include <iostream>
using namespace std;

void addOne(int &r){
    r++;
}

int main(){
    int a = 10;
    int *p = &a;
    const int *pp = &a;
    
    //int r = a; r++; 아래의 함수로 대체체
    addOne(a);
    cout << a << endl;//11 
/*  레퍼런스란  
    메모리 주소가 아닌 원본 변수를 참조한다 원본을 바꿔야할경우 || 원본의 카피가 너무 많아져 원본에 접촉해야하는 경우
    원본에 붙는 별명개념이다 즉 기존 변수없이 래퍼런스 선언하면 오류
    int &r = a; || void addOne(int &r) : 매개변수를 래퍼런스로 사용가능
*/
    a =20;
    p = nullptr;
    p = nullptr;


    return 0;
}