#include<iostream>
using namespace std;
struct List{
	int key;
	List *prev;
	List *next;
};
void Insert(List *&head, int v);
List *Search(List * head, int v);
void Delete(List *&head, int v);
void Print(List *head);
int main(){
	List *head = NULL;
	int v = 0;
	Insert(head, 70);
	Insert(head, 50);
	Insert(head, 60);
	Insert(head, 20);
	Insert(head, 40);
	Print(head);
	cout << endl;
	Delete(head, 20);
	Delete(head, 40);
	Search(head, 70);
	Delete(head, 60);
	Delete(head, 50);
	Delete(head, 70);
	Print(head);
	cin.get();
	cin.get();
}
void Insert(List *&head, int v){
	List *x = new List;
	x->key = v;
	x->prev = NULL;
	x->next = head;
	if (head != NULL)
		head->prev = x;
	head = x;
}
List *Search(List * head, int v){
	List *x = head;
	while (x != NULL && x->key != v)
		x = x->next;
	return x;
}
void Delete(List *&head, int v){
	List *x = new List;
	x = Search(head, v);
	if (x != NULL){
		if (x->prev != NULL)
			x->prev->next = x->next;
		else
			head = head->next;
		if (x->next != NULL)
			x->next->prev = x->prev;
		delete x;
	}
}
void Print(List *head){
	List *x = head;
	while (x != NULL){
		cout << x->key << " ";
		x = x->next;
	}
}