// C++ Program to Implement Doubly Linked List

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>

//Deklarasi node
using namespace std;
struct node {
	int data;
	struct node *next;
	struct node *prev;
}*head, *tail ;

//Deklarasi Class
class DoubleLinkedList {
	public:
		void create_list(int value);
		void add_begin(int value);
		void add_last(int value);
		void add_before(int value, int pos);
		void add_after(int value, int pos);
		void del_pos(int pos);
		void del_begin();
		void del_last();
		void del_before(int pos);
		void del_after(int pos);
		void display_list();
		DoubleLinkedList(){
			head=tail=NULL;
		}
};

//Main : Daftar menu
int main(){
	short choice;
	int element, position;
	DoubleLinkedList dl;
	while (1){
		cout<<endl<<"----------------------------"<<endl;
		cout<<endl<<" Operasi Double Linked List "<<endl;
		cout<<endl<<"----------------------------"<<endl;
		cout<<" 1. Tampilkan Double Linked List"<<endl;
		cout<<" 2. Buat linked list"<<endl;
		cout<<" 3. Tambah node di awal"<<endl;
		cout<<" 4. Tambah node di akhir"<<endl;
		cout<<" 5. Tambah node sebelum"<<endl;
		cout<<" 6. Tambah node sesudah"<<endl;
		cout<<" 7. Hapus node di posisi x"<<endl;
		cout<<" 8. Hapus node di awal"<<endl;
		cout<<" 9. Hapus node di akhir"<<endl;
		cout<<"10. Hapus node sebelum"<<endl;
		cout<<"11. Hapus node sesudah"<<endl;
		cout<<"12. Exit"<<endl;
		cout<<endl<<"Masukkan kode pilihan : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				dl.display_list();
				cout<<endl;
				break;
			case 2:
				cout<<">> Membuat Linked List... <<"<<endl;
				cout<<"Masukan nilai data : "; cin>>element;
				dl.create_list(element);
				cout<<endl;
				break;
			case 3:
				cout<<">> Menambahkan node di awal... <<"<<endl;
				cout<<"Masukkan nilai data : "; cin>>element;
				dl.add_begin(element);
				cout<<endl;
				break;
			case 4:
				cout<<">> Menambahkan node di akhir... <<"<<endl;
				cout<<"Masukkan nilai data : "; cin>>element;
				dl.add_last(element);
				cout<<endl;
				break;
			case 5:
				cout<<">> Menambahan node sebelum... <<"<<endl;
				cout<<"Masukkan nilai data : "; cin>>element;
				cout<<"Masukan posisi	   : "; cin>>position;
				dl.add_before(element,position);
				cout<<endl;
				break;
			case 6:
				cout<<">> Menambahkan node sesudah... <<"<<endl;
				cout<<"Masukkan nilai data : "; cin>>element;
				cout<<"Masukan posisi	   : "; cin>>position;
				dl.add_after(element,position);
				cout<<endl;
				break;
			case 7:
				if (head == NULL){
					cout<<"!! Daftar kosong !!"; break;
				}
				cout<<">> Menghapus node di posisi x...<<"<<endl;
				cout<<"Masukan posisi	   : "; cin>>position;
				dl.del_pos(position);
				cout<<endl;
				break;
			case 8:
				if (head == NULL){
					cout<<"!! Daftar kosong !!"; break;
				}
				cout<<">> Menghapus node awal...<<"<<endl;
				dl.del_begin();
				cout<<endl;
				break;
			case 9:
				if (head == NULL){
					cout<<"!! Daftar kosong !!"; break;
				}
				cout<<">> Menghapus node akhir...<<"<<endl;
				dl.del_last();
				cout<<endl;
				break;
			case 10:
				if (head == NULL){
					cout<<"!! Daftar kosong !!"; break;
				}
				cout<<">> Menghapus node sebelum...<<"<<endl;
				cout<<"Masukan posisi	   : "; cin>>position;
				dl.del_before(position);
				cout<<endl;
				break;
			case 11:
				if (head == NULL){
					cout<<"!! Daftar kosong !!"; break;
				}
				cout<<">> Menghapus node sesudah...<<"<<endl;
				cout<<"Masukan posisi	   : "; cin>>position;
				dl.del_after(position);
				cout<<endl;
				break;
			case 12:
				exit(1);
			default: cout<<"!!kode masukan tidak tepat!!"<<endl;
		}
	} return 0;
}

//Membuat Double Linked List
void DoubleLinkedList::create_list(int value){
	struct node *temp;
	temp=new(struct node);
	temp->data = value;
	temp->next = NULL;
	if (head== NULL){
		temp->prev = NULL;
		head=tail=temp;
	} else {
		tail = head;
		while (tail->next != NULL)
			tail= tail->next;
		tail->next = temp;
		temp->prev = tail;
	}
}

//Menambahan node di awal
void DoubleLinkedList::add_begin(int value){
	if (head==NULL) {
		cout<<"!!Buat Linked list terlebih dahulu!!"<<endl;
		return;
	}
	struct node *temp;
	temp = new(struct node);
	temp->prev=NULL; temp->data=value; temp->next=head;
	head->prev=temp; head=temp; 
	cout<<">> Data telah Ditambahkan <<"<<endl;
}

