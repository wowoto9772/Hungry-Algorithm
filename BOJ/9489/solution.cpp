#include <stdio.h>
#include <vector>

using namespace std;

vector < int > lnk[1000003];

int p[1000003];

int main(){

	int n, k;
	while(scanf("%d %d", &n, &k) == 2){

		if(!(n|k))break;

		vector <int> e(n);

		for(int i=0; i<n; i++){
			scanf("%d", &e[i]);
			lnk[e[i]].clear();
		}

		if(n == 1)printf("0\n");
		else{

			int c = 0;

			p[e[0]] = e[0];

			for(int l=1; l<n; l++){
				
				int r = l;
				
				while(r+1 < n && e[r+1] == e[r]+1){
					r++;
				}

				for(int i=l; i<=r; i++){
					lnk[e[c]].push_back(e[i]);
					p[e[i]] = e[c];
				}

				c++;
				l = r;
			}

			int par = p[k];

			int gpar = p[par];

			if(par != gpar){
				
				int cs = 0;
				for(int i=0; i<lnk[gpar].size(); i++){
					if(lnk[gpar][i] == par)continue;
					cs += lnk[lnk[gpar][i]].size();
				}
				printf("%d\n", cs);
			}else{
				printf("0\n");
			}

		}

	}

}
