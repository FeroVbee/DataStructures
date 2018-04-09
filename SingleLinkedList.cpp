// C++ Program : Single Linked List

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//Deklarasi Simpul
struct node {
	int info;
	struct node *next;
}*start;

//Deklarasi Class
class SingleLinkedList {
	public:
		node* create_node(int);
		void insert_begin();
		void insert_pos();
		void insert_last();
		void delete_pos();
		void sort();
		void search();
		void update();
		void reverse();
		void display();
		SingleLinkedList(){
			start = NULL;
		}
};

//Main : Isi Menu
main() {
	int pilih, nodes, element, posisi, i;
	SingleLinkedList sl;
	start = NULL;
	
	while(1)
	{
		cout<<endl<<"-------------------------------"<<endl;
		cout<<endl<<"Operasi pada LinkedList Tunggal"<<endl;
		cout<<endl<<"-------------------------------"<<endl;
		cout<<" 1. Masukkan node di awal"<<endl;
		cout<<" 2. Masukkan node di akhir"<<endl;
		cout<<" 3. Masukkan node di posisi x"<<endl;
		cout<<" 4. Sortir linked list"<<endl;
		cout<<" 5. Hapus node tertentu"<<endl;
		cout<<" 6. Update nilai node"<<endl;
		cout<<" 7. Cari Elemen"<<endl;
		cout<<" 8. Tampilkan linked list"<<endl;
		cout<<" 9. Balik linked list"<<endl;
		cout<<"10. Keluar"<<endl;
		cout<<endl<<"Masukkan kode anda : ";
		cin>>pilih;
		switch(pilih)
		{
			case 1:
				cout<<"Memasukan node di awal : "<<endl;
				sl.insert_begin();
				cout<<endl;
				break;
			case 2:
				cout<<"Memasukan node di akhir : "<<endl;
				sl.insert_last();
				cout<<endl;
				break;
			case 3:
				cout<<"Memasukan node di posisi x : "<<endl;
				sl.insert_pos();
				cout<<endl;
				break;
			case 4:
				cout<<"Menyortir linked list : "<<endl;
				sl.sort();
				cout<<endl;
				break;
			case 5:
				cout<<"Menghapus node tertentu : "<<endl;
				sl.delete_pos();
				break;
			case 6:
				cout<<"Mengupdate nilai node : "<<endl;
				sl.update();
				break;
			case 7:
				cout<<"Mencari elemen di Linked List : "<<endl;
				sl.search();
				break;
			case 8:
				cout<<"Menampilkan elemen dari Linked list..."<<endl;
				sl.display();
				break;
			case 9:
				cout<<"Membalik elemen dari linked list... "<<endl;
				sl.reverse();
				break;
			case 10:
				cout<<"Keluar..."<<endl;
				exit(1);
				break;
			default:
				cout<<"Pilihan salah..."<<endl;
		}
	}
}

//Membuat node
node *SingleLinkedList::create_node(int value){
	struct node *temp, *s;
	temp= new(struct node);
	if (temp == NULL){
		cout<<"Memory tidak dialoasikan"<<endl;
		return 0;
	} else {
		temp -> info = value;
		temp -> next = NULL;
		return temp;
	}
}

//Memasukkan element di awal
void SingleLinkedList::insert_begin(){
	int value;
	cout<<"Input nilai yang ingin dimasukkan : ";
	cin>>value;
	struct node *temp, *p;
	temp = create_node(value);
	if (start == NULL){
		start = temp;
		start -> next = NULL;
	} else {
		p = start;
		start = temp;
		start -> next = p;
	}
	cout<<"Elemen telah dimasukkan di awal"<<endl;
}

//Memasukan elemen di akhir
void SingleLinkedList::insert_last(){
	int value;
	cout<<"Input nilai yang ingin dimasukkan : ";
	cin>>value;
	struct node *temp, *s;
	temp = create_node(value);
	s = start;
	while (s->next != NULL){
		s=s->next;
	}
	temp -> next = NULL;
	s -> next = temp;
	cout<<"Elemen telah dimasukkan di akhir"<<endl;
}

