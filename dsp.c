#include<stdio.h>
#include<conio.h>
main()
{
int b[10],pno[10],ts,n,s[10],e[10],w[10],t[10],r[10];
int i, c=0,X=0;
float aw=0,at=0;
printf("enter the number of processes");
scanf("%d",&n);
for(i=0;i<n;i++)
    pno[i]=i+1;
printf("enter the time slice");
scanf("%d",&ts);
printf("enter the brust time of each process");
for(i=0;i<n;i++)
scanf("%d",&b[i]);
s[0]=0;
X=0;
c=0;
for(i=0;i<n;i++)
{
	if(b[i]<ts)
	{
		e[i]=X+b[i];
		r[i]=0;
	}
	else
	{
	e[i]=ts+X;
	r[i]=b[i]-ts;
}
X=e[i];
s[i+1]=e[i];
t[i]=e[i];
w[i]=s[i];
}
while(c>=0)
{
	for(i=0;i<n;i++)
	{
		if(r[i]!=0)
		{
			w[i]=w[i]+X-e[i];
			if(r[i]<ts)
			{
				e[i]=X+r[i];
				r[i]=0;
			}
			else
			{
				e[i]=X+ts;
				r[i]=r[i]-ts;
			}
			X=e[i];
			t[i]=e[i];
		}
		if(r[i]!=0)
		c++;
	}
	c--;
}
for(i=0;i<n;i++)
{
	aw=aw+w[i];
	at=at+t[i];
}
   aw==aw/n;
   at=at/n;
   printf("time slice=%d",ts);
   printf("\n pno\t bt\t st\t et\t wt\ttat");
   for(i=0;i<n;i++)
   printf("\n %d\t %d\t %d\t %d/t %d/t %d",pno[i],b[i],s[i],e[i],w[i],t[i]);
   printf("\n average waiting time=%f",aw);
   printf("\n average turnaroundtime=%f,at");
}
