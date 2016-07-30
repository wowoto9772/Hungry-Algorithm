#include <stdio.h>
#include <string.h>

#include <deque>

using namespace std;

char str[8];

int main(){

	deque <int> q;

	int n;
	scanf("%d", &n);

	while (n--){

		scanf("%s", str);

		if (!strcmp(str, "push")){
			int x;
			scanf("%d", &x);
			q.push_back(x);
		}
		else if (!strcmp(str, "front") || !strcmp(str, "pop")){
			if (q.size()){
				printf("%d\n", q.front());
				if (!strcmp(str, "pop"))q.pop_front();
			}
			else{
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "back")){
			if (q.size()){
				printf("%d\n", q.back());
			}
			else{
				printf("-1\n");
			}
		}
		else if (!strcmp(str, "empty")){
			printf("%d\n", (q.empty()) ? 1 : 0);
		}
		else if (!strcmp(str, "size")){
			printf("%d\n", q.size());
		}

	}

}