/*
给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意 0 不能做首位）。
例如：给定两个 0，两个 1，三个 5，一个 8，我们得到的最小的数就是 10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。整数间用一个空格分隔。
10 个数字的总个数不超过 50，且至少拥有 1 个非 0 的数字。
输出格式：
在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558
*/

/*
#include<iostream>
using namespace std;

int main() {
    int zero, n;
    cin >> zero; //记录0的个数
    bool flag = true;
    for(int i = 1; i < 10; i++) {
        cin >> n;
        if(n != 0 && flag) { //第一个非0数，输出一个，输出所有0，输出剩余个数
            flag = false;
            cout << i;
            for(int j = 0; j < zero; j++) cout << 0;
            for(int j = 0; j < n - 1; j++) cout << i;
        }
        else if(n != 0 && !flag) { //其余数顺序输出
            for(int j = 0; j < n; j++) cout << i;
        }
    }
    return 0;
}
*/

//常规法
#include<iostream>
using namespace std;

int main() {
    int count[10];
    for(int i = 0; i < 10; i++) cin >> count[i];
    for(int i = 1; i < 10; i++) {
        if(count[i] > 0) {
            cout << i;
            count[i]--;
            break;
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) cout << i;
    }
    return 0;
}
