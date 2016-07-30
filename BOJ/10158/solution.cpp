#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int R, C;
	int r, c;
	int t;
	
	scanf("%d %d %d %d %d", &C, &R, &c, &r, &t);

	int dx = 1, dy = 1;

	while (t){

		int mi = min(dx == 1 ? (C - c) : c, dy == 1 ? (R - r) : r);

		mi = min(mi, t);

		r += mi * dy;
		c += mi * dx;

		t -= mi;

		if (r == R || !r)dy *= -1;
		if (c == C || !c)dx *= -1;
	}

	printf("%d %d\n", c, r);
}