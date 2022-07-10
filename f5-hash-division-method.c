#include <stdio.h>

int division(int k, int m){
	return k % m;
}

int main(){
	int k = 12345678;
	int m = 15000;
	printf(" \n Hash Value = %d\n", division(k,m));
	return 0;
}
