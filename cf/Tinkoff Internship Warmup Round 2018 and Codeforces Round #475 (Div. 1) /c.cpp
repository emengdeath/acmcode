#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
struct node{
    long long x,y,sum;
}a[N];
int b[N],Gcd[N];
int n,ans;
bool cmp(const node&a,const node&b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
long long gcd(long long x,long long y){
    return !y?x:gcd(y,x%y);
}
int did(int x){
    if (x%b[0])return x%b[0];
    return b[0];
}
bool check(int l,int r){
    if (r-l+1!=b[0])return 0;
    for (int i=1;i+l-1<=r;i++)
        if (a[i].y!=b[i])return 0;
    return 1;
}
void work(){
    for (int i=1;i<=n;i++)
        b[i]=a[i].y;
    sort(b+1,b+n+1);
    b[0]=1;
    for (int i=2;i<=n;i++)if (b[b[0]]!=b[i])b[++b[0]]=b[i]; 
    if (b[0]==1&&n!=1)return;
    if (n%b[0]){
        return;
    }
    sort(a+1,a+n+1,cmp);
    int l=1;
    long long Gcd=a[1].sum;
    for (int i=1;i<=n;i++)
        if (a[l].x!=a[i].x){
            if (!check(l,i-1)){
                return;
            }
            l=i;
        }
    if (!check(l,n)){
        return;
    }
    for (int i=1;i<=n;i++)
        Gcd=gcd(Gcd,a[i].sum);
    for (int i=1;(long long)i*i<=Gcd;i++)
        if (Gcd%i==0){
            ans++;
            if ((long long)i*i!=Gcd)ans++;
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    bool sig=0;
    for (int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].sum,b[i]=a[i].y;
        if (a[i].x!=a[i].y)sig=1;
    }
    work();
    if (sig){
        for (int i=1;i<=n;i++)
            swap(a[i].x,a[i].y);
        work();
    }
    cout<<ans;
    return 0;
}
