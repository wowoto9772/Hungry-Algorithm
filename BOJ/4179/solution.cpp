#include <stdio.h>
#include <string.h>

#include <queue>

using namespace std;

class node{
public:
	int r, c;
	node(){}
	node(int a, int b){ r = a, c = b; }
};

char str[1003][1003];
int dead[1003][1003];

bool chk[1003][1003];

int dr[] = { 0, 0, -1, 1 };
int dc[] = { -1, 1, 0, 0 };

int main(){


	int r, c;
	scanf("%d %d", &r, &c);

	node J;

	queue <node> q;
	queue <int> t;

	for (int i = 0; i < r; i++){

		scanf("%s", str[i]);

		for (int j = 0; j < c; j++){
			if (str[i][j] == 'F'){
				q.emplace(i, j);
				t.push(0);

				dead[i][j] = 0;
				continue;
			}
			else if (str[i][j] == 'J'){
				J = node(i, j);
			}
			dead[i][j] = -1;
		}

	}

	while (!q.empty()){

		node f = q.front(); q.pop();
		int m = t.front(); t.pop();

		m++;

		for (int i = 0; i < 4; i++){

			node g = node(f.r + dr[i], f.c + dc[i]);

			if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c)continue;

			if (dead[g.r][g.c] < 0 && str[g.r][g.c] != '#'){

				dead[g.r][g.c] = m;
				q.emplace(g);
				t.push(m);

			}

		}

	}

	q.emplace(J);
	t.push(0);
	chk[J.r][J.c] = true;

	while (!q.empty()){

		node f = q.front(); q.pop();
		int m = t.front(); t.pop();

		m++;

		for (int i = 0; i < 4; i++){

			node g = node(f.r + dr[i], f.c + dc[i]);

			if (g.r < 0 || g.c < 0 || g.r >= r || g.c >= c){

				printf("%d\n", m);
				return 0;

			}

			if (!chk[g.r][g.c] && str[g.r][g.c] != '#'
				&& (m < dead[g.r][g.c] || dead[g.r][g.c] == -1)){

				chk[g.r][g.c] = true;
				q.emplace(g);
				t.push(m);

			}

		}

	}

	printf("IMPOSSIBLE\n");


}