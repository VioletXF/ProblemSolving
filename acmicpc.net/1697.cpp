#include <iostream>
#include <queue>
#define END 100000
using namespace std;
queue<int> q;
int N, K;
bool visited[END + 1] = { false };
int bfs() {
	int time = 0;
	int temp = 0;
	bool move = false;
	int nextMoves = 1;
	while (!q.empty()) {
		move = false;
		temp = 0;
		for (int i = 0; i < nextMoves; i++) {
			int x = q.front();
			q.pop();
			if (x == K) {
				return time;
			}
			visited[x] = true;
			if (x + 1 <= END && !visited[x+1]) {
				q.push(x + 1);
				move = true;
				temp++;
			}
			if (x - 1 >= 0 && !visited[x-1]) {
				q.push(x - 1);
				move = true;
				temp++;
			}
			if (x * 2 <= END && !visited[x*2]) {
				q.push(x * 2);
				move = true;
				temp++;
			}
			
		}
		nextMoves = temp;
		if (move)time++;
	}
}
int main() {

	cin >> N >> K;
	if (N == K) {
		cout << 0;
	}
	else {
		q.push(N);
		cout << bfs();
	}
}