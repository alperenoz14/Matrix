#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int BubbleSort(int number_rows, int number_columns, int **array);
int Transpose(int number_rows, int number_columns, int **array);
int PrintingFile1(int number_rows, int number_columns, int **arrayD);
int PrintingFile2(int number_rows, int number_columns, int **transpozeD);

int main()
{
	int **matrix, row, column, i, j;
	printf( "Enter the number of rows of the matrix will create: " );			//get the size of matrix from user...
	scanf( "%d", &row );
	printf( "Enter the number of columns of the matrix will create: " );
	scanf( "%d", &column );
	matrix = (int **)malloc( row * sizeof(int) );						//creating matrix with dynamic memory allocation...
	if( matrix == NULL )
		printf( "Insufficient memory space !" );
		
	for( i = 0; i < row; i++ ) {
		matrix[i] = (int *)malloc( row * sizeof(int) );
		if( matrix[i] == NULL )
			printf( "Insufficient memory space!" );
	}
	printf("\nOur %dx%d size matrix: \n",row,column);
	srand(time(NULL));
	for( i = 0; i < row; i++ ) {
		for( j = 0; j < column; j++ ){			
			matrix[i][j] = 5+rand()%40000;
			printf( "%d ", matrix[i][j] );			
		}
		printf( "\n" );		
	}
	BubbleSort(row,column,matrix);                     //call bubbleSort function...
	
	for( i = 0; i < row; i++ ) {						//unload the used memories...
		free( matrix[i] );
	}
	
	free( matrix );

	return 0;
}

int BubbleSort(int number_rows, int number_columns, int **array){		//function of bubblesort...
	int i, j;
	int result[number_rows*number_columns],k=0,temp;
	for( i = 0; i < number_rows; i++ ) {
		for( j = 0; j < number_columns; j++ ){
			result[k++]=array[i][j];			
		}		
	}	
	
	for(i=0;i<number_rows*number_columns;i++){						//we sort the matrix form low to high with bubbleSort(using 'swap' logic)...
     for(j=0;j<(number_rows*number_columns)-1;j++){
       if(result[j] > result[j+1]){
         temp=result[j];
         result[j]=result[j+1];
         result[j+1]=temp;
        }
      }
   }

	i=0;
    k=0;
    int l=0;
   while(i<number_rows*number_columns){

     for(j=0;j<number_rows;j++){
     array[k][j]=result[l];
     l++;
   }
   k++;
   i=i+number_rows;

   }
	
	printf("\nOur %dx%d matrix after being BubbleSort : ",number_rows,number_columns);
	for(i=0;i<number_rows;i++){
      printf("\n");
      for(j=0;j<number_columns;j++){
        printf(" %d",array[i][j]);
      }
    }
    PrintingFile1(number_rows,number_columns,array);								//matrix is printed to file...
	Transpose(number_rows,number_columns,array);										//we call transpose function...
return 0;
}
int Transpose(int number_rows, int number_columns, int **arrayT){					//our transpose function...
	int transpose[number_rows][number_columns], i, j, **transposep;
	for (i = 0; i < number_rows; ++i){
        for (j = 0; j < number_columns; ++j) {
            transpose[j][i] = arrayT[i][j];
		}
	}
	printf("\n");	
	printf("\nTranspose of our matrix:\n");						//printing the transpose of matrix...
    for (i = 0; i < number_rows; ++i){
        for (j = 0; j < number_columns; ++j) {
            printf("%d  ", transpose[i][j]);
            if (j == number_columns - 1)
                printf("\n");       
    	}
	}
	printf("\n***Our matrix and transpose of our matrix printed to file named transpose.txt !!***\n");
	transposep = (int **)malloc( number_rows * sizeof(int) );
	if( transposep == NULL )
		printf( "Insufficient memory space !" );
		
	for( i = 0; i < number_rows; i++ ) {
		transposep[i] = (int *)malloc( number_rows * sizeof(int) );
		if( transposep[i] == NULL )
			printf( "Insufficient memory space !" );
	}
	for (i = 0; i < number_rows; ++i){
        for (j = 0; j < number_columns; ++j) {
            transposep[i][j] = transpose[i][j];
		}
	}
	PrintingFile2(number_rows,number_columns,transposep);								//calling function for print to file...
}

int PrintingFile1(int number_rows, int number_columns, int **arrayD){					//our function for print to file...	
	int i,j;
	FILE *file;
	file = fopen("transpose.txt","w");
	fprintf(file,"Our %dx%d matrix which generated with random numbers: \n",number_rows,number_columns);
	for (i = 0; i < number_rows; ++i){
        for (j = 0; j < number_columns; ++j){            
			fprintf(file,"%d ",arrayD[i][j]);
		}
		fprintf(file, "\n" );	
	}
	return 0;
}

int PrintingFile2(int number_rows, int number_columns, int **transposeD){				//we print the transpose of matrix to file...
	int i,j;
	FILE *file;
	file = fopen("transpose.txt","a");
	fprintf(file,"Transpose of our %dx%d matrix: \n",number_rows,number_columns);
	for (i = 0; i < number_rows; ++i){
        for (j = 0; j < number_columns; ++j){
            fprintf(file,"%d ",transposeD[i][j]);
		}
		fprintf(file, "\n" );
	}
	fprintf(file, "PRINTING PROCESS DONE !" );											//we give successful message...
	return 0;
}

	
