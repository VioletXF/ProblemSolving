#include <iostream>
#include <tuple>
#include <queue>
#include <cstdio>
using namespace std;
int N, M, H;

int zerosCnt = 0;
int todayTaskNum = 0;
int map[100][100][100] = { 0 };
int dirs[6][3] = { //for z, y, x
	{0, -1, 0}, {0, 0, -1}, {0, 1, 0}, {0, 0, 1},{-1, 0, 0}, {1, 0, 0}
};
queue<tuple<int, int, int>> q;
bool checkRange(int z, int y, int x) {
	return !(y < 0 || x < 0 || x >= M || y >= N || z<0||z>=H);
}
int bfs() {
	int day = 0;
	int temp = 0;
	while (!q.empty()) {
		
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		todayTaskNum--;
		for (int i = 0; i < 6; i++) {
			int nz = z + dirs[i][0];
			int ny = y + dirs[i][1];
			int nx = x + dirs[i][2];
			if (checkRange(nz, ny, nx) && map[nz][ny][nx] == 0) {
				map[nz][ny][nx] = 1;
				zerosCnt--;
				q.push(tuple<int, int, int>(nz, ny, nx));
				temp++;
			}
		}
		if (todayTaskNum == 0) {
			todayTaskNum = temp;
			temp = 0;
			day++;
		}
	}
	if (zerosCnt != 0)
		return -1;
	else
		return day - 1;
}
int main() {
	bool modu = true;

	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int input;
				cin >> input;
				if (input == 0) {
					modu = false;
					zerosCnt++;
				}
				else if (input == 1) {
					q.push(tuple<int,int,int>(k,i,j));
				}
				map[k][i][j] = input;

			}
		}
	}
	if (modu) {
		cout << 0;
	}
	else {
		todayTaskNum = q.size();
		cout<<bfs();
	}
}