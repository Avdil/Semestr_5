#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
void insertion_sort(int*A);
void Merge(int *A, int p, int q, int r);
void Merge_Sort(int *A, int p, int r);
void Heapsort(int *A);
void QuickSort(int *A, int p, int r);
void Randomized_Quicksort(int *A, int p, int r);
void Counting_Sort(int *CS, int *B);
void sort_rand(int *A, int *B);
void sort_vozr(int *A, int*B);
void sort_ub(int *A, int *B);
const int n = 10000;
const int k = 1000;
int hs = n - 1;
void main()
{
	/*int A[n]{7, 9, 3, 8, 1, 4, 5, 6, 2, 10 };
	insertion_sort(A);
	Merge_Sort(A, 0, n - 1);
	Heapsort(A);
	QuickSort(A, 0, n-1);
	Randomized_Quicksort(A, 0, n - 1);
	int B[n];
	Counting_Sort(CS, B);
	for (int x = 0; x < n; x++)
		cout << B[x] << " ";*/
	int A[n], B[n];
	sort_rand(A, B);
	sort_vozr(A, B);
	sort_ub(A, B);
	cin.get();
	cin.get();
}
void sort_rand(int *A, int *B) {
	int IS[n], MS[n], HS[n], QS[n], CS[n];
	for (int i = 0; i < n; i++) {
		IS[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		MS[i] = IS[i];
	}
	for (int i = 0; i < n; i++) {
		HS[i] = IS[i];
	}
	for (int i = 0; i < n; i++) {
		QS[i] = IS[i];
	}
	for (int i = 0; i < n; i++) {
		CS[i] = IS[i];
	}

	int i1 = GetTickCount();
	insertion_sort(IS);
	int i2 = GetTickCount();
	cout << "\n" << "Insertion_Sort: " << i2 - i1;
	for (int i = 0; i < n; i++) {
		A[i] = IS[i];
	}

	int m1 = GetTickCount();
	Merge_Sort(MS, 0, n - 1);
	int m2 = GetTickCount();
	cout << "\n" << "Merge_Sort: " << m2 - m1;

	int h1 = GetTickCount();
	Heapsort(HS);
	int h2 = GetTickCount();
	cout << "\n" << "Heapsort: " << h2 - h1;

	int q1 = GetTickCount();
	QuickSort(QS, 0, n - 1);
	int q2 = GetTickCount();
	cout << "\n" << "Quick_Sort: " << q2 - q1;

	int c1 = GetTickCount();
	Counting_Sort(CS, B);
	int c2 = GetTickCount();
	cout << "\n" << "Counting_Sort: " << c2 - c1;
}
void sort_vozr(int *A, int*B) {
	int IS_V[n];
	for (int i = 0; i < n; i++) {
		IS_V[i] = A[i];
	}
	int MS_V[n], HS_V[n], QS_V[n], CS_V[n];
	for (int i = 0; i < n; i++) {
		MS_V[i] = IS_V[i];
		HS_V[i] = IS_V[i];
		QS_V[i] = IS_V[i];
		CS_V[i] = IS_V[i];
	}
	int iv1 = GetTickCount();
	insertion_sort(IS_V);
	int iv2 = GetTickCount();
	cout << "\n" << "Insertion_Sort_VOZR: " << iv2 - iv1;

	int mv1 = GetTickCount();
	Merge_Sort(MS_V, 0, n - 1);
	int mv2 = GetTickCount();
	cout << "\n" << "Merge_Sort_VOZR: " << mv2 - mv1;

	int hv1 = GetTickCount();
	Heapsort(HS_V);
	int hv2 = GetTickCount();
	cout << "\n" << "Heapsort_VOZR: " << hv2 - hv1;

	int qv1 = GetTickCount();
	QuickSort(QS_V, 0, n - 1);
	int qv2 = GetTickCount();
	cout << "\n" << "Quick_Sort_VOZR: " << qv2 - qv1;

	int cv1 = GetTickCount();
	Counting_Sort(CS_V, B);
	int cv2 = GetTickCount();
	cout << "\n" << "Counting_Sort_VOZR: " << cv2 - cv1;
}
void sort_ub(int *A, int *B) {
	int IS_U[n];
	for (int i = 0; i < n; i++)
		IS_U[i] = A[i];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; j++) {
			if (IS_U[i] < IS_U[i + 1])
				swap(IS_U[i + 1], IS_U[i]);
		}
	}
	int MS_U[n], HS_U[n], QS_U[n], CS_U[n];
	for (int i = 0; i < n; i++) {
		MS_U[i] = IS_U[i];
		HS_U[i] = IS_U[i];
		QS_U[i] = IS_U[i];
		CS_U[i] = IS_U[i];
	}
	int iu1 = GetTickCount();
	insertion_sort(IS_U);
	int iu2 = GetTickCount();
	cout << "\n" << "Insertion_Sort_UB: " << iu2 - iu1;

	int mu1 = GetTickCount();
	Merge_Sort(MS_U, 0, n - 1);
	int mu2 = GetTickCount();
	cout << "\n" << "Merge_Sort_UB: " << mu2 - mu1;

	int hu1 = GetTickCount();
	Heapsort(HS_U);
	int hu2 = GetTickCount();
	cout << "\n" << "Heapsort_UB: " << hu2 - hu1;

	int qu1 = GetTickCount();
	QuickSort(QS_U, 0, n - 1);
	int qu2 = GetTickCount();
	cout << "\n" << "Quick_Sort_UB: " << qu2 - qu1;

	int cu1 = GetTickCount();
	Counting_Sort(CS_U, B);
	int cu2 = GetTickCount();
	cout << "\n" << "Counting_Sort_UB: " << cu2 - cu1;
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
		int q = ((p + r) / 2);
		Merge_Sort(A, p, q);
		Merge_Sort(A, q + 1, p);
		Merge(A, p, q, r);
	}
}
int Parent(int i){ return(i - 1) / 2;}
int Left(int i){ return 2*i + 1; }
int Right(int i) { return 2*i + 2; }

