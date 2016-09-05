#include <stdio.h>

int a[1000003], b[1000003];

int main(){

	int n, m;
	
	while(scanf("%d %d", &n, &m) == 2){

		if(!(n|m))break;

		for(int i=0; i<n; i++)scanf("%d", &a[i]);

		for(int i=0; i<m; i++)scanf("%d", &b[i]);

		int l = 0, r = 0;

		int c = 0;

		while(l < n && r < m){
			
			if(a[l] == b[r])l++, r++, c++;
			else if(a[l] > b[r])r++;
			else if(a[l] < b[r])l++;

		}

		printf("%d\n", c);

	}

}
