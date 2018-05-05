#include <iostream>
#include <fstream>
using namespace std;
void main() {
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n, max = 0;
	fin >> n;
	if (n % 3 == 0)
		max = n / 3 * 7;
	else {
		if (n % 3 == 1)
			max = (n / 3 - 1) * 7 + 4;
		else
			if (n % 3 == 2)
				max = n / 3 * 7 + 1; 
	}
	fout << max;
}