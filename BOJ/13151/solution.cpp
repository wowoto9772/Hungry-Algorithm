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
		return c < A.c;
	}
}e[500003];

int p[50003];

int top;

int find(int a){
	if(p[a]){
		return p[a] = find(p[a]);
	}
	return a;
}

int main(){

	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);

	int pay = 0;

	for(int i=1; i<=l; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pay += c;
		e[top++] = {a, b, c};
	}

	m -= l;

	for(int i=1; i<=m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[top++] = {a, b, c};
	}

	sort(e, e+top);

	l = pay;
	m = 0;

	for(int i=0; i<top && l >= e[i].c; i++){
		int a = e[i].a, b = e[i].b;
		if(find(a) == find(b))continue;
		l -= e[i].c;
		m++;
		p[find(a)] = find(b);
	}

	if(m == n-1)printf("possible");
	else
		printf("impossible");

	

}
