#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int T,E,F;
int main(){
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &E, &F);
		printf("%d\n", F- E + 2);
	}
}
