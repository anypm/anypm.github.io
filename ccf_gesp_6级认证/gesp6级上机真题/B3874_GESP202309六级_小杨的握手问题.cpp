#include <iostream>
using namespace std;

int n;
long long ans;
int arr[300005];
int x[300005];

void bing(int a[],int left,int mid,int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if(a[j] > a[i]){
            x[k] = a[j];
            k++;j++;
            ans += (mid - i + 1);
        }
        else{
            x[k] = a[i];
            k++;i++;
        }
    }
    while(i <= mid){
        x[k] = a[i];
        k++;i++;
    }
    while(j <= right){
        x[k] = a[j];
        k++;j++;
    }

    for(int c = left;c <= right;c++){
        a[c] = x[c];
    }
}

void chai(int a[],int left,int right){
    if(left == right) return ;
    int mid = (left + right) / 2;
    chai(a,left,mid);
    chai(a,mid + 1,right);
    bing(a,left,mid,right);
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    chai(arr,1,n);
    cout << ans << endl;

    return 0;
}