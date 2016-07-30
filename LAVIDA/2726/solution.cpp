#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int X, Y;
	scanf("%d %d", &X, &Y);

	double stb = (double)(X * 1000.0 / Y);

	int n;
	scanf("%d", &n);

	while (n--){
		int X, Y;
		scanf("%d %d", &X, &Y);

		stb = min(stb, (double)(X * 1000.0 / Y));
	}

	printf("%.2lf\n", stb);
}
