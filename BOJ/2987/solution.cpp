#include <stdio.h>
#include <algorithm>

using namespace std;

struct point{
	int x, y;
	point(int x = 0, int y = 0) :x(x), y(y){}
};

int ccw(point &a, point &b, point &c){

	int dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;

	return abs(dx1*dy2-dx2*dy1);

}



int main(){

	point p[3];

	for(int i=0; i<3; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
	}



	int n;
	scanf("%d", &n);

	int c = 0;

	for(int i=1; i<=n; i++){
		point k;
		scanf("%d %d", &k.x, &k.y);

		if(ccw(p[0], p[1], k) + ccw(p[1], p[2], k) + ccw(p[2], p[0], k) == ccw(p[0], p[1], p[2])){
			c++;
		}

	}

	int s = abs(ccw(p[0], p[1], p[2]));

	printf("%d", s>>1);

	if(s&1)printf(".5");
	else
		printf(".0");

	printf("\n%d", c);

}
