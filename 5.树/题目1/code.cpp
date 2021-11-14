#include<iostream>
using namespace std;
typedef struct TreeNode {
	char data;
	TreeNode* firstchild, * nextsibling;
}*Tree, TreeNode;
struct Queue {
	Tree data[100];
	int front, rear;
};
void Creat_Tree(Tree& t) {
	t = NULL;
	Tree r = new TreeNode;
	Queue q;
	q.front = 0, q.rear = 0;
	char parent, son;
	for (cin >> parent >> son; son != '#'; cin >> parent >> son) {
		Tree p = new TreeNode;
		p->firstchild = p->nextsibling = NULL;
		p->data = son;
		q.data[q.front++] = p;
		if (parent == '#') t = p;
		else {
			Tree temp = new TreeNode;
			temp = q.data[q.rear];
			while (temp->data != parent) temp = q.data[++q.rear];
			if (!(temp->firstchild)) {
				temp->firstchild = p;
				r = p;
			}
			else {
				r->nextsibling = p;
				r = p;
			}
		}
	}
}
int TreeDepth(Tree& t) {
	if (!t)return 0;
	else {
		int h1 = TreeDepth(t->firstchild);
		int h2 = TreeDepth(t->nextsibling);
		return(max(h1 + 1, h2));
	}
}
int main() {
	Tree t;
	Creat_Tree(t);
	cout << TreeDepth(t) << endl;
	return 0;
}
