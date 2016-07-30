#include <stdio.h>
#include <math.h>

#include <algorithm>

#define dig1 i%10
#define dig2 (i%100)/10
#define dig3 (i%1000)/100
#define dig4 (i%10000)/1000
#define dig5 (i%100000)/10000
#define dig6 (i%1000000)/100000
#define dig7 (i%10000000)/1000000
#define dig8 i/10000000

using namespace std;

#define MAX 10000000

bool p[MAX + 3];
int P[1003];
// cnt : 781

int top;

int rev(int a){
	int ret = 0;
	while (a){
		ret = ret * 10 + a % 10;
		a /= 10;
	}return ret;
}

int main(){

	int a, b;
	scanf("%d %d", &a, &b);

	int M = sqrt(b);

	int lim = min(b, 10000000);
	// biggest = 9989899

	for (int i = 2; i <= lim; i++){
		if (!p[i]){
			
			if (i == rev(i)){
				P[top++] = i;
			}

			if (i > M+3)continue; 
			// for error

			for (int j = i*i; j <= lim; j += i)p[j] = true;
		}
	}

	int x = lower_bound(P, P + top, a) - P;
	for (int i = x; i < top && P[i] <= b; i++){

		printf("%d\n", P[i]);

	}

	printf("-1\n");

}