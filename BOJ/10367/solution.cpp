#include <stdio.h>

#include <algorithm>

using namespace std;

class ele{

public:

	int a, b, c;

	ele(){}
	ele(int _a, int _b, int _c){
		a = _a, b = _b, c = _c;
	}

	bool operator<(const ele &A)const{

		return c > A.c;

	}

}e[100003];

int p[10003];

int pfind(int a){
	if(p[a] == a) return p[a];
	else return p[a] = pfind(p[a]);
}

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int n, m;
		scanf("%d %d", &n, &m);

		for(int i=1; i<=n; i++)p[i] = i;

		for(int i=0; i<m; i++)scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].c);

		sort(e, e+m);

		int ans = 0;

		int maxi = 0;

		for(int i=0; i<m; i++){

			int a = pfind(e[i].a), b = pfind(e[i].b);

			if(a == b){
				ans += e[i].c;
				maxi = max(maxi, e[i].c);
			}else{
				p[a] = b;
			}

		}

		// only remains maximum spanning tree.

		printf("Case #%d: %d %d\n", ++tc, ans, maxi);

	}

}


