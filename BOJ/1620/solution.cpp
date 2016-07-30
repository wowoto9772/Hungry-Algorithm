#include <stdio.h>
#include <string.h>

#include <map>
#include <string>

using namespace std;

char str[23];

int pan(char *str){
	int s = strlen(str);
	int ret = 0;

	for (int i = 0; i < s; i++){
		ret = ret * 10 + str[i] - '0';
	}

	return ret;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	map <string, int> pars;
	map <int, string> par;
	
	for (int i = 1; i <= n; i++){
		scanf("%s", str);
		par[i] = string(str);
		pars[string(str)] = i;
	}

	for (int i = 1; i <= m; i++){
		scanf("%s", str);
		if (str[0] <= '9' && str[0] >= '0'){
			printf("%s\n", par[pan(str)].c_str());
		}
		else{
			printf("%d\n", pars[string(str)]);
		}
	}
}