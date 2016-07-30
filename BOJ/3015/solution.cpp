#include <stdio.h>
#include <stack>

#define ll long long

using namespace std;

int a[500003];

int main(){
	int n;
	scanf("%d", &n);

	stack <pair <int, int> > stk;

	ll ans = 0;

	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);

		if (stk.empty())stk.push(make_pair(i, 1));
		else{
			
			pair <int, int> none (i, 1);

			while (!stk.empty() && a[stk.top().first] <= a[i]){

				ans += stk.top().second;

				if (a[stk.top().first] == a[i]){
					none.second += stk.top().second;
				}

				stk.pop();
			}

			if (!stk.empty()){ 
				// if more than 2(include current(i)), cnt <- cnt + 1
				ans++;
			}

			stk.push(none);
		}
	}

	printf("%lld\n", ans);
}