#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m;
    cin >> m;
    string people_lock, people_unlock;
    string lock_time = "00:00:00", unlock_time = "24:00:00";
    while (m--) {
        string name, signin, signout;
        cin >> name >> signin >> signout;
        if  (signin < unlock_time) {
            unlock_time = signin;
            people_unlock = name;
        }
        if (signout > lock_time) {
            lock_time = signout;
            people_lock = name;
        }
    }
    cout << people_unlock << " " << people_lock;
}