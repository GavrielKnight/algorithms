#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<vector<bool>> MB; 

VI dijkstra(MB &mt, int start) {
    int n = mt.size();

    VI minCost(n, numeric_limits<int>::max());
    minCost[start - 1] = 0;

    VI prev(n, -1);

    VB visited(n, false);
    visited[start - 1] = true;

    //cout << "minCost: "; printVector(minCost);
    //cout << "prev: "; printVector(prev);
    //cout << "visited: "; printVector(visited);

    int current = start;
    int count = 0;
    while (count < n) {
        for (int i = 0; i < n; i++) {
            if (!visited[i] && mt[current - 1][i]) {
                int cost = minCost[current - 1] + mt[current - 1][i];
                if (cost < minCost[i]) {
                    minCost[i] = cost;
                    prev[i] = current;
                }
            }
        }

        //cout << "minCost: "; printVector(minCost);
        //cout << "prev: "; printVector(prev);

        int min = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minCost[i] < min) {
                min = minCost[i];
                current = i + 1;
            }
        }

        visited[current - 1] = true;
        ++count;
    }

    return prev;
}

#endif