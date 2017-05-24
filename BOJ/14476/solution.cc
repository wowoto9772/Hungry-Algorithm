#include <cstdio>

using namespace std;

int gcd(int a, int b){
	int m = 1;
	while(m){
		m = a % b;
		a = b;
		b = m;
	}return a;
}

int e[1000003];
int le[1000003], ri[1000003];

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		scanf("%d", &e[i]);
	}
	
	le[1] = e[1];
	for(int i=2; i<=n; i++)le[i] = gcd(le[i-1], e[i]);
	ri[n] = e[n];
	for(int i=n-1; i>=1; i--)ri[i] = gcd(ri[i+1], e[i]);
	
	int p = -1, q = 0;
	
	if(e[n] % le[n-1])p = le[n-1], q = e[n];
	if(e[1] % ri[2]){
		if(p < ri[2])p = ri[2], q = e[1];
	}
	
	for(int i=2; i<n; i++){
		int g = gcd(le[i-1], ri[i+1]);
		if(e[i] % g){
			if(p < g)p = g, q = e[i];
		}
	}
	
	printf("%d ", p);
	if(p != -1)printf("%d\n", q);
	
}