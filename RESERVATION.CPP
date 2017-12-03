#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>

int cnt=0;
void end();
void air_tic();
void trn_tic();
void goto_plane();
void goto_trn();
void age_check();
void dt_check();
void no_check();
void stcode_check(int);
void trn_birth_check();
void air_birth_check();

struct abc
{
	char trn_no[6];
	char nm[20],st_nm1[15],st_nm2[15],trn_dt[11],trn_ch_asgn[12];
	char age[5],coach_no[4];
	int ch,flag,fare,birth_no,gate_no,seat_no,flag1;
	char tic_no[9];
}at;

class reserv
{
	private:
	char choic,tic[10],str1[9],str2[7];
	long int aa;
	int choice,flag;
	public:

	void rail_book()
	{
		top:
		clrscr();
	cout<<"\n________________________________________________________________________________";
	cout<<"\n\n\n\t\t\t\tWelcome to \n\t\t\ttrain reservation system";
	cout<<"\n\t\t:::::::::::::::::::::::::::::::::::::::::";
		if(cnt==0)                          // to check arrival or departure
		{
			cout<<"\n\nWrite details for your departure";
			cout<<"\n--------------------------------";
		}
		 else
		{
			cout<<"\n\nWrite details for your arrival";
			cout<<"\n--------------------------------";
		}
	cout<<"\n\nPlease enter your name including your sirname: ";
	gets(at.nm) ;

	cout<<"\nAge: ";
	cin>>at.age;
	age_check();

	cout<<"\nDate of departure(DD/MM/YYYY): ";
	cin>>at.trn_dt;
	dt_check();

	cout<<"\nEnter your train no (4 digits): ";
	cin>>at.trn_no;
	no_check();

	flag=1;
	cout<<"\nDeparture station code(3 letters): ";
	cin>>at.st_nm1;
	stcode_check(flag);

	flag++;
	cout<<"\nArrival station code(3 letters): ";
	cin>>at.st_nm2;
	stcode_check(flag);

	cout<<"\nWhich train birth would you like to prefer....";
	cout<<"\n\n\tSleeper      (l)\n\tAc 1st class (2)\n\tAc 2nd class (3)\n\tAc 3rd class (4)\n\n\t ";
	cin>>at.ch;
	trn_birth_check();

	gotoxy(54,24);
	cout<<"Press Enter to proceed....";
	getch();
	textmode(BW40);
	gotoxy(14,12);
	cout<<"Processing";
	randomize();	//fare
		at.fare=(rand() % 700)+800;   // B/W 800 to 800+700
	randomize();    //Birth no
		at.birth_no=(rand() % 72)+1;
	strcpy(str1,"PR");
	randomize();    //tic_no
	    aa=(rand() % 8765432)+1234567;
	ltoa(aa,str2,10);
	strcat(str1,str2);
	strcpy(at.tic_no,str1);
	if(at.ch==1)
		      {		strcpy(str1,"SL");
				randomize();
				     aa=(rand() % 12)+1;      // coach no
		      }
		      else
		      {		strcpy(str1,"AC");
				randomize();
				     aa=(rand() % 3)+1;
		      }
	ltoa(aa,str2,10);
	strcat(str1,str2);
	strcpy(at.coach_no,str1);
		for(int i=0;i<4;i++)
		{
			sleep(1);
			cout<<".";
		}
	 // Saving the info in file hadling
			ofstream o;
			o.open("reservation.dat",ios::app);
			o.write((char*)&at,sizeof(at));
			o.close();

	textmode(BW80);
	trn_tic();
	gotoxy(69,25);		cout<<"Press Enter";
	getch();
	if(cnt==0)
		{       clrscr();
			cnt++;
			cout<<"\n\nPress 1 to Book ticket for arrival";
			cout<<"\nPress any key to Go back on MENU screen";
			cout<<"\n\n\tEnter your choice: ";
			cin>>flag;
			gotoxy(69,24);		cout<<"Press Enter";
			getch();
			if(flag==1)
				rail_book();
		}
	adm.menu();
	}

