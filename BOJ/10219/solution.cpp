#include <stdio.h>

#include <algorithm>

using namespace std;

char str[14][14];

int main(){

	int t;
	scanf("%d", &t);

	while(t--){

		int h, w;
		scanf("%d %d", &h, &w);

		for(int i=0; i<h; i++){
			scanf("%s", str[i]);
			for(int j=0; j<w/2; j++){
				swap(str[i][j], str[i][w-1-j]);
			}
		}
		
		for(int i=0; i<h; i++){
			printf("%s\n", str[i]);
		}

	}

}
