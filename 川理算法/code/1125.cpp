#include<cstdio>

int main(){
	int N;
	int i;
	int *p,temp;
	int sum,previous;

	while(scanf("%d",&N) && N!=0){
		p=new int[N];
		for(i=0;i<N;i++){
			scanf("%d",&temp);
			p[i]=temp;
		}
		previous=p[0];
		sum=0;
		sum=sum+p[0]*6+5;
		for(i=1;i<N;i++){
			if(p[i]-previous>0){
				sum += (p[i]-previous)*6+5;
			}else if(p[i]-previous<0){
				sum += (previous-p[i])*4+5;
			}else{
				sum += 5;
			}
			previous=p[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}