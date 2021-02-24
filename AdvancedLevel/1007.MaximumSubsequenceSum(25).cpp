#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int k;
    cin >> k;
    vector<int> a(k);
    int max_sum = -1, max_i = 0, max_j = k-1;
    int sum = 0, index = 0;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        sum += a[i];
        if (sum > max_sum) {
            max_sum = sum;
            max_j = i;
            max_i = index;
        }
        else if (sum < 0) {
            index = i + 1;
            sum = 0;
        }
    }
    if (max_sum < 0) max_sum = 0;
    cout << max_sum <<  " " << a[max_i] << " " << a[max_j];
    return 0;
}