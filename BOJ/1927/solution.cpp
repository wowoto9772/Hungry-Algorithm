#include <cstdio>
#include <algorithm>

using namespace std;

// max heap
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

char str[8];

int main(){

    int n;
    scanf("%d", &n);

    while(n--){
        int v;
        scanf("%d", &v);

        if(v)push(v);
        else
            printf("%d\n", pop());
    }

}
