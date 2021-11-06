#include<iostream>
using namespace std;
typedef struct BiTNode {
	char data;
	BiTNode* LChild, * RChild;
}BiTNode, * BiTree;
void Creeat_BiTree(BiTree &t) {
	t = new BiTNode;
	char x;
	cin >> x;
	if (x == '#')t = NULL;
	else {
		t->data = x;
		t->LChild = t->RChild = NULL;
		Creeat_BiTree(t->LChild);
		Creeat_BiTree(t->RChild);
	}
}
void PreOrderTraverse(BiTree& t) {  //先序遍历
	if (t) {
		cout << t->data;
		PreOrderTraverse(t->LChild);
		PreOrderTraverse(t->RChild);
	}
}
void InOrderTraverse(BiTree& t) {  //中序遍历
	if (t) {
		InOrderTraverse(t->LChild);
		cout << t->data;
		InOrderTraverse(t->RChild);
	}
}
void PostOrderTraverse(BiTree& t) {  //后序遍历
	if (t) {
		PostOrderTraverse(t->LChild);
		PostOrderTraverse(t->RChild);
		cout << t->data;
	}
}
int TreeNum(BiTree t) {             //统计节点数
	if (t == NULL)return 0;
	else {
		if (t->LChild == NULL && t->RChild == NULL)return 1;
		else return TreeNum(t->LChild) + TreeNum(t->RChild) + 1;
	}
}
int BiTreeDeep(BiTree t) {        //二叉树的深度
	if (t == NULL)return 0;
	else {
		int LTreeDeep = BiTreeDeep(t->LChild);
		int RTreeDeep = BiTreeDeep(t->RChild);
		return LTreeDeep > RTreeDeep ? LTreeDeep + 1 : RTreeDeep + 1;
	}
}
int main() {
	BiTree Tree;
	Creeat_BiTree(Tree);
	PreOrderTraverse(Tree); cout << endl;
	InOrderTraverse(Tree); cout << endl;
	PostOrderTraverse(Tree); cout << endl;
	cout << TreeNum(Tree) << endl;
	cout << BiTreeDeep(Tree) << endl;
	return 0;
}
