#include <cstdio>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int ds;
        scanf("%d", &ds);
    
        int m;
        scanf("%d", &m);

        int m1 = 1, m2 = 1;
        int p = 0;

        bool first = true;

        while(first || (m1 != 1 || m2 != 1)){
            int tmp = (m1+m2) % m;
            m1 = m2;
            m2 = tmp;
            p++;
            first = false;
        }

        printf("%d %d\n", ds, p);

    }

}
