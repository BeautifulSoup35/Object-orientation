#include <iostream>
# include <map>

using namespace std;
//���� ���� ������������
int main(){
    map<string , int> myMap;

    myMap.insert(make_pair("ȫ�浿", 10));
    myMap.insert(make_pair("��浿", 20));
    myMap.insert(make_pair("�̱浿", 30));

    //map<string, int> :: iterator it = myMap.find("ȫ�浿");
    auto it = myMap.find("ȫ�浿");
    if(it != myMap.end())
    { 
        cout << it->first << " "<< it->second <<endl;;
    }
    myMap.erase("ȫ�浿");

    int cnt = myMap.count("ȫ�浿");

    //if(cnt > 1)
    {
            auto range = myMap.equal_range("ȫ�浿");
            if(range.first != myMap.end())
            {
                for(auto it = range.first; it != range.second; it++){
                    cout << it-> second << " ";
            }
        }
    }

    
    for(auto x: myMap)
    { 
        //cout << x <<endl;
    }
    return 0;
}