	void air_book()
	{
		top:
		clrscr();
	cout<<"\n________________________________________________________________________________";
	cout<<"\n\n\n\t\t\t\t Welcome at \n\t\t\t\Aeroplane reservation system";
	cout<<"\n\t\t :::::::::::::::::::::::::::::::::::::::::";
		if(cnt==0)                          // to check arrival or departure
		{
			cout<<"\n\nWrite details for your departure";
			cout<<"\n--------------------------------";
		}
		 else
		{
			cout<<"\n\nWrite details for your arrival";
			cout<<"\n--------------------------------";
		}
	cout<<"\n\nPlease enter your name including your sirname: ";
	gets(at.nm) ;

	cout<<"\nAge: ";
	cin>>at.age;
	age_check();

	cout<<"\nDate of departure(DD/MM/YYYY): ";
	cin>>at.trn_dt;
	dt_check();

	cout<<"\nEnter your Plane no (4 digits): ";
	cin>>at.trn_no;
	no_check();

	flag=1;
	cout<<"\nDeparture airport code(3 letters): ";
	cin>>at.st_nm1;
	stcode_check(flag);

	flag++;
	cout<<"\nArrival airport code(3 letters): ";
	cin>>at.st_nm2;
	stcode_check(flag);

	cout<<"\nWhich plane birth would you like to prefer....";
	cout<<"\n\tEconomy class  (1)\n\tBuissness class(2)\n\n\t ";
	cin>>at.ch;
	air_birth_check();
	char id[30];
	cout<<"\nGive your ID proof: ";
	gets(id);
	cout<<"\n\n";
	gotoxy(54,24);
	cout<<"Press Enter to proceed....";
	getch();
	textmode(BW40);
	gotoxy(14,12);
	cout<<"Processing";
	randomize();                 	         //fare
	    at.fare=(rand() % 15000)+5000;

	randomize();
	    at.gate_no=(rand() % 20)+1;       	 // gate no

	randomize();              	         //seat no
	    at.seat_no= (rand() % 9)+1;

	strcpy(str1,"AR");
	randomize();    			 //tic_no
	    aa=(rand() % 8765432)+1234567;
	ltoa(aa,str2,10);
	strcat(str1,str2);
	strcpy(at.tic_no,str1);
		for(int i=0;i<4;i++)
		{
			sleep(1);
			cout<<".";
		}
	 // Saving the info using file hadling
			ofstream o;
			o.open("reservation.dat",ios::app);
			o.write((char*)&at,sizeof(at));
			o.close();

	textmode(BW80);
	cout<<"Congrats Mr/Mrs "<<at.nm<<" Your ticket is booked for "<<at.trn_ch_asgn<<" class";
	cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";

	air_tic();
	gotoxy(69,25);		cout<<"Press Enter";
	getch();
		if(cnt==0)
		{       cnt++;
			clrscr();
			cout<<"\n\nPress 1 to Book ticket for arrival";
			cout<<"\nPress any key to Go back on MENU screen";
			cout<<"\n\n\tEnter your choice: ";
			cin>>flag;
			gotoxy(69,24);		cout<<"Press Enter";
			getch();
			if(flag==1)
				air_book();
		}
	adm.menu();
	}
	void ticket()
	{
		ifstream i;
		i.open("reservation.dat",ios::end);
		i.seekg(0,ios::end);
		while(i)
		{
		i.read((char*)&at,sizeof(at));
		if(at.flag1==1)
			trn_tic();
			else if(at.flag1==2)
				air_tic();
				else
				{       clrscr();
					gotoxy(29,12);
					cout<<"NO RECORD TO BE DISPLAYED";
				}
		}
		i.close();
		getch();
	}
	void cancel()
	{       char tic[10];
		clrscr();
		flag=0;
		cout<<"\nEnter the ticket no you want to cancel: ";
		cin>>tic;
		ifstream i;
		i.open("reservation.dat",ios::beg);
		ofstream temp;
		temp.open("temperary.dat",ios::app);
		i.seekg(0);
			while(i)
			{
				i.read((char*)&at,sizeof(at));
				if(!i.eof())
				{
					if(strcmpi(at.tic_no,tic))
						flag=1;
					else
						temp.write((char*)&at,sizeof(at));
				}
			}
			i.close();
			temp.close();
			gotoxy(29,12);
			if(flag==0)
				cout<<"Sorry No such ticket exists";
			else
			{
				cout<<"Ticket found...";
				sleep(1);
				gotoxy(29,12);
				cout<<"CANCELLING...  ";
				sleep(1);
				gotoxy(29,12);
				cout<<"Ticket cancelled...";
				remove("reservation.dat");
				rename("temp.dat","reservation.dat");
			}
		gotoxy(69,24);
		cout<<"Press Enter";
		getch();
		adm.menu();
	}
};

