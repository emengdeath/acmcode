#include<iostream>
#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define N 100000
using namespace std;
int n,m;
long long a[N];
long long calc(long long x,long long y){
	long long s=1;
	while (y){
		if (y&1)(s*=x)%=MOD;
		(x*=x)%=MOD,y/=2;
		if (x==1)break;
	}
	return s;
}
int main(){
	freopen("did.in","r",stdin);
	freopen("did.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		while (m--){
			int l,r,sig,v;
			scanf("%d %d %d",&sig,&l,&r);
			if (sig==1){
				scanf("%d",&v);
				for (int i=l;i<=r;i++)	(a[i]*=v)%=MOD;
			}else
			if (sig==2){
				scanf("%d",&v);
				for (int i=l;i<=r;i++)a[i]=calc(a[i],v);
			}else{
				long long s=1;
				for (int i=l;i<=r;i++)
					(s*=a[i])%=MOD;
				printf("%lld\n",s);
			}
		}
	}
	return 0;
}
