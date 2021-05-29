//Spiral Graph.cpp
//To print a n*n matrix that sprial form outside to inside.

#include <iostream>
#include <iomanip>

using namespace std;

void printSprial(int);

int main()
{
    cout<<"Input dimension: ";
    int dimension;
    cin>>dimension;
    cout<< "\n";

    printSprial(dimension);

    return 0;
}

//A function to print Sprial Graph.
void printSprial(int dim)
{
    int total = dim*dim;
    int temp[dim][dim]={0};
    int boundary= dim, nextb= dim-1, flag = 0;
    int direction = 'r';
    int col=0, row=0;

    temp [0][0] =1;

    for(int i=2;i<=total;i++)
    {

        switch(direction)
        {
            case 'r':
                col+=1;
                break;
            case 'd':
                row+=1;
                break;
            case 'l':
                col-=1;
                break;
            case 'u':
                row-=1;
        }
        temp[row][col] = i;

        if(i==boundary)
        {
            flag+=1;

            boundary +=nextb;
            if(flag==2){nextb-= 1;flag=0;}

            switch(direction)
            {
            case 'r':
                direction = 'd';
                break;
            case 'd':
                direction = 'l';
                break;
            case 'l':
                direction = 'u';
                break;
            case 'u':
                direction = 'r';
            }

        }

    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++)
        {
            cout<<setw(2)<<setfill('0')<<temp[i][j]<<" ";
        }
        if(i==dim-1)break;
        else cout<<"\n";}
}
