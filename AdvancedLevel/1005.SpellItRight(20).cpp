#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int sum = 0;
    char c;
    while (cin >> c) {
        sum += c - '0';
    }
    string ans = to_string(sum);
    string digit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << digit[ans[i]-'0'];
        if (i != ans.size()-1) {
            cout << " ";
        }
    }
    return 0;
}