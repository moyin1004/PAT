#include <bits/stdc++.h>

using namespace std;

struct TNode {
    int weight;
    vector<int> child;
};

TNode Tree[102];
int Ans[102];

bool cmp(int a, int b) {
    return Tree[a].weight > Tree[b].weight;
}

void print(int cnt) {
    for (int i = 0; i < cnt; ++i) {
        cout << Ans[i];
        if (i != cnt - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void dfs(int node, int w, int cnt, int s) {
    w += Tree[node].weight;
    Ans[cnt++] = Tree[node].weight;
    if (Tree[node].child.empty() &&  w == s) {
        print(cnt);
    } else if (w > s || Tree[node].child.empty()) {
        return ;
    }
    for (int i = 0; i < Tree[node].child.size(); ++i) {
        dfs(Tree[node].child[i], w, cnt, s);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> Tree[i].weight;
    }
    int num = 0;
    for (int i = 0; i < m; ++i) {
        int num, cnt;
        cin >> num >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int next;
            cin >> next;
            Tree[num].child.push_back(next);
        }
        // 权值大的序列先输出，对权值进行排序
        sort(Tree[num].child.begin(), Tree[num].child.end(), cmp);
    }
    dfs(0, 0, 0, s);
    return 0;
}