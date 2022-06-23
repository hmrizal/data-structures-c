#include <stdio.h>
#include <stdlib.h>

// buat deret sebagai sebuah double linked list
struct linkedList{
	struct linkedList *prev;
	int num;
	struct linkedList *next;
}*head, *tail, *curr; // pointer variable

// fungsi untuk menampilkan deret
void tampilkan(){
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
		curr->prev = tail;
		tail->next = curr;
		tail = curr;
	}
	// tail dan head menunjuk ke NULL, karena data terakhir
	head->prev = NULL;
	tail->next = NULL;
}

// fungsi untuk menghapus tail
void hapusTail(){
	// jika head = NULL, otomatis deret kosong
	if(head == NULL){
		printf("Deret kosong\n");
	}
	// menghapus tail 
	else{
		tail = tail->prev;
		free(curr);
		tail->next = NULL;
	}
}

// fungsi utama
int main(void){
	// deret pada soal
	int deret[] = {23, 45, 79, 3, 47, 11, 92, 60, 39, 28, 6, 72, 13, 28};
	int i = 0;
	// mengisi deret sesuai dalam soal
	for(i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		isikan(deret[i]);
	}
	printf("Deret :\n");
	tampilkan();
	printf("\n");
	printf("Hapus Tail dari deret\n");
	hapusTail();
	printf("\n");
	printf("Deret setelah tail dihapus :\n");
	tampilkan();
	return 0;
}
