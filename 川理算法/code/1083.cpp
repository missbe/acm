#include<cstdio>

int main(){
	int N,*p;
	int line;
	int count;
	int i,j,k;
	int num;

    while(scanf("%d",&line)!=EOF){
	  while(line--){
		scanf("%d",&N);
		p=new int[N+1];

		for(i=1;i<=N;i++){
			p[i]=i;
		}
		if(N <= 3){
			printf("1");
				for(i=2;i<=N;i++)
					printf(" %d",i);
				printf("\n");
				continue;
		}
		num=N;
		count=2;
		while(num > 3){			
			k=0;
	    	for(j=1;j<=N;j++){
				if(p[j]!=-1)
					k++;
				if(k==count){
				    p[j]=-1;
					k=0;
					num--;
//					printf("Num:%d K:%d P[%d]:%d\n",num,k,j,p[j]);
				}
			}
			if(count==2)
				count=3;
			else
				count=2;
		}//end while num
		k=0;
		for(i=1;i<=N;i++){
		  if(p[i]!=-1){
			if(k<num-1)
			     printf("%d ",p[i]);
			else
				 printf("%d\n",p[i]);			
			 k++;
			}
		}
		delete p;
	  }
	}///end while
	return 0;
}