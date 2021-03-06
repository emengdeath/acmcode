#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200000
using namespace std;
int g[N],a[N*2][2],v[N],deep[N],fa[N][20],l[N],r[N],to[N];
long long f[N*3],sig[N*3];
int n,q;
void ins(int x,int y){
	static int sum=1;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void dfs(int x){
	static int sum=0;
	to[l[x]=++sum]=x;
	deep[x]++;
	for (int i=0;fa[fa[x][i]][i];i++)fa[x][i+1]=fa[fa[x][i]][i];
	for (int i=g[x];i;i=a[i][1])
		if (a[i][0]!=fa[x][0]){
			deep[a[i][0]]=deep[x];
			fa[a[i][0]][0]=x;
			dfs(a[i][0]);
		}
	r[x]=sum;
}
void build(int l,int r,int s){
	if (l==r){
		f[s]=v[to[l]];
		return;
	}
	build(l,(l+r)/2,s+s);
	build((l+r)/2+1,r,s+s+1);
	f[s]=f[s+s]+f[s+s+1];
}
void down(int l,int r,int s){
	if (sig[s]){
		f[s]+=(r-l+1)*sig[s];
		if (l!=r)sig[s+s]+=sig[s],sig[s+s+1]+=sig[s];
		sig[s]=0;
	}
}
void ins(int l,int r,int s,int ll,int rr,int x){
	down(l,r,s);
	if (r<ll||rr<l)return;
	if (ll<=l&&r<=rr){
		sig[s]=x;
		down(l,r,s);
		return;
	}
	ins(l,(l+r)/2,s+s,ll,rr,x),ins((l+r)/2+1,r,s+s+1,ll,rr,x);
	f[s]=f[s+s]+f[s+s+1];
}
long long get(int l,int r,int s,int ll,int rr){
	down(l,r,s);
	if (r<ll||rr<l)return 0;
	if (ll<=l&&r<=rr)return f[s];
	return get(l,(l+r)/2,s+s,ll,rr)+get((l+r)/2+1,r,s+s+1,ll,rr);
}
int getlca(int x,int y){
	int i=19;
	if (deep[x]<deep[y])swap(x,y);
	while (deep[x]!=deep[y]){
		while (deep[fa[x][i]]<deep[y])i--;
		x=fa[x][i];
	}
	i=19;
	while (x!=y){
		while (fa[x][i]==fa[y][i]&&i)i--;
		x=fa[x][i],y=fa[y][i];
	}
	return x;
}
int up(int x,int y){
	int i=19;
	while (deep[x]!=y){
		while (deep[fa[x][i]]<y)i--;
		x=fa[x][i];
	}
	return x;
}
int main(){
//	freopen("e.in","r",stdin);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++)scanf("%d",&v[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	dfs(1);
	build(1,n,1);
	int root=1;
	while (q--){
		int sig,u,v,x;
		scanf("%d %d",&sig,&v);
		if (sig==1){
			root=v;
		}else
		if (sig==2){
			scanf("%d %d",&u,&x);
			int lca1=getlca(u,root);
			int lca2=getlca(v,root);
			int lca3=getlca(u,v);
			if (deep[lca1]<deep[lca2])swap(u,v),swap(lca1,lca2);
			if (lca1==root&&deep[lca3]<=deep[root])ins(1,n,1,1,n,x);
			else
			if (lca1==lca2&&lca1!=lca3)ins(1,n,1,l[lca3],r[lca3],x);
			else{
				int lca4=up(root,deep[lca1]+1);
				ins(1,n,1,1,n,x);
				ins(1,n,1,l[lca4],r[lca4],-x);
			}
		}else{
			int lca1=getlca(v,root);
			if (root==v)printf("%I64d\n",get(1,n,1,1,n));
			else
			if (lca1!=v)printf("%I64d\n",get(1,n,1,l[v],r[v]));
			else{
				int lca2=up(root,deep[v]+1);
				printf("%I64d\n",get(1,n,1,1,n)-get(1,n,1,l[lca2],r[lca2]));
			}
				
		}
	}
	return 0;
}
