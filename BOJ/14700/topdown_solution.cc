#include <cstdio>

using namespace std;

const int lmod = 1000000007;

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int dp[300][1 << 18];
int r, c;

int dy(int i, int s){

	if (i == r*c)return 1;
	else{
		int &ret = dp[i][s];
		if (ret != -1)return ret;
		ret = 0;

		int lt = s & 1, t = s & 2, l = s&(1 << ((c)));

		if (!((i%c != 0) && lt && t && l))ret += dy(i + 1, (s >> 1) | (1 << (c)));
		ret += dy(i + 1, s >> 1);

		if (ret >= lmod)ret -= lmod;
		return ret;
	}

}

int main(){

	scanf("%d %d", &r, &c);

	if (r < c)swap(r, c);

	for (int i = 0; i < r*c; i++){
		for (int j = 0; j < (1 << (c + 1)); j++)dp[i][j] = -1;
	}

	printf("%d\n", dy(0, 0));

}