void Heapify(int *A, int i){
	int lar;
	int l = Left(i);
	int r = Right(i);
	if (l <= hs && A[l] > A[i])
		lar = l;
	else
		lar = i;
	if (r <= hs && A[r] > A[lar])
		lar = r;
	if (lar != i){
		swap(A[i],A[lar]);
		Heapify(A, lar);
	}
}
void Build_Heap(int *A){
	for (int i = (n - 1) / 2; i >= 0; i--){
		Heapify(A, i);
	}
}
void Heapsort(int *A){
	Build_Heap(A);
	for (int i = n - 1; i > 0; i--){
		swap(A[0], A[i]);
		hs--;
		Heapify(A, 0);
	}
}
int Partition(int *A, int p, int r){
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++){
		if (A[j] <= x){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}
void QuickSort(int *A, int p, int r){
	if (p < r){
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}
int Randomized_Partition(int *A, int p, int r){
	int x = rand() % (r - p + 1) + p;
	swap(A[r], A[x]);
	return Partition(A, p, r);
}
void Randomized_Quicksort(int *A, int p, int r){
	if (p < r) {
		int q = Randomized_Partition(A, p, r);
		Randomized_Quicksort(A, p, q - 1);
		Randomized_Quicksort(A, q + 1, r);
	}
}
void Counting_Sort(int *CS, int *B){
	int C[k];
	for (int i = 0; i < k; i++){
		C[i] = 0;
	}
	for (int j = 0; j < n; j++){
		C[CS[j]] = C[CS[j]] + 1;
	}
	for (int i = 1; i < k; i++){
		C[i] = C[i] + C[i - 1];
	}
	for (int j = n - 1; j >= 0; j--){
		C[CS[j]] = C[CS[j]] - 1;
		B[C[CS[j]]] = CS[j];
	}
}
