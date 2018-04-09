// C++ Program to Implement Stack

#include<iostream>
#include<cstdlib>

using namespace std;

//Deklarasi node
struct node{
	int info;
	struct node *link;
}*top;

//Deklarasi class
class stack_list {
	public:
		node *push(node *, int);
		node *pop(node *);
		void traverse(node *);
		stack_list(){
			top= NULL;
		}
};

//Main : Daftar Menu
int main(){
	int choice, item;
	stack_list sl;
	while (1) {
		cout<<endl<<"----------------------------"<<endl;
		cout<<endl<<"       Operasi Stack        "<<endl;
		cout<<endl<<"----------------------------"<<endl;
		cout<<" 1. Push Elemen kedalam stack"<<endl;
		cout<<" 2. Pop Elemen dari Stack"<<endl;
		cout<<" 3. Tampilkan isi Stack"<<endl;
		cout<<" 4. Exit"<<endl;
		cout<<endl<<"Masukkan kode pilihan : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Masukkan nilai input : ";
				cin>>item;
				top = sl.push(top,item);
				break;
			case 2:
				top = sl.pop(top);
				break;
			case 3:
				sl.traverse(top);
				break;
			case 4:
				exit(1);
				break
			default:
				cout<<"!!Kode Masukan Tidak Tepat!!";
			}
	}
	return 0;
}

//Push Elemen kedalam Stack
node *stack_list::push(node *top, int item){
	node *tmp;
	tmp = new(struct node);
	tmp->info = item;
	tmp->link = top;
	top = tmp;
	return top;
}

//Pop Elemen dari Stack
node *stack_list::pop(node *top){
	node *tmp;
	if (top == NULL)
		cout<<"!!Stack Kosong!!"<<endl;
	else{
		tmp=top;
		cout<<"Elemen "<<tmp->info<<" Terambil"<<endl;
		top=top->link;
		delete(tmp);
	}
	return top;
}

//Menampilkan isi Stack
void stack_list::traverse(node *top){
	node *ptr;
	ptr=top;
	if (top == NULL)
		cout<<"!!Stack Kosong!!"<<endl;
	else{
		cout<<"Elemen Stack : "<<endl;
		while(ptr != NULL){
			cout<<ptr->info<<endl;
			ptr=ptr->link;
		}
	}
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		