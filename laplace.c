#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define N 1000
#define tol 10e-7

int tolerancia(double **V, double **A);

double **potencial()  //função que implementa V
{	int i, j, cont=0;
	double **V, **A;
	
	//alocando memória para a matriz V
	V=(double**)malloc(N*sizeof(double*));
        for(i=0;i<N;i++)
        {  V[i]=(double*)malloc(N*sizeof(double));
        }
	A=(double**)malloc(N*sizeof(double*)); //matriz auxiliar
        for(i=0;i<N;i++)
        {  A[i]=(double*)malloc(N*sizeof(double));
        }

	for(i=0;i<N;i++)	//inicializando a matriz com zeros para não pegar lixo
	{  for(j=0;j<N;j++)
	   {  V[i][j]=0.;
	      A[i][j]=0.;
	   }
	}
	for(i=0;i<N;i++)	//Condições de contorno das bordas laterais
	{  V[i][0]=-1;
	   V[i][N-1]=1;
	   A[i][0]=-1;
           A[i][N-1]=1;
	}	
	for(i=1;i<N;i++)	//Condicões de contorno das bordas superior e inferior
	{  V[0][i]=1;
	   V[N-1][i]=-1;
	   A[0][i]=1;
           A[N-1][i]=-1;
	}
	do{
	for(i=1;i<N-1;i++)
        {   for(j=1;j<N-1;j++)
            {  A[i][j]= V[i][j];
            }
        }
	for(i=1;i<N-1;i++)
	{   for(j=1;j<N-1;j++)
	    {  V[i][j]= (V[i-1][j] + V[i+1][j] + V[i][j-1] + V[i][j+1])*0.25;
            }
	}
	cont++;
	}while(tolerancia(V,A));
	printf("Número de passos: %d\n\n", cont);
	
	return(V);
}
int tolerancia(double **V, double **A)
{	double dif;
	int i, j;

	for(i=0;i<N;i++)
	{  for(j=0;j<N;j++)
	   {  dif=fabs(V[i][j]-A[i][j]);
	      if(dif>=tol)
	        return(1);
           }
	}
	return(0);
}	
void main()
{	double **V;
	int i, j;
	clock_t inicio, fim;
	FILE *fp, *ft;

	fp=fopen("dados.dat","w");
	ft=fopen("time.dat", "w");
	inicio=clock();
	V=potencial();	
 	
	//salvando matriz no arquivo    
	for(i=0;i<N;i++)
	{  for(j=0;j<N;j++)
	  	fprintf(fp,"%lf \t", V[i][j]);
 	   fprintf(fp,"\n");	
	}   
	fclose(fp);
	fim=clock();
	printf("Tempo gasto: %lf\n\n",((fim-inicio)/(double)CLOCKS_PER_SEC));
	fprintf(ft,"%lf \n", ((fim-inicio)/(double)CLOCKS_PER_SEC));
	fclose(ft);
}
