#include<iostream>
#include<stdlib.h>

using namespace std;

struct staff
{
	char name[100];
	char position[100];
	int id;
};

int main()
{
	int m, n, op, x;
	cin >> n >> m;                   //n for number of staff & m for options
	staff* worker;
	worker = (staff*)malloc(1000 * sizeof(staff));
	for (int i = 0; i < n; i++) {
		cin >> worker[i].name >> worker[i].position >> worker[i].id;
	}
	for (int i = 0; i < m; i++) {
		cin >> op >> x;               //op for option & x for location
		if (op == 1) {                //"1" for deleting member
			if (x <= 0 || x > n)
				cout << -1 << endl;
			else {
				for (int j = x - 1; j < n - 1; j++)
					worker[j] = worker[j + 1];
				n -= 1;
				for (int k = 0; k < n; k++)
					cout << worker[k].name << ' ' << worker[k].position << ' ' << worker[k].id << ' ';
				cout << endl;
			}
		}
		else if(op == 2) {            //"2" for adding member 
			if (x <= 0 || x > n + 1) {
				cout << -1 << endl;
				staff temp;
				cin >> temp.name >> temp.position >> temp.id;
			}
			else {
				for (int j = n; j >= x; j--)
					worker[j] = worker[j - 1];
				staff join;
				cin >> join.name >> join.position >> join.id;
				worker[x - 1] = join;
				n += 1;
				for (int k = 0; k < n; k++)
					cout << worker[k].name << " " << worker[k].position << " " << worker[k].id << " ";
				cout << endl;
			}
		}
		else if (op == 3) {         //"3" for finding member
			if (x <= 0 || x > n)
				cout << -1 << endl;
			else
				cout << worker[x - 1].name << " " << worker[x - 1].position << " " << worker[x - 1].id << endl;
		}
	}
	return 0;
}
