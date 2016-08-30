#include <stdio.h>
#include <vector>

#define le(x) (x<<1)
#define ri(x) ((x<<1)|1)

using namespace std;

class Segment{
	public:
		int S;
		vector <int> c, my;
		vector <bool> lz;

		int added;

		Segment(int _S, int _added){
			S = _S, added = _added;
			c.resize(S<<1);
			my.resize(S<<1);
			lz.resize(S<<1);
			init(1, 0, S-1);
		}

		void init(int x, int xl, int xr){
			if(xl < xr){
				int m = (xl + xr) >> 1;
				init(le(x), xl, m);
				init(ri(x), m+1, xr);
				c[x] = c[le(x)] + c[ri(x)];
			}else{
				if(xl >= S-added)c[x] = 0;
				else{
					c[x] = 1;
				}
			}
		}

		int value(int x){
			if(lz[x])return c[x] - my[x];
			return my[x];
		}

		void update(int il, int ir, int x, int xl, int xr){
			
			if(il > xr || ir < xl)return ;
			
			if(il <= xl && xr <= ir){
				//printf("%d to %d updated\n", xl, xr);
				lz[x] = lz[x] ^ true;
			}else{

				int m = (xl + xr) >> 1;

				if(lz[x]){
					lz[le(x)] = lz[le(x)] ^ true;
					lz[ri(x)] = lz[ri(x)] ^ true;
					lz[x] = false;
				}

				update(il, ir, le(x), xl, m);
				update(il, ir, ri(x), m+1, xr);

				my[x] = value(le(x)) + value(ri(x));

			}
		}

		void update(int il, int ir){
			update(il, ir, 1, 0, S-1);
		}

		int query(int il, int ir, int x, int xl, int xr){

			if(il > xr || ir < xl)return 0;

			if(il <= xl && xr <= ir){
				//printf("%d to %d = %d\n", xl, xr, value(x));
				return value(x);
			}else{

				int m = (xl + xr) >> 1;
				
				if(lz[x]){
					lz[le(x)] = lz[le(x)] ^ true;
					lz[ri(x)] = lz[ri(x)] ^ true;
					lz[x] = false;
				}

				int ans = query(il, ir, le(x), xl, m) + query(il, ir, ri(x), m+1, xr);
				my[x] = value(le(x)) + value(ri(x));

				return ans;

			}

		}

		int query(int il, int ir){
			return query(il, ir, 1, 0, S-1);
		}
};

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	int s = 1;
	while(s < n)s <<= 1;

	Segment tree(s, s - n);

	for(int i=1; i<=m; i++){
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);

		a--, b--;

		if(t == 0){
			tree.update(a, b);
		}else{
			printf("%d\n", tree.query(a, b));
		}
	}

}
