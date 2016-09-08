#include <stdio.h>

#include <algorithm>

using namespace std;

class ele{
	public:
		int a, b, c;

		ele(){}
		ele(int _a, int _b, int _c){
			a = _a, b = _b , c = _c;
		}

		bool operator<(const ele &A)const{
			return c < A.c;
		}
};

#define node(i, j) (4*(c*(i)+(j)))

#define up(i,j) (node(i,j) + 0)
#define right(i,j) (node(i,j) + 1)
#define down(i,j) (node(i,j) + 2)
#define left(i,j) (node(i,j) + 3)

char str[103][103];

int parent[40004];

int findParent(int a){
	if(parent[a] == a)return a;
	return parent[a] = findParent(parent[a]);
}

int main(){

	int t;
	scanf("%d", &t);

	int tc = 0;

	while(t--){

		int r, c;
		scanf("%d %d", &r, &c);

		for(int i=0; i<r; i++)scanf("%s", str[i]);

		vector < ele > edge;

		// 1
		//4 2
		// 3

		for(int i=0; i<r; i++)for(int j=0; j<c; j++){

			int cst;
			scanf("%d", &cst);

			if(str[i][j] == '\\'){
				edge.emplace_back(up(i,j), right(i,j), 0);
				edge.emplace_back(left(i,j), down(i,j), 0);
				edge.emplace_back(up(i,j), left(i,j), cst);
				edge.emplace_back(right(i,j), down(i,j), cst);

				if(i)edge.emplace_back(up(i,j), down(i-1,j), 0);
				if(j != c-1)edge.emplace_back(right(i,j), left(i,j+1), 0);
				if(i != r-1)edge.emplace_back(down(i,j), up(i+1,j), 0);
				if(j)edge.emplace_back(left(i,j), right(i,j-1), 0);
			}else if(str[i][j] == '/'){
				edge.emplace_back(up(i,j), left(i,j), 0);
				edge.emplace_back(right(i,j), down(i,j), 0);
				edge.emplace_back(up(i,j), right(i,j), cst);
				edge.emplace_back(left(i,j), down(i,j), cst);

				if(i)edge.emplace_back(up(i,j), down(i-1,j), 0);
				if(j)edge.emplace_back(left(i,j), right(i,j-1), 0);
				if(i != r-1)edge.emplace_back(down(i,j), up(i+1,j), 0);
				if(j != c-1)edge.emplace_back(right(i,j), left(i,j+1), 0);
			}

		}

		sort(edge.begin(), edge.end());

		for(int i=0; i<r*c*4; i++)parent[i] = i;

		printf("Case %d: ", ++tc);

		int ans = 0;

		for(int i=0; i<edge.size(); i++){

			int a = findParent(edge[i].a), b = findParent(edge[i].b), c = edge[i].c;

			if(a == b)continue;
			else{
				//printf("%d(%d) %d(%d) %d\n", edge[i].a, a, edge[i].b, b, c);
				ans += c;
				parent[a] = b;
			}

		}

		printf("%d\n", ans);

	}

}
