#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int count=0,n;
char prod[10][10],first[10];

void findfirst(char c,int p1,int p2){
	int j,t;
	if(!isupper(c)){
		first[n++] = c;
		return ;
	}
	for(j=0;j<count;j++){
		if(c==prod[j][0]){
			if(prod[j][2]=='$'){
				if(prod[p1][p2]!='\0' && (p1!=0 || p2!=0)){
					findfirst(prod[p1][p2],p1,(p2+1));
				}
				else{
					first[n++] = '$';
				}
			}
			else if(!isupper(prod[j][2])){
				first[n++] = prod[j][2];
			}
			else{
				findfirst(prod[j][2],j,3);
			}
		}
	}
}

int main(){
	char c;
	int i;
	printf("Enter the no of productions : ");
	scanf("%d",&count);
	printf("Enter the production with = in place of -> and $ in place of epsilon\n");
	for(i=0;i<count;i++)
	scanf("%s",&prod[i]);
	int t=1;
	do{
		n = 0;
		printf("Enter the element : ");
		scanf("%s",&c);
		printf("FIRST(%c) = { ",c);
		findfirst(c,0,0);
		for(i=0;i<n;i++){
			printf("%c ",first[i]);
		}
		printf("}\nenter 1 to continue and 0 to end : ");
		scanf("%d",&t);
	}while(t==1);
	return 0;
}










