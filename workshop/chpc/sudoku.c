#include <stdio.h>
#include<omp.h>
FILE *fp;

int puzzle2[15][9][9];
int puzzle[9][9];
int i,j,k;

int isAvailable(int puzzle[][9], int row, int col, int num)

{

    int rowStart = (row/3) * 3;

    int colStart = (col/3) * 3;

    int i, j;

    for(i=0; i<9; ++i)

    {

       if (puzzle[row][i] == num) return 0;

       if (puzzle[i][col] == num) return 0;

       if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;

    }

    return 1;

}

int read()

{
  int c,p;
 char  ch;

char  file_name[25];

  

  printf("Reading from file sudo.txt\n");

 // gets(file_name);

  fp = fopen("sudo.txt","r"); // read mode

  if( fp == NULL )

  {

     printf("Error while opening the file.\n");

   

  }
  for(k=0;k<15;k++){
   for(i=0;i<9;i++)
    { 	
	for(j=0;j<9;j++)

	  { 
	     
	      ch=fgetc(fp);
	     
	      if(ch!='\n')
		{
	      c=ch-48;
	    
	   
	      puzzle2[k][i][j]=c;
	      }
	      else
		j--;
	  }
    }
    


  }


}


  

   

  



int fillSudoku(int puzzle[][9], int row, int col)

{

    int i;

    if(row<9 && col<9)

    {

       if(puzzle[row][col] != 0)

       {

           if((col+1)<9) return fillSudoku(puzzle, row, col+1);

           else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);

           else return 1;

       }

       else

       {

           for(i=0; i<9; ++i)

           {

               if(isAvailable(puzzle, row, col, i+1))

               {

                   puzzle[row][col] = i+1;

                   if((col+1)<9)

                   {

                       if(fillSudoku(puzzle, row, col +1)) return 1;

                       else puzzle[row][col] = 0;

                   }

                   else if((row+1)<9)

                   {

                       if(fillSudoku(puzzle, row+1, 0)) return 1;

                       else puzzle[row][col] = 0;

                   }

                   else return 1;

               }

           }

       }

       return 0;

    }

    else return 1;

}

void main()

{

    int i, j=1;

    /*int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},

                     {1, 9, 0, 4, 7, 0, 6, 0, 8},

                     {0, 5, 2, 8, 1, 9, 4, 0, 7},

                     {2, 0, 0, 0, 4, 8, 0, 0, 0},

                     {0, 0, 9, 0, 0, 0, 5, 0, 0},

                     {0, 0, 0, 7, 5, 0, 0, 0, 9},

                     {9, 0, 7, 3, 6, 4, 1, 8, 0},

                     {5, 0, 6, 0, 8, 1, 0, 7, 4},

                     {0, 8, 0, 0, 0, 0, 0, 0, 0}};*/
    read();
   
    for(k=0;k<15;k++)
      {printf("################ puzzle %d################\n",k);
	
  printf("\n+-----+-----+-----+\n");

       for(i=1; i<10; ++i)

       {

	 for(j=1; j<10; ++j) printf("|%d", puzzle2[k][i-1][j-1]);

           printf("|\n");

           if (i%3 == 0) printf("+-----+-----+-----+\n");

       }
	for(i=0;i<9;i++)
	  { 	
	for(j=0;j<9;j++)

	  { 
	     
	    
	      puzzle[i][j]=puzzle2[k][i][j];}
	  
	  
    
	  }
    if(fillSudoku(puzzle, 0, 0))

    {

       printf("\n+-----+-----+-----+\n");
       
       for(i=1; i<10; ++i)

       {

           for(j=1; j<10; ++j) printf("|%d", puzzle[i-1][j-1]);

           printf("|\n");

           if (i%3 == 0) printf("+-----+-----+-----+\n");

       }

    }

    else printf("\n\nNO SOLUTION\n\n");

      }

}




