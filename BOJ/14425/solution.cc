#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char str[103];
char pt[103];

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector <string> v(n);
	for(int i=0; i<n; i++){
		scanf("%s", str);
		v[i] = string(str);
	}
	
	sort(v.begin(), v.end());
	
	int ans = 0;
	while(m--){
		scanf("%s", pt);
		string u = string(pt);
		int l = 0, r = n-1, x;
		while(l <= r){
			x = (l+r) / 2;
			if(v[x] < u) l = x + 1;
			else if(v[x] > u)r = x - 1;
			else{
				ans++;
				break;	
			}
		}
	}
	
	printf("%d\n", ans);
	
}