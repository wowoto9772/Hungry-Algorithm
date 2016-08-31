#include <stdio.h>
#include <vector>

#define ll long long

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	ll ans = 0;

	vector <int> X, Y;

	for(int i=0; i<n; i++){

		int a;
		scanf("%d", &a);

		if(X.empty()){
			X.push_back(a), Y.push_back(i);
		}else{
			int k = X.size() - 1;

			if(X[k] > a){
				X.push_back(a), Y.push_back(i);
			}else{

				bool f = false;

				while(!X.empty()){
					if(X[k] <= a){
						int y = Y[k];
						ans += i-y-1;
						X.pop_back(), Y.pop_back();
						k--;
					}else{
						f = true;
						X.push_back(a), Y.push_back(i);
						break;
					}
				}
				
				if(!f){
					X.push_back(a), Y.push_back(i);
				}
			}
		}
	}

	for(int i=0; i<Y.size(); i++)ans += Y.back() - Y[i];

	printf("%lld\n", ans);
}

