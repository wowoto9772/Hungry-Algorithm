#include <stdio.h>
#include <string.h>

#define ll long long

char str[103];

ll dp[103][3][3][103];

int n;

bool isVowel(int a){

	if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')return true;
	return false;
	
}

ll dy(int m, int v, int c, int L){
	
	if(v == 3 || c == 3)return 0;

	if(m == n){
		return L > 0;
	}

	ll &ret = dp[m][v][c][L];

	if(ret != -1)return ret;

	ret = 0;
	
	if(str[m] == '_'){
		ret += 20LL * dy(m+1, 0, c+1, L);
		ret += dy(m+1, 0, c+1, L+1);
		ret += 5LL * dy(m+1, v+1, 0, L);
	}else{
		if(isVowel(str[m]))ret += dy(m+1, v+1, 0, L);
		else
			ret += dy(m+1, 0, c+1, L + (str[m] == 'L'));
	}

	return ret;

}

int main(){

	scanf("%s", str);

	n = strlen(str);

	for(int i=0; i<n; i++)for(int j=0; j<3; j++)for(int k=0; k<3; k++)for(int l=0; l<100; l++)dp[i][j][k][l] = -1; 

	printf("%lld\n", dy(0, 0, 0, 0));

}
