//#include <stdio.h>
//#include <queue>
//
//using namespace std;
//
//class node{
//public:
//	int r, c;
//	node(){}
//	node(int a, int b){ r = a, c = b; }
//	node operator + (const node &A)const{
//		node ret;
//		ret.r = r + A.r;
//		ret.c = c + A.c;
//		return ret;
//	}
//};
//
//char str[23][23];
//int r, c;
//node d[] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
//node portal[10];
//
//bool Possible(node &start, node &goal, int pmax){
//	bool chk[22][22] = { 0 };
//
//	queue <node> q;
//	q.emplace(start);
//
//	chk[start.r][start.c] = true;
//
//	for (int p = 1; p <= pmax; p++){
//		if (chk[portal[p].r][portal[p].c])continue;
//		q.emplace(portal[p].r, portal[p].c);
//		chk[portal[p].r][portal[p].c] = true;
//	}
//
//
//	while (!q.empty() && !chk[goal.r][goal.c]){
//		node pop = q.front(); q.pop();
//
//		for (int i = 0; i < 4; i++){
//			node psh = pop + d[i];
//			if (psh.r < 0 || psh.c < 0 || psh.r >= r || psh.c >= c)continue;
//			if (chk[psh.r][psh.c])continue;
//
//			if (str[psh.r][psh.c] == '#')continue;
//
//			q.emplace(psh);
//			chk[psh.r][psh.c] = true;
//		}
//	}
//
//	return chk[goal.r][goal.c];
//}
//
//int main(){
//	int t;
//	scanf("%d", &t);
//
//	while (t--){
//		scanf("%d %d", &r, &c);
//
//		node player, goal, btn, box;
//
//		int pcnt = 0; // portal_cnt
//		for (int i = 0; i < r; i++){
//			scanf("%s", str[i]);
//			for (int j = 0; j < c; j++){
//				if (str[i][j] == 'P'){
//					player = node(i, j);
//				}
//				else if (str[i][j] == 'D'){
//					goal = node(i, j);
//				}
//				else if (str[i][j] == 'S'){
//					btn = node(i, j);
//				}
//				else if (str[i][j] == 'B'){
//					box = node(i, j);
//				}
//				else if (str[i][j] >= '1' && str[i][j] <= '9'){
//					portal[str[i][j] - '0'] = node(i, j);
//					pcnt++;
//				}
//			}
//		}
//
//		if (Possible(player, box, pcnt) && 
//			(Possible(player, btn, pcnt) && Possible(player, goal, pcnt)) ||
//			(Possible(player, btn, pcnt) && Possible(btn, goal, pcnt)) ||
//			(Possible(box, btn, pcnt) && Possible(box, goal, pcnt)) ||
//			(Possible(box, btn, pcnt) && Possible(btn, goal, pcnt))){
//			printf("YES\n");
//		}
//		else{
//			printf("NO\n");
//		}
//	}
//}

#include <stdio.h>
#include <queue>

using namespace std;

class node{
public:
	int r, c;
	node(){}
	node(int a, int b){ r = a, c = b; }
	node operator + (const node &A)const{
		node ret;
		ret.r = r + A.r;
		ret.c = c + A.c;
		return ret;
	}
};

char str[23][23];
int r, c;
node d[] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
node portal[10];

bool Possible(node &start, node goal[], int pmax){
	bool chk[22][22] = { 0 };

	queue <node> q;
	q.emplace(start);

	chk[start.r][start.c] = true;

	for (int p = 1; p <= pmax; p++){
		if (chk[portal[p].r][portal[p].c])continue;
		q.emplace(portal[p].r, portal[p].c);
		chk[portal[p].r][portal[p].c] = true;
	}


	while (!q.empty()){
		node pop = q.front(); q.pop();

		for (int i = 0; i < 4; i++){
			node psh = pop + d[i];
			if (psh.r < 0 || psh.c < 0 || psh.r >= r || psh.c >= c)continue;
			if (chk[psh.r][psh.c])continue;

			if (str[psh.r][psh.c] == '#')continue;

			q.emplace(psh);
			chk[psh.r][psh.c] = true;
		}
	}

	return chk[goal[0].r][goal[0].c] && chk[goal[1].r][goal[1].c] && chk[goal[2].r][goal[2].c];
}

int main(){
	int t;
	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &r, &c);

		node player, goal, btn, box;

		int pcnt = 0; // portal_cnt
		for (int i = 0; i < r; i++){
			scanf("%s", str[i]);
			for (int j = 0; j < c; j++){
				if (str[i][j] == 'P'){
					player = node(i, j);
				}
				else if (str[i][j] == 'D'){
					goal = node(i, j);
				}
				else if (str[i][j] == 'S'){
					btn = node(i, j);
				}
				else if (str[i][j] == 'B'){
					box = node(i, j);
				}
				else if (str[i][j] >= '1' && str[i][j] <= '9'){
					portal[str[i][j] - '0'] = node(i, j);
					pcnt++;
				}
			}
		}

		node must[] = { box, btn, goal };
		if (Possible(player, must, pcnt)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}