#include <iostream>
#include <vector>
using namespace std;

const long long INF = 2000000000000000000LL;

struct Edge {
    int v;
    long long w;
};

void dijkstra(int n, int S, vector<vector<Edge>> E, vector<long long> &D, vector<int> &trace) {
    D.resize(n, INF);
    trace.resize(n, -1);
    
    vector<bool> P(n, 0);
    D[S] = 0;
    
    for (int i = 0; i < n; i++) {
        int uBest = -1; 
        long long Min = INF;
        for (int u = 0; u < n; u++) {
            if (!P[u] && D[u] < Min) {
                uBest = u;
                Min = D[u];
            }
        }
        
        int u = uBest;
        P[u] = true;
        for (auto x : E[u]) {
            int v = x.v;
            long long w = x.w;
            if (D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<Edge>> E(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w; 
        E[u].push_back({v, w});
    }
    
    int S; 
    cin >> S;
    
    vector<long long> D;
    vector<int> trace;
    dijkstra(n, S, E, D, trace);
    
    cout << "Shortest distances from source vertex " << S << ":\n";
    for (int i = 0; i < n; i++) {
        if (D[i] == INF)
            cout << "Vertex " << i << " is unreachable\n";
        else
            cout << "Vertex " << i << ": " << D[i] << "\n";
    }
    
    return 0;
}
