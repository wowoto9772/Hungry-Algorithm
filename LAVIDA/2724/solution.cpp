#include <stdio.h>
#include <algorithm>

using namespace std;

int L[500003];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)scanf("%d", &L[i]);

	sort(L, L + n);

	int l = 0, r = n - 1;
	int c = 0;

	while (l < r){

		if (L[l] < r - l){
			c += L[l];
			r -= L[l];
			l++;
		}
		else{
			c += r - l;
			break;
		}
	}

	printf("%d\n", c);

}