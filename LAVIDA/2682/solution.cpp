/*
	obtain a value >= R at least X out of Y rolls
	variety of dice with different numbers of sides S
	R, S, X, Y, W

	1 ~ S sided dice

	Y번 던져서 최소한 X번은 R보다 큰 밸류를 얻지 못할 것이다.
	==> 베티 (P)

	==> 바비가 돈을 딸려면
	(!P) R보다 작은 밸류로 얻어야해

	P(bobby) = yCx * ((s-r+1)/s)^x
	P(betty) = 1/W

	P(bobby) > P(betty) : is P(Bobby) greater than P(Betty)
*/

#include <stdio.h>
#include <math.h>

int c[12][12];

int main(){

	c[0][0] = 1;
	for (int i = 1; i <= 10; i++){
		c[i][0] = 1;
		for (int j = 1; j <= i; j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}

	int t;
	scanf("%d", &t);

	while (t--){
		int r, s, w, x, y;
		scanf("%d %d %d %d %d", &r, &s, &x, &y, &w);

		double bobby = 0.0;
		for (int i = x; i <= y; i++){ // at least x <=> at best x
			double q = 1 - (double)(r - 1) / s;

			double nq = 1 - q;

			double p = c[y][i] * pow(q, i) * pow(nq, y-i);
			bobby += p;
		} // value < R on at least X out of Y rolls

		double betty = 1.0 / w;
		// P(betty) = 1 / w

		if (bobby * w > 1.0 + 1e-9)printf("yes\n");
		else{
			printf("no\n");
		}
	}
}