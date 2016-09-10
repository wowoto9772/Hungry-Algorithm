#include <stdio.h>

#include <algorithm>

using namespace std;

int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int s[13];

int nxt[367];

int pars(int _m, int _d){
	return s[_m-1] + _d;
}

int main(){

	for(int i=1; i<=12; i++)s[i] = s[i-1] + d[i];

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){

		int sx, sy, ax, ay;
		scanf("%d %d %d %d", &sx, &sy, &ax, &ay);

		int a = pars(sx,sy), b = pars(ax,ay);

		nxt[a] = max(nxt[a], b);

	}

	int st = pars(3,1), ed = pars(11,30);

	int c = 0;

	for(int i=st; i<=ed; ){

		int ni = 0;

		for(int j=0; j<=i; j++){
			if(i < nxt[j]){
				ni = max(ni, nxt[j]);
			}
		}

		if(ni == 0){
			printf("0");
			return 0;
		}

		i = ni;
		c++;

	}

	printf("%d", c);

}
