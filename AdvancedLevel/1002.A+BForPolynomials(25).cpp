#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

void readPoly(float a[]) {
    int k;
    cin >> k;
    int ex = 0;
    float co = 0;
    for (int i = 0; i < k; ++i) {
        cin >> ex >> co;
        a[ex] += co;
    }
}

int main() {
    float ans[N];
    memset(ans, 0, sizeof(ans));
    readPoly(ans);
    readPoly(ans);
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (ans[i]) ++count;
    }
    cout << count;
    for (int i = N-1; i >=0; --i) {
        if (ans[i]) {
            cout << " ";
            printf("%d %.1f", i, ans[i]);
        }
    }
    return 0;
}