#include <stdio.h>

char str[53][53];

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	for(int i=1; i<=r; i++){
		scanf("%s", str[i]);
	}

	int a[53] = {0};

	bool chk[53] = {0};
	
	int f = 1;

	for(int i=c-2; i>=1; i--){

		bool flag = false;
		for(int j=1; j<=r; j++){
			if(!chk[j] && str[j][i] != '.'){
				chk[j] = true;
				a[str[j][i] - '0'] = f;
				flag = true;
			}
		}
		if(flag)f++;
	}

	for(int i=1; i<=9; i++)printf("%d\n", a[i]);
}
