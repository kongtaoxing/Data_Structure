/*首先建立单链表，然后从头节点开始循环，循环的内部
从该节点的下一个节点循环，寻找与第一遍循环中相等或
者为相反数的值，找到之后删除节点，并使数组长度减1,
最后按顺序输出链表的值，时间复杂度O(nlog(n))*/
#include<iostream>
using namespace std;
struct chainnode {
	int data;
	chainnode*next;
};
int main() {
	int n; cin >> n;
	chainnode*t_h = new chainnode, *t_t, *temp1 = new chainnode, *p, *temp2;
	t_h->next = NULL; t_t = t_h;
	for (int i = 0; i < n; i++) {
		p = new chainnode; p->next = NULL;
		cin >> p->data;
		t_t->next = p; t_t = p;
	}temp1 = t_h;
	for (int i = 0; i < n; i++) {
		temp1 = temp1->next;
			temp2 = temp1;
		for (int j = i + 1; j < n; j++) {
			while (temp2->next && (temp1->data == temp2->next->data || temp1->data == -temp2->next->data)) {
				temp2->next = temp2->next->next; n--;
				}
			temp2 = temp2->next;
		}
	}
	for (int i = 0; i < n; i++) {
		t_h = t_h->next;
		cout << t_h->data << ' ';
	}cout << endl;
	return 0;
}
