#include <bits/stdc++.h>
using namespace std;

char status[] = "WTL";

int max_value(float a[], float &profit) {
    int pos = 0;
    float val = 0;
    for (int i = 0; i < 3; ++i) {
        if (a[i] > val) {
            pos = i;
            val = a[i];
        }
    }
    profit *= val;
    return pos;
}

int main() {
    float a[3][3];
    memset(a, 0, sizeof(a));
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    float profit = 1;
    for (int i = 0; i < 3; ++i) {
        int pos = max_value(a[i], profit);
        cout << status[pos] << " ";
    }
    printf("%.2f", (profit*0.65-1) * 2);
    return 0;
}