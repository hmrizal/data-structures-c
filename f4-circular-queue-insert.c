#include <stdio.h>
#include <conio.h>

#define MAX 15

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int num){
	if(front==0 && rear == MAX-1){
		printf("\n OVERFLOW");
	}
	else if(front == -1 && rear== -1){
		front=rear=0;
		queue[rear]=num;
	}
	else if(rear==MAX-1 && front!=0){
		rear=0;
		queue[rear]=num;
	}
	else{
		rear++;
		queue[rear]=num;
	}
}

void display(){
	int i;
	printf("\n");
	if(front == -1 && rear == -1){
		printf("\n QUEUE IS EMPTY");
	}
	else{
		if(front<rear){
			for(i = front;i <= rear;i++){
				printf("\t %d", queue[i]);
			}
		}
		else{
			for(i = front;i < MAX;i++){
				printf("\t %d", queue[i]);
			}
			for(i = 0;i <= rear;i++){
				printf("\t %d", queue[i]);
			}
		}
	}
}

int main(void){
	// deret pada soal
	int deret[] = {7, 19, 72, 44, 62, 10, 9, 34, 50, 27, 83, 4};
	// mengisi deret sesuai dalam soal
	for(int i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		insert(deret[i]);
	}

	printf(" Circular Queue :\n");
	display();
	printf("\n\n");
	printf(" Masukkan 3 ke dalam queue\n");
	insert(3);
	printf("\n");
	printf(" Circular queue setelah 3 ditambahkan :\n");
	display();
	return 0;
}
