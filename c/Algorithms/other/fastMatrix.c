#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 10 
#define COL 10
#define MAX_TERMS 60
#define line "======================================\n"

typedef struct {
   int row;
   int col;
   int values;
}term;

term triple[MAX_TERMS];
term transpose[MAX_TERMS];

int orig[ROW][COL]={0};
void creatMatrix(void);
void getMatrix(void);
void setNewMatrix(term trans[]);
void fast_transpose(term trip[],term transp[]);

int main(void)
{  
   creatMatrix();
   getMatrix();
   fast_transpose(triple,transpose);
   setNewMatrix(transpose);
   return 0;
}

void creatMatrix(void)//随机产生一个稀疏矩阵
{
   int i,j,value;
   int temp[MAX_TERMS];
   srand((unsigned int)time(NULL));//产生随机数的种子,使得每次的随机数不一样
   for(i=0;i<MAX_TERMS;i++)//产生元素的最多为60,有时可能覆盖
   {
      orig[rand()%ROW][rand()%COL]=rand()%100;//随机产生位置和值
   }
   
    FILE *fp=fopen("randomMatrix.dat","w");
    fprintf(fp,"Random creat a Matrix\n");
    fprintf(fp,line);
    for(i=0;i<ROW;i++)
    {
       for(j=0;j<COL;j++)
       {
         fprintf(fp,"%d\t",orig[i][j]);
       }
       fprintf(fp,"\n");
     }
    fprintf(fp,line);
    fclose(fp);
}

void getMatrix(void)
{
   FILE *fp=fopen("randomMatrix.dat","r");
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
    
  fclose(fp);
  triple[0].row=ROW;
  triple[0].col=COL;
  triple[0].values=counts;
  
  for(i=0;i<ROW;i++)
  {
    for(j=0;j<COL;j++)
     {
        if(orig[i][j]!=0)
        {
           triple[current].row=i;
           triple[current].col=j;
           triple[current].values=orig[i][j];
           current++;
        }
     }
  }
}

void setNewMatrix(term transp[])
{
   int i,j;
   int newMatrix[ROW][COL]={0};
   FILE *fp=fopen("randomMatrix.dat","a");
   
   if(fp==NULL)
   {
       fprintf(stderr,"Error! can't open the my.dat\n");
       exit(1);
   }
   
   char c[]="the tranpose matrix is:\n";
   fprintf(fp,"%s",c);
   fprintf(fp,line);
   
   for(i=1;i<=transp[0].values;i++)
   {
       newMatrix[transp[i].row][transp[i].col]=transp[i].values;
   }
   
   for(i=0;i<ROW;i++)
   {
       for(j=0;j<COL;j++)
       {
          fprintf(fp,"%d\t",newMatrix[i][j]);
       }
       fprintf(fp,"\n");
   }
   fclose(fp);
}

//从稀疏矩阵的三元列中获得每列元素个数,就可以得到转置矩阵每行的个数 
void fast_transpose(term trip[],term transp[])
{
   int row_terms[COL],starting_pos[COL];
   //get original's column number and non-zero elements number
   int i,j=0,num_cols=trip[0].col,num_terms=trip[0].values;
   //get how many column isn't all zero elements
   transp[0].row=num_cols;
   /*col transpose to row,set transp's col as trip's row value*/
   transp[0].col=trip[0].row;
   //set transpose's elements number as original's
   transp[0].values=num_terms;
   
   if(num_terms>0)
   {
      for(i=0;i<num_cols;i++)//初始化转置矩阵每行的元素个数
         row_terms[i]=0;
      for(i=1;i<num_terms;i++)
         row_terms[trip[i].col]++;//统计转置矩阵每行的元素个数
      starting_pos[0]=1;//设置起始位置为1,因为三元列是从第1开始存储原矩阵的相关信息
      for(i=1;i<num_cols;i++)
         starting_pos[i]=starting_pos[i-1]+row_terms[i-1];//计算每一行转置的起始位置
      for(i=1;i<=num_terms;i++)
      {
      /*trip sort original matrix's non-zero elements suffix and 
      *correspond values,using starting_pos get every column's first
      *non-zero element and increment in loop.loop retrive all 
      *elements in trip.so we transpose matrix in a efficiently way.
      */
         j=starting_pos[trip[i].col]++;//转到下一个转置的元素处
         /*trip sort by column ,but transpose use row instead.
         *use col to row transpose ,we must set correct position
         *that transpose from trip to transpose in order
         */
         transp[j].row=trip[i].col;
         transp[j].col=trip[i].row;
         transp[j].values=trip[i].values;
      }   
   }
}
