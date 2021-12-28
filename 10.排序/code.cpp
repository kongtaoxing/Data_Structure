#include<iostream>
using namespace std;
void zheban(int* arr, int n) {     //折半插入排序
	int min_num = 1000000, arr0 = arr[0], flag = 0;
	for(int i = 0; i < n; i++)
		if (arr[i] < min_num) { min_num = arr[i]; flag = i; }
	arr[0] = arr[flag]; arr[flag] = arr0;
	int low, high, med;
	for (int i = 2; i < n; i++) {
		arr[0] = arr[i];
		low = 1; high = i - 1;
		while (low <= high) {
			med = (low + high) / 2;
			if (arr[med] > arr[i]) high = med - 1;
			else low = med + 1;
		}
		for (int j = i - 1; j >= high + 1; j--) arr[j + 1] = arr[j];
		arr[high + 1] = arr[0];
	}arr[0] = min_num;
	for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
}
void maopao(int* arr, int n) {     //冒泡排序
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j]) arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
	for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
}
void kuaisu(int* arr, int low, int high) {     //快速排序
	int h = high, l = low;
	if (low < high) {
		int key = arr[low];
		while (low < high) {
			while (low < high && arr[high] >= key)high--;
			if (low < high)arr[low] = arr[high];
			while (low < high && arr[low] <= key)low++;
			if (low < high)arr[high] = arr[low];
		}
		arr[low] = key;
		kuaisu(arr, l, low - 1);
		kuaisu(arr, low + 1, h);
	}
}
void jiandan(int* arr, int n) {     //简单选择排序
	for (int i = 0; i < n; i++) {
		int min_num = 100000, flag = 0;
		for (int j = i; j < n; j++)
			if (arr[j] < min_num) { flag = j; min_num = arr[j]; }
		if (flag != i) arr[flag] ^= arr[i] ^= arr[flag] ^= arr[i];
	}
	for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
}
void merge(int* arr, int low, int mid, int high) {     //归并排序
	int* temp = new int[high - low + 1], i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) { temp[k] = arr[i]; i++; }
		else { temp[k] = arr[j]; j++; }
		k++;
	}
	while (i <= mid) { temp[k] = arr[i]; i++; k++; }
	while (j <= high) { temp[k] = arr[j]; j++; k++; }
	i = low;
	for (int tempK = 0; tempK < k && i <= high; tempK++) { arr[i] = temp[tempK]; i++; }
	delete[]temp; temp = NULL;
}
void guibing(int* arr, int low, int high) {
	if (low < high) {
		int mid = (high + low) / 2;
		guibing(arr, low, mid);
		guibing(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
void adj(int* arr, int i, int L) {     //堆排序
	int temp = arr[i];
	for (int k = 2 * i + 1; k < L; k = 2 * i + 1) {
		if (k + 1 < L && arr[k] < arr[k + 1]) k++;
		if (temp < arr[k]) { arr[i] = arr[k]; i = k; }
		else break;
	}arr[i] = temp;
}
void dui(int* arr, int n) {
	int node = n / 2 - 1, min_num = 100000;
	for (int i = 0; i < n; i++)if (min_num > arr[i])min_num = arr[i];
	for (int i = node; i >= 0; i--) adj(arr, i, n);
	for (int j = n - 1; j >= 0; j--) {
		arr[0] ^= arr[j] ^= arr[0] ^= arr[j];
		adj(arr, 0, j);
	} arr[0] = min_num;
	for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
}
int main() {
	int n, * arr;
	cin >> n; arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	zheban(arr, n);
	maopao(arr, n);
	kuaisu(arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
	jiandan(arr, n);
	guibing(arr, 0, n - 1);
	for (int i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;
	dui(arr, n);
	return 0;
}
