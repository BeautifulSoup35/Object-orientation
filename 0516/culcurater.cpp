#include <iostream>
#include <string>

using namespace std;    


// ����ڷκ��� �Է¹��� �� �Ǽ��� ������(+, -, *, /, %)�� ó���ϴ� ���⸦ ���弼��.
// ���������� 0���� ������ ��� ���� ó���ϼ���.
// bool, auto, ���� ������, switch ���� �ݵ�� Ȱ���ϼ���.

int main(){
    int a, b =0;
    auto num = '*';
    char chather;
    cout << "���� a�� b�� �Է����ּ���: ";
    cin >> a, b;
    cin >> chather ;
    cout << "�����Ͻ� ��ȣ�� �Է����ּ���: ";
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
    cout <<a % b<<endl;//float�϶� b���� ���� 
        break;
        
    default:
        break;
    }
    return 0;
}