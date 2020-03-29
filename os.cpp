#include<stdio.h> 
#include<conio.h>
int main() 
{ 
	int Process=5,Resource=3;
	printf("Enter number of process and resources accorting to choice:	");
	scanf("%d%d",&Process,&Resource);
	const int P=Process,R=Resource;
    int avl[15];
    printf("Enter the number of available resources respectively:	");
	     for(int i=0;i<R;i++)
     	{
		scanf("%d",&avl[i]);
    	} 
    int max[10][10];
    for(int i=0;i<P;i++)
	{
		printf("Enter max number of resources required for process P%d:	",i+1);
		for(int j=0;j<R;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
    int allt[10][10];   
    for(int i=0;i<P;i++)
	{
		printf("Enter all the  resources allocated by P%d:	",i+1);
		for(int j=0;j<R;j++)
		{
			scanf("%d",&allt[i][j]);
		}
	}

   int need[P][R]; 
    for (int i = 0 ; i < P ; i++) 
        for (int j = 0 ; j < R ; j++) 
            need[i][j] = max[i][j] - allt[i][j]; 
    bool finish[P] = {0}; 
    int safeSeq[P]; 
    int work[R]; 
    for (int i = 0; i < R ; i++) 
        work[i] = avl[i]; 
    int count = 0; 
	while (count < P) 
    { 
        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            if (finish[p] == 0) 
            { 
                int j; 
                for (j = 0; j < R; j++) 
                    if (need[p][j] > work[j]) 
                        break; 
   				if (j == R) 
                { 
                
                    for (int k = 0 ; k < R ; k++) 
                        work[k] += allt[p][k]; 
                     safeSeq[count++] = p; 
                    finish[p] = 1; 
  
                    found = true; 
                } 
            } 
        } 
        if (found == false) 
        { 
            printf("System is not in safe state");  
        } 
    } 
    printf("System is in safe state \n");
    printf("Hence, The safe Sequence is: "); 
    for (int i = 0; i < P ; i++) 
        printf("P%d___",safeSeq[i]+1);

}
