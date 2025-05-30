#include <iostream>
# include <set>

using namespace std;

int main (){
    set<int> mset;

    mset.insert(0);
    mset.insert(1);
    mset.insert(2);
    mset.insert(3);
    mset.insert(0);

    for(auto x : mset){
        cout << x << endl;// 중복 허용안한다
    }

    if(mset.find(1) != mset.end()) {cout << "존재" << endl;}//find는 const로 구성
    else
     {cout << "없음" << endl;}
    return 0;
}