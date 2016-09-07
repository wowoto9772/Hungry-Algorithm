#include <stdio.h>

#include <algorithm>

using namespace std;

int c[23];

int main(){

	for(int i=1; i<=20; i++)c[i] = i;

	int n = 10;

	while(n--){
		int a, b;
		scanf("%d %d", &a, &b);

		for(int i=0; i<=(b-a)/2; i++)swap(c[a+i], c[b-i]);
	}

	for(int i=1; i<=20; i++)printf("%d ", c[i]);

}
