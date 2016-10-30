#include <cstdio>
#include <deque>

using namespace std;

char w[1003];

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        for(int i=1; i<=n; i++)scanf(" %c", &w[i]);

        deque <int> q;
        q.push_back(w[1]);

        for(int i=2; i<=n; i++){
            if(q.front() >= w[i]){
                q.push_front(w[i]);
            }else{
                q.push_back(w[i]);
            }
        }

        for(auto &e : q){
            printf("%c", e);
        }printf("\n");

    }

}
