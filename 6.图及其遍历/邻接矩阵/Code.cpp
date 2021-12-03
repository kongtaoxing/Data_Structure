#include<iostream>
using namespace std;
int main() {
	int n, m, w, * u1, * v1, flag = 1, ** matrix, flag1 = 0, visited[100], queue[100], front = 0, rear = 0;
	cin >> n >> m;     //输入节点及边数
	u1 = new int[m]; v1 = new int[m];
	matrix = new int* [n]; for (int i = 0; i < n; i++) matrix[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;     //输入边的两个顶点
		u1[i] = u; v1[i] = v;
		for (int j = 0; j < i; j++)
			if (u1[j] == u && v1[j] == v) { flag = 0; m++; }
		if (flag == 1) matrix[u - 1][v - 1] = matrix[v - 1][u - 1] = 1;
		else flag = 1;
	}
	cin >> w;     //输入起始顶点 
	if (w < 1 || w > n) cout << "起始顶点不存在" << endl;
	else {
		queue[rear++] = w;     //广度优先
		for (int i = 1; i <= n; i++) visited[i] = false; visited[w] = true;
		cout << w; int p;
		if (w == 1) p = w + 1; else p = 1; int w1 = w;
		while (front != rear) {
			if (matrix[w - 1][p - 1] && !visited[p]) {
				visited[p] = true;
				cout << ' ' << p;
				queue[rear++] = p;
				p++; front++; if (rear == n)rear = n - 1;
				if (p > n) { w++; p = 1; }
			} else { p++; if (p > n) { w++; p = 1; } }
		}cout << endl; front = rear = 0; queue[rear++] = w1;
		for (int i = 1; i <= n; i++)     //深度优先
			visited[i] = false; visited[w1] = true; cout << w1;
		if (w1 == 1) p = w1 + 1; else p = 1;
		while (front != rear) {
			if (matrix[w1 - 1][p - 1] && !visited[p]) {
				visited[p] = true;
				cout << ' ' << p; front++;
				queue[rear++] = p;
				if (p == n && n - 1 == rear) { cout << ' ' << 1; p = 1; front++; }
				w1 = p; p = 1;
				if (rear == n)rear = n - 1; if (front == n)front = n - 1;
			}
			else { p++; if (p == n + 1) { w1--; p = 1; } }
		} cout << endl;
	}
	return 0;
}
