#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 25

#define ROW 5
#define COL 5

typedef struct {
   int col;
   int row;
   int value;
   }term;

term a[MAX_TERMS];
term b[MAX_TERMS];
int orig[ROW][COL];

void getMatrix();
void setNewMatrix();
void transpose(term old[],term new[]);
int main(void)
{
   getMatrix();
   transpose(a,b);
   setNewMatrix(b);
   return 0;
}
void getMatrix(void)
{
   FILE *fp=fopen("my.dat","r");
   int i,j,counts=0,current=1;
   if(fp==NULL)
   {
      fprintf(stderr,"Error! can't open the my.dat\n");
      exit(1);
   }
   for(i=0;i<ROW;i++)
   {
      for(j=0;j<COL;j++)
      {
         fscanf(fp,"%d",&orig[i][j]);
         if(orig[i][j]!=0)
            counts++;
      }
    }
   a[0].row=ROW;
   a[0].col=COL;
   a[0].value=counts;
   for(i=0;i<ROW;i++)
   {
      for(j=0;j<COL;j++)
      {
         if(orig[i][j]!=0)
         {
            a[current].row=i;
            a[current].col=j;
            a[current].value=orig[i][j];
            current++;
         }
      }
   }
   fclose(fp);
}
void transpose(term old[],term new[])
{
   int i,j,currentNew;
   int n=old[0].value;
   new[0].row=old[0].col;
   new[0].col=old[0].row;
   new[0].value=n;
   if(n)
   {
      currentNew=1;
      for(i=0;i<old[0].col;i++)
      {
         for(j=1;j<n;j++)
         {
            if(old[j].col==i)
            {
               new[currentNew].row=old[j].col;
               new[currentNew].col=old[j].row;
               new[currentNew].value=old[j].value;
               currentNew++;
            }
         }//end of inner for
      }//end of first for
   }//end of if
}
void setNewMatrix(term b[])
{
   int i,j;
   int newMatrix[ROW][COL]={0};
   FILE *fp=fopen("result.dat","a");
   if(fp==NULL)
   {
       fprintf(stderr,"Error! can't open the my.dat\n");
       exit(1);
   }
   char c[]="the tranpose matrix is:\n";
   fprintf(fp,"%s",c);
   for(i=1;i<b[0].value;i++)
   {
       newMatrix[b[i].row][b[i].col]=b[i].value;
   }
   for(i=0;i<ROW;i++)
   {
       for(j=0;j<COL;j++)
       {
          fprintf(fp,"%d\t",newMatrix[i][j]);
       }
       fprintf(fp,"\n");
   }
}
