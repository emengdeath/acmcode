#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 10000
using namespace std;
int a[3][3]={{0,1,2},{2,0,1},{1,2,0}};
int b[N];
int sum[3];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sum[b[i]]++;
	}
	int ans=n*2;
	for (int i=0;i<3;i++){
		int s=a[0][i]*sum[0]+a[1][i]*sum[1]+a[2][i]*sum[2];
		ans=min(ans,s);
	}
	printf("%d",ans);
	return 0;
}
