#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

class ele{
public:
	long long y; // y segment
	long long mx, my;
	bool operator<(const ele &A)const{
		if (mx == A.mx){
			if (my == A.my)return y < A.y;
			return my < A.my;
		}
		return mx < A.mx;
	}
}S[1000003];

class DAT{
public:
	long long x, y;
	bool operator<(const DAT &B)const{
		if (x == B.x)return y < B.y;
		return x < B.x;
	}
}I[1003];

int Y[500000];

int x[2000003] = { 0 };
int y[2000003] = { 0 };

int ab(int a){ return a < -a ? -a : a; }

int GCD(int a, int b){
	int mod = 1;
	while (mod){
		mod = a % b;
		a = b;
		b = mod;
	}return a;
}

int main()
{
	for (int i = 2; i <= 1000; i++){
		int k = i * (i - 1) / 2;
		Y[k] = i;
	}

	char str[120] = { 0 };
	bool f = false;
	int T = 1, top = 0, top2 = 0;
	long long a, b;
	while (gets(str)){
		if (str[0] == '-' && str[1] == '-'){
			if (f)break;
			else{
				memset(x, 0, sizeof(x));
				memset(y, 0, sizeof(y));

				sort(I, I + top);

				int ans = 0;

				for (int i = 0; i < top; i++){
					x[1000000+I[i].x]++;
					y[1000000+I[i].y]++;
					for (int j = i + 1; j < top; j++){
						if (I[i].x != I[j].x && I[i].y != I[j].y){
							long long ax = I[i].x - I[j].x;
							long long ay = I[i].y - I[j].y;

							int k = GCD(ax, ay);

							ax /= k, ay /= k;

							if (ax * ay > 0){
								if (ax < 0){
									ax *= -1, ay *= -1;
								}
							}
							else{
								if (ax < 0){
									ax *= -1, ay *= -1;
								}
							}


							S[top2].mx = ax, S[top2].my = ay;

							S[top2].y = ax * I[i].y;
							S[top2].y -= ay * I[i].x;

							top2++;
						}
					}
				}

				sort(S, S + top2);

				for (int i = 0; i <= 2000000; i++){
					if (x[i])ans = ans < x[i] ? x[i] : ans;
					if (y[i])ans = ans < y[i] ? y[i] : ans;
				}

				int ans2 = 0;


				for (int i = 0; i < top2; i++){
					int c = 1;
					int p = i;
					for (int j = i + 1; j < top2; j++){
						if (S[i].mx == S[j].mx && S[i].my == S[j].my && S[i].y == S[j].y){
							c++;
							p = j;
						}
						else{
							i = j - 1;
							break;
						}
					}
					i = p;
					ans2 = ans2 < c ? c : ans2;
				}

				ans2 = Y[ans2];

				ans = ans < ans2 ? ans2 : ans;

				printf("%d. %d\n", T++, ans);

				top = top2 = 0;

				f = true;

				continue;
			}
		}
		else{
			f = false;
		}
		sscanf(str, "%lld %lld", &a, &b);
		I[top].x = a, I[top].y = b;
		top++;
	}
}