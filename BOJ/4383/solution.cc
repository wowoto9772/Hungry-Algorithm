#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) == 1){
        vector <bool> chk(n);
        vector <int> e(n);
		bool flag = false;

		for(int i=0; i<n; i++){
			scanf("%d", &e[i]);
			if(i >= 1){
				int t = abs(e[i] - e[i-1]);
				if(t > 0 && t < n && chk[t] == false)chk[t] = true;
				else
					flag = true;
			}
		}

		if(flag == true)printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
}
