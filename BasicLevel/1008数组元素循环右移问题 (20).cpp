/*
一个数组A中存有N（N&gt0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M>=0）个位置，即将A中的数据
由（A~0~ A~1~……A~N-1~）变换为（A~N-M~ …… A~N-1~ A~0~ A~1~……A~N-M-1~）（最后M个数循环移至最前面的M个位置）。如
果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式：每个输入包含一个测试用例，第1行输入N ( 1<=N<=100)、M（M>=0）；第2行输入N个整数，之间用空格分隔。
输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
输入样例：
6 2
1 2 3 4 5 6
输出样例：
5 6 1 2 3 4
*/

#include <iostream>
#include <cmath>
using namespace std;

void reverse(int begin, int end, int a[]);

int main() {
    int a[100];
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> a[i];
    if(M > N) M -= N;
    reverse(0, N - M, a);
    reverse(N - M, N, a);
    reverse(0, N, a);
    for(int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if(i != N - 1) cout << ' ' ;
    }
    return 0;
}

void reverse(int begin, int end, int a[]) {
    for(int i = 0; i < (end - begin) / 2; i++) 
    {
        swap(a[begin + i], a[end - 1 - i]);
    }
}

/*
非常规解法
#include <iostream>
using namespace std;

void move(int N, int M,int a[]);
void print(int N, int a[]);

int main() {
    int a[100];
    int N, M;
    cin >> N >> M;
    if(M <= N) {
        move(N, M, a);
        print(N, a);
    }
    else if(M > N) {
        move(N, M - N, a);
        print(N, a);
    }
    return 0;
}

void move(int N, int M,int a[]) {
    for(int i = M; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> a[i];
}

void print(int N, int a[]) {
    for(int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if(i != N - 1) cout << ' ' ;
    }
}
*/