class admin
{
	private:
	char choic;
	char choice;
	reserv res;
	public:
	void menu()
	{       textmode(C40);
		cout<<"\n\n\n\n\n\n\n\t   W E L C O M E   A T"<<"\n\n\t\tM E N U";
		sleep(2);

		delay(50);
		textmode(BW80);
		cout<<"\n\n\t\t\t M E N U ";
		cout<<"\n\t\t\t  *******  ";
		cout<<"\n ";//ctrl+ _ & ctrl+ ^
		cout<<"\n "<<setw(49)<<"";

		cout<<"\n \t 1.Book your ticket"<<setw(24)<<"";
		cout<<"\n \t 2.Show your recently booked ticket"<<setw(8)<<"";
		cout<<"\n \t 3.Cancel your booked ticket"<<setw(15)<<"";
		cout<<"\n \t 0.E X I T"<<setw(33)<<"";
		cout<<"\n "<<setw(49)<<"";
		cout<<"\n ";//ctrl+ _ & ctrl+ ^

		cout<<"\n\n\t\tPlease enter your choice: ";
		choice=getch();
		switch(choice)
		{
			case '1':		book();
						break;
			case '2':		res.ticket();
						menu();
						break;
			case '3':		res.cancel();
						break;
			case '0':		end();
						break;
			default:       	        cout<<"\n\n\tINVALID CHOICE";
						sleep(1);
						cout<<"\n\t\tRE-ENTER your choice";
						sleep(2);
						menu();
						break;
		}

	}
	void book()
	{
		clrscr();
		cout<<"\n\n\t1. Book your ticket for Railways.";
		cout<<"\n\t2. Book your for Airways.";
		cout<<"\n\tPress 'm' to go back on MENU screen";
		cout<<"\n\n\t\tPlease enter your choice: ";
		choic=getch();
		switch(choic)
		{
			case '1':       at.flag1=1;
					res.rail_book();
					break;
			case '2':       at.flag1=2;
					res.air_book();
					break;
			case 'm':
			case 'M':	menu();
					break;
			default:	cout<<"\n\n\tINVALID CHOICE";
					sleep(1);
					cout<<"\n\t\tRE-ENTER your choice";
					sleep(2);
					book();
					break;
		}

	}
	void end()
	{
		clrscr();
		int cnt=1;
		for(int a=1;a<=38;a++)
		{
			gotoxy(1,a);
			cout<<" ";
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
		gotoxy(19,14); cout<<"*****************************************";
		sleep(2);
		exit(0);
	}

}adm;



void air_tic()
{
	clrscr();
cout<<"\n\n\t _______________________________________________________";
cout<<"\n\t|\t\t\t\t\t\t\t|";
cout<<"\n\t|\t\t\b\b\bWELCOME TO AEROPLANE RESERVATION\t\t|";
cout<<"\n\t|"<<setw(30)<<" SYSTEM"<<setw(26)<<"|";
cout<<"\n\t|"<<setw(56)<<"|"<<"\n\t| Plane no\tDate of departure\tTicket no\t|";

cout<<"\n\t|"<<setw(56)<<"\t|";
cout<<"\n\t|-------------------------------------------------------|";
cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|  Departure airport\t\tArrival airport\t\t|";

cout<<"\n\t|   \t\t\t\t"<<setw(25)<<"|";

cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|-------------------------------------------------------|";


cout<<"\n\t|  ";
cout<<"Gate no \t Seat no \t class\t\tAge"<<setw(6)<<"|";
cout<<"\n\t|"<<setw(56)<<"|";

cout<<"\n\t|-------------------------------------------------------|";

cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|"<<setw(50)<<"FARE= Rs \t|";

cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t_________________________________________________________";
goto_plane();
}
void goto_plane()
{
	char tic_no[10];
gotoxy(12,9);	cout<<at.trn_no;         // plane no
gotoxy(28,9);   cout<<at.trn_dt;     	 // D_O_D
gotoxy(49,9);   cout<<at.tic_no;         // tic_no
gotoxy(16,14);  cout<<at.st_nm1;      	 // dep a_port
gotoxy(46,14);  cout<<at.st_nm2;     	 // ariv a_port
gotoxy(13,17);  cout<<at.gate_no;
gotoxy(28,17);	cout<<at.seat_no;
gotoxy(42,17);  cout<<at.trn_ch_asgn;    // class
gotoxy(57,17); 	cout<<at.age;  		 // age

gotoxy(58,20);  cout<<at.fare;	         // fare

}

void trn_tic()
{
	clrscr();
cout<<"\n\n\t _______________________________________________________";
cout<<"\n\t|\t\t\t\t\t\t\t|";
cout<<"\n\t|\t\t\bWELCOME TO RAILWAY RESERVATION\t\t|";
cout<<"\n\t|"<<setw(31)<<" SYSTEM"<<setw(25)<<"|";
cout<<"\n\t|"<<setw(56)<<"|"<<"\n\t| Train no\tDate of departure\tTicket no\t|";

cout<<"\n\t|"<<setw(56)<<"\t|";
cout<<"\n\t|-------------------------------------------------------|";
cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|  Departure station\t\tArrival station\t\t|";

cout<<"\n\t|   \t\t\t\t"<<setw(25)<<"|";

cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|-------------------------------------------------------|";

cout<<"\n\t|  Coach No\t\t Birth\t\t\t\b\bAge"<<setw(8)<<"|";
cout<<"\n\t|"<<setw(56)<<"|";

cout<<"\n\t|-------------------------------------------------------|";

cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|"<<setw(49)<<"\t FARE= Rs \t|";

cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t|"<<setw(56)<<"|";
cout<<"\n\t_________________________________________________________";
goto_trn();
}
void goto_trn()
{
gotoxy(12,9);         cout<<at.trn_no;	//train no
gotoxy(28,9);         cout<<at.trn_dt;	// date
gotoxy(49,9);         cout<<at.tic_no; 	//ticket_no
gotoxy(16,14);        cout<<at.st_nm1;	//dep station
gotoxy(46,14);        cout<<at.st_nm2;	//ariv sation
gotoxy(13,17);	      cout<<at.coach_no;//coach_no
gotoxy(35,17);	      cout<<at.birth_no;//birth_no
gotoxy(55,17); 	      cout<<at.age;     //age
gotoxy(59,20);	      cout<<at.fare;    //fare

}


void main()
{
	clrscr();
	textmode(BW80);
	adm.menu();
	getch();
}
void age_check()
{       char store[5]="__";
	strcpy(store,at.age);
	char choice='m';
	if(strlen(store)>2)
	{	cout<<"\n\n\nPress r: To Re-enter your age(if you are less than 99)";
		cout<<"\nPress m: To go back on menu screen\n\n\tEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 'r':
			case 'R':
					cout<<"\n\nRe-enter your correct age(below 100): ";
					cin>>store;
					break;
			case 'm':
			case 'M':
					adm.menu();
					break;
			default:	cout<<"\n\tRe-enter your choice";
					age_check();
					break;
		}
	strcpy(at.age,store);
	age_check();
	}
}

