#include<iostream>
using namespace std;
struct Sqstack {
	int Top = 0;
	int in_ves[302];
	int out_ves[302];
}garage;
int main() {
	int n, m, q;
	cin >> n >> m >> q;      //输入车库容量、等待容量及操作数
	for (int i = 0; i < q; i++) {
		int op, x;
		cin >> op >> x;      //输入操作名及车牌号
		if (op == 1) {       //1 for into garage
			if (garage.Top < n) {
				garage.in_ves[garage.Top] = x;
				garage.Top++;
				cout << "parking lot:";
				for (int j = 0; j < garage.Top; j++)
					cout << " " << garage.in_ves[j];
				cout << "\nwaiting queue:\n";
			}
			else if (garage.Top >= n && garage.Top < n + m) {
				garage.out_ves[garage.Top - n] = x;
				garage.Top++;
				cout << "parking lot:";
				for (int j = 0; j < n; j++)
					cout << " " << garage.in_ves[j];
				cout << "\nwaiting queue:";
				for (int j = 0; j < garage.Top - n; j++)
					cout << " " << garage.out_ves[j];
				cout << endl;
			}
			else;
		}
		else if (op == 2) {   //2 for out garage
			int zb = 0;
			for (int j = 0; j < n; j++) {
				if (garage.in_ves[j] == x) {
					zb = 1;
					if (garage.Top <= n) {
						for (int k = j; k < n - 1; k++)
							garage.in_ves[k] = garage.in_ves[k + 1];
						garage.Top--;
						cout << "parking lot:";
						for (int k = 0; k < garage.Top; k++)
							cout << " " << garage.in_ves[k];
						cout << "\nwaiting queue:\n";
					}
					else {
						for (int k = j; k < n - 1; k++)
							garage.in_ves[k] = garage.in_ves[k + 1];
						garage.in_ves[n - 1] = garage.out_ves[0];
						for (int k = 0; k < m; k++)
							garage.out_ves[k] = garage.out_ves[k + 1];
						garage.Top--;
						cout << "parking lot:";
						for (int k = 0; k < n; k++)
							cout << " " << garage.in_ves[k];
						cout << "\nwaiting queue:";
						for (int k = 0; k < garage.Top - n; k++)
							cout << " " << garage.out_ves[k];
						cout << endl;
					}
				}
				else;
			}
			if (zb == 0) cout << "parking lot:\nwaiting queue:\n";
		}
		else if (op == 3) {   //3 for check in-garage car
			if (x > 0 && x <= n) cout << garage.in_ves[x - 1] << endl;
			else cout << -1 << endl;
		}
		else if (op == 4) {   //4 for checking waiting car
			if (x > 0 && x <= m) cout << garage.out_ves[x - 1] << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}
