//#include <stdio.h>
//#include <limits.h>
//
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//class ele{
//public:
//	int a, c;
//};
//
//int d[20003];
//
//int main()
//{
//	freopen("large_dat19.in", "r", stdin);
//	freopen("large_dat19.out", "w", stdout);
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	vector < vector <ele> > L;
//	ele psh, pop;
//
//	L.resize(n + 1);
//
//	for (int i = 1; i <= m; i++){
//		int a, b, c;
//		scanf("%d %d %d", &a, &b, &c);
//		psh.a = b, psh.c = c;
//		L[a].push_back(psh);
//	}
//
//	for (int i = 2; i <= n; i++)d[i] = INT_MAX;
//
//	queue <ele> X;
//	d[1] = 0;
//	psh.a = 1, psh.c = 0;
//
//	X.push(psh);
//
//	while (!X.empty()){
//		pop = X.front();
//		X.pop();
//
//		for (int i = 0; i < L[pop.a].size(); i++){
//			psh = L[pop.a][i];
//			if (d[psh.a] > pop.c + psh.c){
//				d[psh.a] = pop.c + psh.c;
//				psh.c = d[psh.a];
//				X.push(psh);
//			}
//		}
//	}
//
//	if (d[n] == INT_MAX)printf("BIG HEAD\n");
//	else
//		printf("%d\n", d[n]);
//}