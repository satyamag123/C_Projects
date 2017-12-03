#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include<dos.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>
#include<string.h>


fstream ini("INITIAL.txt",ios::in|ios::out|ios::ate);
fstream bank("BANKING.txt",ios::in|ios::out|ios::app);
//***********************************
//CLASS DECLARATION
//***********************************
class detail
{
	public:
	long float amount;
	char address[50],nm[20],type[8];
	long int acc_no,cont_no;
	void input_det();
	void disp_det();
}det;


class transaction
{
	public:
	long int accno,withdraw,deposit,balance;
	int dd,mm,yy;
	char mode;
}tran;
//****************************************
//CLASS FUNCTION TO OPEN NER ACCOUNT
//****************************************
void detail::input_det()
{       cout<<"\n\n\t\t\t\tDETAIL INPUT ZONE\n";
	cout<<"\n\n\n";
	cout<<"\t\t***********************************************\n";
	for(int i=0;i<25;i++)
	cout<<"\t\t*                                             *\n";
	cout<<"\t\t***********************************************\n";
	gotoxy(26,10);
	cout<<"NAME:-";
	gotoxy(26,13);
	cout<<"ADDRESS:-";
	gotoxy(26,16);
	cout<<"PHONE NO.:-";
	gotoxy(26,19);
	cout<<"ACCOUNT TYPE:-";
	gotoxy(26,22);
	cout<<"DEPOSITING MONEY:-";
	gotoxy(26,25);
	cout<<"ACCOUNT NO.:-";
	gotoxy(33,10);
	gets(nm);
	gotoxy(35,13);
	gets(address);
	gotoxy(39,16);
	cin>>cont_no;
	gotoxy(30,45);
	cout<<"ACCOUNT TYPE FOR SAVING(S),CURRENT(C)";
	gotoxy(42,19);
	cin>>type;
	for(int j=0;j<37;j++)
	{
		gotoxy(66-j,45);
		cout<<" ";
	}
	gotoxy(45,22);
	cin>>amount;
	gotoxy(39,25);
	randomize();
	acc_no= rand() % 20+1000;
	cout<<acc_no;

}

//****************************************
//CLASS FUNCTION TO DISPLAY ACCOUNT
//****************************************
void detail::disp_det()
{
	cout<<"\n"<<acc_no<<setw(20)<<nm<<setw(20)<<cont_no<<setw(20)<<address<<setw(15)<<amount;
}
//****************************************
//FUCTION TO SEE INDIVIDUAL RECORD
//    1.ACCOUNT NO.
//    2.NAME
//****************************************
void indirec()
{
	int ch,f=0;

	long int acc2;
	char name[30];
	cout<<"\n\n\t1.SEARCH BY ACCOUNT NUMBER\n\t2.SEARCH BY NAME\n";
	cout<<"\n\t\tENTER YOUR CHOICE\t";
	cin>>ch;
	switch(ch)
	{
		case 1: clrscr();
			{
			 ifstream dr("initial.txt",ios::in);
			 detail dt;
			cout<<"\n\n\tENTER YOUR ACCOUNT NUMBER\t";
			cin>>acc2;
			while(dr)
			{
				dr.read((char*)&dt,sizeof(dt));
				if(!dr.eof())
				{
					if(dt.acc_no==acc2)
					{
						sleep(1.0);
						f=1;
						cout<<"\n\n================================================================================\n";
						cout<<"Accno.\t\t   Name\t\t  PHONE NO.\t\tAddress\t\tBalance\n";
						cout<<"================================================================================\n";
						dt.disp_det();
					}
				}
			}

			if(f==0)
			cout<<"\n\n\tACCOUNT DOESN'T EXIST\t\n";

			dr.close();
			}
			getch();
			break;

		case 2: clrscr();
			 {
			 ifstream dr("initial.txt",ios::in);
			 detail dt;
			cout<<"\n\n\tENTER THE ACCOUNT HOLDER NAME\t";
			gets(name);
			while(dr.read((char*)&dt,sizeof(dt)))
			{
			if(!dr.eof())
			{
				if(strcmpi(dt.nm,name)==0)
				{       sleep(1.0);
					f=1;
					cout<<"\n\n================================================================================\n";
					cout<<"Accno.\t\t  Name\t\tPHONE NO.\t\tAddress\t\tBalance\n";
					cout<<"================================================================================\n";
					dt.disp_det();
				}

			}
			}
			if(f==0)
			{
			cout<<"\nrecord not found";
			}

			dr.close();  }
			getch();
			break;
	    }

}
//**************************************************
//FUNCTION FOR DAILY TRANSACTION                   *
//**************************************************

