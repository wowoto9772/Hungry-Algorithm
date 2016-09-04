#include <stdio.h>

int dr[] = {-1, 0, 1, 1};
int dc[] = {1, 1, 1, 0};
char str[33][33];

int main(){

	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(str[i][j] != '.'){
				for(int k=0; k<4; k++){

					bool win = true;

					for(int l=1; l<=2 && win; l++){
						int ni = i + l * dr[k], nj = j + l * dc[k];
						if(ni < 0 || ni >= n || nj < 0 || nj >= n){
							win = false;
							break;
						}
						if(str[ni][nj] != str[i][j])win = false;
					}

					if(win){
						printf("%c", str[i][j]);
						return 0;
					}
				}
			}
		}
	}

	printf("ongoing");

}
