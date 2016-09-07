#include <stdio.h>

#define ll long long

int N, L, l;

ll dp[33][33];

int num[33], ans[33];

ll dy(int c, int m){

	if(c == N){
		return 1;
	}

	ll &ret = dp[c][m];

	if(ret != -1){
		return ret;
	}

	ret = 0;

	ret += dy(c+1, m);

	if(m < L){

		ret += dy(c+1, m+1);

	}

	return ret;

}

ll dy2(int c, int m){



}

int main(){

	scanf("%d %d %d", &N, &L, &l);

	for(int i=0; i<N; i++)for(int j=0; j<=L; j++)dp[i][j] = -1;

	dy(0, 0);



}

/*

   00000

   00001
   00010
   00011
   00100
   00101

   00110
   00111
   01000
   01001
   01010

   01011
   01100
   01101
   01110
   10000

   10001
   10010
   10011


 */
