#include<iostream>
#include<algorithm>
#include<cstdio>
#define eps 1e-6
#define R 100
#define N 1000000
#include<cmath>
#include<ctime>
using namespace std;
typedef double ld;
struct point{
	ld x,y;
	point(ld X=0,ld Y=0){x=X,y=Y;}
	void trans(){
		x=R*R/x,y=R*R/y;
	}
	ld len(){
		return sqrt(x*x+y*y);
	}
	void read(){
		scanf("%lf %lf",&x,&y);
	}
}a[N],b[N],ans;
int T;
int n;
ld r;
point operator /(point a,ld b){
	return point(a.x/b,a.y/b);
}
ld operator *(point a,point b){
	return a.x*b.y-a.y*b.x;
}
point operator -(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
point operator +(point a,point b){
	return point(a.x+b.x,a.y+b.y);
}
ld sqr(ld x){
	return x*x;
}
bool equal(ld x,ld y){
	return abs(x-y)<eps;
}
ld dis(point a,point b){
	a=a-b;
	return a.len();
}
ld cross(point a,point b,point c){
	return (b-a)*(c-a);
}
point circumcenter(point a,point b,point c){
	ld A1=2*(b.x-a.x),B1=2*(b.y-a.y),C1=(sqr(b.x)+sqr(b.y)-sqr(a.x)-sqr(a.y));
	ld A2=2*(c.x-a.x),B2=2*(c.y-a.y),C2=(sqr(c.x)+sqr(c.y)-sqr(a.x)-sqr(a.y));
	return point((C1*B2-B1*C2)/(A1*B2-B1*A2),(A1*C2-C1*A2)/(A1*B2-B1*A2));
}
void get(point a,point b,point c,point&p,ld&r){
	ans=circumcenter(a,b,c);
	a=a-ans;
	r=a.len();
}
bool check(){
	int sum=0;
	if (abs(ans.x)>1e9||abs(ans.y)>1e9||r>1e9)return 0;
	for (int i=1;i<=n;i++)
		if (equal(dis(a[i],ans),r))sum++;
	return sum>=(n+1)/2;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			a[i].read();
		if ((n+1)/2==1){
			ans=a[1]+point(1,0),r=1;
		}else
		if ((n+1)/2==2){
			ans=(a[1]+a[2])/2;
			a[1]=a[1]-ans;
			r=a[1].len();
		}else{
			point x,y,z;
			do{
				do{
					x=a[rand()%n+1];
					y=a[rand()%n+1];
					z=a[rand()%n+1];
				}while (cross(x,y,z)<eps);
				get(x,y,z,ans,r);
			}while (!check());
		}
		printf("%5f %5f %5f\n",ans.x,ans.y,r);
	}
	return 0;
}
