#include <stdio.h>
#include <conio.h>

#define MAX 15

int st[MAX];
int top = -1;

void push(int num){
	if(top == MAX-1){
		printf("\n STACK OVERFLOW");
	}
	else{
		top++;
		st[top] = num;
	}
}

int pop(int num){
	if(top == -1){
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else{
		num = st[top];
		top--;
		return num;
	}
}

void display(){
	int i;
	if(top == -1){
		printf("\n STACK IS EMPTY");
	}
	else{
		for(i=top;i>=0;i--){
			printf("\t %d",st[i]);
		}
	}
}

int main(void){
	// deret pada soal
	int deret[] = {60, 13, 83, 4, 21, 72, 11, 43, 99, 27, 54, 85};
	// mengisi deret sesuai dalam soal
	for(int i=sizeof(deret)/sizeof(deret[0])-1;i>=0;i--){
		push(deret[i]);
	}

	printf(" Stack :\n");
	display();
	printf("\n\n");
	printf(" Hapus stack\n");
	for(int i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		pop(deret[i]);
		printf("\n Elemen yang dihapus adalah %d\n", deret[i]);
		display();
		printf("\n");
	}
	printf("\n");
	printf(" Stack setelah dihapus :\n");
	display();
	return 0;
}
