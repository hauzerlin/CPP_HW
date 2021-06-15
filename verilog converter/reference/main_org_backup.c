#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *ifp1;
    unsigned int key,score,weighting;
    unsigned int sum=0, i=0;
    float average=0.0;

    if (argc!=3) {
        printf("\n\nUsage... \n");
        printf("program file_name\n");
        printf("EX.\n");
        printf("a.exe weighting sample_payload.txt\n");
        exit(0);
       }
 weighting=atoi(argv[1]);
  if((ifp1=fopen(argv[2],"r"))==NULL)
    {
      printf("Error!! Can't open pattern file: %s !!!\n",argv[2]);
      exit(0);
    }

     while (fscanf(ifp1, "%d %d",&key , &score)==2) {

         sum=sum+score;
         i++;
         printf("key=%d, length=%d\n",key, score);
     }
      fclose(ifp1);
    average=sum/i;
     printf("No. of Students=%d, Total sum=%d, average=%f, weighting=%d, avg2=%f\n",i,sum,average, weighting, weighting+average );
    return 0;
}