//Menambahan node di akhir
void DoubleLinkedList::add_last(int value){
	if (head==NULL) {
		cout<<"!!Buat Linked list terlebih dahulu!!"<<endl;
		return;
	}
	struct node *temp;
	temp = new(struct node);
	tail = head;
	while (tail->next != NULL){
		tail=tail->next;
	}
	temp->prev=tail; temp->data=value; temp->next=NULL;
	tail->next=temp; tail=temp;
	cout<<">> Data telah ditambahkan <<"<<endl;
}

//Menambahkan node sebelum
void DoubleLinkedList::add_before(int value, int pos){
	if (head==NULL){
		cout<<"!!!Buat Linked List terlebih dahulu!!"<<endl;
		return;
	}
	struct node *temp, *q;
	int i;
	q = head;
	for(i=0; i<pos-1; i++)
	{
		q = q->next;
		if (q == NULL){
			cout<<"kurang dari "<<pos<<" data"<<endl;
			return;
		}
	}
	temp=new(struct node);
	temp->data=value;
	if(q->prev==NULL){
		q->prev=temp;
		temp->prev = NULL;
		temp->next = q;
	} else {
		temp->next = q;
		q->prev->next =temp;
		temp->prev=q->prev;
		temp->next->prev=temp;		
	}
	cout<<">> Data telah ditambahkan <<"<<endl;
}

//Menambahkan node sesudah
void DoubleLinkedList::add_after(int value, int pos){
	if (head==NULL){
		cout<<"!!Buat Linked List terlebih dahulu!!"<<endl;
		return;
	}
	struct node *temp, *q;
	int i;
	q = head;
	for(i=0; i<pos-1; i++){
		q = q->next;
		if (q == NULL){
			cout<<"kurang dari "<<pos<<" data"<<endl;
			return;
		}
	}
	temp=new(struct node);
	temp->data=value;
	if(q->next==NULL){
		q->next=temp;
		temp->next = NULL;
		temp->prev = q;
	} else {
		temp->next=q-> next;
		temp->next->prev = temp;
		q->next = temp;
		temp->prev = q;
	}
	cout<<">> Data telah ditambahkan <<"<<endl;
}

//Menghapus node posisi x
void DoubleLinkedList::del_pos(int pos){
	struct node *q; int i;
	q=head;
	if (pos==1){
		head=q->next; head->prev=NULL;
	} else {
		for(i=0; i<pos-1; i++){
			q= q->next;
			if (q == NULL){
				cout<<"kurang dari "<<pos<<" data"<<endl;
				return;
			}	
		}
		q->prev->next=q->next;
		q->next->prev=q->prev;
	}
	free(q);
	cout<<">> Data posisi "<<pos<<" telah dihapus <<"<<endl;
}

//Menghapus node di awal
void DoubleLinkedList::del_begin(){
	struct node *q;
	q=head;
	head=q->next;
	head->prev=NULL;
	free(q);
	cout<<">> Data posisi awal telah dihapus <<"<<endl;
}

//Menghapus node di akhir
void DoubleLinkedList::del_last(){
	struct node *q;
	q=tail;
	tail=q->prev;
	tail->next=NULL;
	free(q);
	cout<<">> Data posisi akhir telah dihapus <<"<<endl;
}

//Menghapus node sebelum
void DoubleLinkedList::del_before(int pos){
	struct node *q, *p; int i;
	q=head;
	if (pos==1){
		head=q->next; head->prev=NULL;
	} else {
		for(i=0; i<pos-1; i++){
			q= q->next;
			if (q == NULL){
				cout<<"kurang dari "<<pos<<" data"<<endl;
				return;
			}	
		}
		p=q->prev;
		p->prev->next=q;
		q->prev=p->prev;
	}
	free(p);
	cout<<">> Data posisi "<<pos-1<<" telah dihapus <<"<<endl;
	
}

//Menghapus node sesudah
void DoubleLinkedList::del_after(int pos){
	struct node *q, *n; int i;
	q=head;
	if (pos==1){
		head=q->next; head->prev=NULL;
	} else {
		for(i=0; i<pos-1; i++){
			q= q->next;
			if (q == NULL){
				cout<<"kurang dari "<<pos<<" data"<<endl;
				return;
			}	
		}
		n=q->next;
		q->next=n->next;
		n->next->prev=q;
	}
	free(n);
	cout<<">> Data posisi "<<pos+1<<" telah dihapus <<"<<endl;
}

//Menampilkan linked list
void DoubleLinkedList::display_list(){
	struct node *x;
	if (head == NULL) {
		cout<<"!!List Kosongan, nothing to display!!"<<endl;
		return;
	}
	x=head;
	cout<<"Double Linked list : "<<endl;
	while (x != NULL) {
		cout<<x->data<<" <-> ";
		x = x->next;
	}
	cout<<"NULL"<<endl;
	getch();
	system("cls");
}



































