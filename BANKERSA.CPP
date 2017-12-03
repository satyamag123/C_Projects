#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();

	int pro,res,allo[6][6],max[6][6],av[6];
	int need[6][6];
	int i,j,k,flag=0,cnt=0;
cout<<"Enter the no of processes: ";
cin>>pro;
cout<<"Enter the no of resources: ";
cin>>res;
cout<<"Enter allocation matrix: \n";

for(i=0;i<pro;i++)
	for(j=0;j<res;j++)
	cin>>allo[i][j];

cout<<"\nEnter max matrix: \n";

for(i=0;i<pro;i++)
	for(j=0;j<res;j++)
	cin>>max[i][j];

cout<<"The need matrix is:\n";

for(i=0;i<pro;i++)
{
	for(j=0;j<res;j++)
	{
	need[i][j]=max[i][j]-allo[i][j];
	cout<<need[i][j]<<"  ";
	}
cout<<"\n";
}
cout<<"Enter available matrix: \n";
for(i=0;i<res;i++)
cin>>av[i];

i=0;
while(flag<5)
{
	for(i=0;i<pro;i++)
	{
	cnt=0;
		for(j=0;j<res;j++)
		{
			if(need[i][j]<=av[j])
			cnt++;
			if(cnt==res && need[i][j]>=0)
			{       flag++;
				cout<<"P"<<i+1<<"--> ";
				for(k=0;k<res;k++)
				{
				 av[k]=av[k]+allo[i][k];
				 need[i][k]=-1;
				}
			}
		}
	}

}
cout<<"\nAnswer: ";
for(i=0;i<res;i++)
cout<<av[i]<<"  ";
	getch();
}