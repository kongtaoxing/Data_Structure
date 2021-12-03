#include<iostream>
using namespace std;
struct Closedge {
	int pre;
	int quan;
}*closedge;
int main() {
	int n, m, r, ** matrix, sum = 0, min_num = 1000;
	cin >> n >> m;     //输入顶点数与边数
	matrix = new int* [n]; 
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			matrix[i][j] = 10000;
	closedge = new Closedge[n];
	for (int i = 0; i < n; i++) closedge[i].quan = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;     //表示u、v之间有一条权值为w的无向边
		matrix[u - 1][v - 1] = matrix[v - 1][u - 1] = w;
	}
	cin >> r;     //输入起始顶点
	for (int i = 0; i < n; i++)
		if (i != r - 1) {
			closedge[i].pre = r - 1;
			closedge[i].quan = matrix[r - 1][i];
		}
	closedge[r - 1].quan = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (closedge[j].quan < min_num && closedge[j].quan > 0) {
				min_num = closedge[j].quan; r = j;
			}
		cout << closedge[r].pre + 1 << ' ' << r + 1 << ' ' << min_num << endl;
		closedge[r].quan = 0; sum += min_num; min_num = 1000;
		for (int j = 0; j < n; j++)
			if (matrix[r][j] < closedge[j].quan) {
				closedge[j].quan = matrix[r][j];
				closedge[j].pre = r;
			}
	}
	cout << sum << endl;
	return 0;
}
