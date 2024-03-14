#include<stdio.h>
int main(){
//	product data
	int code[20];
	char name[20][30];
	int qty[20],discount[20];
	float price[20],total[20],pay[20];
	
	int i,j,n,op;
	
	do{
		printf("-------- ||| PRODUCT MANAGEMENT SYSTEM ||| --------\n");
		printf("1. Input \n");
		printf("2. Output \n");
		printf("3. Search \n");
		printf("4. Update \n");
		printf("5. Insert \n");
		printf("6. Delete \n");
		printf("7. Sort\n");
		printf("8. Add \n");
		printf("please choose an option: ");scanf("%d",&op);
		switch(op){
			case 1:{
				printf("---------| INPUT |-----------\n");
				printf("Enter number of products: ");scanf("%d",&n);
				for(i=0;i<n;i++){
					printf("Input Code     : ");scanf("%d",&code[i]);
					printf("Input Name     : ");fflush(stdin);gets(name[i]);
					printf("Input Quantity : ");scanf("%d",&qty[i]);
					printf("Input Price    : ");scanf("%f",&price[i]);
					total[i] = qty[i]*price[i];
					
					// total <=10 => dis=5
					// total <=25 => dis=10
					// total >=25 => dis=15
					
					if(total[i]<=10){
						discount[i] = 5;
					}
					else if(total[i]<=25){
						discount[i] = 10;
					}
					else{
						discount[i] = 15;
					}
					
					pay[i] = total[i]-(total[i]*discount[i])/100;
					
					
				}
				break;
			}
			case 2:{
				printf("---------| OUTPUT |-----------\n");
				printf("Code \t Name \t Quantity \t Price \t Total \t Discount \t Payment\n");
//				printf("%d \t %s \t %d \t\t %.2f$ \t %.2f$ \t %d \t\t %.2f$\n",111,"Coca",5,10,50,15,30);
				for(i=0;i<n;i++){
					printf("%d \t %s \t %d \t\t %.2f$ \t %.2f$ \t %d%% \t\t %.2f$\n"
						,code[i],name[i],qty[i],price[i],total[i],discount[i],pay[i]);
				}		
				break;
			}
			
		}
	}while(1);
}
