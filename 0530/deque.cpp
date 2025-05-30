#include <iostream>
# include <deque>

using namespace std;

int main(){
    deque<double> myList;

    myList.push_back(0);
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    cout << "\n" <<endl; 

    //cout << myList[0] <<endl;
    for(auto a :myList){
        cout << a <<endl; 
        
       }
       cout << "\n" <<endl; 
    //향상된 for문
    for(const int& value:myList){
        cout << value <<endl;
        
    }
    return 0;
}