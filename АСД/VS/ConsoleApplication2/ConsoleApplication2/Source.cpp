#include<iostream>
using namespace std;
void Merge(int *A, int p, int q, int r);
void Merge_Sort(int *A, int p, int r);
const int n = 10;
int hs = n - 1;
void main()
{
	int A[n]{ 5, 4, 8, 9, 2, 6, 7, 1, 6, 3 }, B[n];
	Merge_Sort(A, 0, n - 1);
	//QuickSort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	//sort_rand(A, B);
	//sort_vozr(A, B);
	//sort_ub(A, B);
	cin.get();
	cin.get();
}
void Merge(int *A, int p, int q, int r) {
	int i = p, j = q + 1, k = 0, l = 0;
	int *C = new int[r - p + 1];
	while (i <= q && j <= r) {
		if (A[i] < A[j]) {
			C[k] = A[i];
			i++;
		}
		else {
			C[k] = A[j];
			j++;
		}
		k++;
	}
	if (i <= q)
		l = i;
	else
		l = j;
	while (k <= r - p) {
		C[k] = A[l];
		k++;
		l++;
	}
	for (l = 0; l < k; l++) {
		A[l + p] = C[l];
	}
}
void Merge_Sort(int *A, int p, int r) {
	if (p < r) {
		int q = ((p + r) / 2);
		Merge_Sort(A, p, q);
		Merge_Sort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}
