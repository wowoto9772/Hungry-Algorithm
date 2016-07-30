#include <stdio.h>
#include <limits.h>
#include <memory.h>

#include <queue>
#include <vector>

using namespace std;

class ele{
public:
	int a, c; // arrival and cost || Blue and Purple cycle
	int f;    // first remain time
	int t;    // type 0 is blue
}psh, pop, I[303];

bool TheTime(int t, int w){
	if (t >= I[w].f){
		t -= I[w].f;
		t %= I[w].a + I[w].c;
		if (I[w].t){ // is purple
			if (t < I[w].a)return 0;
			else
				return 1;
		}
		else{		 // is blue
			if (t < I[w].c)return 1;
			else
				return 0;
		}
	}
	else{
		return I[w].t;
	}
}

int main()
{
	int S, D;
	scanf("%d %d", &S, &D);

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++){
		char a;
		int b, c, d;
		scanf(" %c %d %d %d", &a, &b, &c, &d);
		I[i].a = c, I[i].c = d, I[i].f = b;
		if (a == 'B')I[i].t = 0;
		else
			I[i].t = 1;
	}

	vector < vector < ele > > L;
	L.resize(N + 1);

	for (int i = 1; i <= M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		psh.a = b, psh.c = c;
		L[a].push_back(psh);
		psh.a = a;
		L[b].push_back(psh);
	}

	int d[303];
	memset(d, 0x4f, sizeof(d));

	d[S] = 0;
	psh.a = S, psh.c = 0;

	queue <ele> Q;
	Q.push(psh);

	while (!Q.empty()){
		pop = Q.front(); Q.pop();

		for (int i = 0; i < L[pop.a].size(); i++){

			psh = L[pop.a][i];

			ele pre = I[pop.a], pst = I[psh.a];

			int t = pre.a + pre.c;
			if (t < pst.a + pst.c)t = pst.a + pst.c;

			for (int k = 0; k <= 2*t; k++){
				int cst = pop.c + k;
				if (TheTime(cst, pop.a) == TheTime(cst, psh.a)){
					cst += psh.c;
					if (d[psh.a] > cst){
						d[psh.a] = cst;
						psh.c = cst;
						Q.push(psh);
					}
					break;
				}
			}

		}
	}

	if (d[D] >= 1000000000)printf("0\n");
	else
		printf("%d\n", d[D]);
}

/*
	a -> b is same color	  : just go
			  different color : wait ... when? 
								finding the time 
								that two things's color are same
*/