#include <stdio.h>

#include <algorithm>

using namespace std;

bool chk[50003] = {true};

int main(){

	int m, n;
	scanf("%d %d", &m, &n);


	for(int i=1; i<=n; i++){

		int e;
		scanf("%d", &e);

		for(int j=m-e; j>=0; j--){
			chk[j+e] |= chk[j];
		}

	}

	for(int j=m; j>=0; j--){
		if(chk[j]){
			printf("%d\n", j);
			break;
		}
	}

}
