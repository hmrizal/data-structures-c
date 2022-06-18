#include <stdio.h>
#include <stdlib.h>

// buat deret sebagai sebuah single linked list
struct linkedList{
	int num;
	struct linkedList *next;
}*head, *tail, *curr, *temp; // pointer variable

// fungsi untuk menampilkan deret
void tampilkan(void){
	int i = 0;
	curr = head;
	while(curr){
		i++;
		printf("(%d) = %d\n", i, curr->num);
		curr = curr->next;
	}
}

// fungsi untuk mengisi deret
void isikan(int num){
	// alokasi memori untuk node baru tiap mengisi deret
	curr = (struct linkedList*)malloc(sizeof(struct linkedList));
	// mengisi deret
	curr->num = num;
	/* jika deret kosong,
	maka head dan tail menunjuk ke node baru */
	if(head==NULL){
		head = tail = curr;
	}
	/* jika deret sudah terisi,
	masukkan node baru setelah tail */
	else{
		tail->next = curr;
		tail = curr;
	}
	// tail menunjuk ke NULL, karena data terakhir
	tail->next = NULL;
}

// fungsi untuk mencari dan menghapus isi deret
void hapusHead(){
	if(head == NULL){
		printf("Deret kosong\n");
	}
	else{
		temp = head;
		head = head->next;
		free(temp);
	}
}

// fungsi utama
int main(void){
	// deret pada soal
	int deret[] = {90, 12, 37, 81, 20, 45, 71, 3, 66, 103, 29, 47, 8, 10, 92, 41};
	int i = 0;
	// mengisi deret sesuai dalam soal
	for(i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		isikan(deret[i]);
	}
	printf("Deret :\n");
	tampilkan();
	printf("\n");
	printf("Hapus Head dari deret\n");
	hapusHead();
	printf("\n");
	printf("Deret setelah head dihapus :\n");
	tampilkan();
	return 0;
}
