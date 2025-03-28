#include <iostream>
#include <string>
#include <cstdlib>  // rand(), srand() 함수를 사용하기 위한 헤더
#include <ctime> // time() 함수를 사용하기 위한 헤더
using namespace std;

/*
부터 100 사이의 임의의 숫자를 생성하고, 사용자가 그 숫자를 맞출 때까지 "더 큰 수입니다" 또는 "더 작은 수입니다"라는 힌트를 제공하는 게임을 작성하세요.

시도 횟수도 함께 출력하세요.

 

<실행 예시>

1부터 100 사이의 숫자를 맞춰보세요!
숫자를 입력하세요: 50
더 작은 수입니다.
숫자를 입력하세요: 19
정답입니다! 6번 만에 맞추셨습니다.

*/


using namespace std;

int main() {
    int user_input =0;
    int count =0;

    // 난수 발생기 초기화 (프로그램이 실행될 때마다 다른 난수를 생성하기 위함)
    srand(time(0));
    
    // 1부터 100 사이의 임의의 숫자 생성
    int secretNumber = rand() % 100 + 1;

    cout << "1부터 100 사이의 숫자를 맞춰보세요!" <<endl;
    
    while(true){
        cout <<"숫자를 입력하세요 :";
        cin >> user_input;
        count++;

        if(user_input > secretNumber) {
            cout << "더 작은 수입니다." <<endl; 
            continue;
        }
        else if (user_input < secretNumber) {
            cout << "더 큰 수입니다." <<endl; 
            continue;
        }
        else{
            cout << "정답입니다"<< count<<"만에 맞추셨습니다." <<endl;
            break;
        }
        
    }
    

   return 0;

}

