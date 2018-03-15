#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 200
using namespace std;
int a[N*10][2],g[N],b[N],in[N],f[N],d[N];
bool c[N][N];
int T,n,sum;
void ins(int x,int y){
	in[y]++;
	a[++sum][0]=y,a[sum][1]=g[x],g[x]=sum;
}
void bfs(){
	int l=0,r=0;
	for (int i=1;i<=n;i++)
		if (!in[i])d[++r]=i;
	while (l!=r){
		l++;
		for (int i=0;i<=n;i++)
			if (!c[d[l]][i]){
				f[d[l]]=i;
				break;
			}
		for (int i=g[d[l]];i;i=a[i][1]){
			c[a[i][0]][f[d[l]]]=1;
			if (!(--in[a[i][0]]))d[++r]=a[i][0];
		}
	}
}
int did(int x){
	return x?0:1;
}
int main() {
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		sum=0;
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)g[i]=in[i]=0;
		for (int i=1;i<=n;i++)scanf("%d",&b[i]);
		int x=0;
		for (int i=1;i<=n;i++){
			if (b[i]>b[i-1]&&i>1)ins(i,i-1);
			if (b[i]>b[i+1]&&i<n)ins(i,i+1);
			if (b[i]==1)x=i;
		}
		bfs();
		int ans=0;
		for (int i=1;i<=n;i++)
			if (!g[i]&&i!=x)ans^=f[i];
		!((ans^did(f[x-1]))||(ans^did(f[x+1])))?printf("Alice\n"):printf("Bob\n");
	}
	return 0;
}
