#include <stdio.h>
#include <vector>

using namespace std;

int P[2003], S[2003];

int FindE(int p){

	while(P[p] != -1){
		p = P[p];
	}

	return p;

}

int main()
{
	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int n, m;
		scanf("%d %d", &n, &m);

		vector < vector <int> > SN;
		SN.resize(n+1);

		for(int i=1; i<=n; i++){
			SN[i].push_back(i);
			P[i] = S[i] = -1;
		}

		bool flag = false;

		for(int i=1; i<=m; i++){

			int a, b;
			scanf("%d %d", &a, &b);

			if(flag)continue;

			int ta = FindE(a), tb = FindE(b);
			if(ta == tb){
				if(S[a] == S[b]){
					flag = true;
				}
			}else{
				bool f = false;

				if(S[a] == S[b])f = true;

				for(int j=0; j<SN[tb].size(); j++){

					if(f)S[SN[tb][j]] *= -1;

					SN[ta].push_back(SN[tb][j]);

					P[SN[tb][j]] = ta;

				}

				SN[tb].clear();
			}
		}

		printf("Scenario #%d:\n", ++tc);

		if(flag)printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");

		printf("\n");
	}
}

