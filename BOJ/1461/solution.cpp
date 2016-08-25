#include <stdio.h>

#include <algorithm>

using namespace std;

int p[10003];

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++){
		scanf("%d", &p[i]);
	}

	p[n] = 0;

	sort(p, p+1+n);

	int s;

	for(int i=0; i<=n; i++){
		if(0 == p[i]){
			s = i;	
			break;
		}
	}

	int l = s;
	int r = n - s;

	int le = 0;

	for(int i=s-(l%m); i>=0; i-=m){
		le += p[s] - p[i];
		if(i || (i == 0 && s+1 <= n))le += p[s] - p[i];
	}


	if(s+1 <= n){
		for(int i=s+(r%m); i<=n; i+=m){
			le += p[i] - p[s];
			if(i < n)le += p[i] - p[s];
		}
	}


	int ri = 0;

	for(int i=s+(r%m); i<=n; i+=m){
		ri += p[i] - p[s];
		if(i < n || (i == n && s-1 >= 0))ri += p[i] - p[s];
	}

	if(s-1 >= 0){
		for(int i=s-(l%m); i>=0; i-=m){
			ri += p[s] - p[i];
			if(i)ri += p[s] - p[i];
		}
	}

	printf("%d\n", min(le, ri));

}
