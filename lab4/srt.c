#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pn[10];
	int arr[10], bur[10], tat[10], wt[10], rm[10], rp[10], start[10], finish[10];
	int i, n;
	float aw, atat;
	int totwt=0, tottat=0;
	
	FILE *fil;
    	
	if ((fil = fopen("input.txt", "r")) == NULL)
        	exit(1);
    	if(fscanf(fil, "%d", &n) != 1)
        	exit(1);
    	for(i=0; i<n; i++) {
        	if(fscanf(fil, "%d%d%d", &pn[i], &arr[i], &bur[i]) != 3)
            		exit(1);
    		rm[i]=bur[i];
		start[i]=-1;
    	}
    	fclose(fil);
	
	int complete=0, smallest;
	rm[9]=999;
	for (int t=0;complete!=n;t++)
	{
		smallest=9;
		for (i=0;i<n;i++)
		{
			if (arr[i]<=t && rm[i]<rm[smallest] && rm[i]>0)
				smallest=i;
		}
		if (start[smallest]==-1) start[smallest]=t;
		rm[smallest]--;
		if (rm[smallest]==0)
		{
			complete++;
			finish[smallest]=t+1;
			wt[smallest]=finish[smallest]-arr[smallest]-bur[smallest];
			tat[smallest]=finish[smallest]-arr[smallest];
			rp[smallest]=start[smallest]-arr[smallest];
		}
	}
	
	FILE *fil1;
    	
	if ((fil1 = fopen("output.txt", "w")) == NULL)
        	exit(1);
	
	for (i=0;i<n;i++)
	{
		fprintf(fil1, "\n%d %d %d %d",pn[i], rp[i], wt[i], tat[i]);
		totwt+=wt[i];
		tottat+=tat[i];
	}
	aw=(float)totwt/n;
	atat=(float)tottat/n;
	fprintf(fil1, "\n%0.2f \n%0.2f\n",aw,atat);
	fclose(fil1);
	return 0;
}	
