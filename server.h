typedef struct Account
{
	char name[50];
	int pin;
	float savings;
}account_t;

int confirm(account_t *p,char name[],int pin);

account_t details(account_t *p,char name[],int pin);

float withdraw(float sav_amt);

float deposit(float sav_amt);

//int pin_c(int old_pin);

void update(account_t *p1,account_t *p2);