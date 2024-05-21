#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18; 

void init_trace(vector<vector<int>> &trace) {
    int n = trace.size();
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            trace[u][v] = u;
        }
    }
}

void floydWarshall(int n, vector<vector<long long>> &w, vector<vector<long long>> &D, vector<vector<int>> &trace) {
    D = w;
    init_trace(trace); 

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (D[u][k] < INF && D[k][v] < INF && D[u][v] > D[u][k] + D[k][v]) {
                    D[u][v] = D[u][k] + D[k][v];
                    trace[u][v] = trace[k][v];
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<long long>> w(n, vector<long long>(n, INF)); 
    vector<vector<int>> trace(n, vector<int>(n)); 
    for (int i = 0; i < n; i++) {
        w[i][i] = 0; 
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        long long weight;
        cin >> u >> v >> weight; 
        w[u][v] = weight; 
    }

    vector<vector<long long>> D; 
    floydWarshall(n, w, D, trace); 


    cout << "Ma tran duong di ngan nhat:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << D[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Duong di ngan nhat tu mot dinh den cac dinh con lai:\n";
    for (int i = 0; i < n; i++) {
        cout << "Tu dinh " << i << ":\n";
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cout << "  Den dinh " << j << ": ";
            if (D[i][j] == INF) {
                cout << "Khong co duong di.\n";
            } else {
                cout << i << " ";
                int cur = i;
                while (cur != j) {
                    cur = trace[cur][j];
                    cout << cur << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
