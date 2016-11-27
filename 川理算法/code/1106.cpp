#include<cstdio>

int main(){
	int *f;
	int N,i;

	while(scanf("%d",&N)!=EOF){
	  if(N<=3){
		 printf("1\n");
	  }else{
	  	 f=new int[N+1];
		 f[0]=f[1]=f[2]=f[3]=1;
		 for(i=4;i<=N;i++)
			 f[i]=f[i-1]+f[i-3];
		  printf("%d\n",f[N]);
		  delete f;
	  }
	}
	return 0;
}