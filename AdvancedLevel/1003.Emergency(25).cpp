#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v;
    int w;
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

typedef vector<Edge> Vex;
typedef pair<int, int> pii;

const int N = 505;
const int inf = 99999999;
int n, m, c1, c2, teams[N], num[N], max_w[N];
vector<Vex> Graph;

void dijstra() {
    bool visit[N] = {0};
    int dist[N];
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push(make_pair(0, c1));
    fill(dist, dist + N, inf);
    dist[c1] = 0;
    max_w[c1] = teams[c1];
    num[c1] = 1;
    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();
        if (dist[u] > dist[c2]) break;
        if (!visit[u]) {
            visit[u] = true;
            int size = Graph[u].size();
            for (int i = 0; i < size; ++i) {
                int w = Graph[u][i].w, v = Graph[u][i].v;
                if (dist[u] + w > dist[v]) {
                    continue;
                }
                if (dist[u] + w == dist[v]) {
                    max_w[v] = max(max_w[v], max_w[u]+teams[v]);
                    num[v] = num[u]+num[v];
                }
                if (dist[u] + w < dist[v]) {
                    max_w[v] = max_w[u]+teams[v];
                    num[v] = num[u];
                }
                dist[v] = dist[u] + w;
                heap.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i) {
        cin >> teams[i];
    }
    Graph.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back(Edge(v, w));
        Graph[v].push_back(Edge(u, w));
    }
    dijstra();
    cout << num[c2] << " " << max_w[c2];
    return 0;
}