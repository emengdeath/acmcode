#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define random(x)(rand()%(x))
using namespace std;
int n;
int main(){
	freopen("input","w",stdout);
	srand((int)time(0));
	n=50;
	printf("%d\n",n);
	int all=(n-1)*2;
	for (int i=1;i<n;i++){
		int x=random(all-(n-i))+1;
		printf("%d ",x);
		all-=x;
	}
	printf("%d",all);
	return 0;
}
