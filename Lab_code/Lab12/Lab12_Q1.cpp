#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
struct Edge{
    int u ,v ,w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
};
int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    vector<Edge> graph(edge + 1, Edge(0, 0, 0));
    vector<int> cluster(vertex + 1);
    for(int i = 0; i <= vertex; i++){
        cluster[i] = i;
    }
    for(int i = 0; i < edge; i++){
        int u ,v ,w;
        cin >> u >> v >> w;
        if (u > v){
            swap(u,v);
        }
        Edge newEdge(u, v, w);
        graph.push_back(newEdge);
    }
    sort(graph.begin(), graph.end(), [](const Edge &a, const Edge &b) {
        if (a.w != b.w) {
            return a.w < b.w;
        }
        if (a.u != b.u) {
            return a.u < b.u;
        }
        return a.v < b.v;
    });
    for(int i = 0; i < graph.size(); i++){
        Edge e = graph[i];
        int u = e.u;
        int v = e.v;
        if(cluster[u] != cluster[v]){
            int oldClusterNo = cluster[v];
            for(int j = 0; j <= vertex; j++){
                if(cluster[j] == oldClusterNo){
                    cluster[j] = cluster[u];
                }
            }
            if (u > v) {
                swap(u, v);
            }
            int w = e.w;
            cout << u << " " << v << " " << w << "\n";
        }
        /*
        cout << "Cluster: ";
        for(int j = 0; j <= vertex; j++){
            cout << cluster[j] << " ";
        }
        cout << "\n";
        */
    }
    
    
    return 0;
}