#include <stdio.h>
int main()
{
  //indeg-indegree
  int tr[10][10],visited[10],indeg[10];
  int i,j,k,size,count=1;
  printf("Enter the Size of the matrix ");
  scanf("%d",&size);
  for(i=0;i<size;i++)
  {
   printf("Enter the %d row\n",i+1);
    for(j=0;j<size;j++)
    {
      scanf("%d",&tr[i][j]);
    }

  }
  for(i=0;i<size;i++)
  {
    visited[i]=0;
    indeg[i]=0;
  }
  for(i=0;i<size;i++)
    for(j=0;j<size;j++)
      indeg[i]=indeg[i]+tr[j][i];
  printf("The topological Order \n");
  while(count<=size)
  {
    for(k=0;k<size;k++)
    {
      if(indeg[k]==0&& (visited[k]==0))
      {
        printf(" %d ",k+1);
        visited[k]=1;
      }
      for(i=0;i<size;i++)
      {
        if(tr[i][k]==1)
        indeg[k]--;
      }
    }
    count++;
  }
return 0;

}
