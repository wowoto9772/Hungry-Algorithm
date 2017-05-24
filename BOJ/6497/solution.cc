#include <cstdio>
#include <algorithm>

using namespace std;

class ele{
	public:
	int a, b, c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}edge[200003];

int parent[200003];

int findParent(int a){
	if(parent[a] == a)return a;
	return parent[a] = findParent(parent[a]);
}

int main(){
	
	int n, m;
	while(scanf("%d %d", &n, &m) == 2){
		if((n|m) == 0)break;
		for(int i=0; i<n; i++)parent[i] = i;
		for(int i=0; i<m; i++){
			scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].c);			
		}
		sort(edge, edge+m);
		int x = 0, y = 0;
		for(int i=0; i<m; i++){
			y += edge[i].c;
			if(findParent(edge[i].a) == findParent(edge[i].b))continue;
			parent[findParent(edge[i].a)] = findParent(edge[i].b);
			x += edge[i].c;
		}
		printf("%d\n", y-x);
	}
	
}