#include <stdio.h>
#include <memory.h>

class ele{
public:
	int a, b, c;
}R[6003];

int main()
{
	int t;
	scanf("%d", &t);

	while (t--){
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);

		int top = 0;

		for (int i = 1; i <= M; i++){ // bidirecional edge
			scanf("%d %d %d", &R[top].a, &R[top].b, &R[top].c);
			top++;
			R[top].a = R[top - 1].b, R[top].b = R[top - 1].a, R[top].c = R[top - 1].c;
			top++;
		}

		for (int i = 1; i <= W; i++){ // Wormholes : directional edge
			scanf("%d %d %d", &R[top].a, &R[top].b, &R[top].c);
			R[top].c *= -1;
			top++;
		}

		bool f = false;

		int d[505] = { 0 }; // start at some points
		// negative cycle detect.
		// yes : negative cycle is existed.

		for (int i = 0; i < N; i++){ // Vertex
			for (int j = 0; j < top; j++){ // Edge
				if (d[R[j].b] > d[R[j].a] + R[j].c){
					d[R[j].b] = d[R[j].a] + R[j].c;
					if (i == N - 1)f = true; // is negative cycle
				}
			}
		}

		if (!f)printf("NO\n");
		else
			printf("YES\n");
	}

} // bellman-ford : O(V*E)