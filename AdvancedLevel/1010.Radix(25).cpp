#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll convert(const string &num, int radix) {
    ll ans = 0;
    ll product = 1;
    for (auto it = num.crbegin(); it != num.crend(); ++it) {
        ans += (isdigit(*it) ? (*it-'0') : (*it-'a'+10)) * product;
        product *= radix;
    }
    return ans;
}

int compare(ll num, string &s_num) {
    char c = *max_element(s_num.begin(), s_num.end());
    ll low = (isdigit(c) ? c - '0': c - 'a' + 10) + 1;
    ll high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(s_num, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return 0;
}

int main() {
    string N1, N2;
    int tag = 0, radix = 0;
    cin >> N1 >> N2 >> tag >> radix;
    ll ans = 0;
    if (tag == 1) {
        ll num = convert(N1, radix);
        ans = compare(num, N2);
    } else {
        ll num = convert(N2, radix);
        ans = compare(num, N1);
    }
    if (0 == ans) puts("Impossible");
    else cout << ans;
    return 0;
}