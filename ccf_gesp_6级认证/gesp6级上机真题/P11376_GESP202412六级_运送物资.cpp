#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int p;
    int c;
};
struct car{
    int a;
    int b;
};

int n,m,x;
node a[100005];
car b[100005];
long long ans;

bool compare1(node A,node B){
    return A.p < B.p;
}
bool compare2(car A,car B){
    return A.a - A.b > B.a - B.b;
}

int main(){
    cin >> n >> m >> x;
    for(int i = 1;i <= n;i++){
        cin >> a[i].p >> a[i].c;
    }
    for(int i = 1;i <= m;i++){
        cin >> b[i].a >> b[i].b;
    }
    sort(a + 1,a + 1 + n,compare1);
    sort(b + 1,b + 1 + m,compare2);

    int i = 1;
    int j = 1;
    while(b[i].a > b[i].b){
        if(a[j].c == 0) j++;
        a[j].c--;
        ans += (long long)2 * a[j].p * b[i].a + (long long)2 * (x - a[j].p) * b[i].b;
        i++;
    }

    int p = m;
    int q = n;
    while(p >= i){
        if(a[q].c == 0) q--;
        a[q].c--;
        ans += (long long)2 * a[q].p * b[p].a + (long long)2 * (x - a[q].p) * b[p].b;
        p--;
    }
    cout << ans << endl;

    return 0;
}