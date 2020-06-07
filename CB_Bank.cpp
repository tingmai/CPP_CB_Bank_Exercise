
#include<iostream>

using namespace std;


//for account creation
int account_no[100000];
string name[100000];
string nrc[100000];
int amt[100000];
string phone[100000];

int index=0;



void mainMENU();
void account();
int getChoice();
void view();
void update();
void exitProgram();

int main()
{
	
	bool loop=true;
	
	while(loop){
		
		mainMENU();
		switch(getChoice())
		{
			case 1:account();break;
			case 2:view();break;
			case 3:update();break;
			case 4:exitProgram();loop=false;break;
		}
		
		
	}
	
	
	
}

void mainMENU()
{
	
cout<<" ************************    \n";
cout<<" ----Welcome to CB Bank-----	\n";
cout<<" *************************	\n";
cout<<" Main MENU					\n";
cout<<" [1] Account					\n";
cout<<" [2] View Account			\n";
cout<<" [3] Update					\n";
cout<<" [4] Exit				     \n";
cout<<"------------------------------\n";

}
void exitProgram()
{
	cout<<"Exiting Now...See you....\n";
}

int getChoice()
{
	int choice;
	cout<<"Enter Choice:";
	cin>>choice;
	return choice;
}

void accountMENU()
{
	cout<<"    Account MENU       		\n";
	cout<<"----------------------------\n";
	cout<<" [1] Open Account			\n";
	cout<<" [2] Close Account			\n";
	cout<<" [3] Back to Main MENU		\n";
	cout<<"------------------------------\n";
}

int getAccountNo()
{
	int accno;
	cout<<"Enter Account NO:";
	cin>>accno;
	return accno;
}
string getName(){
	
	string dummy;
	string name;
	
	getline(cin,dummy);
	cout<<"Enter Account Name:";
	getline(cin,name);
	
	return name;
	
}
string getNRC(){
	

	string nrc;

	cout<<"Enter NRC :";
	getline(cin,nrc);
	
	return nrc;
	
}

int getAmount()
{
	int amt;
	cout<<"Enter Initial Amount:";
	cin>>amt;
	return amt;
}

string getPhone()
{
	string dummy;
	string phone;
	getline(cin,dummy);
	cout<<"Enter Phone No:";
	getline(cin,phone);
	
	return phone;
}


void openAccount()
{
	
	account_no[index]=getAccountNo();
	name[index]=getName();
	nrc[index]=getNRC();
	amt[index]=getAmount();
	phone[index]=getPhone();
	
	index++;
	
	
}

void closeAccount()
{
	cout<<" Close Account  \n";
}

void backToMain()
{
	cout<<"Back to Main MENU ...\n";
}
void account()
{
	bool loop=true;
	while(loop)
	{
		accountMENU();
		switch(getChoice())
		{
			case 1:openAccount();break;
			case 2:closeAccount();break;
			case 3:backToMain();loop=false;break;
		}
		
	}
}

void view()
{
	cout<<"   List of Account     \n";
	cout<<"--------------------------\n";
	for(int i=0;i<index;i++)
	{
		cout<<"--------------Account----------------\n";
		cout<<"Account Number   :"<<account_no[i]<<"\n";
		cout<<"Account Name  :"<<name[i]<<"\n";
		cout<<"NRC  :"<<nrc[i]<<"\n";
		cout<<"Balance  :"<<amt[i]<<"\n";
		cout<<"Phone No   :"<<phone[i]<<"\n";
		cout<<"-------------------------------------\n";
	}
}

void deposit()
{
	int deposit_amt;
	bool found=false;
	int found_index=0;
	
	cout<<"         Deposit Account      \n";
	cout<<"------------------------------\n";
	int accNO=getAccountNo();
	
	for(int i=0;i<index;i++)
	{
		found=false;
		if(accNO==account_no[i])
		{
			found=true;
			found_index=i;
			break;
		}
	}
	
	if(found==true)
	{
		cout<<"            Account Found!           \n";
		cout<<"-----------Account Info --------------\n";
		cout<<" Accouont NO  :"<<account_no[found_index]<<"\n";
		cout<<" Account Name : "<<name[found_index]<<"\n";
		cout<<" NRC          :"<<nrc[found_index]<<"\n";
		cout<<" Balance      : "<<amt[found_index]<<"\n";
		cout<<" PHone No     : "<<phone[found_index]<<"\n";
		cout<<"----------------------------------------\n";
		
		cout<<"Enter Deposit Amount:";
		cin>>deposit_amt;
		
		amt[found_index]+=deposit_amt;
		
		cout<<"Deposit Transaction Success!...\n";
		cout<<"-------------------------------\n";
		cout<<"Your Balance Now is :"<<amt[found_index]<<"\n";
		cout<<"-------------------------------------------\n";
		cout<<"           Have a Great Day                 \n";
		cout<<"---------------------------------------------\n";
	}
}

void updateMENU()
{
	cout<<"     Update MENU                \n";
	cout<<"--------------------------------\n";
	cout<<"[1] Deposit                     \n";
	cout<<"[2] Withdraw                    \n";
	cout<<"[3] Update Phone No             \n";
	cout<<"[4] Back to Main MENU           \n";
	cout<<"--------------------------------\n";
}

void withdraw()
{
	cout<<" withdraw   money   \n";
}

void updatePhoneNo()
{
	cout<<" update Phone No   \n";
}
void update()
{
	bool loop=true;
	while(loop)
	{
		updateMENU();
		switch(getChoice())
		{
			case 1:deposit();break;
			case 2:withdraw();break;
			case 3:updatePhoneNo();break;
			case 4:backToMain();loop=false;break;
		}
	}
}
