#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> Tree[N];
int leaf[N];
int max_h;

// 寻找每层叶结点个数
void DFS(int index, int h) {
    max_h = max(h, max_h);
    int size = Tree[index].size();
    if (size == 0) ++leaf[h];
    for (int i = 0; i < size; ++i) {
        DFS(Tree[index][i], h+1);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int id, k;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int temp;
            cin >> temp;
            Tree[id].push_back(temp);
        }
    }
    DFS(1, 1);
    for (int i = 1; i <= max_h; ++i) {
        cout << leaf[i];
        if (i != max_h) cout << " ";
    }
    return 0;
}