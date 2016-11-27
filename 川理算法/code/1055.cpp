#include<cstdio>
#include<cassert>

int main(){
	int N,i;
	int num[1001];

	while(scanf("%d",&N) && N!=0)
	{
		assert(N>=1 && N<=1000);
		 num[0]=1,num[1]=1;
		 if(1==N || 2==N){
		   printf("ODD\n");
		   continue;
		 }
	     for(i=2;i<N;i++)
		   num[i]=num[i-1]+num[i-2];
	     if(1==num[N-1]%2)
		   printf("ODD\n");
	     else
	  	   printf("EVEN\n");
	}
    return 0;
}