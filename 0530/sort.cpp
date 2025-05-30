#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec = {3, 4, 5, 1, 2};
    for(auto x : vec){
        cout << x << " ";
    }
    cout << endl;

    sort(vec.begin() , vec. end(), greater<int>());//내림차순
    for(auto x : vec){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}