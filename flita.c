#include <malloc.h> //функции стандартной библиотеки malloc, free и realloc позволяют реализовать массив переменного размера
#include <stdio.h>
void push_back(int *arr, int size, int value)//функция для добавления в массив элемента
{
	int *newArray = (int*)malloc(sizeof(int) * (size+1));;
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	//free(arr); // Освобождение памяти после использования массива
	arr = newArray;
	printf("array after element added:");
	printf("\n");
	for(int i=0;i<size;i++)
    {
      printf("%d",arr[i]);
      printf("\t");
    }
    printf("\n");
}
void rem_elt(int *A, int *n, int x)//функция для удаления элемента х из массива
{
     int i_from, i_to;
     i_from=0;
     i_to=0;
     while (1)
     {
        if (i_from > *n) break;   
        if (A[i_from]==x)
        {
           i_from++;
        }
        else
        {
           A[i_to++]=A[i_from++];    
        }
      }      
      *n=i_to-1;
      return;
}   
/*void pop_back(int *arr, int size)//функция для удаления элемента массива
{
	size--;
	int *newArray = (int*)malloc(sizeof(int) * (size+1));;
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	//free(arr); // Освобождение памяти после использования массива
	arr = newArray;
	printf("Array after removing: ");
	printf("\n");
    for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
        printf("\t");
    }
}*/
int main()
{
    int size;
    printf("Enter the size of the array:");
    printf("\n");
    scanf("%d", &size);
    int *arr = (int*)malloc(sizeof(int) * size);  // Создание динамического массива из size элементов типа int
    for(int i=0;i<size;i++)
    {
      printf("Enter an element with a number - ");
      printf("%d",i+1);
      printf("\n");
      scanf("%d",&arr[i]);
        
    }
    
    printf("Source array:");
    printf("\t");
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        printf("\t");
    }
    
    printf("\n");
    
    int size2;
    printf("Enter the size of the array №2:");
    printf("\n");
    scanf("%d", &size2);
    int *arr2 = (int*)malloc(sizeof(int) * size2);  // Создание динамического массива из size элементов типа int
    for(int i=0;i<size2;i++)
    {
      printf("Enter an element with a number - ");
      printf("%d",i+1);
      printf("\n");
      scanf("%d",&arr2[i]);
        
    }
    
    printf("Source array №2:");
    printf("\t");
    for(int i=0;i<size2;i++)
    {
        printf("%d",arr2[i]);
        printf("\t");
    }
    
    printf("\n");
    //push_back(arr,size,value);
    //pop_back(arr,size+1);
    /*for(int i=0;i<size;i++)
    {
      printf("%d",arr[i]);
        
    }*/
    //size=size+1;
    while(1)
    {
        int v;
        printf("select array(1 or 2)");
        printf("\n");
        printf("program exit - 3");
        printf("\n");
        scanf("%d",&v);
        if(v==1)
        {
            int d;
            printf("choose what you want to do: delete or add, 1 - delete, 2- add");
            printf("\n");
            scanf("%d",&d);
            if(d==1)
            {
                int r;
                printf("Please, enter the element you want to remove");
                printf("\n");
                scanf("%d", &r);
                rem_elt(arr,&size,r);
                
                printf("Array after removing: ");
                for (int i=0; i<size; i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
            }
            if(d==2)
            {
                int value;
                printf("write the number you want to add to the array");
                printf("\n");
                scanf("%d", &value);
                push_back(arr,size,value);
            }
        }
        if(v==2)
        {
            int d;
            printf("choose what you want to do: delete or add, 1 - delete, 2- add");
            scanf("%d",&d);
            if(d==1)
            {
                int r;
                printf("Please, enter the element you want to remove");
                printf("\n");
                scanf("%d", &r);
                rem_elt(arr2,&size2,r);
                
                printf("Array after removing: ");
                for (int i=0; i<size2; i++)
                {
                    printf("%d ",arr2[i]);
                }
                printf("\n");
            }
            if(d==2)
            {
                int value;
                printf("write the number you want to add to the array");
                printf("\n");
                scanf("%d", &value);
                push_back(arr2,size2,value);
            }
        }
        if(v==3)
        {
            break;
        }
    }
    free(arr);
    free(arr2);
    return 0;
}

