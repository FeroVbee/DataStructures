#include <iostream>

using namespace std;
 
// Mendapatkan nilai max dari array.
int getMax(int arr[], int n)
{
	int max = arr[0]; // Inisialisasi nilai arr[0] adalah nilai max
	for (int i = 1; i < n; i++)
		if (arr[i] > max) // arr[n] merupakan nilai NULL
			max = arr[i];
	return max;
}
 
// Mengurutkan nilai arr[].
void countSort(int arr[], int n, int exp)
{
	// Count[i] array akan menghitung jumlah nilai array yang mempunyai angka 'i' pada tempat ke-(exp) mereka.  
	int output[n], i, count[10] = {0};
 
	// Menghitung berapa kali tiap digit terjadi tempat ke-(exp)th di setiap input.
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
 
	// Menghitung jumlah kumulatif mereka.
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 
	// Memasukkan nilai sesuai dengan digit '(arr [i] / exp)% 10' diambil ke dalam hitungan [(arr [i] / exp)% 10].
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
 
	// Menugaskan hasilnya ke pointer arr dari main ().
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
 
// Mengurutkan ukuran dari arr[] menggunakan Radix Sort.
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n); // memanggil fungsi getMax().
 
	// Memanggil countSort() untukk digit pada tempat ke-(exp) di setiap input.
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
 
int main()
{
	int n, i;
	cout<<"\nMasukkan banyak data yang hendak diurutkan: ";
	cin>>n; // Memasukan data ke n.
 	cout<<"\n";
	int arr[n]; 
	for(i = 0; i < n; i++)
	{
		cout<<"Masukkan data ke-"<<i+1<<": ";
		cin>>arr[i]; // nilai pertama diiisi di arr[0]
	}
 
	radixsort(arr, n); //Masuk fungsi radixsort
 
	// Printing the sorted data.
	cout<<"\nUrutan Data ";
	for (i = 0; i < n; i++)
		cout<<"->"<<arr[i];
	return 0;
}

/* PENJELASAN POGRAM :
	1. Ambil masukan data.
	2. Dapatkan input data maksimal.
	3. Jalankan countSort () sampai (m / exp)> 0.
	4. Urutkan data berdasarkan angka di (exp) tempat th.
	5. Tetapkan data diurutkan kembali ke arr [] array.
	6. Cek kondisi pada langkah 3.
	7. Jika salah, cetak output yang diurutkan.
	8. Keluar.
*/