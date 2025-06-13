#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    // �ν��Ͻ� ���
    int accountNumber;
    string ownerName;
    double balance;
    vector<BankAccount*> start = allAccounts;
    
    // TODO: ���� ��� ���� ����
    static int nextAccountNumber;    // ���� ���¹�ȣ
    static int totalAccounts;        // ��ü ���� ��
    static double totalBalance;      // ��ü �ܾ�
    static vector<BankAccount*> allAccounts;  // ��� ���� ������

    
public:
    BankAccount(string name, double initialDeposit) {
        // TODO: ����
        // - accountNumber�� nextAccountNumber ���
        // - ���� ������ ������Ʈ
        // - allAccounts�� this �߰�
        cout<<"��ü ���� �� "<< totalAccounts << endl;
        cout<<"��ü �ܾ� "<< totalBalance << endl;
        cout << "���� ����: " << accountNumber << " (" << ownerName << ")" << endl;

        this->allAccounts;
       
    }
    
    ~BankAccount() {
        // TODO: ����
        // - ���� ������ ������Ʈ
        // - allAccounts���� this ����
        delete[];
        cout << "���� ���: " << accountNumber << endl;
    }
    
    void deposit(double amount) {
        // TODO: ����
        // - balance�� totalBalance ������Ʈ
        balance = amout;
        totalBalance += balance;
    }
    
    bool withdraw(double amount) {
        // TODO: ����
        // - �ܾ� Ȯ�� �� ���
        // - balance�� totalBalance ������Ʈ
        if(totalAccounts - amount < 0 ){
            cout<< "��� �Ұ� �ܾ׺���" << endl;
            return 0;
        }
        balance = amount;
        cout << "��� �ݾ� : "<< balance << endl;
        cout<< "�� �ݾ� :" << totalBalance<< endl;
        return true;
    }
    
    // TODO: ���� ��� �Լ��� ����
    static void printBankStatus() {
        allAccounts = start;
        int i =0;
        while(allAccounts != NULL){
            cout << allAccounts + i << endl;
        }
        // ���� ��ü ���� ���

    }
    
    static BankAccount* findAccount(int accNumber) {
        // ���¹�ȣ�� ���� ã��
        allAccounts = start;
        int i =0;
        while(allAccounts != NULL){
            if(allAccounts + i == accNumber){
                return *( allAccounts + i);
            }
            else i++;
        }
        cout << "�ش���´� ���°ɷ� ���ɴϴ�"<< endl;
        return nullptr;
    }
    
    static double getAverageBalance() {
        // ��� �ܾ� ���
        return totalBalance / totalAccounts;
    }
    
    void printInfo() {
        cout << "����: " << accountNumber 
             << ", ������: " << ownerName 
             << ", �ܾ�: " << fixed << setprecision(2) << balance << endl;
    }
};

//�������� ����
    // ���� ���¹�ȣ
      // ��ü �ܾ�


// TODO: ���� ��� ���� ���� (Ŭ���� �ܺ�)
int BankAccount::nextAccountNumber = 1001;
int BankAccount :: totalAccounts = 0 ;        // ��ü ���� ��
double BankAccount :: totalBalance =0.0 ;
// ... ������ ���� �����鵵 ����

int main() {
    cout << "=== ���� �ý��� ���� ===" << endl;
    BankAccount::printBankStatus();
    
    // ���� ����
    BankAccount* acc1 = new BankAccount("��ö��", 10000);
    BankAccount* acc2 = new BankAccount("�̿���", 20000);
    BankAccount* acc3 = new BankAccount("�ڹμ�", 15000);
    
    cout << "\n=== �ŷ� ó�� ===" << endl;
    acc1->deposit(5000);
    acc2->withdraw(3000);
    
    cout << "\n=== ���� ���� ���� ===" << endl;
    BankAccount::printBankStatus();
    cout << "��� �ܾ�: " << BankAccount::getAverageBalance() << endl;
    
    cout << "\n=== ���� �˻� ===" << endl;
    BankAccount* found = BankAccount::findAccount(1002);
    if (found) {
        found->printInfo();
    }
    
    cout << "\n=== ���� ��� ===" << endl;
    delete acc2;
    
    cout << "\n=== ���� ���� ���� ===" << endl;
    BankAccount::printBankStatus();
    
    delete acc1;
    delete acc3;
    
    return 0;
}

/* ���� ���:
=== ���� �ý��� ���� ===
��ü ���� ��: 0
��ü �ܾ�: 0.00

���� ����: 1001 (��ö��)
���� ����: 1002 (�̿���)
���� ����: 1003 (�ڹμ�)

=== �ŷ� ó�� ===
�Ա�: 5000.00
���: 3000.00

=== ���� ���� ���� ===
��ü ���� ��: 3
��ü �ܾ�: 47000.00
��� �ܾ�: 15666.67

=== ���� �˻� ===
����: 1002, ������: �̿���, �ܾ�: 17000.00

=== ���� ��� ===
���� ���: 1002

=== ���� ���� ���� ===
��ü ���� ��: 2
��ü �ܾ�: 30000.00




=== ���� �ý��� ���� ===
���� ����: -1501161568 ()
���� ����: -1501141472 ()
���� ����: -1501141472 ()

=== �ŷ� ó�� ===

=== ���� ���� ���� ===
��� �ܾ�: 0

=== ���� �˻� ===

=== ���� ��� ===
���� ���: -1501141472

=== ���� ���� ���� ===
���� ���: -1501161568
���� ���: -1501141472
*/