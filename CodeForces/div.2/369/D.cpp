#include <stdio.h>

int c[2][2];
int d[4];

int main(){

	scanf("%d %d %d %d", &c[0][0], &c[0][1], &c[1][0], &c[1][1]);

	if((c[0][0]|c[0][1]|c[1][0]|c[1][1])==0)printf("1"); // or 0
	else{
		
		int zero, one;

		for(zero=0; zero*(zero-1)/2 < c[0][0]; zero++);
		for(one=0; one*(one-1)/2 < c[1][1]; one++);

		if(zero == 0 && (c[1][0]|c[0][1]))zero++;
		if(one == 0 && (c[0][1]|c[1][0]))one++;

		if(zero*(zero-1)/2 == c[0][0] && one*(one-1)/2 == c[1][1]){
			int tot = zero + one;
			if(c[0][1]+c[1][0] == zero*one){
				for(int i=1; i<=tot; i++){
					if(c[0][1] >= one){
						c[0][1] -= one;
						zero--;
						printf("0");
					}else{
						one--;
						printf("1");
					}
				}
			}else{
				printf("Impossible\n");
			}
		}else{
			printf("Impossible");
		}

	}

}
