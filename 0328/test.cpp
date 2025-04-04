/*
���� ����
�������� �л����� ������ �����ϴ� ���α׷��� �����ؾ� �մϴ�. �� ���α׷��� ���� �л��� ������ �� �л��� ���� ������ ������ ������ �� �־�� �մϴ�. Ư�� �����Ϳ� ���� �޸� �Ҵ��� Ȱ���Ͽ� �޸𸮸� ȿ�������� �����ؾ� �մϴ�.

�䱸����
����ü ����
Student ����ü�� �����Ͽ� ���� ������ �����ؾ� ��:


�⺻ ���



�����Ϳ� �޸� ����
���� �л� ������ ������ �迭�� �������� �Ҵ�
�� �л����� ���� ������ ������ �迭�� �������� �Ҵ�
���α׷� ���� �� ��� ���� �Ҵ� �޸𸮸� ������ ����
�Լ� ����
���� ����� �����ϴ� �Լ����� �����ؾ� ��:
�л� ����ü �ʱ�ȭ (���� �迭 ���� �Ҵ�)
�л� ���� �Է�
��� ���� ���
���� ����
�л� ���� ���
���� �Ҵ� �޸� ����
�Է� ����
ù ��: ������ �л� ���� ���� �� �Է�
�� �л���:
�̸� �Է�
�й� �Է�
�� ���� ���� �Է� (0-100 ���� �Ǽ�)
��� ����
�� �л���:
�̸��� �й�
�� ���� ���� ���
��� ���� (�Ҽ��� ��° �ڸ�����)
����
�޸� �ּ� ����
���� ����
������ 0���� 100 ������ ���� ���
�л� ���� ���� ���� 1 �̻��� ������ ���
��� ���� �Ҵ�� �޸𸮴� ���α׷� ���� ���� �ݵ�� �����Ǿ�� ��
��� ����
===== �л� ���� ���� =====

----- ȫ�浿 (�й�: 20230001) -----
���� ����: 85, 90, 95
��� ����: 90.00
����: A
----- ��ö�� (�й�: 20230002) -----
���� ����: 75, 80, 85
��� ����: 80.00
����: B
*/
#include <iostream>
#include <string>

using namespace std;

//�Լ�����
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
    //����ڷκ��� ������ �л� ���� ���� ���� �Է¹���

    int student_num = 0;
    int odject_num = 0;

    cout << "�л����� �Է��ϼ��� : ";
    cin >> student_num ;
    cout << "������ ���� �Է��ϼ��� : ";
    cin >> odject_num;
    
    num_error(student_num, odject_num);
   
    double *avg_score = new double[student_num];
    Student *student = new Student[student_num];
   
    //��� �л��� ����(�̸�, �й�, �� ���� ����, ��� ����, ����)�� ���
    cout <<"===== �л� ���� ���� =====\n"<<endl;
    for(int i =0; i < student_num; i++){
        information(student, i, odject_num, avg_score);//�л� ���� �Է·�
        print_student(student, i, odject_num, avg_score);
    }

    //����
    free(student,student_num, avg_score);
    
return 0;
}

//��� ������ ���� ���� �ο� (A: 90�̻�, B: 80�̻�, C: 70�̻�, D: 60�̻�, F: 60�̸�)
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
    //�л� ���� ���� ���� 1 �̻��� ������ ���
    if (student_num < 1 || odject_num <1 )  cout<<"1 �̻����� ������ּ���";exit(1);
}

void information(Student* student, int i, int odject_num, double * agv){
    double total_score =0;
    student[i].score = new double[odject_num];
    cout << "�л��̸� : ";
    cin >> student[i].name;
    cout << "�л��й� : ";
    cin >> student[i].code;

    cout << "---���ݺ��� ���� ���� �Է��� �����մϴ�-- "<< endl;
    
    for(int j = 0; j < odject_num; j++){
        cout << j+1 <<" �� ���� ���� : ";
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
        cout <<"-----"<<student[i].name<<"------(�й�: "<<student[i].code<<" )"<<endl;
        cout <<"�� ������ ����: ";
        for(int j =0; j < odject_num; j++){
            cout <<student[i].score[j]<< " ";
        }cout <<endl;
        cout <<"���� ��� ����: "<< avg_score[i]<<endl;
        cout <<"�̹� ���: "<<score_level(*(avg_score+i))<<endl;
    }
