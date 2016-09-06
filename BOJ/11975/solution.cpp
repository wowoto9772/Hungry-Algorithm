#include <stdio.h>

#include <vector>

#include <set>

#include <algorithm>

using namespace std;

#define x first
#define y second

char str[1003];

class edge{
	public:
		int ax, ay, bx, by;
		edge(){}
		edge(int _ax, int _ay, int _bx, int _by){
			ax = _ax, ay = _ay, bx = _bx, by = _by;
			if(ax > bx){
				swap(ax, bx);
				swap(ay, by);
			}else if(ax == bx){
				if(ay > by)swap(ay, by);
			}
		}

		bool operator<(const edge &A)const{
			if(ax == A.ax){
				if(ay == A.ay){
					if(bx == A.bx)return by < A.by;
					return bx < A.bx;
				}
				return ay < A.ay;
			}
			return ax < A.ax;
		}

		bool operator==(const edge &A)const{
			return ax == A.ax && ay == A.ay && bx == A.bx && by == A.by;
		}
};

int main(){

	int n;
	scanf("%d", &n);

	scanf("%s", str);

	set < pair<int,int> > V;

	vector < edge > E;

	int xx = 0, yy = 0;

	V.emplace(xx, yy);

	for(int i=0; i<n; i++){

		int nx = xx, ny = yy;
		
		if(str[i] == 'N'){
			ny++;
		}else if(str[i] == 'S'){
			ny--;
		}else if(str[i] == 'E'){
			nx++;
		}else{
			nx--;
		}

		V.emplace(nx, ny);

		E.emplace_back(xx, yy, nx, ny);

		xx = nx, yy = ny;

	}

	sort(E.begin(), E.end());
	E.resize(unique(E.begin(), E.end()) - E.begin());

	int v = V.size(), e = E.size();

	// v - e + f = 2
	// f-1 = e - v + 1

	printf("%d\n", e-v+1);

}
