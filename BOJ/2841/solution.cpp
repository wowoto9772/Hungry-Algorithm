#include <cstdio>
#include <stack>

using namespace std;

int main(){

    int n, p;
    scanf("%d %d", &n, &p);

    stack <int> st[6];

    int c = 0;

    for(int i=1; i<=n; i++){

        int a, k;
        scanf("%d %d", &a, &k);

        a--;

        if(st[a].empty() || st[a].top() < k){
            st[a].push(k);
            c++;
        }else{

            while(!st[a].empty() && st[a].top() > k){
                st[a].pop();
                c++;
            }

            if(!st[a].empty() && st[a].top() == k)continue;

            st[a].push(k);
            c++;
         
        }

    }

    printf("%d\n", c);

}
