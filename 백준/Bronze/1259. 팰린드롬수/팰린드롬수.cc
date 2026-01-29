#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        if (s == "0") break;

        bool ok = true;
        for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) { ok = false; break; }
        }
        cout << (ok ? "yes\n" : "no\n");
    }
    return 0;
}