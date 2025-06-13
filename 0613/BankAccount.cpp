#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    // 인스턴스 멤버
    int accountNumber;
    string ownerName;
    double balance;
    vector<BankAccount*> start = allAccounts;
    
    // TODO: 정적 멤버 변수 선언
    static int nextAccountNumber;    // 다음 계좌번호
    static int totalAccounts;        // 전체 계좌 수
    static double totalBalance;      // 전체 잔액
    static vector<BankAccount*> allAccounts;  // 모든 계좌 포인터

    
public:
    BankAccount(string name, double initialDeposit) {
        // TODO: 구현
        // - accountNumber는 nextAccountNumber 사용
        // - 정적 변수들 업데이트
        // - allAccounts에 this 추가
        cout<<"전체 계좌 수 "<< totalAccounts << endl;
        cout<<"전체 잔액 "<< totalBalance << endl;
        cout << "계좌 개설: " << accountNumber << " (" << ownerName << ")" << endl;

        this->allAccounts;
       
    }
    
    ~BankAccount() {
        // TODO: 구현
        // - 정적 변수들 업데이트
        // - allAccounts에서 this 제거
        delete[];
        cout << "계좌 폐쇄: " << accountNumber << endl;
    }
    
    void deposit(double amount) {
        // TODO: 구현
        // - balance와 totalBalance 업데이트
        balance = amout;
        totalBalance += balance;
    }
    
    bool withdraw(double amount) {
        // TODO: 구현
        // - 잔액 확인 후 출금
        // - balance와 totalBalance 업데이트
        if(totalAccounts - amount < 0 ){
            cout<< "출금 불가 잔액부족" << endl;
            return 0;
        }
        balance = amount;
        cout << "출금 금액 : "<< balance << endl;
        cout<< "총 금액 :" << totalBalance<< endl;
        return true;
    }
    
    // TODO: 정적 멤버 함수들 구현
    static void printBankStatus() {
        allAccounts = start;
        int i =0;
        while(allAccounts != NULL){
            cout << allAccounts + i << endl;
        }
        // 은행 전체 상태 출력

    }
    
    static BankAccount* findAccount(int accNumber) {
        // 계좌번호로 계좌 찾기
        allAccounts = start;
        int i =0;
        while(allAccounts != NULL){
            if(allAccounts + i == accNumber){
                return *( allAccounts + i);
            }
            else i++;
        }
        cout << "해당계좌는 없는걸로 나옵니다"<< endl;
        return nullptr;
    }
    
    static double getAverageBalance() {
        // 평균 잔액 계산
        return totalBalance / totalAccounts;
    }
    
    void printInfo() {
        cout << "계좌: " << accountNumber 
             << ", 소유자: " << ownerName 
             << ", 잔액: " << fixed << setprecision(2) << balance << endl;
    }
};

//정적변수 정의
    // 다음 계좌번호
      // 전체 잔액


// TODO: 정적 멤버 변수 정의 (클래스 외부)
int BankAccount::nextAccountNumber = 1001;
int BankAccount :: totalAccounts = 0 ;        // 전체 계좌 수
double BankAccount :: totalBalance =0.0 ;
// ... 나머지 정적 변수들도 정의

int main() {
    cout << "=== 은행 시스템 시작 ===" << endl;
    BankAccount::printBankStatus();
    
    // 계좌 생성
    BankAccount* acc1 = new BankAccount("김철수", 10000);
    BankAccount* acc2 = new BankAccount("이영희", 20000);
    BankAccount* acc3 = new BankAccount("박민수", 15000);
    
    cout << "\n=== 거래 처리 ===" << endl;
    acc1->deposit(5000);
    acc2->withdraw(3000);
    
    cout << "\n=== 현재 은행 상태 ===" << endl;
    BankAccount::printBankStatus();
    cout << "평균 잔액: " << BankAccount::getAverageBalance() << endl;
    
    cout << "\n=== 계좌 검색 ===" << endl;
    BankAccount* found = BankAccount::findAccount(1002);
    if (found) {
        found->printInfo();
    }
    
    cout << "\n=== 계좌 폐쇄 ===" << endl;
    delete acc2;
    
    cout << "\n=== 최종 은행 상태 ===" << endl;
    BankAccount::printBankStatus();
    
    delete acc1;
    delete acc3;
    
    return 0;
}

/* 예상 출력:
=== 은행 시스템 시작 ===
전체 계좌 수: 0
전체 잔액: 0.00

계좌 개설: 1001 (김철수)
계좌 개설: 1002 (이영희)
계좌 개설: 1003 (박민수)

=== 거래 처리 ===
입금: 5000.00
출금: 3000.00

=== 현재 은행 상태 ===
전체 계좌 수: 3
전체 잔액: 47000.00
평균 잔액: 15666.67

=== 계좌 검색 ===
계좌: 1002, 소유자: 이영희, 잔액: 17000.00

=== 계좌 폐쇄 ===
계좌 폐쇄: 1002

=== 최종 은행 상태 ===
전체 계좌 수: 2
전체 잔액: 30000.00




=== 은행 시스템 시작 ===
계좌 개설: -1501161568 ()
계좌 개설: -1501141472 ()
계좌 개설: -1501141472 ()

=== 거래 처리 ===

=== 현재 은행 상태 ===
평균 잔액: 0

=== 계좌 검색 ===

=== 계좌 폐쇄 ===
계좌 폐쇄: -1501141472

=== 최종 은행 상태 ===
계좌 폐쇄: -1501161568
계좌 폐쇄: -1501141472
*/