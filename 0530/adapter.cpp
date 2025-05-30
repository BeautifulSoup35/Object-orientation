#include <iostream>
# include <stack>

using namespace std;

int main(){
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << myStack.size() <<"개"<< endl;
    cout << myStack.top()<< endl;
    myStack.pop();
    cout << myStack.top()<< endl;

    cout << myStack.size() << "개"<< endl;

    //cout << myStack.front() << "개"<< endl;
    //cout << myStack.back() << "개"<< endl;

    /*
    for(int x : myStack){
        cout << x <<endl;
    } 배열이 아니라 향상된 for문 사용 불가능
        */
    return 0;
}