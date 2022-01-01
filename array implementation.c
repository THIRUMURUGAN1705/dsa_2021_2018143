#include <stdio.h>
int size=5;
int i;
void insert(int array[6],int element, int pos)
{
    int k=size;
    for(i=0; i<size; i++)
    {
        if(k>=pos)
        {
            array[k]=array[k-1];

            k--;
        }
    }
    array[pos]=element;
    printf("New array:\n");
    for(i=0; i<size+1; i++)
    {
        printf("%ls\n", array[i]);
    }

}
void delete(int array[5],int pos)
{
    int k=size;
    for(i=pos; i<size-1; i++)
    {
        array[k]=array[k+1];
        k--;
    }
    printf("New array:\n");
    for(i=0; i<size-1; i++)
    {
        printf("%ls\n",&array[i]);
    }
}
void traverse()
{
    int array[6];
    for(i=0; i<size; i++)
    {
        printf("%d\n",&array[i]);
    }
}
void main()
{
    int i,p,choice,N,element,pos;
    int array[6];
    printf("Enter the array elements :\n");
    for(i=0; i<size; i++)
    {
        scanf("%d",&array[i]);
    }
    while(1)
    {
        printf("1.insertion \n2.deletion \n3.traverse\n4.search\n5.exit");
        printf("Enter your choice:\n");
        scanf("%d\n",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element and position:\n");
            scanf("%d\n%d\n",&element,&pos);
            insert(array,element,pos);
            break;
        case 2:
            printf("Enter the position😊:\n");
            scanf("%d",&pos);
            delete(array,pos);
            break;
        case 3:
            printf("the elements in the array:\n");
            for(i=0; i<size; i++)
            {
                printf("%d\n",&array[i]);
            }
            break;
        case 4:
            printf("1.search by value \n2.search by position \n");
            printf("Enter your choice:\n");
            scanf("%d",&p);
            if(p=1)
            {
                printf("Enter the value:\n");
                scanf("%d",&N);
                if(array[i]=N)
                {
                    printf("The element is in %d th position.\n",i+1);
                }
                else
                {
                    printf("Element not found!");
                }
            }
            else if(p==2)
            {
                printf("Enter the position\n");
                scanf("%d",&N);
                if(N<size)
                {
                    printf("the element is %d\n", array[N-1]);
                }
                else
                {
                    printf("Enter valid position value!");
                }
            }
            else
            {
                printf("Enter valid option!");
            }
        
        break;
        case 5:
        exit(1);
        default:
        printf("wrong input");
        }

    }
}