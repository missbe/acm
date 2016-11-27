#include<cstdio>
#include<cassert>

struct time{
	int hour;
	int minute;
	int second;
};
int main(){
	int count;
	time *p,result;
	int i;
	int hour,minute,second;
	bool flag;

	while(scanf("%d",&count)!=EOF){
		p=new time[count];
		flag=true;
		for(i=0;i<count;i++){
			scanf("%d %d %d",&hour,&minute,&second);
			if(minute>=60 ||minute<0|| second>=60||second<0){
				flag=false;
			}
			p[i].hour=hour;
			p[i].minute=minute;
			p[i].second=second;
		}
		if(!flag){
		   printf("not legitimate\n");
		   continue;
		}
		result.hour=0;
		result.minute=0;
		result.second=0;
		for(i=0;i<count;i++){
			result.second += p[i].second;
			result.minute +=result.second/60+p[i].minute;
			result.second %= 60;
			result.hour += result.minute/60+p[i].hour;
			result.minute %= 60;
//			printf("%d %d %d\n",result.hour,result.minute,result.second);
		}
	
		printf("%d  %d  %d\n",result.hour,result.minute,result.second);
		delete p;
	}
	return 0;
}
/*
2
12  24  48  10  13 35
3
1  3  5  2  4  6  0  7  8
2
12 24  36  48  59 60
*/