#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

	int r, b;
	scanf("%d %d", &r, &b);

	for(int i=2; i<(r>>1); i++){
		int j = (r>>1) - i + 2;

		if((i-2)*(j-2) == b){
			printf("%d %d\n", max(i,j), min(i,j));
			return 0;
		}
	}

}
