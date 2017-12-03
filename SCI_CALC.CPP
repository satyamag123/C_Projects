#include<iostream.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void welcome();
void menu();
void calc();
void mat();
void temp_conv();
void help();
void info();
void end();

void calc()
{
	char choice;
    do
    {
	clrscr();
	char letter1,letter2,letter3,letter4;
	float a,b;
	double a1,b1;
	float result;
	double result1;


     clrscr();
     gotoxy(1,2);
     cout<<"________________________________________________________________________________";
     gotoxy(33,4);
     cout<<"SCIENTIFIC CALCULATOR\n";
     gotoxy(30,5);
     cout<<":::::::::::::::::::::::::::";


		cout<<"\n\n ";//ctrl+ _ & ctrl+ ^
		cout<<"\n "<<setw(49)<<"";
		cout<<"\n \t 1 : Arithmetic Operations"<<setw(17)<<"";
		cout<<"\n \t 2 : Trigonometric Functions"<<setw(15)<<"";
		cout<<"\n \t 3 : Logarithmic Functions"<<setw(17)<<"";
		cout<<"\n \t 4 : Power Functions"<<setw(23)<<"";
		cout<<"\n \t 5 : Go back to Menu"<<setw(23)<<"";
		cout<<"\n \t 0 : EXIT"<<setw(34)<<"";
		cout<<"\n "<<setw(49)<<"";
		cout<<"\n ";//ctrl+ _ & ctrl+ ^

		cout<<"\n\n\tEnter your choice: ";
		choice = getche();


	switch(choice)

	{
		case '1':

				 {
					clrscr();
					gotoxy(1,2);
					cout<<"________________________________________________________________________________";
					gotoxy(31,4);
					cout<<"Arithmetic Operations\n";
					gotoxy(29,5);
					cout<<":::::::::::::::::::::::::";

					cout<<"\n\n              ";//ctrl+ _ & ctrl+ ^
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n \t1: Addition"<<setw(23)<<"";
					cout<<"\n \t2: Subtraction"<<setw(20)<<"";
					cout<<"\n \t3: Multipilication"<<setw(16)<<"";
					cout<<"\n \t4: Division"<<setw(23)<<"";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n              ";//ctrl+ _ & ctrl+ ^

					cout<<"\n\n\tEnter your choice: ";
					letter1 = getche();

					clrscr();

					gotoxy(1,2);
					cout<<"________________________________________________________________________________";
					switch(letter1)
					{
						case '1':
								 {
									gotoxy(36,4);
									cout<<"ADDITION";
									gotoxy(34,5);
									cout<<"::::::::::::";


									cout<<"\n\n  Enter your digits";

									gotoxy(27,11);
									cin>>a;
									gotoxy(33,11);
									cout<<"+   ";
									cin>>b;

									result=a+b;
									gotoxy(43,11);
									cout<<"= "<<result;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();

									//system("pause");
									break;
								 }
						case '2':
								 {
									gotoxy(36,4);
									cout<<"SUBTRACTION";
									gotoxy(34,5);
									cout<<":::::::::::::::";


									cout<<"\n\n  Enter your digits";

									gotoxy(27,11);
									cin>>a;
									gotoxy(33,11);
									cout<<"-   ";
									cin>>b;

									result=a-b;
									gotoxy(43,11);
									cout<<"= "<<result;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();

									//system("pause");
									break;

								 }

						case '3':
								 {
									gotoxy(36,4);
									cout<<"MULTIPLICATION";
									gotoxy(34,5);
									cout<<"::::::::::::::::::";


									cout<<"\n\n  Enter your digits";

									gotoxy(27,11);
									cin>>a;
									gotoxy(33,11);
									cout<<"*   ";
									cin>>b;

									result=a*b;
									gotoxy(43,11);
									cout<<"= "<<result;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();

									//system("pause");
									break;

								 }

						case '4':
								 {
									gotoxy(36,4);
									cout<<"DIVISION";
									gotoxy(34,5);
									cout<<"::::::::::::";


									cout<<"\n\n  Enter your digits";

									gotoxy(27,11);
									cin>>a;
									gotoxy(33,11);
									cout<<"/   ";
									cin>>b;

									result=a/b;
									gotoxy(43,11);
									if(b==0)
									{
										cout<<"=   INFINITY";
									}
									else
									{
										cout<<"=  "<<result;
									}
									gotoxy(69,24);
									cout<<"Press Enter";
									getch();

									break;
								 }

						default:          gotoxy(1,8);
								  cout<<"\n\n\t\tWrong Input";
								  delay(600);
								  cout<<"\n\t\t\tRE-ENTER YOUR CHOICE";
								  sleep(1);
								  continue;
					}// end of inner switch
					break;
				 }// end of case 1 arithmatic operation

		case '2':
				 {
					clrscr();
					gotoxy(1,2);
					cout<<"________________________________________________________________________________";
					gotoxy(29,4);
					cout<<"Trigonometric Operations\n";
					gotoxy(27,5);
					cout<<"::::::::::::::::::::::::::::";


					cout<<"\n\n              ";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n \t1: Sin function"<<setw(19)<<"";
					cout<<"\n \t2: Cos function"<<setw(19)<<"";
					cout<<"\n \t3: Tan function"<<setw(19)<<"";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n              ";

					cout<<"\n\n\tEnter your choice: ";
					letter2 = getche();

					clrscr();

					gotoxy(1,2);
					cout<<"________________________________________________________________________________";


					 switch(letter2)
					 {
						case '1':
								 {
									gotoxy(36,4);
									cout<<"SIN FUNCTION";
									gotoxy(34,5);
									cout<<":::::::::::::::::";


									cout<<"\n\n  Enter your values: ";

									gotoxy(27,11);

									cout<<"SIN ";
									cin>>a1;
									a1=(a1*3.141)/180; //Converting degree into gradient
									result1=(sin(a1));
									gotoxy(35,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;
								 }
						case '2':
								 {
									gotoxy(36,4);
									cout<<"COS FUNCTION";
									gotoxy(34,5);
									cout<<":::::::::::::::::";


									cout<<"\n\n  Enter your values: ";

									gotoxy(27,11);

									cout<<"COS ";
									cin>>a1;
									a1=(a1*3.141)/180;//Converting degree into gradient
									result1=(cos(a1));
									gotoxy(35,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;

								 }
						case '3':
								 {

									gotoxy(36,4);
									cout<<"TAN FUNCTION";
									gotoxy(34,5);
									cout<<":::::::::::::::::";


									cout<<"\n\n  Enter your values: ";

									gotoxy(27,11);

									cout<<"TAN ";
									cin>>a1;
									a1=(a1*3.141)/180;//Converting degree into gradient
									result1=(tan(a1));
									gotoxy(35,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;

								 }

					 }// inner switch
					 break;
				 }//inner case 2 trignomatic
		case '3':
				 {
					clrscr();
					gotoxy(1,2);
					cout<<"________________________________________________________________________________";
					gotoxy(32,4);
					cout<<"Logarithmic Operations\n";
					gotoxy(30,5);
					cout<<"::::::::::::::::::::::::::::";


					cout<<"\n\n              ";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n \t1: Natural Log"<<setw(20)<<"";
					cout<<"\n \t2: Naturam Log with base 10"<<setw(7)<<"";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n              ";

					cout<<"\n\n\tEnter your choice: ";
					letter3 = getche();

					clrscr();

					gotoxy(1,2);
					cout<<"________________________________________________________________________________";

					 switch(letter3)
					 {
						case '1':
								 {
									gotoxy(36,4);
									cout<<"NATURAL LOG";
									gotoxy(34,5);
									cout<<":::::::::::::::::";
									cout<<"\n\n  Enter your values: ";
									gotoxy(27,11);

									cout<<"LOG ";
									cin>>a1;
									result1=log(a1);

									gotoxy(35,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;

								 }
						case '2':
								 {
									gotoxy(36,4);
									cout<<"NATURAL LOG WITH BASE 10";
									gotoxy(34,5);
									cout<<":::::::::::::::::";
									cout<<"\n\n  Enter your values: ";
									gotoxy(27,11);
									cout<<"LOG10  ";
									cin>>a1;
									result1= log10(a1);
									gotoxy(38,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;

									cout<<"\n\n Result = "<<result1<<endl;
									system("pause");
									break;
								 }
					 }// end of switch
					 break;
				 }// end of case 3 logrithmic
		case '4':
				 {
					clrscr();
					gotoxy(1,2);
					cout<<"________________________________________________________________________________";
					gotoxy(35,4);
					cout<<"Power Operations\n";
					gotoxy(33,5);
					cout<<"::::::::::::::::::::";

					cout<<"\n\n              ";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n \t1: Get power"<<setw(22)<<"";
					cout<<"\n \t2: Get Square Root"<<setw(16)<<"";
					cout<<"\n "<<setw(39)<<"";
					cout<<"\n              ";

					cout<<"\n\n\tEnter your choice: ";
					letter4 = getche();

					clrscr();

					gotoxy(1,2);
					cout<<"________________________________________________________________________________";

					 switch(letter4)
					 {
						case '1':
								 {
									gotoxy(34,4);
									cout<<"GET POWER VALUE";
									gotoxy(32,5);
									cout<<":::::::::::::::::::";
									cout<<"\n\n  Enter your values: ";

									gotoxy(25,13);
									cout<<"Enter a number...";
									gotoxy(27,11);
									cin>>a1;
									gotoxy(33,11);
									cout<<"^";
									gotoxy(25,13);
									cout<<"Enter power...   ";
									gotoxy(38,11);
									cin>>b1;

									result1=pow(a1,b1);

									gotoxy(43,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;
								 }
						case '2':
								 {
									gotoxy(35,4);
									cout<<"SQUARE ROOT";
									gotoxy(33,5);
									cout<<":::::::::::::::::";
									cout<<"\n\n  Enter your values: ";
									gotoxy(27,11);
									cout<<"SQRT  ";

									cin>>a;
									result1=sqrt(a);

									gotoxy(38,11);
									cout<<"=  "<<result1;

									gotoxy(69,24);
									cout<<"Press Enter";
									getch();
									break;
								 }

					 }// end of switch
					 break;
				 }// end of case power function
		case '5':	menu();
				break;

		case '0':	end();
				break;

		default:	cout<<"\n\n\t\tWrong Input";
				delay(600);
				cout<<"\n\t\t\tRe-enter your choice";
				sleep(1);

	}// outer switch
     }//End of DO

     while(choice!='0');

	end();

}// End of function

class matrix
{
	public:

	int a[5][5],b[5][5],c[5][5],m,n,p,q,i,j,k;
	int e,f;	//Arrangement of matrices

void input()
{
	clrscr();
	gotoxy(1,2);
cout<<"________________________________________________________________________________";
	gotoxy(32,4);
cout<<"Enter Matrix Details";
	gotoxy(30,5);
cout<<"::::::::::::::::::::::::";

cout<<"\n\n Enter no. of rows and coloums for first matrix: ";
cin>>m;
gotoxy(52,7);
cout<<"*";
gotoxy(54,7);
cin>>n;
cout<<"\n\n Enter no. of rows and coloums for second matrix: ";
cin>>p;
gotoxy(53,10);
cout<<"*";
gotoxy(55,10);
cin>>q;

	clrscr();
	gotoxy(1,2);
cout<<"________________________________________________________________________________";
	gotoxy(33,4);
cout<<"MATRIX DETAILS";
	gotoxy(28,5);
cout<<"::::::::::::::::::::::::";

e=10;
f=10;
gotoxy(6,7);
cout<<"Enter First Matrix"<<"\n";
for(i=0;i<m;i++)
{       e=10;
	for(j=0;j<n;j++)
	{
		gotoxy(e,f);
		cin>>a[i][j];
		e=e+4;
	}
	f=f+2;
}

gotoxy(60,7);
cout<<"Enter Second Matrix";

e=64;
f=10;
for(i=0;i<p;i++)
{
	e=64;
	for(j=0;j<q;j++)
	{       gotoxy(e,f);
		cin>>b[i][j];
		e=e+4;
	}
	f=f+2;
}

}


void mat_add()
{
	for (i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}

	cout<<"\n\n"<<setw(46)<<"Addition\n";
	cout<<setw(49)<<"::::::::::::\n\n";
	for(i=0;i<m;i++)
	{       cout<<"\t\t\t\t      ";
		for(j=0;j<q;j++)
		{
			cout<<c[i][j]<<"  ";
		}
		cout<<"\n\n";
	}
gotoxy(69,24);
cout<<"Press Enter";
getch();
}

void mat_sub()
{
	for (i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}

	cout<<"\n\n"<<setw(46)<<"Subtraction\n";
	cout<<setw(49)<<":::::::::::::::\n\n";
	for(i=0;i<m;i++)
	{       cout<<"\t\t\t\t      ";
		for(j=0;j<q;j++)
		{
			cout<<c[i][j]<<"  ";
		}
		cout<<"\n\n";
	}
gotoxy(69,24);
cout<<"Press Enter";
getch();

}


void mat_mul()
{
if(n==p && m==q)
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
		c[i][j]=0;

			for(k=0;k<p;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}

	cout<<"\n\n"<<setw(49)<<"Multiplication\n";
	cout<<setw(52)<<"::::::::::::::::::\n\n";
	for(i=0;i<m;i++)
	{       cout<<"\t\t\t\t      ";
		for(j=0;j<q;j++)
		{
			cout<<c[i][j]<<"  ";
		}
	cout<<"\n\n";
	}
}

else
{
	cout<<"\n\n\n\n\n\t\t It can not be multiplied";
}
gotoxy(69,24);
cout<<"Press Enter";
getch();

}



void mat_trans()
{

	clrscr();
	gotoxy(1,2);
cout<<"________________________________________________________________________________";
	gotoxy(32,4);
cout<<"Enter Matrix Details";
	gotoxy(30,5);
cout<<"::::::::::::::::::::::::";

cout<<"\n\n Enter no. of rows and coloums for first matrix: ";
cin>>m;
gotoxy(52,7);
cout<<"*";
gotoxy(54,7);
cin>>n;

	clrscr();
	gotoxy(1,2);
cout<<"________________________________________________________________________________";
	gotoxy(33,4);
cout<<"MATRIX DETAILS";
	gotoxy(28,5);
cout<<"::::::::::::::::::::::::";

e=10;
f=12;
gotoxy(6,9);
cout<<"Enter The Matrix"<<"\n";
for(i=0;i<m;i++)
{       e=10;
	for(j=0;j<n;j++)
	{
		gotoxy(e,f);
		cin>>a[i][j];
		e=e+4;
	}
	f=f+2;
}


cout<<"\n"<<setw(43)<<"Transpose\n";
	cout<<setw(46)<<":::::::::::::\n\n";
	for(i=0;i<m;i++)
	{       cout<<"\t\t\t\t  ";
		for(j=0;j<n;j++)
		{
			cout<<a[j][i]<<"  ";
		}
	cout<<"\n\n";
	}
gotoxy(69,24);
cout<<"Press Enter";
getch();
}

};   //END OF CLASS

void mat()
{
matrix m;
char choice;
clrscr();
gotoxy(1,2);
cout<<"________________________________________________________________________________";
gotoxy(35,4);
cout<<"Matrix Operations\n";
gotoxy(33,5);
cout<<":::::::::::::::::::::";
cout<<"\n\n              ";
cout<<"\n "<<setw(39)<<"";
cout<<"\n \t1: Addition of Matrices"<<setw(11)<<"";
cout<<"\n \t2: Subtraction of Matrices"<<setw(8)<<"";
cout<<"\n \t3: Multiplication of Matrices"<<setw(5)<<"";
cout<<"\n \t4: Transpose of Matrices"<<setw(10)<<"";
cout<<"\n \t5: Go back to menu"<<setw(16)<<"";
cout<<"\n \t0: EXIT"<<setw(27)<<"";
cout<<"\n "<<setw(39)<<"";
cout<<"\n              ";
cout<<"\n\n\tEnter your choice: ";
choice=getche();
	switch(choice)
	{
	case '1':       m.input();
			m.mat_add();
			break;

	case '2':	m.input();
			m.mat_sub();
			break;

	case '3':	m.input();
			m.mat_mul();
			break;

	case '4':	m.mat_trans();
			break;

	case '5':	menu();
			break;

	case '0':	end();
			break;

	default:	cout<<"\n\n\t\tWrong Input.";
			sleep(1);
			cout<<"\n\t\t\tRE-ENTER YOUR CHOICE.";
			sleep(2);
	}
	mat();
}

void welcome()
{
	clrscr();
	textmode(C80);
gotoxy(1,2);
cout<<"________________________________________________________________________________";

gotoxy(27,11);
cout<<"W E L C O M E   T O   M Y ";
gotoxy(30,13);
cout<<"  S C I - C A L C    ";
sleep(2);
menu();
}

void menu()
{
	clrscr();
	textmode(BW80);
	char choice,choice1;
gotoxy(1,2);
cout<<"________________________________________________________________________________";
gotoxy(35,4);
cout<<" MENU \n";
gotoxy(35,5);
cout<<"  ****  ";
cout<<"\n\n ";//ctrl+ _ & ctrl+ ^
cout<<"\n "<<setw(49)<<"";
cout<<"\n \t 1.Use Scientific Calculator"<<setw(15)<<"";
cout<<"\n \t 2.Use Matrix Calculator"<<setw(19)<<"";
cout<<"\n \t 3.Use Temperature conversion system"<<setw(7)<<"";
cout<<"\n \t 4.Go to `HELP' menu"<<setw(23)<<"";
cout<<"\n \t 5.More Information "<<setw(23)<<"";
cout<<"\n \t 0.E X I T"<<setw(33)<<"";
cout<<"\n "<<setw(49)<<"";
cout<<"\n ";//ctrl+ _ & ctrl+ ^

cout<<"\n\n\t\tPlease enter your choice: ";
choice=getch();
switch(choice)
{
			case '1':  		calc();
						break;

			case '2':               mat();
						break;

			case '3':		temp_conv();
						break;

			case '4':               help();
						break;

			case '5':		info();
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
void help()
{
	clrscr();
gotoxy(1,2);
cout<<"________________________________________________________________________________";
gotoxy(37,4);
cout<<"H E L P";
gotoxy(35,5);
cout<<"";
gotoxy(2,7);
cout<<"1. In menu window you have to select an option (1,2,3,4,0) and these options"<<"\n    will redirect you to your desired location to be worked in.";

gotoxy(69,25);
cout<<"Press Enter";
getch();
menu();

}
void info()
{
	clrscr();
gotoxy(1,2);
cout<<"________________________________________________________________________________";
gotoxy(35,4);
cout<<"INFORMATION";
gotoxy(33,5);
cout<<"";
gotoxy(1,7);

cout<<" \t\t     This program has been created using C++.";
cout<<"\n\n\t\t  This program is created for our Maths Project.";
cout<<"\n\n\t  This proram is created for a basic purpose i.e. for calculation.";
cout<<"\n\n\tMain feature of this program is that it is a scientific calculator.";
cout<<"\n\n  We would like to thank SRM University for giving us such a good opportunity";
cout<<"\n\t\t\t   to showcase our talent.";
cout<<"\n\n Members of this team are:";
cout<<"\n\n\t\t\t\tSatyam Agrawal";
cout<<"\n\t\t\t\t Naveen Bakshi";
cout<<"\n\t\t\t\t      KK";
cout<<"\n\t\t\t\t Mridula Vats";
cout<<"\n\t\t\t\t   Nandini";
cout<<"\n\t\t\t\tVaibhavi Verma";
cout<<"\nCSE-E";
gotoxy(69,25);
cout<<"Press Enter";
getch();
menu();

}

void temp_conv()
{
	clrscr();
	float c,f;
	char choice;
gotoxy(1,2);
cout<<"________________________________________________________________________________";
gotoxy(28,4);
cout<<"  Temperature conversion";
gotoxy(28,5);
cout<<"::::::::::::::::::::::::::";

gotoxy(1,7);
cout<<"\n ";
cout<<"\n                                             ";
cout<<"\n \t 1. Convert Celcius to Fahrenheit     ";
cout<<"\n \t 2. Convert Fahrenheit to Celsius     ";
cout<<"\n \t 3. Go back to main menu              ";
cout<<"\n \t 0. EXIT                              ";
cout<<"\n                                             ";
cout<<"\n ";

cout<<"\n\n\t\tPlease enter your choice: ";
choice=getch();
switch(choice)
{
			case '1':      		{
							clrscr();
							gotoxy(1,2);
							cout<<"________________________________________________________________________________";
							gotoxy(28,4);
							cout<<"  Temperature conversion";
							gotoxy(28,5);
							cout<<"::::::::::::::::::::::::::";

							cout<<"\n\nEnter the Temperature in degree celsius: ";
							gotoxy(10,9);
							cout<<":: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: ::";
							gotoxy(10,10);
							cout<<"::                                                    ::";
							gotoxy(10,11);
							cout<<"::    Temperature in degree celsius                   ::";
							gotoxy(10,12);
							cout<<"::    Temperature in degree fahrenheit                ::";
							gotoxy(10,13);
							cout<<"::                                                    ::";
							gotoxy(10,14);
							cout<<":: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: ::";

							gotoxy(49,11);
							cin>>c;
							f=((c*9)/5)+32;
							gotoxy(49,12);
							cout<<f;

							gotoxy(69,24);
							cout<<"Press Enter";
							getch();
							temp_conv();

						}
						break;

			case '2':      		{
							clrscr();
							gotoxy(1,2);
							cout<<"________________________________________________________________________________";
							gotoxy(28,4);
							cout<<"  Temperature conversion";
							gotoxy(28,5);
							cout<<"::::::::::::::::::::::::::";

							cout<<"\n\nEnter the Temperature in degree Fahrenheit: ";
							gotoxy(10,9);
							cout<<":: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: ::";
							gotoxy(10,10);
							cout<<"::                                                    ::";
							gotoxy(10,11);
							cout<<"::    Temperature in degree fahrenheit                ::";
							gotoxy(10,12);
							cout<<"::    Temperature in degree celsius                   ::";
							gotoxy(10,13);
							cout<<"::                                                    ::";
							gotoxy(10,14);
							cout<<":: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: :: ::";

							gotoxy(49,11);
							cin>>f;
							c=((f-32)*5)/9;
							gotoxy(49,12);
							cout<<c;

							gotoxy(69,24);
							cout<<"Press Enter";
							getch();

							temp_conv();
							}
						break;

			case '3':		menu();
						break;

			case '0':	      	end();
						break;

			default:       	        cout<<"\n\n\tINVALID CHOICE";
						sleep(1);
						cout<<"\n\t\tRE-ENTER your choice";
						sleep(2);
						temp_conv();
						break;
		}
}
void main()
{
	clrscr();
welcome();
	getch();
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
	gotoxy(19,12); cout<<"*     DESIGNED BY CSE - E students....  *\n";
	gotoxy(19,13); cout<<"*                                       *\n";
	gotoxy(19,14); cout<<"*****************************************";
	sleep(2);
	exit(0);
}
