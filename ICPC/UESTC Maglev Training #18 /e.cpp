#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
struct node{
	int cost,v;
}b[N];
struct que{
	int bz,v;
}a[N];
int ans[N];
int n,m;
bool cmp(const que&a,const que&b){
	return a.v>b.v;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i].v),a[i].bz=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i].v);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i].cost);
	for (int i=1;i<=n;i++){
		int x=0;
		for (int j=1;j<=m;j++)
			if (b[j].v>=a[i].v&&(!x||b[x].cost>b[j].cost))
				x=j;
		if (!x){
			printf("impossible\n");
			return 0;
		}
		b[x].v=0;
		ans[a[i].bz]=x;	
	}
	printf("%d",ans[1]);
	for (int i=2;i<=n;i++)
		printf(" %d",ans[i]);
	return 0;
}
