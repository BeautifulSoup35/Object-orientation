#include <iostream>
#include <random>
#include <string>

using namespace std;

int randomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister 엔진
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

void play(int min = 1, int max = 100) {
    int target = randomNumber(min, max);
    int guess;
    int attempts = 0;

    cout<< min << " ," << max << endl;

    while (true) {
        cout << "숫자 : ";
        cin >> guess;
        attempts++;
        if (guess < target) {
            cout << "more big" << endl;
        } else if (guess > target) {
            cout << "more small" << endl;
        } else {
            cout << "총 횟수: " << attempts << "번" << endl;
            break;
        }
    }
}

int main() {
    while (true) {
        play(); // 기본: 1~100 난수

        cout << "다시 플레이하시겠습니까? (y/n): ";
        string line;
        cin >>line;
        if (line != "y" && line != "Y") {
            cout << "게임을 종료합니다." << endl;
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
