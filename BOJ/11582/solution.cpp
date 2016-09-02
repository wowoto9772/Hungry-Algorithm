#include <stdio.h>

#include <algorithm>

using namespace std;

int e[1<<20];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++)scanf("%d", &e[i]);

	int k;
	scanf("%d", &k);

	k = n / k;

	for(int i=0; i<n; i+=k){
		sort(e+i, e+i+k);
	}

	for(int i=0; i<n; i++)printf("%d ", e[i]);

}
