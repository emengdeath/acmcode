#include<cstdio>
#include<algorithm>
#include<iostream>
#define N 10
#define MAXN 1000
#include<ctime>
#define random(x)(rand()%(x))
using namespace std;
int T;
int main(){
	freopen("c.in","w",stdout);
	srand((int)time(0));
	printf("10\n");
	T=10;
	while (T--){
	int n=N;
	int m=N;
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++)
		printf("%d ",random(MAXN)+1);
	printf("\n");
	while (m--){
		int sig=random(3)+1;
		int l=random(N)+1,r=random(N)+1;
		if (l>r)swap(l,r);
		printf("%d %d %d",sig,l,r);
		if (sig<=2)printf(" %d\n",random(MAXN)+1);
		else
			printf("\n");
	}
	}
	return 0;
}
