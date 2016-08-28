#include <stdio.h>

#include <vector>
#include <algorithm>

#define v first
#define i second

using namespace std;

vector < pair <int, int> > e, f;

int sec[50003];

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	e.resize(n);

	for(int i=0; i<n; i++){
		scanf("%d %d", &e[i].v, &sec[i]);
		e[i].i = i;
	}

	sort(e.begin(), e.end());

	f.resize(k);

	int top = 0;

	for(int i=n-1; i>=n-k; i--){
		f[top++] = {sec[e[i].i], e[i].i};
	}

	sort(f.begin(), f.end());

	printf("%d\n", f.back().i+1);

}
