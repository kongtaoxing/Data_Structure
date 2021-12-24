#include<iostream>
using namespace std;
int haspath(int s, int t, int k, int n, int* visit, int** g) {
	if (k == 0 && s == t) return 1;
	else if (k > 0) {
		for (int j = 0; j < n; j++) {
			if (g[s][j] != 0 && !visit[j]) {
				visit[j] = 1;
				if (haspath(j, t, k - 1, n, visit, g)) {
					return 1;
				}
				visit[j] = 0;
			}
		}
	}
	return 0;
}
int main() {
	int n, m, ** g, * visit;
	cin >> n >> m;
	g = new int* [n];
	for (int i = 0; i < n; i++)
		g[i] = new int[n];
	visit = new int[n];
	for (int i = 0; i < n; i++) visit[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = 0;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g[u - 1][v - 1] = g[v - 1][u - 1] = 1;
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		visit[x - 1] = 1;
		if (haspath(x - 1, y - 1, k, n, visit, g)) 
			cout << "YES" << endl;
		else cout << "NO" << endl;
		for (int i = 0; i < n; i++) visit[i] = 0;
	}
	return 0;
}