void transc()
{
	fstream s("initial.txt",ios::in|ios::out|ios::ate);
	int rec=0;
	long int acc1;
	cout<<"\n\t\t\tWELCOME TO RAMSWAROOP BANK\t\t";
	cout<<"\n\t\t\t\t\t\t\tDATE:- ";
	{
	 time_t t = time(0);
	 struct tm * now = localtime( & t );
	 cout << (now->tm_year + 1900) << '-'
	      << (now->tm_mon + 1) << '-'
	      <<  now->tm_mday
	      << endl;
	}
	cout<<"\n\n\tENTER ACCOUNT NO.";
	cin>>acc1;
	s.seekp(0,ios::beg);
	while(s)
	{

	 s.read((char*)&det,sizeof(det));
	 if(!s.eof())
	 {
		rec++;

		if(det.acc_no==acc1)
		{

			tran.accno=det.acc_no;
			cout<<"\n\tENTER DATE OF TRANSACTION:-";
			cout<<"\n\tDAY ";
			cin>>tran.dd;
			cout<<"\tMONTH ";
			cin>>tran.mm;
			cout<<"\tYEAR ";
			cin>>tran.yy;
			cout<<"\n\tDO YOU WANT TO DEPOSIT(D) OR WITHDRAW(W)";
			cout<<"\n\tENTER YOUR CHOICE\t";
			cin>>tran.mode;
			if(toupper(tran.mode)=='W')
			{
				cout<<"\n\tENTER YOUR WTHDRAWING AMOUNT\t";
				cin>>tran.withdraw;
				det.amount=det.amount-tran.withdraw;
				tran.balance=det.amount;
				cout<<"\n\tYOUR BALANCE IS:-  "<<det.amount;
				s.seekp((rec-1)*sizeof(det),ios::beg);
				s.write((char*)&det,sizeof(det));
				bank.write((char*)&tran,sizeof(tran));
			}
			else
			if(toupper(tran.mode)=='D')
			{
				cout<<"\n\tENTER YOUR DEPOSITING AMOUNT\t";
				cin>>tran.deposit;
				det.amount=det.amount+tran.deposit;
				tran.balance=det.amount;
				cout<<"\n\tYOUR BALANCE IS:-  "<<det.amount;
				s.seekp((rec-1)*sizeof(det),ios::beg);
				s.write((char*)&det,sizeof(det));
				bank.write((char*)&tran,sizeof(tran));
			}
			else
			      {	cout<<"\n\tWRONG CHOICE RE-ENTER\t";}


		}

	}
       }
	s.close();
	bank.close();
}
//***************************************************
//FUNCTION FOR MONTHLY REPORT                       *
//***************************************************


