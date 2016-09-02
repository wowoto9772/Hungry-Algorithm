#include <stdio.h>

#include <string.h>

#include <string>
#include <vector>

using namespace std;

// pattern's pi function

#define LMAX 2000003

char org[LMAX], ptn[LMAX >> 1];
int pi[LMAX >> 1];

int pl, ol;

void getPi(){

	int p = 0;
	pi[1] = 0;

	for(int i=2; i<=pl; i++){

		while(p && (ptn[p+1] != ptn[i]))p = pi[p];
		if(ptn[p+1] == ptn[i])p++;
		pi[i] = p;

	}


}

int getAns(){

	int ret = 0;

	int p = 0;

	for(int i=1; i<=ol; i++){

		while(p && (ptn[p+1] != org[i]))p = pi[p];
		if(ptn[p+1] == org[i])p++;
		if(p == pl){
			p = pi[p];
			ret++;
		}

	}

	return ret;

}

int gcd(int a, int b){

	int m = 1;

	while(m){

		m = a % b;
		a = b;
		b = m;

	}

	return a;

}

int main(){

	int n;
	scanf("%d", &n);

	pl = n, ol = (n<<1) - 1;

	for(int i=1; i<=n; i++){
		scanf(" %c", &ptn[i]);
	}

	for(int i=1; i<=n; i++){
		scanf(" %c", &org[i]);
	}

	for(int i=n+1; i<2*n; i++){
		org[i] = org[i-n];	
	}

	getPi();

	int a = getAns(), b = n;

	int g = gcd(a, b);

	a /= g, b /= g;

	printf("%d/%d\n", a, b);

}
