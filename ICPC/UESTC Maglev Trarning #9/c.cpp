#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 1000
#define MAXN 1e9
#include<cmath>
#include<cstring>
using namespace std;
int n,s,t,ss,tt,sum,ans;
int map[N][N],d[N];
bool bz[N];
int g[N],a[N*N][4],dis[N],pre[N];
void ins(int x,int y,int z,int v){
    a[++sum][0]=y,a[sum][1]=z,a[sum][2]=v,a[sum][3]=g[x],g[x]=sum;
    a[++sum][0]=x,a[sum][1]=0,a[sum][2]=-v,a[sum][3]=g[y],g[y]=sum;
}
void ins(int x,int y,int l,int r,int v){
	ins(x,y,r-l,v),ins(ss,y,l,v),ins(x,tt,l,v);
}
bool spfa(int s,int t){
    static int l,r;
    l=0,r=1;
    d[1]=s;
    for (int i=0;i<N;i++)
        dis[i]=MAXN;
    dis[s]=0;
    bz[s]=1;
    while (l!=r){
        for (int i=g[d[l=l%t+1]];i;i=a[i][3])
            if (a[i][1]&&a[i][2]+dis[d[l]]<dis[a[i][0]]){
                dis[a[i][0]]=a[i][2]+dis[d[l]];
                pre[a[i][0]]=i;
                if (!bz[a[i][0]])
                    d[r=r%t+1]=a[i][0],bz[a[i][0]]=1;
            }
        bz[d[l]]=0;
    }
    return dis[t]!=MAXN;
}
void cost(int s,int t){
    static int x;
    while (spfa(s,t)){
        x=t;
        ans+=dis[t];
        while (x!=s){
            a[pre[x]][1]--;
            a[pre[x]^1][1]++;
            x=a[pre[x]^1][0];
        }
    }
}
int main(){
	freopen("c.in","r",stdin);
    while (scanf("%d",&n)!=EOF){
    	sum=1;
  		for (int i=1;i<=n;i++)
  			for (int j=1;j<=n;j++)
  				scanf("%d",&map[i][j]);
  		s=0,t=n*4+1,ss=t+1,tt=ss+1;
  		for (int i=0;i<=tt;i++)g[i]=0;
  		for (int i=1;i<=n;i++){
  			int l,r,v=0;
  			scanf("%d %d",&l,&r);
  			for (int j=1;j<=n;j++)
  				v+=map[i][j];
  			if (v<=l){
  				ins(i+n+n,t,l-v,r-v,0);
  			}else
  			if (v<=r){
  				ins(s,i,0,v-l,0);
  				ins(i+n+n,t,0,r-v,0);
  			}else
				ins(s,i,v-r,v-l,0);
  		}
  		for (int i=1;i<=n;i++){
  			int l,r,v=0;
  			scanf("%d %d",&l,&r);
  			for (int j=1;j<=n;j++)
  				v+=map[j][i];
  			if (v<=l){
  				ins(i+n+n+n,t,l-v,r-v,0);
  			}else
  			if (v<=r){
  				ins(s,i+n,0,v-l,0);
  				ins(i+n+n+n,t,0,r-v,0);
  			}else
  				ins(s,i+n,v-r,v-l,0);
  		}
  		for (int i=1;i<=n*n/2;i++){
  			int x1,y1,x2,y2;
  			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
  			if (map[x1][y1]==map[x2][y2])continue;
  			if (map[x2][y2]==1)swap(x1,x2),swap(y1,y2);
  			if (x1==x2){
  				ins(y1+n,y2+n+n+n,1,1);
  			}else{
  				ins(x1,x2+n+n,1,1);
  			}
  		}
  		for (int i=1;i<=n+n;i++)
  			ins(i+n+n,i,MAXN,0);
  		ins(t,s,MAXN,0);
  		ans=0;
  		cost(ss,tt);
  		bool sig=1;
  		for (int i=g[ss];i;i=a[i][3])
  			if (a[i][1])sig=0;
  		if (!sig){
  			printf("-1\n");
  			continue;
  		}
  		printf("%d\n",ans);
    }
    return 0;
}
