#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){

        int a, b;
        scanf("%d/%d", &a, &b);

        string ans = "";

        while(a != 1 || b != 1){

            if(a > b){
                int c = a / b;
                if(!(a % b))c--;
                for(int i=1; i<=c; i++)ans += 'R';
                a -= c * b;
            }else{
                int c = b / a;
                if(!(b % a))c--;
                for(int i=1; i<=c; i++)ans += 'L';
                b -= c * a;
            }

        }
        
        reverse(ans.begin(), ans.end());

        int d = 1;

        for(int i=0; i<ans.size(); i++){
            d *= 2;
            if(ans[i] == 'R')d++;
        }

        printf("%d\n", d);

    }

}