void dt_check()
{
char date[11]="DD/MM/YYYY",choice='m';
strcpy(date,at.trn_dt);
	if(date[2]!='/' || date[5]!='/')
	{
		clrscr();
		cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n\n\t\tW R O N G  I N P U T";
		cout<<"\n\t\t\b----------------------";
		cout<<"\n\n Slash is not at proper place";
		cout<<"\n::::::::::::::::::::::::::::::";
		sleep(1);
		cout<<"\n\nPress 1 to enter new date\nPress m to go back to MENU\n\n\t";
		cin>>choice;
		switch(choice)
		{
			case '1':	cout<<"\nEnter your correct date with proper slash";
					cout<<"\n\tHint: (Use DD/MM/YYYY format) ";
					cin>>date;
					break;
			case 'm':
			case 'M':	adm.menu();
					break;
			default:	cout<<"\n\nW R O N G  C H O I C E";
					sleep(1);
					clrscr();
					cout<<"\n\nYour last input was"<<at.trn_dt;
					cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
					dt_check();
					break;
		}
		strcpy(at.trn_dt,date);
		dt_check();
	}
		else if(strlen(date)!=10)
		{
			clrscr();
			cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout<<"\n\n\t\tW R O N G  I N P U T";
			cout<<"\n\t\t---------------------";
			cout<<"\n\nPress 1 to enter correct date\nPress m to go back to MENU  ";
			cin>>choice;
			switch(choice)
			{
				case '1':	cout<<"\nEnter your correct date: ";
						cin>>date;
						break;
				case 'm':
				case 'M':	adm.menu();
						break;
				default:	cout<<"\n\nW R O N G  C H O I C E";
						sleep(1);
						clrscr();
						cout<<"\n\nYour last input was"<<at.trn_dt;
						cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
						dt_check();
						break;
			}
			strcpy(at.trn_dt,date);
			dt_check();
		}
}

      void no_check()
	{
	char store[10]="####",choice='m';
	strcpy(store,at.trn_no);
		if(strlen(store)!=4)
		{
			clrscr();
			cout<<"\n\n\t\tW R O N G  I N P U T";
			cout<<"\n\t\t---------------------";
			sleep(1);
			cout<<"\n\nPress 1 to enter right train number\nPress m to go back to MENU\n\n\t";
			cin>>choice;
				switch(choice)
				{
					case '1':	cout<<"\nEnter your correct train number(4 digits): ";
							cin>>store;
							strcpy(at.trn_no,store);
							no_check();
							break;
					case 'm':
					case 'M':	adm.menu();
							break;
					default:	cout<<"\n\nW R O N G  C H O I C E";
							sleep(1);
							clrscr();
							cout<<"\n\nYour last input was: "<<at.trn_no;
							cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
							no_check();
							break;
				}

			strcpy(at.trn_no,store);
		}
	}

	void stcode_check(int flag)
	{
		char st_nm[5]="###";
		if(flag==1)
			strcpy(st_nm,at.st_nm1);
			else if(flag==2)
				strcpy(st_nm,at.st_nm2);

		if(strlen(st_nm)!=3)
		{
			clrscr();
			cout<<"\n\n\t\tW R O N G  I N P U T";
			cout<<"\n\t\t---------------------";
			sleep(1);
			cout<<"\n\nRE-WRITE correct Station code in (3 LETTERS): ";
			cin>>st_nm;
				if(flag==1)
			{
				strcpy(at.st_nm1,st_nm);
			}
				else if(flag==2)
				{
					strcpy(at.st_nm2,st_nm);
				}
		stcode_check(flag);
		}
	}
	void trn_birth_check()
	{
		switch(at.ch)
		{
			case 1:		strcpy(at.trn_ch_asgn,"Sleeper");
					break;
			case 2:	        strcpy(at.trn_ch_asgn,"Ac 1st class");
					break;
			case 3:	        strcpy(at.trn_ch_asgn,"Ac 2nd class");
					break;
			case 4:	        strcpy(at.trn_ch_asgn,"Ac 3rd class");
					break;
			default:	clrscr();
					cout<<"\n\n\t\tW R O N G  I N P U T";
					cout<<"\n\t\t---------------------";
					sleep(1);
					cout<<"\n\nRE-WRITE your choice: ";
					cin>>at.ch;
					trn_birth_check();
		}
	}
	void air_birth_check()
	{
		switch(at.ch)
		 {
			case 1:	    strcpy(at.trn_ch_asgn,"Economy ");
					break;
			case 2:     strcpy(at.trn_ch_asgn,"Business");
					break;
			default:	clrscr();
					cout<<"\n\n\t\tW R O N G  I N P U T";
					cout<<"\n\t\t---------------------";
					sleep(1);
					cout<<"\n\nRE-WRITE your choice: ";
					cin>>at.ch;
					air_birth_check();
		 }
	 }
