#include <stdio.h>

#include <vector>

#include <queue>

using namespace std;

class point{
	public:
		int x, y;

		point(){}
		point(int _x, int _y){
			x = _x, y = _y;
		}

		bool operator != (const point &A)const{
			return (x != A.x || y != A.y);
		}

}W[1003];

class edge{
	public:
		point A, B;
		edge(){}
		edge(point _A, point _B){
			A = _A, B = _B;
		}

}P[1003];

int ccw(const point &a, const point &b, const point &c){

	int dx1, dx2, dy1, dy2;
	dx1 = b.x - a.x;
	dy1 = b.y - a.y;
	dx2 = c.x - b.x;
	dy2 = c.y - b.y;

	int ret = dx1*dy2 - dx2*dy1;
	if (ret < 0)return -1;
	else if (ret > 0)return 1;
	else
		return 0;

}

bool meets(const edge &L, const edge &R){

	if(ccw(L.A, L.B, R.A) * ccw(L.A, L.B, R.B) <= 0){
		if(ccw(R.A, R.B, L.A) * ccw(R.A, R.B, L.B) <= 0){
			return true;
		}
	}

	return false;

}

vector < vector <int> > lnk;

int color[1003];

int main(){

	int w, p;
	scanf("%d %d", &w, &p);

	for(int i=1; i<=w; i++){
		scanf("%d %d", &W[i].x, &W[i].y);
	}

	for(int i=1; i<=p; i++){

		int a;
		scanf("%d", &a);

		P[i].A = W[a];
		scanf("%d %d", &P[i].B.x, &P[i].B.y);

	}

	lnk.resize(p+1);

	for(int i=1; i<=p; i++){
		for(int j=i+1; j<=p; j++){

			// fuck same source
			if(P[i].A != P[j].A && meets(P[i], P[j])){
				lnk[i].push_back(j);
				lnk[j].push_back(i);
			}
		}
	}

	queue < int > q;

	bool can = true;

	for(int i=1; i<=p && can; i++){
		
		if(color[i])continue;

		bool flag = true;
	
		color[i] = 1;
		q.push(i);

		while(!q.empty() && flag){
		
			int f = q.front();q.pop();

			for(int j=0; j<lnk[f].size() && flag; j++){
				
				int g = lnk[f][j];

				if(color[g]){
					if(color[g] == -color[f])continue;
					else
						flag = false;
				}else{
					color[g] = -color[f];
					q.push(g);
				}

			}

		}

		can &= flag;

	}

	printf("%s\n", (can) ? "possible" : "impossible");


}
