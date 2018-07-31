/*
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第1行给出正整数N（<=10^5^），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如
果解不唯一，则输出按字母序最小的解。
输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, pin;
    char a[2];
    int suma, sumb, maxa, maxb;
    pin = 0;
    int awin[3] = {0};
    int bwin[3] = {0};
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[0] >> a[1];
        if(a[0] == 'C' && a[1] == 'J') awin[1]++;   //不同手势获胜次数
        else if(a[0] == 'J' && a[1] == 'B') awin[2]++;
        else if(a[0] == 'B' && a[1] == 'C') awin[0]++;
        else if(a[0] == 'J' && a[1] == 'C') bwin[1]++;
        else if(a[0] == 'B' && a[1] == 'J') bwin[2]++;
        else if(a[0] == 'C' && a[1] == 'B') bwin[0]++;
        else pin++;
    }
    suma = awin[2] + awin[1] + awin[0]; //总获胜次数
    sumb = bwin[2] + bwin[1] + bwin[0];
    cout << suma << ' ' << pin << ' ' << N - suma - pin << endl;
    cout << sumb << ' ' << pin << ' ' << N - sumb - pin << endl;
    maxa = max(awin[0], max(awin[1], awin[2]));
    if(awin[0] == maxa) cout << 'B' << ' ';
    else if(awin[1] == maxa) cout << 'C' << ' ';
    else if(awin[2] == maxa) cout << 'J' << ' ';
    maxb = max(bwin[0], max(bwin[1], bwin[2]));
    if(bwin[0] == maxb) cout << 'B';
    else if(bwin[1] == maxb) cout << 'C';
    else if(bwin[2] == maxb) cout << 'J';
    return 0;
}