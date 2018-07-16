#include<iostream>
#include<stack>
#include<string>
#include<cstdio>
using namespace std;

int main() {
    stack<string> s;
    string ch;
    char c;
    int sum = 0;
    int n;
    while(scanf("%c", &c) != EOF)
    {
        sum = sum + c - '0';
    }
    if(sum == 0)
    {
        printf("ling");
        return 0;
    }
    while(sum != 0)
    {
        n = sum % 10;
        switch(n)
        {
            case 1:s.push("yi"); break;
            case 2:s.push("er"); break;
            case 3:s.push("san"); break;
            case 4:s.push("si"); break;
            case 5:s.push("wu"); break;
            case 6:s.push("liu"); break;
            case 7:s.push("qi"); break;
            case 8:s.push("ba"); break;
            case 9:s.push("jiu"); break;
            case 0:s.push("ling");
        }
        sum /= 10;
    }
    while(!s.empty())
    {
        ch = s.top();
        cout << s.top();
        s.pop();
        if(!s.empty()) printf(" ");
    }
    return 0;
}