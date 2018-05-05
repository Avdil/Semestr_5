#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;
void insertion_sort(int *A, int n);
void Merger(int *M, int p, int  q, int r);
void MergeSortHelper(int *M, int p, int r);
void MergeSort(int *M, int A_size);
int n;
int k = 1000;
int heap_size = n - 1;
int Left(int i);
int Right(int i);
void Heapify(int *H, int i);
void Build_Heap(int *H);
void Heapsort(int *H);
int partition(int *Q, int p, int r);
void quicksort(int *Q, int p, int r);
void Counting_Sort(int*Couting, int*B, int k);
void sort_u(int *Array, int *B);
void sort_v(int *Array, int *B);
void main()
{
	int first;
	int last;
	cout << "Enter n: ";
	cin >> n;
	int *A = new int[n];
	int *M = new int[n];
	int *H = new int[n];
	int *Q = new int[n];
	int *Array = new int[n];
	int *Couting = new int[n];
	int *B = new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = rand() % k;
		}
	for (int i = 0; i < n; i++) {
		M[i] = A[i];
		H[i] = A[i];
		Q[i] = A[i];
		Couting[i] = A[i];
	}
	
	int t1 = GetTickCount();
	insertion_sort(A, n);
	int t2 = GetTickCount();
	cout << "\nWorking time of the insertion sort = " << t2 - t1 << endl;
	for (int i = 0; i < n; i++) {
		Array[i] = A[i];
	}
	int m1 = GetTickCount();
	MergeSort(M, n);
	int m2 = GetTickCount();
	cout << "Working time of the merge sort = " << m2 - m1 << endl;
	
	int n1 = GetTickCount();
	Heapsort(H);
	int n2 = GetTickCount();
	cout << "\nWorking time of the heap sort = " << n2 - n1 << endl;

	int q1 = GetTickCount();
	quicksort(Q, 0, n - 1);
	int q2 = GetTickCount();
	cout << "\nWorking time of the quik sort = " << q2 - q1 << endl;
	
	int c1 = GetTickCount();
	Counting_Sort(Couting, B, k);
	int c2 = GetTickCount();
	cout << "\nWorking time of the Couting sort = " << c2 - c1 << endl;
	sort_u(Array, B);
	sort_v(Array, B);
	delete[]A;
	delete[]M;
	delete[]H;
	delete[]Q;
	delete[]Array;
	delete[]Couting;
	delete[]B;
	cin.get();
	cin.get();
}
void insertion_sort(int *A, int n) {
	for (int j = 1; j < n; j++)
	{
		int key = A[j];
		int i = j - 1;
		while (i > -1 && A[i] > key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
	//for (int i = 0; i < n; i++)
	//cout << ' ' << A[i];
}

void Merger(int *M, int p, int  q, int r) {
	int * C = new int[r - p + 1];
	int i = p, j = q + 1;
	int k = 0;
	while (i <= q && j <= r) {
		if (M[i] <= M[j])
			C[k++] = M[i++];
		else
			C[k++] = M[j++];
	}
	while (i <= q)
		C[k++] = M[i++];

	while (j <= r)
		C[k++] = M[j++];
	for (k = 0, i = p; i <= r; ++i, ++k)
		M[i] = C[k];

	delete[]C;
}
void MergeSortHelper(int *M, int p, int r) {
	int l;
	if (p < r) {
		l = (p + r) >> 1;
		MergeSortHelper(M, p, l);
		MergeSortHelper(M, l + 1, r);
		Merger(M, p, l, r);
	}
}
void MergeSort(int *M, int A_size) {
	MergeSortHelper(M, 0, A_size - 1);
}

int Left(int i)
{
	return 2 * i + 1;
}
int Right(int i)
{
	return 2 * i + 2;
}
void Heapify(int *H, int i) {
	int l = Left(i);
	int r = Right(i);
	int largest = 0;
	if (l <= heap_size && H[l] > H[i])
		largest = l;
	else
		largest = i;
	if (r <= heap_size && H[r] > H[largest])
		largest = r;
	if (largest != i) {
		swap(H[i], H[largest]);
		Heapify(H, largest);
	}
}
void Build_Heap(int *H)
{
	heap_size = n - 1;
	for (int i = (n - 1) / 2; i >= 0; i--)
		Heapify(H, i);
}
void Heapsort(int *H) {
	Build_Heap(H);
	for (int i = n - 1; i > 0; i--)
	{
		swap(H[0], H[i]);
		heap_size = heap_size - 1;
		Heapify(H, 0);
	}
}


int partition(int *Q, int p, int r)

{
int x = Q[r];
int i = p - 1;
for (int j = p; j < r; j++)
{
if (Q[j] <= x){
i++;
swap(Q[i], Q[j]);
}
}
swap(Q[i + 1], Q[r]);
return i + 1;
}

void quicksort(int *Q, int p, int r)

{
if (p < r)
{
int q;
q = partition(Q, p, r);
quicksort(Q, p, q - 1);
quicksort(Q, q + 1, r);
}
}

void sort_u(int *Array, int *B) {    //по убыванию
	int *Mass_u = new int[n];
	for (int i = 0; i < n; i++)
		Mass_u[i] = Array[i];
	for (int j = 1; j < n; ++j)
	{
		for (int i = 0; i < n - j; i++)
		{
			if (Mass_u[i] < Mass_u[i + 1])
			{
				swap(Mass_u[i + 1], Mass_u[i]);
			}
		}
	}
	
	int *ms = new int[n];
	int *hs = new int[n];
	int *couting_u = new int[n];
	int *qs = new int[n];

	for (int i = 0; i < n; i++) {
		ms[i] = Mass_u[i];
		hs[i] = Mass_u[i];
		couting_u[i] = Mass_u[i];
		qs[i] = Mass_u[i];
	}
	
	int t1 = GetTickCount();
	insertion_sort(Mass_u, n);
	int t2 = GetTickCount();
	cout << "\nWorking time of the ISU = " << t2 - t1;

	int m1 = GetTickCount();
	MergeSort(ms, n);
	int m2 = GetTickCount();
	cout << "\n\nWorking time of the msu = " << m2 - m1 << endl;

	int n1 = GetTickCount();
	Heapsort(hs);
	int n2 = GetTickCount();
	cout << "\nWorking time of the hsu = " << n2 - n1 << endl;

	int q1 = GetTickCount();
	quicksort(qs, 0, n - 1);
	int q2 = GetTickCount();
	cout << "\nWorking time of the qsu = " << q2 - q1 << endl;

	int c1 = GetTickCount();
	Counting_Sort(couting_u, B, k);
	int c2 = GetTickCount();
	cout << "\nWorking time of the Couting sort_u = " << c2 - c1 << endl;
	
	delete[]Mass_u;
	delete[]ms;
	delete[]hs;
	delete[]qs;
	delete[]couting_u;
}

void sort_v(int *Array, int *B) {
	int *Mass_v = new int[n];
	for (int i = 0; i < n; i++)
		Mass_v[i] = Array[i];

	int *msv = new int[n];
	int *hsv = new int[n];
	int *qsv = new int[n];
	int *couting_v = new int[n];
	for (int i = 0; i < n; i++) {
		msv[i] = Mass_v[i];
		hsv[i] = Mass_v[i];
		qsv[i] = Mass_v[i];
		couting_v[i] = Mass_v[i];
	}
	int t3 = GetTickCount();
	insertion_sort(Mass_v, n);
	int t4 = GetTickCount();
	cout << "\nWorking time of the ISV = " << t4 - t3;

	int m3 = GetTickCount();
	MergeSort(msv, n);
	int m4 = GetTickCount();
	cout << "\nWorking time of the msv = " << m4 - m3 << endl;

	int n3 = GetTickCount();
	Heapsort(hsv);
	int n4 = GetTickCount();
	cout << "\nWorking time of the hsv = " << n4 - n3 << endl;

	int q3 = GetTickCount();
	quicksort(qsv, 0, n - 1);
	int q4 = GetTickCount();
	cout << "\nWorking time of the qsv = " << q4 - q3 << endl;

	int c1 = GetTickCount();
	Counting_Sort(couting_v, B, k);
	int c2 = GetTickCount();
	cout << "\nWorking time of the Couting sort_v = " << c2 - c1 << endl;
	delete[]Mass_v;
	delete[]msv;
	delete[]hsv;
	delete[]qsv;
	delete[]couting_v;
}

void Counting_Sort(int*Couting, int*B, int k)
{
	int *C = new int[k];
	for (int i = 0; i < k; i++)
		C[i] = 0;
	for (int j = 0; j < n; j++)
		C[Couting[j]] = C[Couting[j]] + 1;
	for (int i = 1; i < k; i++)
		C[i] = C[i] + C[i - 1];
	for (int j = n - 1; j >= 0; j--)
	{
		C[Couting[j]] = C[Couting[j]] - 1;
		B[C[Couting[j]]] = Couting[j];
	}
	delete[]C;
}