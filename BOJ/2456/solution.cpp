#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);

	int x[3] = { 0 };
	int q[3][2] = { 0 };

	for (int i = 1; i <= n; i++){

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		x[0] += a;
		if (a == 2)q[0][0]++;
		else if (a == 3)q[0][1]++;
		x[1] += b;
		if (b == 2)q[1][0]++;
		else if (b == 3)q[1][1]++;
		x[2] += c;
		if (c == 2)q[2][0]++;
		else if (c == 3)q[2][1]++;

	}

	int max = 0;
	int c = 0;
	int p;

	for (int i = 0; i < 3; i++){
		if (max < x[i]){
			p = i;
			max = x[i];
			c = 1;
		}
		else if (max == x[i]){
			if (q[p][1] < q[i][1])p = i;
			else if (q[p][1] == q[i][1]){
				if (q[p][0] < q[i][0])p = i;
				else if (q[p][0] == q[i][0])c++;
			}
		}
	}

	if (c != 1)p = 0;
	else
		p++;

	printf("%d %d\n", p, max);

}