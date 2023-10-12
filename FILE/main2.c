#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE* file;
	int i,j=1,k=6;
	char T[10]={'a','b','c','d','e'};
	file = fopen("toto.txt ", "r+");
	fwrite(T,i,j,file);
	printf("%d",fwrite(T,j,k,file));
	fclose(file);
	return 0;
}
