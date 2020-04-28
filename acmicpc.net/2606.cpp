#include <iostream>
#include <vector>
using namespace std;

bool visit[101] = { false };
vector<vector<int>> map;
int ans = 0;
void dfs(int x) {
	ans++;
	visit[x] = true;
	for (int i = 0; i < map[x].size(); i++) {
		if (!visit[map[x][i]])dfs(map[x][i]);
	}
	return;
}



int main() {
	int N;
	cin >> N;
	map.resize(N + 1);
	int P;
	cin >> P; //pair
	
	while (P--) {
		int first, last;
		cin >> first >> last;
		map[first].push_back(last);
		map[last].push_back(first);
	}
	dfs(1);
	cout << ans-1;
}