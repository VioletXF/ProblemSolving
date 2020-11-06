#include <iostream>
#include <queue>
#include <vector>
#define SIZE 20001
#define INF 987654321
using namespace std;
int V, E;
int K;
vector<pair<int, int>> edges[SIZE]; //[from], to, val
int dist[SIZE];
void dijkstra() {
    priority_queue<pair<int, int>> pq; // w, v
    pq.push(make_pair(0, K));
    dist[K] = 0;
    while (!pq.empty()) {
        int w = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        for (int i = 0; i < edges[pos].size(); i++) {
            int wnext = edges[pos][i].second;
            int vnext = edges[pos][i].first;
            if (w + wnext < dist[vnext]) {
                dist[vnext] = w + wnext;
                pq.push(make_pair(-dist[vnext], vnext));
            }
        }
    }
}
int main() {
    
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i]<<"\n";
        }
    }

}