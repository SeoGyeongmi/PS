#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int a0, a1, a2;
    cin >> a0 >> a1 >> a2;

    int max0 = a0, max1 = a1, max2 = a2;
    int min0 = a0, min1 = a1, min2 = a2;

    for (int i = 1; i < N; i++) {
        cin >> a0 >> a1 >> a2;

        int nmax0 = a0 + max(max0, max1);
        int nmax1 = a1 + max({max0, max1, max2});
        int nmax2 = a2 + max(max1, max2);

        int nmin0 = a0 + min(min0, min1);
        int nmin1 = a1 + min({min0, min1, min2});
        int nmin2 = a2 + min(min1, min2);

        max0 = nmax0; max1 = nmax1; max2 = nmax2;
        min0 = nmin0; min1 = nmin1; min2 = nmin2;
    }

    cout << max({max0, max1, max2}) << ' ' << min({min0, min1, min2}) << "\n";
    return 0;
}