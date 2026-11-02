#include "dijkstra.h"

int main(){
    cout << "# of nodes: ";
    int n; cin >> n;

    cout << "# of links: ";
    int m; cin >> m;

    MB mt(n, VB(n, false));
    for (int i = 0; i < m; i++) {
        cout << "link " << i + 1 << ": ";
        int u, v; cin >> u >> v;

        mt[u - 1][v - 1] = true;
        mt[v - 1][u - 1] = true;
    }

    cout << "start: ";
    int start; cin >> start;

    VI prev = dijkstra(mt, start);

    cout << "prev: ";
    for (auto x : prev) cout << x << ' ';
}