#include<iostream>
#include<algorithm>
#include<cstdio>
#define N 1000000
using namespace std;
int f[N][2],size[N];
int n,tot;
int g[N],d[N],a[N][4],fa[N],b[N];
struct node{
	int x,l,r;
}c[N];
int sum;
void ins(int x,int y){
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;	
}
void dfs(int x){
	size[x]=1;
	for (int i=g[x];i;i=a[i][1])
		dfs(a[i][0]),size[x]+=size[a[i][0]];
	d[0]=0;
	for (int i=g[x];i;i=a[i][1])
		d[++d[0]]=i;
	f[x][0]=f[x][1]=0;
	while (d[0]){
		int v=f[x][0];
		int i=d[d[0]--];
		if (f[a[i][0]][0]>=f[a[i][0]][1])a[i][2]=0;
		else
			a[i][2]=1;
		f[x][0]=f[x][0]+max(f[a[i][0]][0],f[a[i][0]][1]);
		if (f[x][1]+max(f[a[i][0]][0],f[a[i][0]][1])>=v+f[a[i][0]][0]+1){
			if (f[a[i][0]][0]>=f[a[i][0]][1])
				a[i][3]=0;
			else
				a[i][3]=1;
		}else
			a[i][3]=2;
		f[x][1]=max(f[x][1]+max(f[a[i][0]][0],f[a[i][0]][1]),v+f[a[i][0]][0]+1);
	}
}
void dfs1(int x,int y){
	if (!g[x])return;
	for (int i=g[x];i;i=a[i][1]){
		if (y){
			if (a[i][3]==0){
				b[++b[0]]=a[i][0],dfs1(a[i][0],0);				
			}else
			if (a[i][3]==1){
				dfs1(a[i][0],1);
			}else
				y=0,dfs1(a[i][0],0);
		}else{
			if (a[i][2]==0)b[++b[0]]=a[i][0],dfs1(a[i][0],0);
			else
				dfs1(a[i][0],1);
		}
	}
}
bool cmp(const node&a,const node&b){
	return a.r-a.l>b.r-b.l;
}
void update(int x,int y){
	ins(x,y);
	fa[y]=x;
}
int main(){
	freopen("hidden.in","r",stdin);
	freopen("hidden.out","w",stdout);
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		if (fa[i])
		ins(fa[i],i);
	}
	c[++tot].x=1;
	c[tot].l=b[0]+1;
	dfs(1);
	if (f[1][0]>=f[1][1])b[++b[0]]=1,dfs1(1,0);
	else
		dfs1(1,1);
	c[tot].r=b[0];
	for (int i=2;i<=n;i++)
		if (!fa[i]){
			dfs(i);
			if (f[i][1]*2==size[i]){
				update(1,i);
				continue;
			}
			c[++tot].x=i;
			c[tot].l=b[0]+1;
			b[++b[0]]=i;
			for (int j=g[i];j;j=a[j][1]){
				dfs(a[j][0]);	
				if (f[a[j][0]][0]>=f[a[j][0]][1])b[++b[0]]=a[j][0],dfs1(a[j][0],0);
				else
					dfs1(a[j][0],1);
			}
			c[tot].r=b[0];
		}
	sort(c+2,c+tot+1,cmp);
	int l=1;
	d[0]=0;
	for (int i=c[1].l;i<=c[1].r;i++)
		d[++d[0]]=b[i];
	for (int i=2;i<=tot;i++){
		if (l<=d[0]){
			update(d[l],c[i].x);
			l++;
			for (int j=c[i].l+1;j<=c[i].r;j++)
				d[++d[0]]=b[j];
		}else{
			update(1,c[i].x);
			d[++d[0]]=c[i].x;
			swap(d[l],d[d[0]]);
			for (int j=c[i].l+1;j<=c[i].r;j++)
				d[++d[0]]=b[j];
		}
	}
	dfs(1);
	printf("%d\n",max(f[1][1],f[1][0]));
	printf("%d",fa[2]);
	for (int i=3;i<=n;i++)
		printf(" %d",fa[i]);
	return 0;
}
