#include<cstdio>
#include<cassert>

int main(){
	int *money_dp,*money_num;
	int money_count,money_value_count;
	int temp,i,j;

	while(scanf("%d",&money_count) && money_count!=0){
		assert(money_count>=1 && money_count<=2000);

		scanf("%d",&money_value_count);
		assert(money_value_count>=1 && money_value_count<=10);

		money_num=new int[money_value_count];
		money_dp=new int[money_count+1];

		for(i=0;i<money_value_count;i++){
			scanf("%d",&temp);
			assert(temp>=1 && temp<=1000);
			money_num[i]=temp;
		}
		money_dp[0]=0;
		for(i=1;i<=money_count;i++){
			money_dp[i]=2001;
		}

		for(i=1;i<=money_count;i++){
		   for(j=0;j<money_value_count;j++)
			   if(money_num[j]<=i && money_dp[i-money_num[j]]+1 < money_dp[i])
				   money_dp[i]=money_dp[i-money_num[j]]+1;
		}
		if(2001!=money_dp[money_count])
		  printf("%d\n",money_dp[money_count]);
		else
		  printf("Impossible\n");
	}
	return 0;
}