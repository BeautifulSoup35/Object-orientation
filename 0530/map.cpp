#include <iostream>
# include <map>

using namespace std;
//¼ø¼­ ¾ø°í ¿À¸§Â÷¼øÀ¸·Î
int main(){
    map<string , int> myMap;

    myMap.insert(make_pair("È«±æµ¿", 10));
    myMap.insert(make_pair("±è±æµ¿", 20));
    myMap.insert(make_pair("ÀÌ±æµ¿", 30));

    //map<string, int> :: iterator it = myMap.find("È«±æµ¿");
    auto it = myMap.find("È«±æµ¿");
    if(it != myMap.end())
    { 
        cout << it->first << " "<< it->second <<endl;;
    }
    myMap.erase("È«±æµ¿");

    int cnt = myMap.count("È«±æµ¿");

    //if(cnt > 1)
    {
            auto range = myMap.equal_range("È«±æµ¿");
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