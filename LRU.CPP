			//LEAST RECENTLY USED  (USING QUEUE CONCEPT)
			//BY SATYAM AGRAWAL
#include<iostream.h>
#include<conio.h>
void swap(int *a,int *b)
{	int temp;
temp=*a;
*a=*b;
*b=temp;
}
void main()
{	clrscr();
	int arr[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1},len=20;
	int que[5];
	int i,j,k,flag=0,pcnt=0,pno;
cout<<"Enter no of pages: ";
cin>>pno;
for(i=0;i<pno;i++)
	que[i]=-1;
for(i=0;i<len;i++)
{	flag=0;
cout<<"\n"<<arr[i]<<"= ";
	for(j=0;j<pno;j++)
		if(arr[i]==que[j])//If element is present in queue
		{	flag=1;
			j++;
			break;
		}
	for(k=j-1;k>0;k--)
		que[k]=que[k-1];  //Shift
	que[0]=arr[i];          //Insert new element in queue
	if(flag==0)
		pcnt++;
for(j=0;j<pno;j++)
cout<<que[j]<<" ";
}
cout<<"\nPage Fault= "<<pcnt;
getch();
}