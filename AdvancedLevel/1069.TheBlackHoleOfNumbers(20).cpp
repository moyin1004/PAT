#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int ans = 0;
    while (1) {
        if (str.size() < 4) {
            str.append(4-str.size(), '0');
        }
        sort(str.begin(), str.end());
        int minn = stoi(str);
        sort(str.begin(), str.end(), greater<int>());
        int maxn = stoi(str);
        ans = maxn - minn;
        cout << setfill('0')
             << setw(4) << maxn << " - "
             << setw(4) << minn << " = " 
             << setw(4) << ans << endl;
        if (ans == 0 || ans == 6174) {
            break;
        }
        str = to_string(ans);
    }
    return 0;
}