#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100000
#define M 100
#define MOD 100000000
using namespace std;
int mx[2],mn[2];
struct node{
	int x[2];
	long double v;
	long double calc(long double x,int y){
		long double s=1;
		while (y){
			if (y&1)s*=x;
			x*=x,y/=2;
		}
		return s;
	}
	void get(){
		mx[0]=max(mx[0],x[0]);
		mx[1]=max(mx[1],x[1]);
		mn[0]=min(mn[0],x[0]);
		mn[1]=min(mn[1],x[1]);
		v=calc(2,x[0])*calc(3,x[1]);
	}
}a[N],mn1,mx1;
int n;
int main(){
	scanf("%d",&n);
	mx[0]=mx[1]=0,mn[0]=mn[1]=1000;
	for (int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x[0],&a[i].x[1]);
		a[i].get();
		if (i==1||mn1.v>a[i].v)mn1=a[i];
		if (i==1||mx1.v<a[i].v)mx1=a[i];
	}
	n--;
	for (int i=0;i<=n;i++){
		if (i==n){
			printf("%d %d ",mn[0],mn[1]);
		}else
		if (i==n-1){
			printf("%d %d ",mx1.x[0],mx1.x[1]);
		}else
			printf("%d %d ",mx[0],mx[1]);
		if (i==0){
			printf("%d %d\n",mx[0],mx[1]);
		}else
		if (i==1){
			printf("%d %d\n",mn1.x[0],mn1.x[1]);
		}else
			printf("%d %d\n",mn[0],mn[1]);
	}
	return 0;
}
