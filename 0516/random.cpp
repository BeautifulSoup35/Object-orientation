#include <iostream>
#include <random>
#include <string>

using namespace std;

int randomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister ����
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

void play(int min = 1, int max = 100) {
    int target = randomNumber(min, max);
    int guess;
    int attempts = 0;

    cout<< min << " ," << max << endl;

    while (true) {
        cout << "���� : ";
        cin >> guess;
        attempts++;
        if (guess < target) {
            cout << "more big" << endl;
        } else if (guess > target) {
            cout << "more small" << endl;
        } else {
            cout << "�� Ƚ��: " << attempts << "��" << endl;
            break;
        }
    }
}

int main() {
    while (true) {
        play(); // �⺻: 1~100 ����

        cout << "�ٽ� �÷����Ͻðڽ��ϱ�? (y/n): ";
        string line;
        cin >>line;
        if (line != "y" && line != "Y") {
            cout << "������ �����մϴ�." << endl;
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
