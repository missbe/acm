#include<cstdio>

struct Sort{
   int chinese;
   int total;
   int id;
};
bool isExchange(Sort a,Sort b){
	if(a.total > b.total){
		return true;
	}else if(a.total==b.total){
		if(a.chinese > b.chinese){
			return true;
		}else if(a.chinese==b.chinese){
			if(a.id < b.id)
				return true;
		}
	}
	return false;
}
int main(){
	int N,i,j,k;
	int chinese,math,english;
	Sort *p,temp;

	while(scanf("%d",&N)!=EOF){
		p=new Sort[N+1];

		for(i=1;i<=N;i++){
		  scanf("%d %d %d",&chinese,&math,&english);
		  p[i].total=chinese+math+english;
		  p[i].id=i;
		  p[i].chinese=chinese;
		}
		for(i=1;i<=N-1;i++){
			k=i;
			for(j=i+1;j<=N;j++){
				if(isExchange(p[j],p[k]))
					k=j;
			}
			if(k!=i){
			  temp=p[k];
			  p[k]=p[i];
			  p[i]=temp;
			}
		}
		for(i=1;i<=5;i++){
		  printf("%d %d\n",p[i].id,p[i].total);
		}
		printf("\n");
		delete p;
	}
	return 0;
}