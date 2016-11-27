#include<cstdio>
#include <algorithm>

int dp[102][102];
int m[102][102];
int max_ab(int a,int b){
	return a>b ? a : b;
}
int main(){
	int count;
	int i,j;
	int max;

	scanf("%d",&count);
	for(i=1;i<=count;i++){
		for(j=1;j<=i;j++)
			scanf("%d",&m[i][j]);
	}
	for(i=1;i<=count;i++){
		for(j=1;j<=i;j++)
			dp[i][j] = max_ab(dp[i-1][j],dp[i-1][j-1])+m[i][j];
	}
	max=-99999;
	for(i=1;i<=count;i++){
		if(dp[count][i]>max)
			max=dp[count][i];
	}
	printf("%d\n",max);
	return 0;
}