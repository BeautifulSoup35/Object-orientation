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
        cout << x << endl;// �ߺ� �����Ѵ�
    }

    if(mset.find(1) != mset.end()) {cout << "����" << endl;}//find�� const�� ����
    else
     {cout << "����" << endl;}
    return 0;
}