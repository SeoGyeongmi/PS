#include <iostream>
#include <set>
#include <string>
using namespace std;
 
int main(){
    set<string> s1;
    set<string> s2;
    int N,M;
    cin >> N >> M;
    
    string t;
    for(int i=0; i<N; i++){
        cin >> t;
        s1.insert(t);
    }
    set<string>::iterator iter;
    for(int i=0; i<M; i++){
        cin >> t;
        if(s1.find(t)!=s1.end()){ // 또는 if(s1.count(t))
            s2.insert(t);
        }
    }
    
    cout << s2.size() << endl;
    for(auto iter=s2.begin(); iter!=s2.end(); iter++){
        cout << *iter << endl;
    }
    return 0;
}
/*
map은 원소를 <key,value>쌍으로 저장한다. -> map<int,string>
- map 정의하기 : map<int, string> m;
- map 사용법 :
    1. insert : m.insert({1, "hello"}); 또는 m.insert(make_pair(2, "world")); 또는 map[1]="hello"
    2. size확인 : m.size()
    3. iterator 사용 : for(iter = m.begin(); iter!=temp.end(); iter++){
                        cout << iter->first << "," << iter->second << endl; 
                      }
*/