#include <iostream>
#include <vector>
using namespace std;

struct node{
    int end;
    int val;
};

int n;
long long sum,maxn;
vector<node> arr[100005];

void dfs(int father,int x,long long dis){
    maxn = max(maxn,dis);
    for(int i = 0;i < arr[x].size();i++){
        if(arr[x][i].end != father){
            dfs(x,arr[x][i].end,dis + arr[x][i].val);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int u,v,l;
        cin >> u >> v >> l;
        sum += l;
        arr[u].push_back({v,l});
        arr[v].push_back({u,l});
    }
    dfs(0,1,0);
    cout << sum * 2 - maxn << endl;

    return 0;
}