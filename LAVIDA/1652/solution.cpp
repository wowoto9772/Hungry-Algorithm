#include <stdio.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int a, b, c;
	ele(){}
	ele(int x, int y, int z){ a = x, b = y, c = z; }
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}I[10003];

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		int n;
		scanf("%d", &n);

		int top = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int a;
				scanf("%d", &a);
				if (i != j){
					I[top++] = ele(i, j, a);
				}
			}
		}

		sort(I, I + top);

		int p[103] = { 0 };
		int ans = 0;

		for (int i = 0; i < top; i++){
			int a = I[i].a, b = I[i].b;
			while (p[a])a = p[a];
			while (p[b])b = p[b];
			int pa = a, pb = b;
			while (p[a]){
				int k = p[a];
				p[a] = pa;
				a = k;
			}
			while (p[b]){
				int k = p[b];
				p[b] = pb;
				b = k;
			}
			if (a != b){
				ans += I[i].c;
				p[a] = b;
			}
		}

		printf("%d\n", ans);
	}
}