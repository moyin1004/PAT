#include <bits/stdc++.h>
using namespace std;

const int N = 1001*2;
using CallBack = function<void(float[], int, float)>;

void readPoly(float a[], const CallBack &op) {
    int k;
    cin >> k;
    int ex = 0;
    float co = 0;
    for (int i = 0; i < k; ++i) {
        cin >> ex >> co;
        op(a, ex, co);
    }
}

void mul(float ans[], float a[], int ex, float co) {
    for (int j = 0; ex + j < N; ++j) {
        ans[ex+j] += co * a[j];
    }
}

void write(float a[], int ex, float co) {
    a[ex] = co;
}

int main() {
    float a[N], ans[N];
    memset(a, 0, sizeof(a));
    memset(ans, 0, sizeof(ans));
    readPoly(a, bind(write, placeholders::_1, placeholders::_2, placeholders::_3));
    readPoly(a, bind(mul, ans, placeholders::_1, placeholders::_2, placeholders::_3));

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (ans[i]) ++count;
    }
    cout << count;
    for (int i = N-1; i >= 0; --i) {
        if (ans[i]) {
            cout << " ";
            printf("%d %.1f", i, ans[i]);
        }
    }
    return 0;
}