#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n, num = 0; 
	fin >> n;
	int *mas = new int[n];
	for (int i = 0; i < n; i++) {
		fin >> mas[i];
	}
	int max = mas[n - 1];
	for (int i = n - 2; i >=n; i--) {
		if (mas[i] > max)
			max = mas[i];
	}
	for (int i = 0; i < n; i++) {
		if (max % mas[i] != 0) {
			fout << n;
			return 0;
		}
		if (mas[i] != max)
			num++;
	}
	fout << num;
	return 0;
	delete[]mas;
}