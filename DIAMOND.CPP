				// D I A M O N D
			// Change the space and see magic
				   // Use n=12
#include<iostream.h>
#include<stdio.h>
#include<conio.h>

void main()
{
	clrscr();
	int n,k,c,space=1;
	textcolor(WHITE);
printf("Enter a number: ");
cin>>n;
space=n-1;

for(k=1;k<=n;k++)
{
	cout<<"\t\t";
	for(c=1;c<=space;c++)
	{	printf("  ");

	}
	space--;

	for(c=1;c<=2*k-1;c++)
	{
		if(c==1)
			textcolor(MAGENTA);
		if(c==2*k-1)
			textcolor(BLUE);
		if((k==n)||(c==k))
		{	textcolor(RED+BLINK);
			cprintf(" \4");
			textcolor(WHITE);
			continue;
		}
		cprintf(" ");
		textcolor(WHITE);
	}
cout<<"\n";
}

space=1;

for(k=1;k<=n-1;k++)
{       cout<<"\t\t";
	for(c=1;c<=space;c++)
		cout<<"  ";

	space++;

	for(c=1;c<=2*(n-k)-1;c++)
	{
			if(c==1)
				textcolor(GREEN);
			if(c==2*(n-k)-1)
				textcolor(YELLOW);
			if(c==n-k)
			{	textcolor(RED+BLINK);
				cprintf(" \4");
				textcolor(CYAN);
				continue;
			}
		cprintf(" ");
		textcolor(CYAN);
	}

	cout<<"\n";
}
	getch();
}