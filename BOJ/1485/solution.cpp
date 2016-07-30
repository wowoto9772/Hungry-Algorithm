#include <stdio.h>
#include <vector>

#define ll long long

using namespace std;

class vec{
public:
	ll x, y;
	vec(){}
	vec(ll a, ll b){ x = a, y = b; }
	
	vec operator -(const vec &A)const{
		return vec(x - A.x, y - A.y);
	}

	int operator *(const vec &A)const{
		return x*A.x + y*A.y;
	}

};

vec v[4];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){
		
		for (int i = 0; i < 4; i++)scanf("%d %d", &v[i].x, &v[i].y);

		bool flag = false;
		for (int i = 1; i < 16; i++){
			int c = 0;
			vector <vec> v1, v2;
			for (int j = 0; j < 4; j++){
				if (i&(1 << j)){
					c++;
					v1.push_back(v[j]);
				}
				else{
					v2.push_back(v[j]);
				}
			}
			if (c == 2){
				vec x = v1[0] - v1[1];
				vec y = v2[0] - v2[1];

				if (x*y == 0){ 
					// two diagonal are orthogonal
					if (x*x == y*y){
						// two diagonal are same length
						flag = true;
					}
				}
			}
		}

		printf("%d\n", (flag) ? 1 : 0);
	}

}