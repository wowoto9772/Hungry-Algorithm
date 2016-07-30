#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class ele{
public:
	int a, b, v;
	bool operator<(const ele &A)const{
		return v < A.v;
	}
}I[500003];

int p[1003], snc[1003], uec[1003]; 
// parent, subtree's node cnt, used edge count

int main()
{

	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int top = 0;
		for (int i = 1; i <= n; i++){
			p[i] = 0, snc[i] = 1, uec[i] = 0;
		}
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				I[top].a = i, I[top].b = j;
				scanf("%d", &I[top++].v);
			}
		}

		sort(I, I + top);

		vector <int> lnk;

		int c = 0;
		for (int i = 0; i < top-1; i++){
			int a = I[i].a, b = I[i].b;
			while (p[a])a = p[a];
			while (p[b])b = p[b];
			int pa = a, pb = b;
			a = I[i].a, b = I[i].b;
			while (p[a]){
				int t = p[a];
				p[a] = pa;
				a = t;
			}
			while (p[b]){
				int t = p[b];
				p[b] = pb;
				b = t;
			}
			uec[b]++;
			if (a != b){
				p[a] = b; // b is root;
				uec[b] += uec[a];
				snc[b] += snc[a];
				uec[a] = snc[a] = 0;
			}

			lnk.push_back(b); // subtree's root
			if (I[i].v == I[i + 1].v)continue;

			sort(lnk.begin(), lnk.end());

			int l = -1;
			
			for (int j = 0; j < lnk.size(); j++){
				int g = lnk[j];
				if (!p[g] && l != g){ // only cnt root
					l = g;
					if (uec[g] == snc[g] * (snc[g] - 1) / 2){ // completely include subtree's edge.
						c++;
					}
				}
			}

			lnk.clear();
		}

		printf("%d\n", c);
	}
}