#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int cur = 0, total = 0;
    for (int i = 0; i < n; ++i) {
        int floor;
        cin >> floor;
        int num = floor - cur;
        total += num > 0 ? num * 6 : abs(num) * 4;
        total += 5;
        cur = floor;
    }
    cout << total;
    return 0;
}