#include <stdio.h>

char a[8];

int c;

void swp(char &a, char &b){
	c++;
	int t = a;
	a = b;
	b = t;
}

int main(){
	for (int i = 1; i <= 5; i++)scanf(" %c", &a[i]);
	int c = -1;
	while (true){

		int c = 0;

		if (a[1] > a[2]){
			swp(a[1], a[2]);
			printf("%c %c %c %c %c\n", a[1], a[2], a[3], a[4], a[5]);		

			if (a[1] < a[2] && a[2] < a[3] && a[3] < a[4] && a[4] < a[5]){
				break;
			}

			c++;
		}
		if (a[2] > a[3]){
			swp(a[2], a[3]);
			printf("%c %c %c %c %c\n", a[1], a[2], a[3], a[4], a[5]);

			if (a[1] < a[2] && a[2] < a[3] && a[3] < a[4] && a[4] < a[5]){
				break;
			}

			c++;
		}
		if (a[3] > a[4]){
			swp(a[3], a[4]);
			printf("%c %c %c %c %c\n", a[1], a[2], a[3], a[4], a[5]);
			
			if (a[1] < a[2] && a[2] < a[3] && a[3] < a[4] && a[4] < a[5]){
				break;
			}
			
			c++;
		}
		if (a[4] > a[5]){
			swp(a[4], a[5]);
			printf("%c %c %c %c %c\n", a[1], a[2], a[3], a[4], a[5]);
			
			if (a[1] < a[2] && a[2] < a[3] && a[3] < a[4] && a[4] < a[5]){
				break;
			}
			
			c++;
		}

		if (!c){
			printf("%c %c %c %c %c\n", a[1], a[2], a[3], a[4], a[5]);
			break;
		}
	}


}