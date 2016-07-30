#include <stdio.h>
#include <queue>

using namespace std;

int gcd(int a, int b){

	int m = 1;

	while (m){

		m = a % b;
		a = b;
		b = m;

	}

	return a;

}

int x[1003], y[1003], r[1003];

int d[1003];

bool intersect(int i, int j){
	return ((r[i] + r[j]) * (r[i] + r[j])) == ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){

		scanf("%d %d %d", &x[i], &y[i], &r[i]);

	}

	queue <int> q;
	q.push(n);

	d[n] = 1;

	while (!q.empty()){

		int p = q.front(); q.pop();

		for (int i = 1; i <= n; i++){

			if (!d[i]){

				if (intersect(i, p)){

					d[i] = d[p] * (-1);

					q.push(i);

				}


			}
			else if (intersect(i, p)){
				if (d[i] * d[p]  > 0){
					printf("The input gear cannot move.\n");
					return 0;
				}
			}
		}

	}

	if (d[1]){
		int g = gcd(r[n], r[1]);
		printf("%d:%d\n", d[1] * r[1] / g, r[n] / g);
	}
	else{
		printf("The input gear is not connected to the output gear.\n");
	}

}