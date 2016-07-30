#include <stdio.h>
#include <memory.h>

int M, N;

int dp[103][10003];
class ele{
public:
	int i, c;
	bool operator<(const ele &A)const{
		return i < A.i;
	}
}I[105];

int dy(int c, int m){
	if (!m)return 1;
	if (dp[c][m] != -1)return dp[c][m];

	dp[c][m] = 0;

	for (int i = c + 1; i <= N; i++){
		for (int j = 1; j <= I[i].c; j++){
			int nxt = m - j * I[i].i;
			if (nxt >= 0){
				dp[c][m] += dy(i, nxt);
			}
			else{
				break;
			}
		}
	}

	return dp[c][m];
}

int main(){
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= N; i++){
		scanf("%d %d", &I[i].i, &I[i].c);
	}

	memset(dp, 0xff, sizeof(dp));

	printf("%d\n", dy(0, M));
}