#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = a+b;
    // note sum == 0
    if (sum == 0) {
        putchar('0');
        return 0;
    }
    bool sign = sum < 0;
    sum = abs(sum);
    int count = 0;
    stack<char> ans;
    while (sum) {
        if (count == 3) {
            ans.push(',');
            count = 0;
        }
        char cur = sum % 10 + '0';
        ans.push(cur);
        sum /= 10;
        ++count;
    }
    if (sign) putchar('-');
    while (!ans.empty()) {
        putchar(ans.top());
        ans.pop();
    }
    return 0;
}