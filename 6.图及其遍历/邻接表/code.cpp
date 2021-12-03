#include<iostream>
using namespace std;
struct ArcNode {
	int No;
	struct ArcNode* next;
};
struct VNode {
	int info;
	struct ArcNode* link; 
};
int main() {
	int n, m, w, front = 0, rear = 0, queue[100], visited[100], flag = 0, * u1, * v1, flag1 = 1;
	cin >> n >> m;    //输入节点数以及边数
	u1 = new int[m]; v1 = new int[m];
	VNode* adjlist = new VNode[n];
	for (int j = 0; j < n; j++) {
		adjlist[j].info = j + 1;
		adjlist[j].link = NULL;
	}
	for (int i = 0; i < m; i++) {
		int u, v; ArcNode* p1, * p2;
		cin >> u >> v;              //输入边的两个顶点
		u1[i] = u; v1[i] = v;
		for (int j = 0; j < i; j++)
			if (u == u1[j] && v == v1[j]) {
				m++; flag1 = 0;
			}
		if (flag1 == 1) {
			p1 = new ArcNode; p2 = new ArcNode;
			p1->No = u; p1->next = adjlist[v - 1].link; adjlist[v - 1].link = p1;
			p2->No = v; p2->next = adjlist[u - 1].link; adjlist[u - 1].link = p2;
		}else flag1 = 1;
	}
	ArcNode* p, * q;     //对邻接表链表元素排序
	for (int i = 0; i < n; i++) {
		for (p = adjlist[i].link; p; p = p->next)
			for (q = p->next; q; q = q->next)
				if (p->No > q->No) {
					p->No = p->No ^ q->No;
					q->No = p->No ^ q->No;
					p->No = p->No ^ q->No;
				}
	}
	cin >> w;     //起始顶点
	for (int i = 0; i < n; i++)
		if (w == adjlist[i].info)
			flag = 1;
	if (flag == 0) {
		cout << "起始顶点不存在" << endl;
		return 0;
	}
	else {
		queue[rear++] = w;
		for (int i = 1; i <= n; i++)      //广度优先
			visited[i] = false; visited[w] = true;
		cout << adjlist[w - 1].info;
		ArcNode* p = NULL;
		while (front != rear) {
			p = adjlist[queue[front++] - 1].link;
			while (p != NULL) {
				if (!visited[p->No]) {
					visited[p->No] = true;
					cout << ' ' << p->No;
					queue[rear++] = p->No;
				}
				p = p->next;
			}
		}cout << endl; front = rear = 0; queue[rear++] = w;
		for (int i = 1; i <= n; i++)     //深度优先
			visited[i] = false; visited[w] = true;
		cout << adjlist[w - 1].info;
		ArcNode* q = NULL;
		while (front != rear) {
			q = adjlist[queue[front++] - 1].link;
			while (q != NULL) {
				if (!visited[q->No]) {
					visited[q->No] = true;
					cout << ' ' << q->No;
					queue[rear++] = q->No;
					q = adjlist[q->No - 1].link;
				}
				else q = q->next;
			}
		}cout << endl;
	}
	return 0;
}
