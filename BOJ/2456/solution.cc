#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);

	int x[4] = { 0 };
	int c[4][2] = { 0 };

	for (int i=1; i<=n; i++){
		for(int j=1; j<=3; j++){
			int a;
			scanf("%d", &a);
			x[j] += a;
			if (a == 2)c[j][0]++;
			else if (a == 3)c[j][1]++;
		}
	}

	int maxV = max({x[1], x[2], x[3]});
	int p = -1, q = -1;

	for (int i=1; i<=3; i++){
		if (maxV == x[i]){
			if(p == -1)p = i;
			else{
				if(c[p][1] < c[i][1])p = i, q = -1;
				else if(c[p][1] == c[i][1]){
					if(c[p][0] < c[i][0])p = i, q = -1;
					else if(c[p][0] == c[i][0]){
						q = 0;
					}
				}
			}
		}
	}

	if(q == 0)p = 0;
	printf("%d %d\n", p, maxV);

}