#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int count=0,n;
char prod[10][10],first[10];

void removeLeftRec(){
	int j;
	for(j=0;j<count;j++){
		if(prod[j][0]==prod[j][2]){
			int x,ai=0,bi=0;
			char alpha[10][10],beta[10][10]={'\0'};
			char c = prod[j][0];
			while(prod[j][0]==c){
				if(prod[j][2]==c){
					for(x=3;x<11 && prod[j][x]!='\0';x++)
						alpha[ai][x-3]=prod[j][x];
					ai++;
				}
				else{
					for(x=2;x<11 && prod[j][x]!='\0';x++)
						beta[bi][x-2]=prod[j][x];
					bi++;
				}
				j++;
			}j--;
			printf("%c = ",c);
			for(x=0;x<bi;x++){
				printf("%s%c\'",beta[x],c);
				if(x!=bi-1)
				printf("|");
			}
			printf("\n");
			printf("%c\' = $",c);
			for(x=0;x<ai;x++){
				printf("|%s%c\'",alpha[x],c);
			}
			printf("\n");
		}
		else{
			printf("%s\n",prod[j]);
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
	removeLeftRec();
	return 0;
}










