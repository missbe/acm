#include<cstdio>
/*
F[1] = 1
F[2] = 1
F[3] = 1
F[n] = F[n - 1] + F[n - 3]
*/
int main(){
	int f1=1,f2=1,f3=1,M;
	int *p;
	int i;
	while(scanf("%d",&M)!=EOF){
		if(M<=3){
			printf("1\n");
			continue;
		}
		p=new int[M+1];
		p[3]=p[1]=p[2]=1;
		for(i=4;i<=M;i++){
			p[i]=p[i-1]+p[i-3];
		}
		printf("%d\n",p[M]);

	}
	return 0;
}