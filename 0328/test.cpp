/*
문제 설명
여러분은 학생들의 성적을 관리하는 프로그램을 개발해야 합니다. 이 프로그램은 여러 학생의 정보와 각 학생별 여러 과목의 점수를 관리할 수 있어야 합니다. 특히 포인터와 동적 메모리 할당을 활용하여 메모리를 효율적으로 관리해야 합니다.

요구사항
구조체 정의
Student 구조체를 정의하여 다음 정보를 포함해야 함:


기본 기능



포인터와 메모리 관리
여러 학생 정보를 저장할 배열을 동적으로 할당
각 학생별로 과목 점수를 저장할 배열을 동적으로 할당
프로그램 종료 시 모든 동적 할당 메모리를 적절히 해제
함수 구현
다음 기능을 수행하는 함수들을 구현해야 함:
학생 구조체 초기화 (점수 배열 동적 할당)
학생 점수 입력
평균 점수 계산
학점 결정
학생 정보 출력
동적 할당 메모리 해제
입력 형식
첫 줄: 관리할 학생 수와 과목 수 입력
각 학생별:
이름 입력
학번 입력
각 과목별 점수 입력 (0-100 사이 실수)
출력 형식
각 학생별:
이름과 학번
각 과목 점수 목록
평균 점수 (소수점 둘째 자리까지)
학점
메모리 주소 정보
제약 사항
점수는 0에서 100 사이의 값만 허용
학생 수와 과목 수는 1 이상의 정수만 허용
모든 동적 할당된 메모리는 프로그램 종료 전에 반드시 해제되어야 함
출력 예시
===== 학생 성적 정보 =====

----- 홍길동 (학번: 20230001) -----
과목 점수: 85, 90, 95
평균 점수: 90.00
학점: A
----- 김철수 (학번: 20230002) -----
과목 점수: 75, 80, 85
평균 점수: 80.00
학점: B
*/
#include <iostream>
#include <string>

using namespace std;

//함수선언
char score_level(int score);
void num_error(int student_num, int odject_num);
void free(Student* student, int student_num, double*avg_score);
void information(Student* student, int i, int odject_num, double * agv);
void print_student(Student* student, int i, int odject_num, double* avg_score );

struct Student{
    string name;
    int code;
    double* score;
    int odject_num;

};

int main(){
    //사용자로부터 관리할 학생 수와 과목 수를 입력받음

    int student_num = 0;
    int odject_num = 0;

    cout << "학생수를 입력하세요 : ";
    cin >> student_num ;
    cout << "과목의 수를 입력하세요 : ";
    cin >> odject_num;
    
    num_error(student_num, odject_num);
   
    double *avg_score = new double[student_num];
    Student *student = new Student[student_num];
   
    //모든 학생의 정보(이름, 학번, 각 과목 점수, 평균 점수, 학점)를 출력
    cout <<"===== 학생 성적 정보 =====\n"<<endl;
    for(int i =0; i < student_num; i++){
        information(student, i, odject_num, avg_score);//학생 정보 입력력
        print_student(student, i, odject_num, avg_score);
    }

    //해제
    free(student,student_num, avg_score);
    
return 0;
}

//평균 점수에 따라 학점 부여 (A: 90이상, B: 80이상, C: 70이상, D: 60이상, F: 60미만)
char score_level(int score){
    if(score > 100 || score < 0) return 'X';
    switch (score/10)
    {
    case 10:
    case 9:
        return 'A';
    case 8:return 'B';
    case 7:return 'C';
    case 6:return 'D';
    default: return 'F';
    }
}

void num_error(int student_num, int odject_num){
    //학생 수와 과목 수는 1 이상의 정수만 허용
    if (student_num < 1 || odject_num <1 )  cout<<"1 이상으로 만들어주세요";exit(1);
}

void information(Student* student, int i, int odject_num, double * agv){
    double total_score =0;
    student[i].score = new double[odject_num];
    cout << "학생이름 : ";
    cin >> student[i].name;
    cout << "학생학번 : ";
    cin >> student[i].code;

    cout << "---지금부터 과목 점수 입력을 시작합니다-- "<< endl;
    
    for(int j = 0; j < odject_num; j++){
        cout << j+1 <<" 번 과목 점수 : ";
        cin >> student[i].score[j];
        total_score += student[i].score[j];
    }
    agv[i]= total_score / odject_num;

}

void free(Student* student, int student_num, double*avg_score){
    for (int i = 0; i < student_num; i++) {
        delete[] student[i].score; 
        delete[] avg_score;
    }
    delete[] student;
}

void print_student(Student* student, int i, int odject_num, double* avg_score ){
        cout <<"-----"<<student[i].name<<"------(학번: "<<student[i].code<<" )"<<endl;
        cout <<"각 과목의 점수: ";
        for(int j =0; j < odject_num; j++){
            cout <<student[i].score[j]<< " ";
        }cout <<endl;
        cout <<"과목 평균 점수: "<< avg_score[i]<<endl;
        cout <<"이번 등급: "<<score_level(*(avg_score+i))<<endl;
    }
