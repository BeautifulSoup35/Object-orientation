#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

class student{
    public:
        student(): name(""), id (0), avg(0.0){};//������ �ʱ�ȭ
        student(const string& n, int i): name(n), id (i), avg(0.0){};
        void print();
        bool operator<(const student& other){
            //����� ���� �ö󰥰��ΰ� 
            return id < other.id;
        }
        void addScores(double kor, double eng, double math);
        double getAvg();
        double avg;
        void  printlast();
        string name;//class �ۿ��� �Լ��� ������ ������ �Ұ����� public���� �ű�����
    private:
        int id;
        map<string, int> score;
        ;//�������
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
    studentList.push_back(student("�ڱ浿", 4));
    studentList.push_back(student("�̽±�", 2));
    studentList.push_back(student("��û��", 3));

    studentList[0].addScores(100, 100, 100);
    studentList[1].addScores(60, 40, 80);
    studentList[2].addScores(90, 90, 90);

    sort(studentList.begin(), studentList.end(), compareMyavg);
    
    for(auto s : studentList) s.print();
    
    studentList.back().print();
    

    
    cout << endl;
//������ �����ε�?
// �л� ���� ���(id, �̸�, ��� ����)
//�л� ������ ������� ������ ���������ؼ� ���
//��� ������ ���� ���� �л� ã��
    return 0;
}