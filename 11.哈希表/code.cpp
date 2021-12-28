#include<iostream>
using namespace std;
int main() {
	int* elem = new int[15];
	for (int i = 0; i < 15; i++) elem[i] = -999;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		int addr = num % 11;
		while (elem[addr] != -999)
			addr = (addr + 1) % 15;
		elem[addr] = num;
	}
	for (int i = 0; i < 15; i++) cout << elem[i] << ' '; cout << endl;
	int x; cin >> x; int addr = x % 11, flag = 0;
	while (elem[addr] != x) {
		if (elem[addr] == -999) { flag = 0; break; }
		else {
			addr = (addr + 1) % 15;
			if (addr == x % 11) { if (addr != 0) addr++; flag = 0; break; }
			else flag = 1;
		}
	}
	if (flag == 0) cout << "插入成功 " << addr << ' ' << endl;
	else cout << "查找成功 " << addr << ' ' << endl;
	return 0;
}
