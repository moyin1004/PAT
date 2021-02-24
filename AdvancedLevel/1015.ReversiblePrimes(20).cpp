#include <bits/stdc++.h>

using namespace std;

int convert(int num, int radix) {
    int ans = 0;
    int d[111];
    int len = 0;
    do {
        d[len++] = num % radix;
        num /= radix;
    } while (num);
    for (int i = 0; i < len; ++i) {
        ans = ans * radix + d[i];
    }
    return ans;
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, d;
    while (cin >> n, n > 0) {
        cin >> d;
        if (!isPrime(n)) cout << "No" << endl;
        else {
            if (isPrime(convert(n, d))) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}