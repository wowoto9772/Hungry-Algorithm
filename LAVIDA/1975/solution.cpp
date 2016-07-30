#include <stdio.h>
#include <memory.h>
#include <limits.h>

#include <queue>

using namespace std;

int cap[203][203], flow[203][203];

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(!cap[a][b])cap[a][b] = c;
		else
			cap[a][b] += c;
	}
	// Source : 1, Sink : N

	int ans = 0;

	while (true){
		int P[203];
		memset(P, -1, sizeof(P));

		P[1] = 1;
		queue <int> R;
		R.push(1);

		while (!R.empty() && P[N] == -1){
			int c = R.front();
			R.pop();

			for (int i = 1; i <= N; i++){
				if (cap[c][i] - flow[c][i] > 0 && P[i] == -1){
					P[i] = c;
					R.push(i);
				}
			}
		}

		if (P[N] == -1)break;

		int m_flow = INT_MAX;

		for (int r = N; r != 1; r = P[r]){
			int k = cap[P[r]][r] - flow[P[r]][r];
			if (m_flow > k)m_flow = k;
		}
		for (int r = N; r != 1; r = P[r]){
			flow[P[r]][r] += m_flow;
			flow[r][P[r]] -= m_flow;
		}

		ans += m_flow;
	}

	printf("%d\n", ans);
}