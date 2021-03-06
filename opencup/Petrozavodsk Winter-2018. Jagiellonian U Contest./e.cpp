#include<bits/stdc++.h>
using namespace std;
const int N=(1<<13);
int T;
int n,m,ans,l;
int f[1594323],d[1594323],a[N+1],num[1594323],to[N*N],c[N+1];
bool bz[N];
inline int turn(int x,int y){
    return to[x*N+y];
}
int dfs(int x,int y,int limit){
    if (!limit||x==(1<<m)-1||(bz[x]&&num[turn(x,y)]<=1))return 0;
    int v=turn(x,y);
    if (f[v])return f[v];
    int s=limit;
    for (int i=0;i<m;i++){
        int z=(1<<i);
        if (z&x)continue;
        int s1=dfs(x+z,y+z,s-1);
        s=min(s,max(s1,dfs(x+z,y,s-1))+1);
    }
    f[v]=s;
    d[++d[0]]=v;
    return s;
}
int C(int x,int y){
    long long s=1;
    for (int i=0;i<y;i++)
        s*=x-i;
    for (int i=1;i<=y;i++)
        s/=i;
    return s;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    for (int i=1;i<N;i++)
        for (int j=0;j<N;j++)
            if ((i&j)==j)
                to[i*N+j]=++to[0];
    while (T--){
        while (d[0]){
            f[d[d[0]]]=num[d[d[0]]]=0;
            d[0]--;
        }
        cin>>n>>m;
        while ((1<<l)<n)++l;
        c[0]=0;
        for (int i=0;i<(1<<m);i++){
            int x=i,y=0;
            while (x)y++,x-=(x&-x);
            if (y>=l&&y<m)c[++c[0]]=i,bz[i]=1;
            else
                bz[i]=0;
        }
        for (int i=1;i<=n;i++){
            char x;
            a[i]=0;
            for (int j=1;j<=m;j++)
                cin>>x,a[i]=a[i]*2+x-'0';
            for (int j=1;j<=c[0];j++)
                num[turn(c[j],a[i]&c[j])]++;
        }
        cout<<dfs(0,0,m)<<endl;
    }
    return 0;
}
