#include <stdio.h>

#include <algorithm>

using namespace std;

char str[103][103];
int arr[103][103];

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++){
		scanf("%s", str[i]+1);
		for(int j=1; j<=m; j++){
			if(str[i][j] != '.'){
				arr[i][j] = -1;
			}
		}
	}

	int key = 0;

	for(int _key=0;;_key++){

		int flg = 0;

		for(int i=0; i<=n+1; i++){
			for(int j=0; j<=m+1; j++){
				key = max(key, arr[i][j]);
				if(arr[i][j] == _key){
					for(int k=0; k<4; k++){
						int ni = i + dr[k], nj = j + dc[k];

						if(ni < 0 || ni > n+1 || nj < 0 || nj > m+1)continue;

						if(arr[ni][nj] == -1){
							arr[ni][nj] = _key+1;
							flg++;
						}

					}
				}
			}
		}

		if(flg == 0)break;

	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int c = arr[i][j];
			if(c <= 0){
				printf("..");
				if(key >= 10)printf(".");
			}
			else{
				if(key >= 10){
					if(c < 10)printf("..%d", c);
					else
						printf(".%d", c);
				}
				else{
					printf(".%d", c);
				}
			}


		}

		printf("\n");

	}

}
