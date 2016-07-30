#include <stdio.h>
#include <memory.h>

#include <algorithm>

using namespace std;

class ele{
public:
	int a, b, c;
	bool operator<(const ele &A)const{
		return c < A.c;
	}
}I[10003];

int top;
int p[103];

int main()
{
	int n;
	while (scanf("%d", &n) == 1){ // includes several testcases
		top = 0;
		memset(p, 0, sizeof(p));

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				int a;
				scanf("%d", &a);
				if (a){
					I[top].a = i, I[top].b = j, I[top].c = a;
					top++;
				}
			}
		}

		sort(I, I + top);

		int c = 0, a = 0;


		for (int i = 0; i < top && c != n - 1; i++){
			int x = I[i].a, y = I[i].b, z = I[i].c;
			while (p[x]) x = p[x];
			while (p[y]) y = p[y];
			if (x != y){
				p[x] = y;
				c++;
				a += z;
			}
		}

		printf("%d\n", a);
	}

}