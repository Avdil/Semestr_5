#include<iostream>
using namespace std;
void insertion_sort(int*A);
void Merge(int *A, int p, int q, int r);
void Merge_Sort(int *A, int p, int r);
const int n = 10;
void main()
{
	int A[n]{7, 9, 3, 8, 1, 4, 5, 6, 2, 10 };
	insertion_sort(A);
	Merge_Sort(A, 0, n - 1);
	for (int x = 0; x < n; x++)
		cout << A[x] << " ";
	cin.get();
	cin.get();
}
void insertion_sort(int *A)
{
	int key, i;
	for (int j = 1; j < n; j++)
	{
		key = A[j];
		i = j - 1;
		while ((i >= 0) && (A[i]>key))
		{
			A[i + 1] = A[i];
			i -= 1;
		}
		A[i + 1] = key;
	}
}
void Merge(int *A, int p, int q, int r){
	int i = p, j = q + 1, k = 0, l = 0;
	int *C = new int[r - p + 1];
	while (i <= q && j <= r){
		if (A[i] < A[j]){
			C[k] = A[i];
			i++;
		}
		else{
			C[k] = A[j];
			j++;
		}
		k++;
	}
		if (i <= q)
			l = i;
		else
			l = j;
		while (k <= r - p){
			C[k] = A[l];
			k++;
			l++;
		}
		for (l = 0; l < k; l++){
			A[l + p] = C[l];
		}
}
void Merge_Sort(int *A, int p, int r){
	if (p < r){
		int q = ((p + r)/2);
		Merge_Sort(A, p, q);
		Merge_Sort(A, q + 1, p);
		Merge(A, p, q, r);
	}
}