#include <bits/stdc++.h>
using namespace std;
int n, m, s, f;
vector<vector<int>> adj;
vector<int> trace;
vector<int> par;

void dfs(int u) {
    for (int v : adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dfs(v);
    }
}

void tracePath(int s, int f) {
    vector<int> path;
    while (f != 0) {
        path.push_back(f);
        f = trace[f];
    }

    if (path.empty()) {
        if (s == f) cout << s; // handle the case when s == f
        else cout << "Can't find a path from s to f";
        return;
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i != 0) cout << "->";
    }
}

int main() {
    cin >> n >> m >> s >> f;
    adj.resize(n + 1);
    trace.resize(n + 1);
    par.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(s);

    if (trace[f] == 0)
        cout << "Can't find a path from s to f";
    else
        tracePath(s, f);

    return 0;
}
