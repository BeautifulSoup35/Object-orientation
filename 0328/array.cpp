#include <iostream>
#include <string>
#include <cstdlib>  // rand(), srand() �Լ��� ����ϱ� ���� ���
#include <ctime> // time() �Լ��� ����ϱ� ���� ���
using namespace std;

/*
���� 100 ������ ������ ���ڸ� �����ϰ�, ����ڰ� �� ���ڸ� ���� ������ "�� ū ���Դϴ�" �Ǵ� "�� ���� ���Դϴ�"��� ��Ʈ�� �����ϴ� ������ �ۼ��ϼ���.

�õ� Ƚ���� �Բ� ����ϼ���.

 

<���� ����>

1���� 100 ������ ���ڸ� ���纸����!
���ڸ� �Է��ϼ���: 50
�� ���� ���Դϴ�.
���ڸ� �Է��ϼ���: 19
�����Դϴ�! 6�� ���� ���߼̽��ϴ�.

*/


using namespace std;

int main() {
    int user_input =0;
    int count =0;

    // ���� �߻��� �ʱ�ȭ (���α׷��� ����� ������ �ٸ� ������ �����ϱ� ����)
    srand(time(0));
    
    // 1���� 100 ������ ������ ���� ����
    int secretNumber = rand() % 100 + 1;

    cout << "1���� 100 ������ ���ڸ� ���纸����!" <<endl;
    
    while(true){
        cout <<"���ڸ� �Է��ϼ��� :";
        cin >> user_input;
        count++;

        if(user_input > secretNumber) {
            cout << "�� ���� ���Դϴ�." <<endl; 
            continue;
        }
        else if (user_input < secretNumber) {
            cout << "�� ū ���Դϴ�." <<endl; 
            continue;
        }
        else{
            cout << "�����Դϴ�"<< count<<"���� ���߼̽��ϴ�." <<endl;
            break;
        }
        
    }
    

   return 0;

}

