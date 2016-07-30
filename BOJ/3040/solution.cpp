#include <stdio.h>

int a[9];

int main(){

	for (int i = 0; i < 9; i++)scanf("%d", &a[i]);

	for (int i = 1; i < (1 << 9); i++){
		int c = 0;
		int m = 0;
		for (int j = 0; j < 9; j++){
			if (i&(1 << j))c++, m += a[j];
		}

		if (m == 100 && c == 7){
			for (int j = 0; j < 9; j++){
				if (i&(1 << j))printf("%d\n", a[j]);
			}
			break;
		}
	}

}