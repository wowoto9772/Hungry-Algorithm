#include <stdio.h>
#include <memory.h>

int main()
{
	int T = 1;
	int a, b;
	bool flag = false;

	int p[103] = { 0 };
	bool u[103] = { 0 };

	while (scanf("%d %d", &a, &b) == 2 && a != -1 && b != -1){
		if (!a && !b){
			printf("Case %d is ", T++);

			int c = 0;

			for (int i = 1; i <= 100; i++){
				if (u[i] && !p[i]){
					c++;
				}
			}

			if (flag || c > 1)printf("not a tree.\n");
			else // if input is 0 0, then output is tree.
				printf("a tree.\n");

			flag = false;
			memset(p, 0, sizeof(p));
			memset(u, 0, sizeof(u));
		}
		else{

			while (p[a])a = p[a];
			while (p[b])b = p[b];

			if (a == b)flag = true;
			else{
				p[a] = b;
			}

			u[a] = true;
			u[b] = true;
		}
	}
}

/*
There is exactly one node, called the root, 
to which no directed edges point.

Every node except the root has 
exactly one edge pointing to it.

There is a unique sequence of directed edges 
from the root to each node.
*/