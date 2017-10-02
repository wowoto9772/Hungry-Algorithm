#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

char str[380000];
char twrd[35] = {};

int main(){

	int n;
	scanf("%d", &n);

	fgets(str, sizeof(str), stdin); // for buffer

	map <string, int> id;
	queue <string> parrot[103];

	bool possible = true;

	for (int i = 1; i <= n; i++){
		fgets(str, sizeof(str), stdin);
		int s = strlen(str);
		if (str[s - 1] == '\n')s--;
		string tpre;
		for (int j = 0; j < s && possible;){
			if (str[j] == ' '){
				j++;
				continue;
			}
			sscanf(str + j, "%s", twrd);
			int k = strlen(twrd);
			string tmp = string(twrd);
			if (id.find(tmp) == id.end()){
				id[tmp] = i;
				parrot[i].push(tmp);
				j += k;
			}
			else{
				possible = false;
			}
		}
	}

	fgets(str, sizeof(str), stdin);
	int s = strlen(str);
	if (str[s - 1] == '\n')s--;

	for (int i = 0; i < s && possible;){

		if (str[i] == ' '){
			i++;
			continue;
		}

		sscanf(str + i, "%s", twrd);
		int k = strlen(twrd);
		string tmp = string(twrd);
		bool flag = false;
        if(parrot[id[tmp]].empty() || parrot[id[tmp]].front() != tmp){
            possible = false;
        }else{
		    i += k;
			parrot[id[tmp]].pop();
        }
	}

	for (int i = 1; i <= n; i++)possible &= parrot[i].empty();

	if (possible)printf("Possible");
	else
		printf("Impossible");

}