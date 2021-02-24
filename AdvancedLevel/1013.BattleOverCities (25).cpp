#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

bool Visit[1010];

void dfs(Graph &graph, int node) {
    Visit[node] = true;
    for (int i = 0; i < graph[node].size(); ++i) {
        int next = graph[node][i];
        if (Visit[next]) continue;
        dfs(graph, next);
    }
}

int dfs_traverse(Graph &graph) {
    int cnt = 0;
    for (int i = 1; i < graph.size(); ++i) {
        if (!Visit[i]) {
            dfs(graph, i);
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    Graph graph;
    graph.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < k; ++i) {
        memset(Visit, 0, sizeof(Visit));
        int city;
        cin >> city;
        Visit[city] = true;
        cout << dfs_traverse(graph) - 1 << endl;
    }
    return 0;
}