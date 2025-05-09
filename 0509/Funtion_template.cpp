#include <iostream>
#include <string.h>

using namespace std;
template <typename T>
class Add{
    private :
        T data1;
        T data2;
    public:
    Add(): data1(0), data2(0){};//생성자 정의
    Add(T _data1, T _data2) : data1(_data1), data2(_data2){};
    T calculate(){
        return data1 + data2;
    }
};
template <typename T1, typename T2>
T1 func(T1 d1, T2 d2){
    return 0;
}
//후문 특성화란 typename과 int를 둘 다 쓰는 경우를 말한다 


// int data_sum(int data1, int data2){
//     return data1 + data2;
// }

// int data_sum(double data1, double data2){
//     return data1 + data2;
// }
//과거 사용하던 방식식
template <typename T>
T data_sum(T data1, T data2){
    return data1 + data2;
}

template <>
const char* data_sum(const char* data1, const char* data2){
    return 0;
}

int main(){
    cout<< data_sum<int>(1, 2) << endl;
    cout<< data_sum<double>(1.0, 2.0) << endl;//형추정과정 생략 방법 -> 묵시에서 명시로 변경경
    // cout<< data_sum("1", "2") << endl;-- 스트링을 묵시로 변경 불가능 오류
    cout<< data_sum<const char*>("1", "2") << endl;

    Add <int>add();
    Add <double>add2();
    //오버로딩 된 상태 
    return 0;
}
