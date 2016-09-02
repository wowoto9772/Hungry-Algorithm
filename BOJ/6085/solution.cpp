#include <stdio.h>

#include <limits.h>

#include <algorithm>

#define ll long long

using namespace std;

int d[503][503];

bool goal[503];

int main(){

	int P, F, C;

	scanf("%d %d %d", &P, &F, &C);

	for(int i=1; i<=F; i++){

		int a;
		scanf("%d", &a);

		goal[a] = true;

	}

	for(int i=1; i<=P; i++){
		for(int j=1; j<=P; j++)d[i][j] = INT_MAX;
		d[i][i] = 0;
	}

	for(int i=1; i<=C; i++){
		
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		if(d[a][b] > c)d[a][b] = d[b][a] = c;

	}

	for(int k=1; k<=P; k++){
		for(int i=1; i<=P; i++){
			for(int j=1; j<=P; j++){
				if((d[i][k]|d[k][j]) == INT_MAX)continue;
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}

	ll ans = LLONG_MAX, x;

	for(int i=1; i<=P; i++){
		ll tmp = 0;
		for(int j=1; j<=P; j++){
			if(goal[j])tmp += d[i][j];
		}
		if(ans > tmp)ans = tmp, x = i;
	}

	printf("%d\n", x);

}
