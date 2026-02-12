#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a(8);
    for (int i = 0; i < 8; i++) cin >> a[i];

    bool asc = true, desc = true;

    for (int i = 0; i < 8; i++) {
        if (a[i] != i + 1) asc = false;        // 1 2 3 4 5 6 7 8
        if (a[i] != 8 - i) desc = false;       // 8 7 6 5 4 3 2 1
    }

    if (asc) cout << "ascending\n";
    else if (desc) cout << "descending\n";
    else cout << "mixed\n";

    return 0;
}
