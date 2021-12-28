#include<iostream>
using namespace std;
struct LinkList {
	int data;
	LinkList* next;
};
int main() {
	int n, k;
	cin >> n;
	LinkList* zb, * head, * tail;
	head= (LinkList*)malloc(sizeof(LinkList));
	head->next = NULL;
	tail = head;
	for (int i = 0; i < n; i++) {
		zb = (LinkList*)malloc(sizeof(LinkList));
		cin >> zb->data;
		tail->next = zb;
		tail = zb;
	}
	cin >> k;
	if (k >= n)
		cout << "no" << endl;
	else {
		LinkList* temp, * temp1;
			temp = (LinkList*)malloc(sizeof(LinkList));
			temp1 = (LinkList*)malloc(sizeof(LinkList));
			temp1->next = NULL;
			temp = head;
		for (int i = 1; i <= (n - k); i++) {
			temp = temp->next;
			temp1 = temp->next;
			for (int j = 0; j < k - 1; j++)
				temp1 = temp1->next;
			cout << temp->data << " " << temp1->data << " " << temp->data + temp1->data << endl;
		}
	}
	return 0;
}
