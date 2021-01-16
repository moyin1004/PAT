#include <bits/stdc++.h>

using namespace std;

// P之前的A数目乘以P与T之间的A的数目等于P后面的A的数目

int main() {
    int n;
    char str[110];
    cin >> n;
    while (n--) {
        int posP = -1, posT = -1, i = 0;
        memset(str, 0, sizeof(str));
        cin >> str;
        int len = strlen(str);
        for (i = 0; i < len; ++i) {
            if (str[i] == 'P') posP = i;
            else if (str[i] == 'T') posT = i;
            else if (str[i] != 'A') break;
        }
        if (i == len && (posT - posP > 1) && posP * (posT - posP - 1) == (len - posT - 1)) puts("YES");
        else puts("NO");
    }
    return 0;
}