#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int heap[1<<20];
int size;

void heapifyUp(int c){
    int p = c >> 1;
    while(p >= 1 && heap[c] < heap[p]){
        swap(heap[c], heap[p]);
        c = p;
        p = c >> 1;
    }
}
void heapifyDown(int c){
    int s = c << 1;
    while(s <= size){
        if(s < size && heap[s] > heap[s+1])s++;
        if(heap[c] > heap[s]){
            swap(heap[c], heap[s]);
            c = s;
            s <<= 1;
        }else{
            break;
        }
    }
}
int pop(){
    if(size == 0)return 0;
    int ret = heap[1];
    swap(heap[1], heap[size--]);
    heapifyDown(1);
    return ret;
}
void push(int v){
    heap[++size] = v;
    heapifyUp(size);
}

int main(){
	
	int n;
	scanf("%d", &n);
	
	vector < vector <int> > itm;
	itm.resize(n+1);
	
	for(int i=1; i<=n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		itm[a].push_back(b);
	}
	
	int ans = 0;
	
	for(int i=n; i>=1; i--){
		for(auto &e : itm[i]){
			push(-e);
		}
		ans += -pop();
	}
	
	printf("%d\n", ans);
	
}