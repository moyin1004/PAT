/*
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, 
and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.

Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of 
no more than 10​^5 characters containing only P, A, or T.
Output Specification:
For each test case, print in one line the number of PAT's contained in the string. Since the result
may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT
Sample Output:
2
*/

//PAT的个数 = 所有A左侧P的个数*A右侧T的个数
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 100010;
const int MOD = 1000000007;

int main() {
    char s[MAXN];
    int leftNumP[MAXN] = {0};
    int ans = 0, rightNumT = 0;
    cin >> s;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(i > 0) leftNumP[i] = leftNumP[i - 1];
        if(s[i] == 'P') leftNumP[i]++;
    }
    for(int i = len - 1; i >= 0; i--) {
        if(s[i] == 'T') rightNumT++;
        else if(s[i] == 'A') ans = (ans + rightNumP * leftNumP[i]) % MOD;
    }
    cout << ans;
    return 0;
}