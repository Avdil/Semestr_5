#include<iostream>
using namespace std;
struct Tree{
	int key;
	Tree *parent;
	Tree *left;
	Tree *right;
	char color;
};
Tree *nil;
void Left_R(Tree *&T, Tree *x);
void Right_R(Tree *&T, Tree *x);
void RB_Insert(Tree *&T, int v);
void Transplant(Tree *&T, Tree *u, Tree *v);
Tree *Search(Tree *T, int v);
Tree *Min(Tree *T);
void RB_Delete(Tree *&T, int v);
void Print(Tree *T);

void main(){
	nil = new Tree;
	nil->left = nil;
	nil->right = nil;
	nil->parent = nil;
	nil->color = 'b';
	Tree *T = nil;
	RB_Insert(T, 70);
	RB_Insert(T, 50);
	RB_Insert(T, 90);
	RB_Insert(T, 20);
	RB_Insert(T, 86);
	RB_Insert(T, 60);
	RB_Insert(T, 100);
	RB_Insert(T, 88);
	RB_Insert(T, 87);
	cout << "All elements the trees: ";
	Print(T);
	cout << endl;
	RB_Delete(T, 50);
	RB_Delete(T, 86);
	RB_Delete(T, 70);
	RB_Delete(T, 100);
	cout << "All elements the trees (delete): ";
	Print(T);
	cout << endl;
	cin.get();
	cin.get();
}
void Left_R(Tree *&T, Tree *x){
	Tree *y = x->right;
	x->right = y->left;
	if (y->left != nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		T = y;
	else{
		if (x == x->parent->left)
			x->parent->left = y;
		else x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}
void Right_R(Tree *&T, Tree *x){
	Tree *y = x->left;
	x->left = y->right;
	if (y->right != nil)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == nil)
		T = y;
	else{
		if (x == x->parent->right)
			x->parent->right = y;
		else x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}
void RB_Insert(Tree *&T, int v){
	Tree *x = T, *y = nil;
	Tree *z = new Tree;
	z->left = nil; z->right = nil; z->key = v; z->color = 'r';
	while (x != nil){
		y = x;
		if (v <= x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == nil)
		T = z;
	else{
		if (z->key <= y->key)
			y->left = z;
		else
			y->right = z;
	}
	while (z->parent->color == 'r'){
		if (z->parent == z->parent->parent->left){
			Tree *y = z->parent->parent->right;
			if (y->color == 'r'){
				z->parent->color = 'b';
				y->color = 'b';
				z->parent->parent->color = 'r';
				z = z->parent->parent;
			}
			else{
				if (z == z->parent->right){
					z = z->parent;
					Left_R(T, z);
				}
				z->parent->color = 'b';
				z->parent->parent->color = 'r';
				Right_R(T, z->parent->parent);
			}
		}
		else{
			Tree *y = z->parent->parent->left;
			if (y->color == 'r'){
				z->parent->color = 'b';
				y->color = 'b';
				z->parent->parent->color = 'r';
				z = z->parent->parent;
			}
			else{
				if (z == z->parent->left){
					z = z->parent;
					Right_R(T, z);
				}
				z->parent->color = 'b';
				z->parent->parent->color = 'r';
				Left_R(T, z->parent->parent);
			}
		}
	}
	T->color = 'b';
}
void Transplant(Tree *&T, Tree *u, Tree *v){
	v->parent = u->parent;
	if (u->parent == nil)
		T = v;
	else{
		if (u->parent->left == u)
			u->parent->left = v;
		else
			u->parent->right = v;
	}
}
Tree *Search(Tree *T, int v){
	Tree *x = T;
	while (x != nil && x->key != v){
		if (v < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}
Tree *Min(Tree *T){
	Tree *x = T;
	while (x->left != nil){
		x = x->left;
	}
	//cout << x->key;
	return x;
}
void RB_Delete(Tree *&T, int v){
	Tree *z = Search(T, v);
	Tree *y = z;
	Tree *x;
	char y_or_col = y->color;
	if (z != nil){
		if (z->left == nil) {
			x = y->right;
			Transplant(T, z, z->right);
		}
		else if (z->right == nil) {
			x = y->left;
			Transplant(T, z, z->left);
		}
		else {
			y = Min(z->right);
			y_or_col = y->color;
			x = y->right;
			if (y->parent != z) {
				Transplant(T, y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			y->left = z->left;
			y->left->parent = y;
			Transplant(T, z, y);
			y->color = z->color;
		}
		if (y_or_col == 'b'){
			while (x != T && x->color == 'b'){
				if (x == x->parent->left){
					Tree *w = x->parent->right;
					if (w->color == 'r'){
						w->color = 'b';
						x->parent->color = 'r';
						Left_R(T, x->parent);
						w = x->parent->right;
					}
					if (w->right->color == 'b' && w->left->color == 'b'){
						w->color = 'r';
						x = x->parent;
					}
					else{
						if (w->right->color == 'b'){
							w->color = 'r';
							w->left->color = 'b';
							Right_R(T, w);
						}
						w->color = w->parent->color;
						x->parent->color = 'b';
						w->right->color = 'b';
						Left_R(T, x->parent);
						x = T;
					}
				}
				else{
					Tree *w = x->parent->left;
					if (w->color == 'r'){
						w->color = 'b';
						x->parent->color = 'r';
						Left_R(T, x->parent);
						w = x->parent->left;
					}
					if (w->left->color == 'b' && w->right->color == 'b'){
						w->color = 'r';
						x = x->parent;
					}
					else{
						if (w->left->color == 'b'){
							w->color = 'r';
							w->right->color = 'b';
							Right_R(T, w);
						}
						w->color = w->parent->color;
						x->parent->color = 'b';
						w->left->color = 'b';
						Left_R(T, x->parent);
						x = T;
					}
				}
			}
			x->color = 'b';
		}
	}
}
void Print(Tree *T){
	Tree *x = T;
	if (x != nil){
		Print(x->left);
		cout << x->key << x->color << " ";
		Print(x->right);
	}
}
