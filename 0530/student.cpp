#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

class student{
    public:
        student(): name(""), id (0), avg(0.0){};//생성자 초기화
        student(const string& n, int i): name(n), id (i), avg(0.0){};
        void print();
        bool operator<(const student& other){
            //어느게 먼저 올라갈것인가 
            return id < other.id;
        }
        void addScores(double kor, double eng, double math);
        double getAvg();
        double avg;
        void  printlast();
        string name;//class 밖에서 함수를 선언해 접근이 불가능함 public으로 옮긴이유
    private:
        int id;
        map<string, int> score;
        ;//평균점수
};
void student :: print(){
    cout << id << " "<< name << " "<< avg << endl;
}


bool compareMyNmae(const student& a, const student& b){
    return a.name < b.name;
}
bool compareMyavg(const student& a, const student& b){
    return a.avg < b.avg;
}
double student ::  getAvg(){
    return avg;
}
void student :: addScores(double kor, double eng, double math){
    avg = (kor + eng + math )/3;
}
void  student :: printlast(){
    cout << id << " "<< name << " "<< avg << endl;
}


int main(){

    
    vector<student> studentList;
    studentList.push_back(student("박길동", 4));
    studentList.push_back(student("이승기", 2));
    studentList.push_back(student("백청기", 3));

    studentList[0].addScores(100, 100, 100);
    studentList[1].addScores(60, 40, 80);
    studentList[2].addScores(90, 90, 90);

    sort(studentList.begin(), studentList.end(), compareMyavg);
    
    for(auto s : studentList) s.print();
    
    studentList.back().print();
    

    
    cout << endl;
//연산자 오버로딩?
// 학생 정보 출력(id, 이름, 평균 점수)
//학생 정보를 평균점수 순으로 내림차순해서 출력
//평균 점수가 가장 높은 학생 찾기
    return 0;
}