#include<iostream>
using namespace std;
typedef struct BiTNode {
	char data;
	BiTNode* LChild, * RChild;
}BiTNode, * BiTree;
void Creat_BiTree(BiTree& t) {
	t = new BiTNode;
	char x;
	cin >> x;
	if (x == '#')t = NULL;
	else {
		t->data = x;
		t->LChild = t->RChild = NULL;
		Creat_BiTree(t->LChild);
		Creat_BiTree(t->RChild);
	}
}
void InOrderTraverse(BiTree& t) {
	BiTree stack[100], p = t;
	int top = -1;
	while (top != -1 || p != NULL) {
		if (p != NULL) {
			stack[++top] = p;
			p = p->LChild;
		}
		else {
			p = stack[top--];
			cout << p->data;
			p = p->RChild;
		}
	}
}
void LevelOrder(BiTree& t) {
	BiTree queue[100], p = t;
	int front = 0, rear = 0;
	if (p != NULL)cout << p->data;
	queue[rear++] = t;
	while (front < rear) {
		p = queue[front++];
		if (p->LChild != NULL) {
			cout << p->LChild->data;
			queue[rear++] = p->LChild;
		}
		if (p->RChild != NULL) {
			cout << p->RChild->data;
			queue[rear++] = p->RChild;
		}
	}
}
int main() {
	BiTree Tree;
	Creat_BiTree(Tree);
	InOrderTraverse(Tree); cout << endl;
	LevelOrder(Tree); cout << endl;
	return 0;
}
