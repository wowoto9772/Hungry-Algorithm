#include <stdio.h>
#include <vector>

using namespace std;

int W[1001][1001];

vector < vector <int> > L;

int Cy[4000000];
int top;

void S(int a){
	for (int i = 0; i < L[a].size(); i++){
		int nxt = L[a][i];
		while (W[a][nxt] > 0){
			W[a][nxt]--;
			W[nxt][a]--;
			S(nxt);
		}
	}
	Cy[top++] = a;
}

int main()
{
	int n;
	scanf("%d", &n);

	L.resize(n + 1);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%d", &W[i][j]);
			if (W[i][j])L[i].push_back(j);
		}
	}

	S(1);// cycle's stating point is every where

	if (Cy[0] == Cy[top - 1]){
		for (int i = top - 1; i > 0; i--)printf("%d ", Cy[i]);
		printf("%d\n", Cy[0]);
	}
	else
		printf("-1\n");

}