#include<iostream>
#include<string>
using namespace std;

class Student{
    private:    
        string name;//å����    
        int number;//����
        double setKorean;
        double setEnglish;
        double setMath;
    public://������
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
    return getAverage()>= 60? "�հ��Դϴ�": "���հ��Դϴ�";
};
       
void Student :: displayInfo(){
    cout <<"\n�̸�:"<< name<< endl;
    cout<<"�й�:"<< number<< endl;
    cout <<"���� :"<< setKorean<< endl;
    cout <<"���� :"<< setEnglish<< endl;
    cout <<"���� :"<< setMath<< endl;
    cout <<getAverage()<< endl;
    cout <<isPassed()<< endl;
};



int main(){
    Student student1("�̼���", 24);
    student1.score(100, 20, 30);
    student1.displayInfo();

    Student student2("�ǹ���", 25);
    student2.score(100, 100, 100);
    student2.displayInfo();

    Student student3("������", 0);
    student3.score(20, 30, 60);
    student3.displayInfo();

    return 0;
}