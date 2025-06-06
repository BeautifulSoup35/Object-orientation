// 사용자로부터 "key=value" 형식의 문자열을 입력받아,
// key와 value를 나눠 출력하고, value가 숫자인지 문자열인지 판별하는 함수를 작성하세요.

// 사용자에게 10개의 정수를 입력받아 배열에 저장하고,
// 해당 배열의 평균, 최댓값, 최솟값, 중앙값을 출력하는 프로그램을 작성하세요.
// 벡터를 이용하여 정렬 후 중앙값 계산을 하며, 반복문과 조건문을 자유롭게 사용하세요.


// Book이라는 클래스를 만들어보세요.
// 멤버: 제목(string), 저자(string), 가격(int)
// 멤버 함수: 정보 출력, 가격 변경 함수

// 메인 함수에서 Book 객체 배열 또는 벡터를 만들고 여러 책 정보를 추가해 출력해보세요.


// MyBuffer 클래스 만들기:
// 내부에 char* buffer와 크기(int size)를 갖고, 생성자에서 메모리를 new로 할당
// 복사 생성자, 복사 대입 연산자, 소멸자를 정의해 깊은 복사를 구현하세요.
// main 함수에서 복사와 대입 연산이 제대로 작동하는지 테스트하세요.


// 사용자에게 정수 개수를 입력받고, 해당 개수만큼 정수를 입력 받아
// 동적으로 메모리를 할당하여 배열처럼 저장하세요.
// 총합과 평균을 출력한 뒤 메모리를 해제하세요.

// Vec2라는 클래스를 만들고 x, y 멤버 변수를 갖게 하세요.
// + 연산자를 오버로딩하여 두 벡터를 더하는 기능을 구현하세요.
// == 연산자도 오버로딩하여 두 벡터가 같은지 비교하세요.


// Animal 클래스를 만들고 speak()라는 가상 함수를 정의하세요.
// Dog와 Cat 클래스가 Animal을 상속받아 speak()를 다르게 구현하도록 하세요.
// Animal 포인터 배열을 통해 다형성을 실습해보세요.


// 사용자로부터 이름과 나이를 입력받아, 다음과 같이 출력하세요:
// "안녕하세요, [이름]님. 당신은 [나이]살입니다."


// 정수형 벡터를 만들고, 사용자로부터 5개의 숫자를 입력받아 벡터에 저장하세요.
// 반복문을 사용하여 모든 값을 출력하고, 합계를 구해서 출력하세요.

// 벡터에 정수를 입력받고, STL의 sort 함수를 사용해 오름차순으로 정렬한 뒤 출력하세요.

// map<string, int>을 사용해 학생 이름과 점수를 저장하고,
// 3명의 정보를 입력받은 후 전체 점수 평균을 구하세요.
// set<string>을 사용해 중복 없이 친구 이름을 입력받고, 저장된 이름을 모두 출력하세요.

// 두 값을 받아 큰 값을 반환하는 템플릿 함수를 작성하세요.
// int, double, string 타입에 대해 호출해보세요.



#include <iostream>
#include <string>

using namespace std;    

int main(){
    //포인터 사용용
    // char *diction = " ";
    // char *key =" ";
    // char *vlaue = "";
    // cout << "key=value 형식의 문자열을 입력해 주세요";
    // cin >> diction;

    // //나누기 함수가 있늬??
    // while(diction != NULL){
    //     if(*diction != '=') {
    //         *key = *diction;
    //         diction++;
    //         key++;
    //     }
    //     else{
    //         *vlaue = *(diction+1); 
    //     } 
    //     cout << key << vlaue << endl;
    // }

    
    //포인터로 받고 배열로 바꿔볼까
    char *diction;
//동적할당 배열 선언
    char arry[50];
    int i = 0;

    cout << "key=value 형식의 문자열을 입력해 주세요";
    //cin >> *diction ;
    cin >> arry;
    //while (diction != NULL){// 계속 돌아감
     //   arry[i] = *diction; 
      //  i++;
    //}
    cout << "==="<< endl;
    i =0;
    while( arry[i] != '='){
        i++;
    }

    int j = 0;
    for(j = 0; j < i; j++) cout << arry[j] << endl;
    cout <<"\n"<<endl;

    while(arry[j] != NULL){
        cout << arry[j+1] << endl;
        j++;
    }


    return 0;
}