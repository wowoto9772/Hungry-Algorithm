#include <cstdio>
#include <vector>

using namespace std;

bool p[10003];

vector <int> P;
void calc(vector <int> &Q, int v, bool add){
    for(int i=0; i<P.size() && P[i] <= v; i++){
        int j = P[i];
        while(j <= v){
            Q[i] = Q[i] + v / j * ((add) ? 1 : -1);
            j *= P[i];
        }
    }
}

int main(){

    for(int i=2; i*i <= 10000; i++){
        if(!p[i]){
            for(int j=i*i; j<=10000; j+=i)p[j] = true;
        }
    }

   for(int i=2; i<=10000; i++)if(!p[i])P.push_back(i);

    int a, b, c, d;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4){

        // a! d! (c-d)!
        // ------------
        // b! (a-b)! c!
       
        vector <int> q(P.size());

        calc(q, a, true);
        calc(q, d, true);
        calc(q, c-d, true);
        calc(q, b, false);
        calc(q, a-b, false);
        calc(q, c, false);

        double ans = 1.0;

        for(int i=0; i<q.size(); i++){
            if(!q[i])continue;
            if(q[i] < 0){
                for(int j=q[i]; j<=-1; j++)ans /= (double)P[i];
            }else{
                for(int j=1; j<=q[i]; j++)ans *= (double)P[i];
            }
        }

        printf("%.5lf\n", ans);
        
    }

}
