#include <stdio.h>

#include <algorithm>

using namespace std;

int main(){

	int t;
	scanf("%d", &t);
	
	int A = 0, B = 0, C = 0;

	while(t--){

		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		A += a, B += b, C += c;

		int mini = min({A, B, C});

		if(mini < 30)printf("NO\n");
		else{
			printf("%d\n", mini);
			A -= mini, B -= mini, C -= mini;
		}

	}


}
