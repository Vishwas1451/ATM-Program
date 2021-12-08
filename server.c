#include<stdio.h>
#include<string.h>
#include"server.h"

int confirm(account_t *p,char name[],int pin)
{
	for(int i=0;i<3;i++)
	{
		if(strcmp((p+i)->name,name)==0&&((p+i)->pin==pin))
			return 1;
	}
	return 0;
}

account_t details(account_t *p,char name[],int pin)
{
	account_t e;
	for(int i=0;i<3;i++)
	{
		if(strcmp((p+i)->name,name)==0&&((p+i)->pin==pin))
		{
			strcpy(e.name,(p+i)->name);
			e.pin = (p+i)->pin;
			e.savings = (p+i)->savings;
		}
	}
	return e;
}

float withdraw(float sav_amt)
{
	float amt;
	printf("Enter the amount you want to withdraw : ");
	scanf("%f",&amt);
	
	if(amt>sav_amt)
		printf("\nInsufficient Balance\n");
	else if(sav_amt<=0)
		printf("\nInsufficient Balance\n");
	else
		sav_amt-=amt;
	return sav_amt;
}

float deposit(float sav_amt)
{
	float amt;
	printf("Enter the amount you want to Deposit : ");
	scanf("%f",&amt);
	sav_amt+=amt;
	return sav_amt;
}

/*
int pin_c(int old_pin)
{
	int new_pin;
	int try = 1;
	do{
		printf("Enter the old pin : ");
		scanf("%d",&new_pin);
		if(new_pin == old_pin)
		{
			printf("Enter the new pin : ");
			scanf("%d",&new_pin);
			printf("PIN Updated");
		}
		else
		{
			if(try<3)
			{
				printf("Wrong PIN entered. Try Again");
				try++;
			}
			else if(try==3)
			{
				exit(0);
			}
		}
		return new_pin;
	}while(try<3)
			

}
*/

void update(account_t *p1,account_t *p2)
{
	for(int i=0;i<3;i++)
	{
		if(strcmp((p1+i)->name,p2->name)==0&&((p1+i)->pin==p2->pin))
		{
			strcpy((p1+i)->name,p2->name);
			(p1+i)->pin = p2->pin;
			(p1+i)->savings = p2->savings;
		}
	}
}