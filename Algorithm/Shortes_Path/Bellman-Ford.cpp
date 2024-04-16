#include <iostream>
#include <vector>
using namespace std;

const long long INF = 2000000000000000000LL;

struct Edge {
    int u, v;
    long long w; 
};

void bellmanFord(int n, int S, vector<Edge> &e, vector<long long> &D, vector<int> &trace) {

    trace.resize(n, -1);

    D[S] = 0;
    for (int T = 1; T < n; T++) {
        for (auto E : e) {
            int u = E.u;
            int v = E.v;
            long long w = E.w;
            if (D[u] != INF && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w; 
    }

    int S; 
    cin >> S;

    vector<long long> D;
    vector<int> trace;
    bellmanFord(n, S, e, D, trace);

    cout << "Khoang cach ngan nhat tu dinh nguon" << S << " den cac dinh khac:\n";
    for (int i = 0; i < n; i++) {
        if (D[i] == INF)
            cout << "Dinh " << i << " khong ket noi duoc\n";
        else if (D[i] == -INF)
            cout << "Dinh " << i << " co chu trinh am\n";
        else
            cout << "Dinh " << i << ": " << D[i] << "\n";
    }

    return 0;
}
