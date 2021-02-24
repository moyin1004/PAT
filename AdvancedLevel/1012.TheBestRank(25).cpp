#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

struct Student {
    int score[4];
    int num;
    void read() {
        cin >> num >> score[1] >> score[2] >> score[3];
        score[0] = (score[1]+score[2]+score[3]) / 3.0 + 0.5;
    }
};
bool cmp(Student &a, Student &b, int flag) {
    return a.score[flag] > b.score[flag];
}

int find_min_pos(const vector<int> &v) {
    int min_pos = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[min_pos] > v[i]) {
            min_pos = i;
        }
    }
    return min_pos;
}

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Student> a;
    unordered_map<int, vector<int>> rank_map;
    for (int i = 0; i < n; i++) {
        Student stu;
        stu.read();
        a.push_back(stu);
    }
    for (int i = 0; i < 4; ++i) {
        sort(a.begin(), a.end(), std::bind(cmp, _1, _2, i));
        for (int j = 0; j < a.size(); ++j) {
            if (rank_map[a[j].num].size() == 0) {
                rank_map[a[j].num].resize(4);
            }
            rank_map[a[j].num][i] = j+1;
            // 考虑相同分数
            if (j > 0 && a[j].score[i] == a[j-1].score[i]) {
                rank_map[a[j].num][i] = rank_map[a[j-1].num][i];
            }
        }
    }
    char flag[5] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        auto it = rank_map.find(num);
        if (it != rank_map.end()) {
            int pos = find_min_pos(it->second);
            cout << it->second[pos] << " " << flag[pos] << endl;
        }
        else {
            cout << "N/A" << endl;
        }
    }
    return 0;
}