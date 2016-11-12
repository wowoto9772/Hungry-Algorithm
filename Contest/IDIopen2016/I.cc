#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <iterator>

using namespace std;


int main()
{
    int N;

    multiset <string> dict;

    scanf("%d",&N);

    for(int i=0;i<N;++i) {

        char s[40];

        int ans;

        scanf("%s",s);
        string x(s);

        multiset<string>::iterator lb = dict.lower_bound(x);
        x.back()++;
        multiset<string>::iterator ub = dict.lower_bound(x);

        if(ub==lb) ans = 0;

        else ans = distance(lb, ub);

        printf("%d\n",ans);

        x.back()--;

        dict.insert(x);
    }

    return 0;
}
