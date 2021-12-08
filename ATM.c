#include<stdio.h>
#include<string.h>
#include"server.h"

int main()
{
	FILE *fp1,*fp2;
	
	fp1 = fopen("Account_Names.txt","r+");
	//fp2 = fopen("Account_Holder.txt","r+");
	
	account_t a1[50],a2;
	account_t *p1 = a1;
	int i=0;
	
	//transfer all the account details in files to array of structures a1
	while(i<3&&(fscanf(fp1,"%s %d %f",a1[i].name,&a1[i].pin,&a1[i].savings))!=EOF)
	{
		i++;
	}
	/*
	for(i=0;i<3;i++)
		printf("%s %d %.2f\n",(p+i)->name,(p+i)->pin,(p+i)->savings);
	*/
	
	int flag = 0,pin;
	char name[50];
	
	while(flag==0)
	{
		fflush(stdin);
	
		printf("Enter Account Name : ");
		scanf("%[^\n]s",name);
		printf("Enter pin : ");
		scanf("%d",&pin);
	
		int check = confirm(p1,name,pin);
	
		if(check)
		{
			printf("\nAccount Found\n");
			flag = 1;
		}
		else
		{
			printf("\nAccount Not Found\n");
			printf("Enter Again\n\n");
		}
		
	}
	//store the account details of the selected person separately
	a2 = details(p1,name,pin);
	account_t *p2 = &a2;
	
	//printf("%s %d %.2f",a2.name,a2.pin,a2.savings);
	
	int flag2=0;
	int ch_t;
	while(flag2==0)
	{
		printf("1. WITHDRAW\n2. DEPOSIT\n3. BALANCE\n4. PIN CHANGE\n5. DENOMINATION\n");
		int ch;
		
		fflush(stdin);
		printf("\nSelect Transaction(1-5) : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1 : a2.savings = withdraw(a2.savings);
			break;
			case 2 : a2.savings = deposit(a2.savings);
			break;
			case 3 : printf("Balance Amount : %.2f",a2.savings);
			break;
			/*
			case 4 : a2.pin = pin_c(a2.pin);
			break;
			*/
			default : printf("\nInvalid Entry\nTry Again\n\n");
			continue;
		}
		fflush(stdin);
		
		printf("\nWould you like to do another transaction(y/n) : ");
		ch_t = getchar();
		
		if(ch_t=='n')
			flag2=1;
	}
	//printf("%.2f",a2.savings);
	
	
	update(p1,p2);
	
	/*
	for(int i=0;i<3;i++)
	{
		printf("%s %d %.2f\n",a1[i].name,a1[i].pin,a1[i].savings);
	}
	*/
	
	//printf("%s %d %.2f",a2.name,a2.pin,a2.savings);
	
	fp2 = fopen("Dummy_Name.txt","w+");
	for(int i=0;i<3;i++)
	{
		fprintf(fp2,"%s %d %.2f\n",a1[i].name,a1[i].pin,a1[i].savings);
	}
	
	fclose(fp1);
	fclose(fp2);
	remove("Account_Names.txt");
	rename("Dummy_Name.txt","Account_Names.txt");
	
	
	return 0;
	
}