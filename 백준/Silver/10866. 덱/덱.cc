#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main(){

    deque<int> d;
    int n;
    string order;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> order;
        if(order=="push_front"){
            int num;
            cin >> num;
            d.push_front(num);
        }
        else if(order=="push_back"){
            int num;
            cin >> num;
            d.push_back(num);
        }
         else if(order=="pop_front"){
            if(d.empty()){
                printf("-1\n");
                continue;
            }
            int num = d.front();
            d.pop_front();
            printf("%d\n", num);
        }
         else if(order=="pop_back"){
            if(d.empty()){
                printf("-1\n");
                continue;
            }
            int num = d.back();
            d.pop_back();
            printf("%d\n", num);
        }
         else if(order=="size"){
            printf("%d\n", d.size());
        }
         else if(order=="empty"){
            printf("%d\n", d.empty());
        }
         else if(order=="front"){
            if(d.empty()){
                printf("-1\n");
                continue;
            }
            printf("%d\n", d.front());
        }
         else if(order=="back"){
            if(d.empty()){
                printf("-1\n");
                continue;
            }
            printf("%d\n", d.back());
        }
    }
    return 0;
}