//Code for Calculator...
#include<stdio.h>
#include<math.h>
#define MAX 10
void sum();
void mul();
void sub();
void fact();
void Multiply();
void table();
void printMatrix(double matrix[MAX][MAX], int row, int col);
int rankOfMatrix(double matrix[MAX][MAX], int row, int col);
int main()
{
    int a,b,c,d,e,n,p,t,i,j,A[3][3],B[3][3],M[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    printf("Enter the 4 Digit password for using calculator:\n");
    scanf("%d",&p);
    if(p==5656)
   {
    printf("Congratulation!");
    printf("Enter 1 for use the calculator:\n");
    scanf("%d",&t);
    if (t==1)
    {
        printf("Ok! Go further---");
    }


    printf("Read the instruction carefully:\n");
    printf("Enter 1 for sum:\n");
    printf("Enter 2 for multiply of two numbers\n");
    printf("Enter 3 for subtract:\n");
    printf("Enter 4 for factorial:\n");
    printf("Enter 5 for Multiplication of 2 Matrix:\n");
    printf("Enter 6 for print Table:\n");
    printf("Enter 7 for find the rank of matrix:\n");
    printf("Enter 1 if you read already\n");
    printf("Enter 2 if you not read\n");
    scanf("%d",&e);
    if (e==1)
    {
    	printf("Nice!\n");
        printf("Enter the number from above instruction:\n");
    scanf("%d",&d);
     if(d==1)
     {
        printf("Enter two numbers for sum:\n");
        scanf("%d%d",&a,&b);
        sum(a,b);
     }
     else if(d==2)
     {
        printf("Enter the two numbers for multiply:\n");
        scanf("%d%d",&a,&b);
        mul(a,b);
     }
     else if(d==3)
     {
        printf("Enter the number for subtract\n");
        scanf("%d%d",&a,&b);
        sub(a,b);
     }
     else if(d==4)
     {
     	printf("Enter the number for factorial\n");
     	scanf("%d",&a);
     	fact(a);
	 }
     else if(d==5)
     {
        printf("Enter the Elements of Matrix A:\n");
        //Input in A---    
        for(i=0;i<3;i++)
        {
           for(j=0;j<3;j++)
          {
            printf("A[%d][%d]= ",i+1,j+1);
            scanf("%d",&A[i][j]);
          }
        }
        //Input in B--- 
        printf("Enter the Elements of Matrix B:\n");   
        for(i=0;i<3;i++)
        {
          for(j=0;j<3;j++)
          {
            printf("B[%d][%d]= ",i+1,j+1);
            scanf("%d",&B[i][j]);
          }
        }
        printf("Result is:\n");
        Multiply(A,B,M);
     }
     else if(d==6)
     {
        printf("Enter the number:\n");
        scanf("%d",&n);
        printf("Table of %d is:\n",n);
        table(n);
     }
     else if(d==7)
     {
        double matrix[MAX][MAX];
        int row, col;
        
        printf("Enter the number of rows: ");
        scanf("%d", &row);
        printf("Enter the number of columns: ");
        scanf("%d", &col);
        
        printf("Enter the elements of the matrix:\n");
        for (int i = 0; i < row; i++) 
        {
            for (int j = 0; j < col; j++) 
            {
                scanf("%lf", &matrix[i][j]);
            }
        }
        
        printf("Original Matrix:\n");
        printMatrix(matrix, row, col);
        
        int rank = rankOfMatrix(matrix, row, col);
        
        printf("Rank of the matrix is: %d\n", rank);
        
        return 0;
    }
    }
    else{
        printf("First read and then go further!\n");
    }
   }
   else
   {
    printf("Invalid Password\n");
   } 
}
void sum(int a,int b)
{
    printf("Sum is: %d \nThank you\n",a+b);
}
void mul(int a,int b)
{
    printf("Multiply is :%d \nThank you\n",a*b);

}
void sub(int a,int b)
{
    printf("Subtract is: %d \nThank you \n",a-b);
}
void fact(int a)
{
	int f,g=1;
	for(f=a;f>=1;f--)
	{
		g=g*f;
	}
	printf("factorial is: %d \nThank you \n",g);
	
}
void Multiply(int A[3][3],int B[3][3],int M[3][3])
{
//Algorithm---    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            M[i][j]=M[i][j]+A[i][k]*B[k][j];
            
          
        }
        
    }
    // printing---    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            
            printf("%d\t",M[i][j]);
          
        }
        printf("\n");
    }
    printf("Thank You!");
}
void table(int n)
{
    int t;
   for(int i=1;i<=10;i++)
   {
    t=n*i;
    printf("%d\n",t);
   }
   printf("Thank you!");
}
void swapRows(double matrix[MAX][MAX], int row1, int row2, int col) 
{
    for (int i = 0; i < col; i++) 
    {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

int rankOfMatrix(double matrix[MAX][MAX], int row, int col) 
{
    int rank = col;
    
    for (int r = 0; r < rank; r++) 
    {
        if (matrix[r][r] != 0) 
        {
            for (int c = 0; c < row; c++) 
            {
                if (c != r) 
                {
                    double mult = matrix[c][r] / matrix[r][r];
                    for (int i = 0; i < rank; i++) 
                    {
                        matrix[c][i] -= mult * matrix[r][i];
                    }
                }
            }
        } else {
            int reduce = 1;
            for (int i = r + 1; i < row; i++) 
            {
                if (matrix[i][r] != 0) 
                {
                    swapRows(matrix, r, i, col);
                    reduce = 0;
                    break;
                }
            }
            if (reduce) 
            {
                rank--;
                for (int i = 0; i < row; i++) 
                {
                    matrix[i][r] = matrix[i][rank];
                }
            }
            r--;
        }
    }
    return rank;
}

void printMatrix(double matrix[MAX][MAX], int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%0.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}