void monthrep()
{       long int acc3;
	ifstream s1("banking.txt");
	cout<<"\n\n          ACCOUNT NO.\t";
	cin>>acc3;
	cout<<"\n\n================================================================================\n";
	cout<<"Date\t\t\tWithdraw\t\tDeposit\t\t\tBalance\n";
	cout<<"================================================================================\n";

	while(s1)
	{
	 s1.read((char*)&tran,sizeof(tran));
	 if(!s1.eof())
	 {
	      if(tran.accno==acc3)
	      {
		cout<<"\n"<<tran.dd<<"/"<<tran.mm<<"/"<<tran.yy<<setw(23)<<tran.withdraw<<setw(24)<<tran.deposit<<setw(24)<<tran.balance;
	      }
	 }
	}
	s1.close();
}
//******************************************************
//FUNCTION TO MODIFY & DELETE RECORD                   *
//******************************************************
void modify()
{
	int ch2,f1=0,f2=0,reco=0;
       long int acc;

	ofstream temp("temp.txt",ios::out);
	ofstream temp1("temp1.txt",ios::out);
	cout<<"\n\n\t1.DELETE AN ACCOUNt\n\t2.MODIFY AN ACCOUNT\n";
	cout<<"\n\tCHOOSE YOUR CHOICE:-\t";
	cin>>ch2;
	switch(ch2)
	{
	case 1: clrscr();            //delete
		fstream aa1("initial.txt",ios::in,ios::out);
		fstream ini4("banking.txt",ios::in,ios::out);
		cout<<"\n\n\t	enter the account no.:-";
		cin>>acc;
		while(aa1)
		{
			aa1.read((char*)&det,sizeof(det));
			if(!aa1.eof())
			{
				if(det.acc_no==acc)
				{
					f1=1;
				}
				else
				{
					temp.write((char*)&det,sizeof(det));
				}
			}
	       }
	       while(ini4)
		{
			ini4.read((char*)&tran,sizeof(tran));
			if(!ini4.eof())
			{
				if(det.acc_no==acc)
				{
				  f2=1;
				}
				else
				{
					temp1.write((char*)&tran,sizeof(tran));
				}
			}
	       }
	       if(f1==0 && f2==0)
		      cout<<"\nrecord not found";
	       else
			cout<<"\n\nrecord deleted\t";

		remove("initial.txt");
		rename("temp.txt","initial.txt");
		remove("banking.txt");
		rename("temp1.txt","banking.txt");
		aa1.close();
		ini4.close();
		temp.close();
		temp1.close();
		getch();
		break;
	case 2: retry:
		clrscr();    //modify
		int f3=0;
		fstream aa("initial.txt",ios::in,ios::ate);
		fstream temp3("temp3.txt",ios::out);

		cout<<"\n\tENTER THE ACCOUNT NO.\t";
		cin>>acc;
		while(aa)
		{
			aa.read((char*)&det,sizeof(det));
			if(!aa.eof())
			{
				if(det.acc_no==acc)
				{
					reco++;
					f3=1;
					cout<<"\n\tenter new name\t";
					gets(det.nm);
					cout<<"\n\tenter new address\t";
					gets(det.address);
					cout<<"\n\tenter the new contact no.\t";
					cin>>det.cont_no;
					temp3.write((char*)&det,sizeof(det)) ;
				}
				else
				{
				 temp3.write((char*)&det,sizeof(det));
				}
			}
		}
		if(f3==0)
		{
			cout<<"\n\tRECORD NOT FOUND RE-TRY";
			sleep(1.0);
			goto retry;

		}
		else
		{
		cout<<"value modified";
		remove("initial.txt");
		rename("temp3.txt","initial.txt");
		}
		aa.close();
		temp3.close();
		getch();
		break;
	}
}
void main()
{
	top:
	clrscr();
	int ch1;
	cout<<"\n\n";
	cout<<"\t\t***********************************\n";
	for(int i=0;i<25;i++)
	cout<<"\t\t*                                 *\n";
	cout<<"\t\t***********************************\n";
	gotoxy(25,10);
	cout<<"1.OPEN NEW ACCOUNT";
	gotoxy(25,12);
	cout<<"2.LIST OF ACCOUNT";
	gotoxy(25,14);
	cout<<"3.SEE INDIVIDUAL ACCOUNT";
	gotoxy(25,16);

	cout<<"4.DAILY TRANSACTION";
	gotoxy(25,18);
	cout<<"5.MONTHLY REPORT";
	gotoxy(25,20);
	cout<<"6.EDIT ACCOUNT";
	gotoxy(25,22);
	cout<<"7.EXIT";
	gotoxy(25,30);
	cout<<"\n\n\n\t\tSELECT YOUR CHOICE";
	gotoxy(40,33);
	cin>>ch1;

	switch(ch1)
	{
		case 1: clrscr();
			{
			fstream ini1("INITIAL.txt",ios::app);
			det.input_det();
			ini1.write((char*)&det,sizeof(det));
			ini1.close();
			}

			break;

		case 2: clrscr();

			{

			cout<<"\n\n\n\t\t\tACCOUNTS LIST IN BANK\t\t\t<enter>main menu\n";
			cout<<"\t\t\t=====================\tDATE:";
			{
			 time_t t = time(0);
			 struct tm * now = localtime( & t );
			  cout << (now->tm_year + 1900) << '-'
			       << (now->tm_mon + 1) << '-'
			       <<  now->tm_mday
			       << endl;
			}

			cout<<"\n\n================================================================================\n";
			cout<<"Accno.\t\t  Name\t\t  PHONE NO.\t\tAddress\t\tBalance\n";
			cout<<"================================================================================\n";
			fstream dr1("initial.txt",ios::in);
			while(dr1)
			{
				dr1.read((char*)&det,sizeof(det));
				if(!dr1.eof())
				{
				det.disp_det();

				}
		       }
			dr1.close();
			getch();

	}
			break;
		case 3: clrscr();
			indirec();


			break;
		case 4: clrscr();
			transc();


			break;
		case 5: clrscr();

			monthrep();


			break;
		case 6: clrscr();
			modify();

			break;
		case 7:

			clrscr();
			int cnt=1;
			for(int a=1;a<=38;a++)
			{
			gotoxy(1,a);
			cout<<"  ";
			delay(20);
			cnt=cnt+2;
			gotoxy(cnt,1);
			cout<<"  ";
			delay(20);
			}
				gotoxy(19,10); cout<<"*****************************************\n";
				gotoxy(19,11); cout<<"*                                       *\n";
				gotoxy(19,12); cout<<"* PROGRAM CREATED BY SATYAM AGRAWAL.... *\n";
				gotoxy(19,13); cout<<"*                                       *\n";
				gotoxy(19,14); cout<<"*****************************************\n";
				sleep(2);

			exit(0);
			break;
	     default: gotoxy(25,40);

		      cout<<"WRONG CHOICE RE-ENTER";
		      sleep(1.0);
		      goto top;
		      break;
	}
	getch();
	goto top;

	getch();
}
