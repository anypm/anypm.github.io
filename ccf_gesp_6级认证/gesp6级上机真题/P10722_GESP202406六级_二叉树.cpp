#include <iostream>
using namespace std;

struct node{
    int lt;
    int rt;
};

int n,q;
node arr[100005];
bool flag[100005],op[100005];

void dfs(int x,bool y){
    if(x == 0) return ;
    if(y == true) flag[x] = !flag[x];

    int ls = arr[x].lt;
    int rs = arr[x].rt;
    dfs(ls,y ^ op[ls]);
    dfs(rs,y ^ op[rs]);
}

int main(){
    cin >> n;
    for(int i = 2;i <= n;i++){
        int num;
        cin >> num;
        if(arr[num].lt == 0) arr[num].lt = i;
        else arr[num].rt = i;
    }
    for(int i = 1;i <= n;i++){
        char ch;
        cin >> ch;
        flag[i] = ch - '0';
    }
    cin >> q;
    while(q--){
        int cnt;
        cin >> cnt;
        op[cnt] = !op[cnt];
    }
    dfs(1,op[1]);

    for(int i = 1;i <= n;i++){
        cout << flag[i];
    }
    cout << endl;

    return 0;
}