#include<iostream>
using namespace std;
struct Tree{
	int key;
	Tree *parent;
	Tree *left;
	Tree *right;
};
void Insert(Tree *&T, int v);
Tree *Search(Tree *T, int v);
void Print(Tree *T);
Tree *Min(Tree *T);
//Tree *Max(Tree *T, Tree *x);
Tree *Successor(Tree *T, int v);
void Transplant(Tree *&T, Tree *u, Tree *v);
void Delete(Tree *&T, int v);
void main(){
	Tree *T = NULL;
	Tree *x = Search(T, 50);
	int v = 0;
	Insert(T, 70);
	Insert(T, 50);
	Insert(T, 90);
	Insert(T, 20);
	Insert(T, 86);
	Insert(T, 60);
	Insert(T, 100);
	cout << "All elements the trees: ";
	Print(T);
	cout << endl;
	cout<< "Input element: " << Successor(T, 50)->key;
	cout << endl;
	Delete(T, 86);
	cout << "Trees after delete element: ";
	Print(T);
	/*Search(T, 60);
	cout << endl;
	Print(T);*/
	//cout << Min(T, x) << "\n";
	//cout << Max(T);
	cin.get();
	cin.get();
}
void Insert(Tree *&T, int v){
	Tree *x = T, *y = NULL;
	Tree *z = new Tree;
	z->left = NULL; z->right = NULL; z->key = v;
	while (x != NULL){
		y = x;
		if (v <= x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
		T = z;
	else{
		if (z->key <= y->key)
			y->left = z;
		else
			y->right = z;
	}
}
Tree *Search(Tree *T, int v){
	Tree *x = T;
	while (x != NULL && x->key != v){
		if (v < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}
void Print(Tree *T){
	Tree *x = T;
	if (x != NULL){
		Print(x->left);
		cout << x->key << " ";
		Print(x->right);
	}
}
Tree *Min(Tree *T){
	Tree *x = T;
	while (x->left != NULL){
		x = x->left;
	}
	//cout << x->key;
	return x;
}
//Tree *Max(Tree *T, Tree *x){
//	x = T;
//	int max = 0;
//	while (x->right != NULL){
//		if (x->key >= max)
//			x = x->right;
//	}
//	return x;
//}
Tree *Successor(Tree *T, int v){
	Tree *x = Search(T, v);
	if (x->right != NULL)
		return Min(x->right);
	else{
		Tree *y = x->parent;
		while (y != NULL && x == y->right){
			x = y;
			y = y->parent;
		}
		return y;
	}
}
void Transplant(Tree *&T, Tree *u, Tree *v){
	if (v != NULL)
		v->parent = u->parent;
	if (u->parent == NULL)
		T = v;
	else{
		if (u->parent->left == u)
			u->parent->left = v;
		else
			u->parent->right = v;
	}
}
void Delete(Tree *&T, int v){
	Tree *z = Search(T, v);
	if (z != NULL){
		if (z->left == NULL)
			Transplant(T, z, z->right);
		else if (z->right == NULL)
			Transplant(T, z, z->left);
		else {
			Tree *y = Min(z->right);
			if (y->parent != z) {
				Transplant(T, y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			y->left = z->left;
			y->left->parent = y;
			Transplant(T, z, y);
		}
	}
}