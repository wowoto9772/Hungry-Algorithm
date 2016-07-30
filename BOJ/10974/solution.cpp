#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void print(char a[]){
	int s = strlen(a);

	for (int i = 0; i < s; i++){
		printf("%c", a[i]);
		if (i < s-1)printf(" ");
	}

	printf("\n");
}

int main(){
	int n;
	scanf("%d", &n);

	char a[10] = { 0 };
	for (int i = 0; i < n; i++)a[i] = i+1 + '0';

	print(a);
	while (next_permutation(a, a + n))print(a);
}