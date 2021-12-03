#include<iostream>
using namespace std;
struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
};
BiTNode* search(BiTNode* t, int a, int flag) {
	flag++;
	if (t == NULL) return NULL;
	else if (t->data == a) {
		cout << "查找成功 " << flag << endl; return t;
	}
	else if (a < t->data) return search(t->lchild, a, flag);
	else return search(t->rchild, a, flag); 
}
BiTNode* insert(BiTNode* t, int a) {
	if (t == NULL) {
		t = new BiTNode;
		t->lchild = t->rchild = NULL; t->data = a;
		return t;
	}
	else if (a > t->data) t->rchild = insert(t->rchild, a);
	else if (a < t->data) t->lchild = insert(t->lchild, a);
	return t;
}
void inorder(BiTNode* t) {
	if (t) {
		inorder(t->lchild);
		cout << t->data << ' ';
		inorder(t->rchild);
	}
}
int main(){
	int n, x; static int flag = 0;
	BiTNode* tree = NULL;
	cin >> n;     //输入数据个数
	for (int i = 0; i < n; i++) {
		int key; cin >> key;
		tree = insert(tree, key);
	}
	cin >> x;     //输入要查找的关键字
	inorder(tree); cout << endl;
	if (!search(tree, x, flag)) {
		tree = insert(tree, x); cout << "插入成功" << endl;
		inorder(tree); cout << endl;
	}
	return 0;
}
