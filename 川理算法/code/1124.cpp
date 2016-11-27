#include<cstdio>

int main(){
	int N,n;
	int i;
	int factorial_n,factorial_n_one;
	double result;
	int temp,remainder;

	scanf("%d",&N);
	while(N--){
		scanf("%d",&n);
		factorial_n=1;
		factorial_n_one=1;
		for(i=n;i>0;i--){
			factorial_n *=n;
			factorial_n_one *= i;
		}
		if(n > 1){
		  factorial_n_one=factorial_n/n;
		}else{
			factorial_n_one=0;
		}
		printf("N:%d N-1:%d\n",factorial_n,factorial_n_one);

		result=factorial_n_one*1.0/(factorial_n*factorial_n);
		temp = (int)(result * 100000);
		printf("Temp_One:%d\n",temp);
		remainder=temp%10;
		temp /=10;
		if(remainder>=5){
			temp++;
		}
		printf("Temp_Two:%d\n",temp);
		result=1.0*temp/100;

		printf("%.2f%%\n",result);
	}
	return 0;
}