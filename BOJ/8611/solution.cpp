#include <string.h>
#include <stdio.h>
#include <math.h>

char num[1004];
int orign[1004];
int pal[3333]; 
// log_2{10^1000} = 1000 * log_2{10}
// = 1000.0 * log(10.0) / log(2.0))
// = 3322
int dvn[1004];

int main(){
	scanf("%s", num);

	

	int os = strlen(num);
	for (int i = 0; i < os; i++)orign[i] = num[i] - '0';

	bool NIE = true;

	for (int j = 2; j <= 10; j++){
		for (int i = 0; i < os; i++)dvn[i] = orign[i];
		int s = os;

		int ptop = 0;

		while (true){
			if (s <= 1){
				int flg = dvn[0];
				if (flg < j){
					pal[ptop++] = flg;
					break;
				}
			}

			int top = 0;
			int g = 0;
			for (int i = 0; i < s; i++){
				g = g * 10 + dvn[i];
				if (g >= j){
					dvn[top++] = g / j;
					g %= j;
				}
				else{
					if (top)dvn[top++] = 0;
				}
			}

			pal[ptop++] = g;
			s = top;
		}

		bool palin = true;
		for (int i = 0; palin && i < ptop / 2; i++){
			if (pal[i] != pal[ptop - 1 - i]){
				palin = false;
			}
		}

		if (palin){
			printf("%d ", j);
			for (int i = 0; i < ptop; i++)printf("%d", pal[i]);
			printf("\n");
			NIE = false;
		}
	}

	if (NIE)printf("NIE\n");
}