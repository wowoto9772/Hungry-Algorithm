#include <stdio.h>
#include <algorithm>

using namespace std;

class ele{
public:
	int x, y;
	bool operator<(const ele &A)const{
		if (x == A.x)return y < A.y;
		return x < A.x;
	}
}I[100003];

int main(){

	int t;
	scanf("%d", &t);

	while (t--){

		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			scanf("%d %d", &I[i].x, &I[i].y);
		}

		sort(I, I + n);

		int mY = I[0].y;
		int mX = I[0].x;
		int ans = 1;
		for (int i = 1; i < n; i++){
			if (mY >= I[i].y){
				ans++;
				mY = I[i].y;
				mX = I[i].x;
			}
			else{
				if (mX >= I[i].x){
					ans++;
					mY = I[i].y;
					mX = I[i].x;
				}
			}
		}
		printf("%d\n", ans);

	}

}