#include <stdio.h>

#include <queue>

using namespace std;

class ele{
	public:
		int r, c, m;
		ele(){}
		ele(int _r, int _c, int _m){
			r = _r, c = _c, m = _m;
		}
};

char str[36][36];

int main()
{
	int w, h;
	while(scanf("%d %d", &w, &h) == 2){

		if(!(w|h))break;

		for(int i=1; i<=2*h-1; i++){
			if(i&1){
				for(int j=1; j<w; j++)scanf(" %c", &str[i][j]);
			}else{
				for(int j=1; j<=w; j++)scanf(" %c", &str[i][j]);
			}
		}

		queue <ele> q;

		q.emplace(1, 1, 1);

		bool ch[36][36] = {0};

		while(!q.empty()){

			ele f = q.front();q.pop();

			int X = f.r, Y = f.c, C = f.m;

			if(X == h && Y == w){
				printf("%d\n", C);
				break;
			}
			
			// down
			if(X < h && ch[X+1][Y] == false && str[2*X][Y] != '1'){
				q.emplace(X+1, Y, C+1);
				ch[X+1][Y] = true;
			}
			
			// up
			if(X >= 2 && ch[X-1][Y] == false && str[2*X-2][Y] != '1'){
				q.emplace(X-1, Y, C+1);
				ch[X-1][Y] = true;
			}

			// left
			if(Y >= 2 && ch[X][Y-1] == false && str[2*X-1][Y-1] != '1'){
				q.emplace(X, Y-1, C+1);
				ch[X][Y-1] = true;
			}

			// right
			if(Y < w && ch[X][Y+1] == false && str[2*X-1][Y] != '1'){
				q.emplace(X, Y+1, C+1);
				ch[X][Y+1] = true;
			}

		}

		if(!ch[h][w])printf("0\n");

	}
}
