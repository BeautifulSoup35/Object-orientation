#include <iostream>
# include <vector>

using namespace std;
int main(){
    vector<int> vec;

    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    vector<int> :: iterator it = vec.begin();

    for(int i = 0; i < vec.size(); i ++){
        cout << *(it+i) << endl;
}
    for (it = vec.begin(); it != vec.end(); it++){
        cout << *it << endl;
    }
    for(int i =0; i<5; i++){
        cout << vec[i]<< endl;
    }

    

    return 0 ;
}