#include <stdio.h>

int x[1083], y[1083], r[1083];

bool meet(int i, int j){
	int d_2 = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	if(d_2 == (r[i] + r[j]) * (r[i] + r[j]))return true;
	return false;
}

int main(){

	int n;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d %d %d", &x[i], &y[i], &r[i]);
	}

	for(int i=1; i<=n; i++){
		
		if(x[i] == 0 && y[i] == 0)continue;
		
		int c = 0;
		
		for(int j=1; j<=n; j++){
			if(i == j)continue;
			if(meet(i, j))c++;
		}

		if(c == 1){
			printf("%d %d\n", x[i], y[i]);
			break;
		}
	}

}
