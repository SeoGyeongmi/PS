#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int bit = 0;  // 비트마스킹으로 집합 표현
    int M;
    cin >> M;
    
    string op;
    int x;
    
    for (int i = 0; i < M; i++) {
        cin >> op;
        
        if (op == "add") {
            cin >> x;
            bit |= (1 << x);
        }
        else if (op == "remove") {
            cin >> x;
            bit &= ~(1 << x);
        }
        else if (op == "check") {
            cin >> x;
            if (bit & (1 << x)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        else if (op == "toggle") {
            cin >> x;
            bit ^= (1 << x);
        }
        else if (op == "all") {
            bit = (1 << 21) - 1;  // 1~20 모두 포함
        }
        else if (op == "empty") {
            bit = 0;
        }
    }
    
    return 0;
}
