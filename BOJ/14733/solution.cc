#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

class Shape{
public:
	int x, y, x_, y_;
	bool operator<(const Shape &A)const{
		if (x == A.x){
			if (x_ == A.x_){
				if (y == A.y)return y_ < A.y_;
				return y < A.y;
			}
			return x_ < A.x_;
		}
		return x < A.x;
	}
}Rect[6002];

int main(){ // plane sweeping : O(n*n) solution

    int n;
	scanf("%d", &n);
		
	int cy[30003] = { 0 };
    int Y[16003] = { 0 };
    
    vector <int> y;

    for (int i = 1; i <= n; i++){
		scanf("%d %d %d %d", &Rect[i].x, &Rect[i].y, &Rect[i].x_, &Rect[i].y_);
        y.push_back(Rect[i].y), y.push_back(Rect[i].y_);
	}
    
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());

	sort(Rect + 1, Rect + 1 + n);

	long long ans = 0;

	for (int i = 0; i < y.size()-1; i++){
		ll dy = y[i + 1] - y[i];
		int s = -1, e = -1;
		bool f = false;
		for (int j = 1; j <= n; j++){
			if (Rect[j].y <= y[i] && y[i + 1] <= Rect[j].y_){
				if (!f){
					f = true;
					s = Rect[j].x;
					e = Rect[j].x_;
				}
				else{
					if (s <= Rect[j].x && Rect[j].x <= e){
						if (e < Rect[j].x_)e = Rect[j].x_;
					}
					else{
						ans += dy * (ll)(e - s);
						s = e = -1;
						f = false;
						j--;
					}
				}
			}
		}
		if (f)ans += dy * (ll)(e - s);
	}
	printf("%lld\n", ans);

}