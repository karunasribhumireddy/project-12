#include <stdio.h>
#include <stdlib.h>
int board[20], n;
int isSafe(int row, int col)
{
    int i;
    for(i = 1; i < row; i++)
    {
        if(board[i] == col ||
           abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}
void solve(int row)
{
    int col, i;
    if(row > n)
    {
        for(i = 1; i <= n; i++)
        {
            for(col = 1; col <= n; col++)
            {
                if(board[i] == col)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for(col = 1; col <= n; col++)
    {
        if(isSafe(row, col))
        {
            board[row] = col;
            solve(row + 1);
            board[row] = 0;
        }
    }
}
int main()
{
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if(n < 1 || n > 20)
    {
        printf("Invalid input");
        return 0;
    }
    solve(1);
    return 0;
}