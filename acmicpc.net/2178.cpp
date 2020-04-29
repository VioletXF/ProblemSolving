#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int N, M;
int map[100][100] = { 0 };
int dirs[4][2] = {
	{-1,0}, {0,-1}, {1,0}, {0,1}
};

bool checkRange(int y, int x) {
	return !(y < 0 || x < 0 || x >= M || y >= N);
}
int bfs() {
	int y = 0, x = 0;
	queue<pair<int, int>>q;
	q.push(pair<int, int>(y, x));
	map[y][x] = 2;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1)break;
		for (int i = 0; i < 4; i++) {
			int y1 = y + dirs[i][0];
			int x1 = x + dirs[i][1];
			if (map[y1][x1] == 1 &&checkRange(y1, x1)) {
				map[y1][x1] = map[y][x] + 1;
				q.push(pair<int, int>(y1, x1));
			}
		}
	}
	return map[N-1][M-1] - 1;
}
int main() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int input;
			scanf("%1d", &input);
			map[i][j] = input;
		}
	}
	cout<<bfs();
}