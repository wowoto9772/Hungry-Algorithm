#include <stdio.h>

#include <string.h>

#include <string>

#include <vector>

#include <map>

using namespace std;

char str[10503];
char howl[103], ani[403];

int main(){

	int t;
	scanf("%d ", &t);
	
	while(t--){

		fgets(str, sizeof(str), stdin);

		vector <string> tar;

		int s = strlen(str);

		if(str[s-1] == '\n')str[s-1] = 0, s--;

		char *token = strtok(str, " ");

		while(token != NULL){
			tar.push_back(string(token));
			token = strtok(NULL, " ");
		}
		
		map <string, bool> del;

		while(true){

			fgets(ani, sizeof(ani), stdin);

			int a = strlen(ani);

			if(ani[a-1] == '\n')ani[a-1] = 0;

			if(strcmp(ani, "what does the fox say?") == 0)break;

			sscanf(ani, "%*s %*s %s", howl);

			del[string(howl)] = true;

		}

		bool print = false;

		for(int i=0; i<tar.size(); i++){
			if(del[tar[i]])continue;
			print = true;
			printf("%s ", tar[i].c_str());
		}

		if(print)printf("\n");

	}

}
