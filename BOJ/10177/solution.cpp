#include <cstdio>
#include <vector>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int n;
        scanf("%d", &n);

        vector < vector <int> > e;
        e.resize(n);

        bool flag = false;
        int goal = 0;

        for(int i=0; i<n; i++){
            e[i].resize(n);
            for(int j=0; j<n; j++){
                scanf("%d", &e[i][j]);
                if(i == 0)goal += e[i][j];
            }
            if(i){
                int cmp = 0;
                for(int j=0; j<n; j++){
                    cmp += e[i][j];
                }
                if(goal != cmp)flag = true;
            }
        }

        for(int i=0; i<n; i++){
            int cmp = 0;
            for(int j=0; j<n; j++){
                cmp += e[j][i];
            }
            if(goal != cmp)flag = true;
        }

        int td = 0, bd = 0;
        for(int i=0; i<n; i++){
            bd += e[i][i];
            td += e[i][n-1-i];
        }

        if(goal != bd || goal != td)flag = true;
        if(flag)printf("Not a magic square");
        else{
            printf("Magic square of size %d", n);
        }

        printf("\n");

    }

}
