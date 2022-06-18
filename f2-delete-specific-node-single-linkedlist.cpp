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
void cariDanHapus(int num){
	// pointer aktif (curr) dimulai dari head
	curr = head;
	/* selama curr belum menunjuk ke isi deret yang akan dihapus,
	maka temp menunjuk node tepat sebelum curr */
	while(curr && curr->num != num){
		temp = curr;
		curr = curr->next;
	}
	/* ketika curr menunjuk ke isi deret yang akan dihapus,
	maka temp menunjuk node tepat setelah curr,
	atau "melompati" curr */
	temp->next = curr->next;
	// dan isi deret tersebut dihapus
	free(curr);
}

// fungsi utama
int main(void){
	// deret pada soal
	int deret[] = {12, 78, 53, 11, 72, 20, 99, 36, 13, 48, 23, 71, 15};
	int i = 0;
	// mengisi deret sesuai dalam soal
	for(i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		isikan(deret[i]);
	}
	printf("Deret :\n");
	tampilkan();
	printf("\n");
	printf("Hapus 11 dari deret\n");
	cariDanHapus(11);
	printf("\n");
	printf("Deret setelah 11 dihapus :\n");
	tampilkan();
	return 0;
}
