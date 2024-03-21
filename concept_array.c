#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
//	product data
	int code[20];
	char name[20][30];
	int qty[20],discount[20];
	float price[20],total[20],pay[20];
	
	int i,j,n,op;
	
	
//	blog function
	
	void input(){
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

	void output(){
		printf("%d \t %s \t %d \t\t %.2f$ \t %.2f$ \t %d%% \t\t %.2f$\n"
				,code[i],name[i],qty[i],price[i],total[i],discount[i],pay[i]);
	}
	
	
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
		printf("9. Check out \n");
		printf("please choose an option: ");scanf("%d",&op);
		switch(op){
			case 1:{
				printf("---------| INPUT |-----------\n");
				printf("Enter number of products: ");scanf("%d",&n);
				for(i=0;i<n;i++){	
					input();
				}
				break;
			}
			case 2:{
				printf("---------| OUTPUT |-----------\n");
				printf("Code \t Name \t Quantity \t Price \t Total \t Discount \t Payment\n");
				for(i=0;i<n;i++){
					output();
				}		
				break;
			}
			
			case 3:{
				printf("---------| SEARCH |-----------\n");
				int search;
				int check = 0;
				printf("Enter Code to search: ");scanf("%d",&search);
				for(i=0;i<n;i++){
					if(search == code[i]){
						printf("Code \t Name \t Quantity \t Price \t Total \t Discount \t Payment\n");
						output();
						check=1;
					}
				}	
				if(check==0){
					puts("code not found...!");
				}
				break;
			}
			case 4:{
				printf("---------| UPDATE |-----------\n");
				int update;
				int check = 0;
				printf("Enter Code to update: ");scanf("%d",&update);
				for(i=0;i<n;i++){
					if(update == code[i]){
						input();
						check=1;
					}
				}	
				if(check==0){
					puts("Update not success...!");
				}
				else{
					puts("Update Success....!");
				}
				break;
			}
			case 5:{
				printf("---------| INSERT |-----------\n");
				int insert;
				int check = 0;
				printf("Enter code to insert near: ");scanf("%d",&insert);
				for(i=0;i<n;i++){
					if(insert == code[i]){
						for(j=n;j>i;j--){
							code[j]     = code[j-1];
							strcpy(name[j],name[j-1]);
							qty[j]      = qty[j-1];
							price[j]    = price[j-1];
							total[j]    = total[j-1];
							discount[j] = discount[j-1];
							pay[j]      = pay[j-1]; 
						}
						n++;
						input();
						check = 1;
						break;
					}
				}
				if(check == 0){
					puts("Insert not success...!");
				}
				else{
					puts("Insert Success ...!");
				}
				break;
			}
			case 6:{
				int deleted,check=0;
				printf("---------| DELETE |-----------\n");
				printf("Enter Code to Delete: ");scanf("%d",&deleted);
				for(i=0;i<n;i++){
					if(code[i]==deleted){
						for(j=i;j<n-1;j++){
							code[j]    = code[j+1];
							strcpy(name[j],name[j+1]);
							qty[j]     = qty[j+1];
							price[j]   = price[j+1];
							total[j]   = total[j+1];
							discount[j]= discount[j+1];
							pay[j]     = pay[j+1];
						}
						n--;
						check = 1;
						break;
					}
				}
				if(check == 0){
					puts("Delete not Success...!");
				}
				else{
					puts("Delete success...!");
				}
				break;
			}
			case 7:{
				int tcode;
				char tname[20];
				int tqty,tdis;
				float tprice,ttotal,tpay;
				
				printf("---------| SORT |-----------\n");
				for(i=0;i<n;i++){
					for(j=i+1;j<n;j++){
						if(pay[i]<pay[j]){
							tcode   = code[i];
							code[i] = code[j];
							code[j] = tcode;
							
							strcpy(tname,name[i]);
							strcpy(name[i],name[j]);
							strcpy(name[j],tname);
							
							tqty   = qty[i];
							qty[i] = qty[j];
							qty[j] = tqty;
							
							tprice   = price[i];
							price[i] = price[j];
							price[j] = tprice;
							
							ttotal   = total[i];
							total[i] = total[j];
							total[j] = ttotal;
							
							tdis   = discount[i];
							discount[i] = discount[j];
							discount[j] = tdis;
							
							tpay   = pay[i];
							pay[i] = pay[j];
							pay[j] = tpay;
							
						}
					}
				}
				puts("Sort Success...!");
				break;
			}
			case 8:{
				int add;
				printf("How many product to add: ");scanf("%d",&add);
				for(i=n;i<n+add;i++){
					input();
				}
				n=n+add;
				puts("Add Success...!");
				break;
			}
			case 9:{
				float total_cash = 0,cash_resive = 0,cash_return = 0;
				char type_money[6];
				for(i=0;i<n;i++){
					total_cash = total_cash+pay[i];
				}
				printf("Total Money: %.2f$\n",total_cash);
				printf("Total Money: %.2f KHR \n",total_cash*4100);
				printf("->By(KHR/Dollar): ");scanf("%s",&type_money);
				if(strcmp(type_money,"KHR")==0){
					while(1){
						printf("Input Money: ");scanf("%f",&cash_resive);
						total_cash = total_cash*4100;
						if(cash_resive>=total_cash){
							cash_return = cash_resive-total_cash;
							printf("Return Money: %.2f\n",cash_return);
							exit(0);
						}
					}
				}
				else{
					while(1){
						printf("Input Money: ");scanf("%f",&cash_resive);
						if(cash_resive>=total_cash){
							cash_return = cash_resive-total_cash;
							printf("Return Money: %.2f\n",cash_return);
							exit(0);
						}
					}
				}
				break;
			}
		}
	}while(1);
}
