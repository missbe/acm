#include<cstdio>

int main(){
	int m;
	int i,x;
	while(scanf("%d",&m)!=EOF){
		x=1;
	   for(i=2;i<=m;i++)
		   x=(x+1)*2l;
		printf("%d\n",x);
	}
	return 0;
}