#include<iostream>
using namespace std;
int main() {
	int num, du[100], deep = 1;
	char node[100];
	cin >> num;
	if (num == 0)cout << 0 << endl;
	else {
		for (int i = 0; i < num; i++)
			cin >> node[i] >> du[i];
		int count = 1, sum = du[0];
		while (sum) {
			int temp = count + sum; sum = 0;
			for (int i = count; i < temp; i++) sum += du[i];
			deep++;
			count = temp;
		}
		cout << deep << endl;
	}
	return 0;
}
