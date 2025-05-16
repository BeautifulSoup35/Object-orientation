#include <iostream>
#include <string>

using namespace std;    


// 사용자로부터 입력받은 두 실수와 연산자(+, -, *, /, %)를 처리하는 계산기를 만드세요.
// 나눗셈에서 0으로 나누는 경우 예외 처리하세요.
// bool, auto, 조건 연산자, switch 문을 반드시 활용하세요.

int main(){
    int a, b =0;
    auto num = '*';
    char chather;
    cout << "숫자 a와 b를 입력해주세요: ";
    cin >> a, b;
    cin >> chather ;
    cout << "연산하실 기호를 입력해주세요: ";
    cin >> num;

    switch (num)
    {
    case '+':
        cout << a + b <<endl;
        break;
    case '-':
    cout << a - b<<endl;
        break;
    case '*':
        cout <<a * b<<endl;
        break;
    case '/':
        if(b != 0) cout <<a / b<<endl;
        break;
    case '%':
    cout <<a % b<<endl;//float일때 b에서 에러 
        break;
        
    default:
        break;
    }
    return 0;
}