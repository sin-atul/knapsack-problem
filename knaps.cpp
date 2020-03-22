#include<stdio.h>
#include<conio.h>
void knapsack(float cap, int n, float w[], float val[])
{
	float arr[20], maxv,y;
	int i,j;
	y=cap;
	maxv=0;
	for(i=0;i < n;i++)
		arr[i]=0.0;
	for(i=0;i < n;i++)
	{
		if(w[i] > y)
			break;
		else
		{
			arr[i]=1.0;
			maxv=maxv+val[i];
			y=y-w[i];
		}
	}
	if(i < n)	
		arr[i]=y/w[i];
	maxv=maxv+(arr[i]*val[i]);
	printf("The selected elements are:-\n ");
	for(i=0;i < n;i++)
		if(arr[i]==1.0)
			printf("\nval is %f with w %f ", val[i], w[i]);
		else if(arr[i] > 0.0)
			printf("\n%f part of val %f with w %f", arr[i], val[i], w[i]);
	printf("\nTotal val for %d objects with cap %f = %f\n\n", n, cap,maxv);
}			
int main()
{
	float w[20],val[20],Pi[20], t1,t2,t3;
	int n;
	float cap;
	int i,j;
	printf("Enter number of objects:  ");
	scanf("%d", &n);
	printf("\nEnter the cap of knapsack: ");
	scanf("%f", &cap);
	for(i=0;i < n;i++)
	{
		printf("\nEnter %d(th)  val: ", (i+1));
		scanf("%f", &val[i]);
		printf("Enter %d(th)  w: ", (i+1));
		scanf("%f", &w[i]);
		Pi[i]=val[i]/w[i];
	}
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
		{
			if(Pi[i] > Pi[j])
			{
				t1=Pi[i];
				Pi[i]=Pi[j];
				Pi[j]=t1;
				t2=w[i];
				w[i]=w[j];
				w[j]=t2;
				t3=val[i];
				val[i]=val[j];
				val[j]=t3;
			}
		}
	knapsack(cap,n,w,val);
	return(0);
}
