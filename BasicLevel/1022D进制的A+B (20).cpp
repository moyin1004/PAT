/*
输入两个非负10进制整数A和B(<=2^30^-1)，输出A+B的D (1 < D <= 10)进制数。
输入格式：
输入在一行中依次给出3个整数A、B和D。
输出格式：
输出A+B的D进制数。
输入样例：
123 456 8
输出样例：
1103
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    int sum = a + b;
    int z[40], num = 0;
    if(sum == 0) {
        printf("%d", sum);
        return 0;
    }
    while(sum != 0) {   //10进制转d进制（d <= 10）
        z[num++] = sum % d;
        sum /= d;
    }
    for(int i = num - 1; i >= 0; i--)
    printf("%d", z[i]);
    return 0;
}