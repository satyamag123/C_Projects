			//LEAST FREQUENTLY USED (USING QUEUE CONCEPT)
			//BY SATYAM AGRAWAL
#include<iostream.h>
#include<conio.h>

void swap(int *a,int *b)
{
	int temp;
temp=*a;
*a=*b;
*b=temp;
}

void main()
{
	clrscr();
	int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2},len=15;
	int que[2][5];
	int i,j,k,flag=0,pcnt=0,pno;
cout<<"Enter no of pages: ";
cin>>pno;

for(i=0;i<2;i++) {
	for(j=0;j<pno;j++){
	que[i][j]=-1;
	cout<<que[i][j]<<"  ";
	}
cout<<"\n";}

for(i=0;i<len;i++)
{
flag=0;
	for(j=0;j<pno;j++)
	{
		if(arr[i]==que[0][j])//If element is present in queue
		{	flag=1;
			que[1][j]++;
		}
	}
	if(flag==0)
	{
		for(j=pno-1;j>0;j--)
		{
			que[0][j]=que[0][j-1];  //Shift
			que[1][j]=que[1][j-1];
		}
		que[0][0]=arr[i];          //Insert new element in queue
		que[1][0]=1;
		pcnt++;
	}

for(j=0;j<pno-1;j++)                  //USE BUBBLE SORT ONLY
	for(k=0;k<(pno-1-j);k++)
		if(que[1][k]<que[1][k+1])
		{
			swap(&que[1][k],&que[1][k+1]);
			swap(&que[0][k],&que[0][k+1]);
		}

/*	for(j=0;j<=2;j++)
	{
	int ptr=0;
		while(ptr<=(j))
		{
			if(que[1][ptr] < que[1][ptr+1])
			{
				swap(&que[0][ptr],&que[0][ptr+1]);
				swap(&que[1][ptr],&que[1][ptr+1]);

			}
		ptr++;
		}
	}

 /*	for(j=0;j<2;j++)
	{
		for(k=j;k<3;k++)
		{
			if(que[1][j]<que[1][k])
			{
				swap(&que[0][j],&que[0][k]);
				swap(&que[1][j],&que[1][k]);
			}
		}
	}
*/
       //PRINTING

for(j=0;j<2;j++)
{
	for(k=0;k<pno;k++)
		cout<<que[j][k]<<"  ";
cout<<"\t";
}

cout<<"Page count="<<pcnt<<"  ";
}//END OF i

getch();
}