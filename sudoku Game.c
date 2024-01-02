SUDOKU
***********
***********
***********

#include <stdio.h>
#include <stdlib.h>

int sudoku[9][9];
void solve_sudoku(int , int);
int row_check(int row, int num)
{
    int column;
    for(column=0; column<9; column++)
    {
        if(sudoku[row][column] == num)
        {
            return 0;
        }
    }
    return 1;
}
int check_column(int column, int num)
{
    int row;
    for(row=0; row<9; row++)
    {
        if(sudoku[row][column]== num)
        {
            return 0;
        }
    }
    return 1;

}
int check_cube(int row, int column,int num)
{
    row=(row/3)*3;
    column=(column/3)*3;
    int r,c;
    for(r=0; r<3; r++)
    {
        for(c=0; c<3; c++)
        {
            if(sudoku[row =r][column =c] == num)
            {
              return 0;
            }
        }
    }
    return 1;
}
void transfer(int row, int column)
{
    if(column <8)
    solve_sudoku(row, column+1);
    else
    solve_sudoku(row+1 , 0);

}
void display()
{
    int row, column;
    printf("the solved sudoku\n");
    for(row=0; row<9; row++)
    {
        for(column=0; column<9; column++)
            printf("%d",sudoku[row][column]);
        printf("\n");
    }

}

void solve_sudoku(int row, int column)
{
    if(row >8)
   display();
   if(sudoku[row][column] !=0)
   {
       transfer(row, column);
   }
   else
   {
       int number;
       for(number=1; number<=9; number++)
       {
           if((row_check(row,number) == 1)&&(check_column(column , number) == 1)&&(check_cube(row, column, number) == 1))
           {
               sudoku[row][column] = number;
               transfer(row, column);
           }
       }
       sudoku[row][column] = 0;
   }
}
int main() {
    int row, column;
    printf("enter the sudoku you want with zero for unknown\n");
    for(row=0; row<9; row++)
        for(column=0; column<9; column++)
        scanf("%d",&sudoku[row][column]);
    solve_sudoku(0,0);

  return 0;
}