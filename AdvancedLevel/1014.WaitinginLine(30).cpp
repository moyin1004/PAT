#include <bits/stdc++.h>

using namespace std;

struct Time {
    int hour = 8;
    int min = 0;
    void add(int minute) {
        min += minute;
        hour += min / 60;
        min %= 60;
    }
    // 起始时间超过17:00返回false
    bool compare(int minute) {
        int temp = hour - minute / 60;
        if ((minute % 60) > min) --temp;
        if (temp >= 17) return false;
        else return true;
    }
};
bool operator<(Time &a, Time &b) {
    if (a.hour == b.hour) return a.min < b.min;
    else if (a.hour < b.hour) return true;
    return false;
}
ostream &operator<<(ostream &os, const Time &t) {
    os << setw(2) << setfill('0') << t.hour << ":";
    os << setw(2) << setfill('0') << t.min;
    return os;
}
struct Win {
    Time cur;
    Time end;
    queue<int> q;
    void execute() {
        if (!q.empty()) {
            cur.add(q.front());
            q.pop();
        }
    }
    void enque(const int &min) {
        q.push(min);
        end.add(min);
    }
};

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<Time> ans;
    vector<Win> win;
    ans.resize(k+1);
    win.resize(n+1);
    int time[1002] = {0};
    int index = 1;
    for (int i = 0; i < k; ++i) {
        cin >> time[i+1];
    }
    // 初始化，顾客进入等待队列
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n && index <= k; ++j) {
            win[j].enque(time[index]);
            ans[index] = win[j].end;
            ++index;
            if (i == 1) win[j].execute();
        }
    }
    while (index <= k) {
        Time minn = win[0].cur;
        int minwin = 0;
        for (int i = 1; i < n; ++i) {
            if (win[i].cur < minn) {
                minn = win[i].cur;
                minwin = i;
            }
        }
        win[minwin].execute();
        win[minwin].enque(time[index]);
        ans[index] = win[minwin].end;
        ++index;
    }

    for (int i = 0; i < q; ++i) {
        int cus;
        cin >> cus;
        if (!ans[cus].compare(time[cus])) {
            cout << "Sorry" << endl;
        }
        else {
            cout << ans[cus] << endl;
        }
    }
    return 0;
}