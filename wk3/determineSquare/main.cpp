#include <iostream>
#define Max 10

using namespace std;

void outputMatrix(int [Max][Max]);
int dimension;
int determine(int [Max][Max],int);


int main()
{
    cout<<"Enter the dimension of square matrix(Maximum is 10): ";
    cin>>dimension;

    int Matrix[10][10]= {0};
    for(int i=0;i<dimension;i++)
        for(int j=0;j<dimension;j++)
        {
            cout<<"Please input row "<<i+1<<" column "<<j+1<<": ";
            cin>>Matrix[i][j];
        }

    cout<<"\nThe Input matrix: \n";

    outputMatrix(Matrix);

    cout<<"\nThe determinant of square matrix: "<<determine(Matrix, dimension);

    return 0;
}

void outputMatrix(int mat[Max][Max])
{
         for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

int determine(int mat[Max][Max], int dim)
{
    int result=0;

    if(dim==2)
    {
       return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    else
    {
        dimension-=1;
        for(int k=0;k<dim;k++)
        {
            int temp[10][10];

            int row=0,col=0;
            for(int i=1;i<dim;i++)
            {
                col=0;
                for(int j=0;j<dim;j++)
                {
                    if(j==k)continue;
                    else
                    {
                        temp[row][col]= mat[i][j];
                        col++;
                    }
                }
                row++;
            }

            if(k%2)
            {
                result += mat[0][k]*(-1)*determine(temp,dim-1);
            }
            else result += mat[0][k]*determine(temp,dim-1);
        }
    }
    return result;
}
