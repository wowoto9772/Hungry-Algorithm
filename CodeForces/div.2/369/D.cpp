#include <stdio.h>
#include <string>

using namespace std;

int o[2000003];
int c[4];
int d[4];

int main(){

	for(int i=0; i<4; i++)scanf("%d", &c[i]);

	// 00 01 10 11
	
	for(int i=2; i<=2*c[0]; i+=2)o[i]++;

	// even : 0s
	// odd  : 1s

	for(int i=1; i<=2*c[0]+1 && d[3] < c[3]; i+=2){
		int l = (i-1) >> 1;
		int r = c[0] - l;
		if(d[1] + l <= c[1] && d[2] + r <= c[2]){
			c[3]--;
			d[1] += l;
			d[2] += r;
			d[3]++;
			o[i]++;
			i-=2;
			continue;
		}
	}

	if(d[1] == c[1] && d[2] == c[2] && d[3] == c[3]){
		for(int i=1; i<=(c[0]*2); i++){
			for(int j=1; j<=o[i]; j++){
				printf("%d", i&1);
			}
		}
	}else{
		printf("Impossible\n");
	}

}
