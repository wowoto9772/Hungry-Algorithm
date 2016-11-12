#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char inp[111];

int main()
{
    scanf("%s",inp);
    int len = strlen(inp);
    int ans = 2*len;
    for(int i=len;i<=(2*len);++i) {
        int cnt = 0;
        int left = 0;
        int right = i-1;
        while(left < right) {
            if(len<=right || inp[left]!=inp[right]) {
                cnt++;
            }
            left++;
            right--;
        }
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
