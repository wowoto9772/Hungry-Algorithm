#include <stdio.h>

char str[10][10];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int A(int a){ return a < -a ? -a : a; }

int main(){
	for (int i = 0; i < 8; i++)scanf("%s", str[i]);

	int c = 0;
	bool meet = false;
	for (int i = 0; !meet && i < 8; i++){
		for (int j = 0; !meet && j < 8; j++){
			if (str[i][j] == '*'){
				c++;
				for (int a = 0; !meet && a < 8; a++){
					for (int b = 0; !meet && b < 8; b++){
						if (a == i && b == j)continue;
						if (str[a][b] == '*'){
							int l = A(a - i);
							for (int k = 0; !meet && k < 8; k++){
								if (i + dx[k] * l == a && j + dy[k] * l == b){
									meet = true;
								}
							}
							l = A(b - j);
							for (int k = 0; !meet && k < 8; k++){
								if (i + dx[k] * l == a && j + dy[k] * l == b){
									meet = true;
								}
							}
						}
					}
				}
			}
		}
	}

	if (meet || c != 8)printf("invalid\n");
	else{
		printf("valid\n");
	}
}