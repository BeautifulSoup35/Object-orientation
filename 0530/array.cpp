#include <iostream>
# include <array>

using namespace std;

int main(){
    array<int, 5> arr;
    arr = {1, 2, 3,4, 5};
    
    for (int i =0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }

    array<int , 5> :: iterator it;
    for (it = arr.begin(); it != arr.end(); it++){
        cout <<*it<< endl;
    }
    // arr[7];// 벡터와 다르게 사이즈를 벗어나면 오류가 난다.

    *(it + 1) = 10;
    return 0;
}