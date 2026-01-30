#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<long long> top(n), bottom(n);
        for (int i = 0; i < n; i++) cin >> top[i];
        for (int i = 0; i < n; i++) cin >> bottom[i];

        // dpNone: i번째 열까지 봤을 때 i열에서 아무것도 안 뜯음
        // dpTop : i번째 열에서 위 스티커 뜯음
        // dpBot : i번째 열에서 아래 스티커 뜯음
        long long dpNone = 0, dpTop = 0, dpBot = 0;

        for (int i = 0; i < n; i++) {
            long long prevNone = dpNone, prevTop = dpTop, prevBot = dpBot;

            dpNone = max({prevNone, prevTop, prevBot});
            dpTop  = max(prevNone, prevBot) + top[i];
            dpBot  = max(prevNone, prevTop) + bottom[i];
        }

        cout << max({dpNone, dpTop, dpBot}) << "\n";
    }
    return 0;
}
