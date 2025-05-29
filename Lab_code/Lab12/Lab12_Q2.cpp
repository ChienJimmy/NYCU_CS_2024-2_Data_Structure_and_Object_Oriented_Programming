#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    vector<pair<int, pair<int, int>>> graph;
    vector<int> distance(vertex+1, 1000000000);
    for(int i = 0; i < edge; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({w, {u, v}});
    }
    int startVertex;
    cin >> startVertex;
    distance[startVertex] = 0;
    for (int i = 1; i < vertex; i++) {
        for (int j = 0; j < edge; j++) {
            int u = graph[j].second.first;
            int v = graph[j].second.second;
            int w = graph[j].first;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
            if (distance[v] + w < distance[u]) {
                distance[u] = distance[v] + w;
            }
        }
    }
    for (int i = 0; i < edge; i++) {
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        int w = graph[i].first;
        if (distance[u] + w < distance[v]) {
            distance[v] = distance[u] + w;
        }
    }
    for (int i = 1; i <= vertex; i++) {
        if (distance[i] == 1000000000) {
            cout << "INF ";
        }
        else {
            cout << distance[i] << " ";
        }
    }
    cout << "\n";

    return 0;
}