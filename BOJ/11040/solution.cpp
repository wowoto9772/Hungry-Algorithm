#include <stdio.h>
#include <string.h>

class ele{
public:
	int lev;
	int val;
	int flg; // 0 : add, 1 : multiply, 2 : value
	ele(){}
	ele(int a, int b, int c){ lev = a, val = b, flg = c; }
}I[10003];

char str[10003];
int n;

int func(int c){
	int ret = 0;
	if (I[c].flg < 2){
		if (I[c].flg == 1)ret = 1;
		for (int j = c + 1; j < n; j++){
			if (I[j].lev == I[c].lev + 1){
				if (I[c].flg == 0) ret += func(j);
				else
					ret *= func(j);
			}
			else if (I[j].lev <= I[c].lev){
				break;
			}
		}
	}
	else{
		ret = I[c].val;
	}
	return ret;
}

int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++){
			scanf("%s", str);
			int s = strlen(str);

			int lev = 0, val = 0, flg = 2;
			for (int j = 0; j < s; j++){
				if (str[j] == '.')lev++;
				else if (str[j] == '*')flg = 1;
				else if (str[j] == '+')flg = 0;
				else{
					val = val * 10 + str[j] - '0';
				}
			}

			I[i] = ele(lev, val, flg);
		}

		printf("%d\n", func(0));
	}
}