#include<iostream>
#include<string>
using namespace std;

class Student{
    private:    
        string name;//책제목    
        int number;//저자
        double setKorean;
        double setEnglish;
        double setMath;
    public://생성자
        Student(string na, int num);
        void score( double kor, double eng, double math);
        void displayInfo();
        double getAverage();
        string isPassed();
};

Student::Student(string na, int num){
    name = na;
    number = num;
}
    
void Student ::score( double kor, double eng, double math){
    setKorean = kor;
    setEnglish = eng;
    setMath = math;
};
double Student ::getAverage(){
    double aver = (setKorean + setEnglish + setMath);
    return aver / 3;
};

string Student :: isPassed(){
    return getAverage()>= 60? "합격입니다": "불합격입니다";
};
       
void Student :: displayInfo(){
    cout <<"\n이름:"<< name<< endl;
    cout<<"학번:"<< number<< endl;
    cout <<"국어 :"<< setKorean<< endl;
    cout <<"영어 :"<< setEnglish<< endl;
    cout <<"수학 :"<< setMath<< endl;
    cout <<getAverage()<< endl;
    cout <<isPassed()<< endl;
};



int main(){
    Student student1("이수아", 24);
    student1.score(100, 20, 30);
    student1.displayInfo();

    Student student2("권민주", 25);
    student2.score(100, 100, 100);
    student2.displayInfo();

    Student student3("하희정", 0);
    student3.score(20, 30, 60);
    student3.displayInfo();

    return 0;
}