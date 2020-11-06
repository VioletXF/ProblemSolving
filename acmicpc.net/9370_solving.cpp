#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_ROAD 50001
#define INF 987654321
using namespace std;
int cross, road, cand;
int start, g, h;
vector<pair<int, int>>edges[MAX_ROAD];
vector<int> overall_dists;
int candidates[101];

bool inf(int value) {
	if (value < 0 || value >= INF)return true;
	return false;
}
vector<int> dijkstra(int from) {
	priority_queue < pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	vector<int> dist(cross+1, INF);
	dist[from] = 0;
	pq.push(make_pair(0, from));
	int i;
	while (!pq.empty()) {
		int w = pq.top().first;
		int v = pq.top().second;
		pq.pop();
		for (i = 0; i < edges[v].size(); i++) {
			int wnext = edges[v][i].second;
			int vnext = edges[v][i].first;
			if (dist[vnext] > wnext + w) {
				dist[vnext] = wnext + w;
				pq.push(make_pair(dist[vnext], vnext));
			}
		}
	}
	return dist;
}
int get_overall_min(int to) { //g,h를 고려하지 않고 모든 경우에서 최소 거리
	
	return overall_dists[to];
}

int get_current_min(int to) { //g,h를 고려한 최소 거리
	vector<int> gtoend = dijkstra(g);
	vector<int> htoend = dijkstra(h);
	int sum1 = overall_dists[g] + gtoend[h] + htoend[cross];
	int sum2 = overall_dists[h] + htoend[g] + gtoend[cross];
	int res = min(sum1, sum2);
	if (inf(res)) {
		return INF;
	}
	else {
		return res;
	}
}

int main() {
	int T,i;
	cin >> T;
	while (T--) {
		cin >> cross >> road >> cand;
		cin >> start >> g >> h;
		for (i = 0; i < road; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			//construct road
			edges[a].push_back(make_pair(b, d));
			edges[b].push_back(make_pair(a, d));
		}
		overall_dists = dijkstra(1);
		for (i = 0; i < cand; i++) {
			int x;
			cin >> x;
			candidates[i] = x;
			int temp = get_overall_min(x);
			if (!inf(temp)) {
				if (temp >= get_current_min(x)) {
					cout << x << " ";
				}
			}
		}
		cout << "\n";
		
		
	}
}