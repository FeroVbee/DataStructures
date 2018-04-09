// C++ Program to Implement Doubly Linked List

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>

using namespace std;
int i=2, prima=1; //for number 4

//Deklarasi Class
class Rekursif {
	public:
		void dataDsc(int n);
		void dataAsc(int n, int a);
		void checkX();
		void checkPrima(int n);
};

//Main : Daftar menu
int main(){
	short choice,nilai;
	Rekursif r;
	while (1){
		cout<<endl<<"----------------------------"<<endl;
		cout<<endl<<"     Percobaan Rekursif     "<<endl;
		cout<<endl<<"----------------------------"<<endl;
		cout<<" 1. Urutkan data dari n ke 0"<<endl;
		cout<<" 2. Urutkan data dari 0 ke n"<<endl;
		cout<<" 3. Check x pada array a[n]"<<endl;
		cout<<" 4. Check bilangan prima"<<endl;
		cout<<" 5. Exit"<<endl;
		cout<<endl<<"Masukkan kode pilihan : ";
		cin>>choice;
switch(choice)
		{
			case 1:
				cout<<endl<<"Masukan nilai n : "; cin>>nilai;
				cout<<endl; r.dataDsc(nilai); cout<<endl;
				getch(); system("cls");
				break;
			case 2:
				cout<<endl<<"Masukan nilai n : "; cin>>nilai;
				cout<<endl; r.dataAsc(nilai,0); cout<<endl;
				getch(); system("cls");
				break;
			case 3:
				//BELUM
				break;
			case 4:
				cout<<endl<<"Masukan bilangan prima : "; cin>>nilai;
				cout<<endl; r.checkPrima(nilai); cout<<endl;
				getch(); system("cls");
				//BELEM SEMPURNA
				break;
			case 5:
				exit(1);
			default: cout<<"!!kode masukan tidak tepat!!"<<endl;
					getch(); system("cls");
		}			
	} return 0;
}

//Answer of number 1
void Rekursif::dataDsc(int n){
	if (n >= 0){
		cout<<" "<<n<<" ";
		Rekursif::dataDsc(n-1);
	}
}
//Answer of number 2
void Rekursif::dataAsc(int n, int a){
	if ( n >= 0){
		cout<<" "<<a<<" ";
		Rekursif::dataAsc(n-1,a+1);
	}
}
//Answer of number 3
void Rekursif::checkX(){
	
}
//Answer of number 4
void Rekursif::checkPrima(int n){
	if ( i<n ){
		if (n%i == 0) {
			prima=0;
			cout<<n<<" bukan merupakan bil prima";
		}
		i++;
		Rekursif::checkPrima(n);
	}
}
