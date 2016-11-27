#include<cstdio>
#include<cassert>

int main(){
	int N;
	int i,j,*score,temp,check;
	int count;
	while(scanf("%d",&N) && N!=0){
	   assert(N<=1000 && N>=0);
	   score=new int[N];
	   for(i=0;i<N;i++){
		   scanf("%d",&temp);
		   assert(temp>=0 && temp<=100);
		   score[i]=temp;
	   }
	   scanf("%d",&check);
	   count=0;
	   for(i=0;i<N;i++)
		   if(score[i]==check)
			   count++;
		printf("%d\n",count);
	}
	return 0;
}