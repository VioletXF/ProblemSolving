#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
#define MAX_E 200001
using namespace std;

int N, E;
int v1, v2;
vector<pair<int, int>> edges[MAX_E];//[from], to, val
vector<int> dijkstra(int from) {
	vector<int> dist(N+1, INF);// starts from index 1
	dist[from] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(0, from));
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		for (int i = 0; i < edges[v].size(); i++) {
			int wnext = edges[v][i].second;
			int vnext = edges[v][i].first;
			if (dist[vnext] > w + wnext) {
				dist[vnext] = w + wnext;
				pq.push(make_pair(dist[vnext], vnext));
			}
		}
	}
	return dist;
}
bool is_inf(int value) {
	if (value >= INF)return true;
	if (value < 0)return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	vector<int> start_to_end = dijkstra(1);
	vector<int> v1_to_end = dijkstra(v1);
	vector<int> v2_to_end = dijkstra(v2);
	//s->v1->v2->N
	int sum1 = start_to_end[v1] + v1_to_end[v2] + v2_to_end[N];
	int sum2 = start_to_end[v2] + v2_to_end[v1] + v1_to_end[N];
	int res = min(sum1, sum2);
	if (is_inf(res)) {
		cout << -1;
	}
	else {
		cout << res;
	}
	
}