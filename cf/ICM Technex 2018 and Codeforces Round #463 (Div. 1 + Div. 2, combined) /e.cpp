#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 5001
#define MOD 1000000007
using namespace std;
int f[N][N];
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
	}
	return s;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	f[0][0]=1;
	for (int i=0;i<k;i++)
		for (int j=0;j<=k;j++)
			if (f[i][j]){
				int b=j,c=n-j;
				(f[i+1][b]+=(long long)f[i][j]*b%MOD)%=MOD;
				(f[i+1][b+1]+=(long long)f[i][j]*c%MOD)%=MOD;
			}
	long long ans=0;
	for (int i=0;i<=k;i++)
		(ans+=(long long)calc(2,n-i)*f[k][i]%MOD)%=MOD;
	printf("%d\n",(int)ans);
	return 0;
}