//Memasukan Node di posisi yang diinginkan
void SingleLinkedList::insert_pos(){
	int value, pos, counter=0;
	cout<<"Input nilai yang ingin dimasukkan : ";
	cin>>value;
	struct node *temp, *s, *ptr;
	temp = create_node(value);
	cout<<"Input posis yang mana node ingin di masukan : ";
	cin>>pos;
	int i;
	s = start;
	while ( s != NULL){
		s = s-> next;
		counter++;
	}
	if (pos == 1){
		if (start == NULL){
			start = temp;
			start -> next = NULL;
		} else {
			ptr = start;
			start = temp;
			start -> next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter){
		s = start;
		for ( i=1; i<pos; i++){
			ptr=s;
			s = s-> next;
		}
		ptr -> next = temp;
		temp -> next = s;
	}
	else {
		cout<<"Posisi diluar jangkauan"<<endl;
	}
}

//Menyortir Linked list
void SingleLinkedList::sort(){
	struct node *ptr, *s;
	int value;
	if (start == NULL){
		cout<<"List Kosong"<<endl;
		return;
	}
	ptr = start;
	while (ptr != NULL)
	{
		for (s=ptr->next; s!=NULL; s=s->next){
			if (ptr->info > s->info){
				value = ptr -> info;
				ptr -> info = s->info;
				s->info= value;
			}
		}
		ptr = ptr->next;
	}
}

//Menghapus elemet di posisi tertentu
void SingleLinkedList::delete_pos(){
	int pos, i, counter = 0;
	if (start == NULL){
		cout<<"List Kosong"<<endl;
		return;
	}
	cout<<"Input posisi nilai yang akan dihapus : ";
	cin>>pos;
	struct node *s, *ptr;
	s =start;
	if (pos == 1){
		start = s->next;
	} else {
		while (s != NULL){
			s = s->next;
			counter++;
		}
		if (pos > 0 && pos <=counter){
			s=start;
			for (i=1; i<pos; i++){
				ptr = s;
				s=s->next;
			}
			ptr->next = s->next;
		}
		else {
			cout<<"Posisi diluar jangkauan"<<endl;
		}
		free(s);
		cout<<"Element terhapus"<<endl;
	}
}

//Mengupdate nilai tertentu
void SingleLinkedList::update(){
	int value, pos, i;
	if (start== NULL){
		cout<<"List kosong"<<endl;
		return;
	}
	cout<<"Input posisi node yang ingin diperbarui : ";
	cin>>pos;
	cout<<"Input nilai baru : ";
	cin>>value;
	struct node *s, *ptr;
	s=start;
	if (pos==1){
		start->info = value;
	}
	else {
		for (i=0; i<pos-1; i++){
			if (s==NULL){
				cout<<"Ada kurang dari "<<pos<<" elemen";
				return;
			}
			s=s->next;
		}
		s->info= value;
	}
	cout<<"Node Diperbaharui"<<endl;
}

//Mencari Sebuah elemen
void SingleLinkedList::search(){
	int value, pos=0;
	bool flag = false;
	if(start==NULL){
		cout<<"List kosong"<<endl;
		return;
	}
	cout<<"Input nilai yang ingin dicari : ";
	cin>>value;
	struct node *s;
	s=start;
	while(s!= NULL){
		pos++;
		if(s->info == value){
			flag= true;
			cout<<"elemen "<<value<<" ditemukan di posisi "<<pos<<endl;
		}
		s=s->next;
	}
	if (!flag)
		cout<<"Elemen "<<value<<" tidak ditemukan di list"<<endl;
}

//Membalik Linked list
void SingleLinkedList::reverse(){
	struct node *ptr1, *ptr2, *ptr3;
	if (start == NULL){
		cout<<"List kosong"<<endl;
		return;
	}
	if (start->next == NULL){
		return;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next=NULL;
	ptr2->next=ptr1;
	while(ptr3 != NULL){
		ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
	}
	start = ptr2;
}

//Menampilkan element dari linked list
void SingleLinkedList::display(){
	struct node *temp;
	if (start == NULL){
		cout<<"List kosong"<<endl;
		return;
	}
	temp = start;
	cout<<"Elemen dari list antara lain : "<<endl;
	while (temp != NULL){
		cout<<temp->info<<" -> ";
		temp = temp -> next;
	}
	cout<<"NULL"<<endl;
}

			