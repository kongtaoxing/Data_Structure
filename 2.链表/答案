#include<iostream>
using namespace std;
struct staff {
	char name[100];
	char position[100];
	int id;
	staff* next;
};
int main() {
	int n, m, op, x;
	cin >> n >> m;                   //n for number of staff & m for number of option
	staff* worker_h, * worker_t, * p;
	worker_h = (staff*)malloc(sizeof(staff));
	worker_h->next = NULL;
	worker_t = worker_h;
	for (int i = 0; i < n; i++) {
		p = (staff*)malloc(sizeof(staff));
		p->next = NULL;
		cin >> p->name >> p->position >> p->id;
		worker_t->next = p;
		worker_t = p;
	}
	for (int i = 0; i < m; i++) {
		cin >> op >> x;               //op for option & x for location
		if (op == 1) {                //"1" for deleting member
			if (x <= 0 || x > n)
				cout << -1 << endl;
			else {
				staff* temp = worker_h, * out = worker_h;
				for (int j = 0; j < x - 1; j++)
					temp = temp->next;
				temp->next = temp->next->next;
				n--;
				for (int j = 0; j < n; j++) {
					out = out->next;
					cout << "{" << out->name << ", " << out->position << ", " << out->id << "} ";
				}
				cout << endl;
			}
		}
		else if (op == 2) {            //"2" for adding member 
			if (x <= 0 || x > n + 1) {
				cout << -1 << endl;
				staff temp;
				cin >> temp.name >> temp.position >> temp.id;
			}
			else {
				staff* current, * temp = worker_h, * out = worker_h;
				current = (staff*)malloc(sizeof(staff));
				cin >> current->name >> current->position >> current->id;
				for (int j = 0; j < x - 1; j++)
					temp = temp->next;
				current->next = temp->next;
				temp->next = current;
				n++;
				for (int j = 0; j < n; j++) {
					out = out->next;
					cout << "{" << out->name << ", " << out->position << ", " << out->id << "} ";
				}
				cout << endl;
			}
		}
		else if (op == 3) {         //"3" for finding member
			if (x <= 0 || x > n)
				cout << -1 << endl;
			else {
				staff* temp = worker_h->next;
				for (int i = 0; i < x - 1; i++)
					temp = temp->next;
				cout << "{" << temp->name << ", " << temp->position << ", " << temp->id << "}" << endl;
			}
		}
	}
	return 0;
}
