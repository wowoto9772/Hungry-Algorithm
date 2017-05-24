#include <cstdio>
using namespace std;
int s[1003];
int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++)scanf("%d", &s[i]);
	int d = 0, e = 0;
	for(int i=0; i<m; i++){
		int c;
		scanf("%d", &c);
		e++;
		d += c;
		if(d >= n)break;
		d += s[d];
		if(d >= n)break;
	}
	
	printf("%d\n", e);
	
}