#include<iostream>
using namespace std;

int dp[100][100];//全局，默认初始化为0
int main()
{
    
    int m,n;
    int i,j,k,num;

    dp[0][0] = 1;
	cin>>num;
    for(k=0;k<num;k++){
		cin>>m>>n;
		for(i = 1; i <= n; ++i)//篮子
            for( j =0; j <= m; ++j)//苹果
            {
                if(j>=i)
                {
                    dp[i][j] = dp[i][j-i] + dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[j][j];                 
                }
      
            }            
             cout<<dp[n][m]<<endl;     
	}
    return 0;    
}