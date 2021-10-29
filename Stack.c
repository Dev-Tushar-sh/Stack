#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack* createstack(int);
void main()
{
  int n;
  struct Stack *stack;
  stack=createstack(4);
while(1)
{
    system("cls");
  printf("This is a stack program created by Tushar sharma");
  printf("\n1 push\n2 pop\n3 showstack\n4 sortstack\n5 Reverse\n6 Exit");
  printf("\nEnter your choice - ");
  scanf("%d",&n);

      switch(n)
      {
      case 1 : push(stack);
               break;
      case 2 : pop(stack);
               break;
      case 3 : showstack(stack);
               break;
      case 4 : sortstack(stack);
               break;
      case 5 : reversestack(stack);
               break;
      case 6 : exit(0);
      default : {printf("aankh k andhe option dekh k bhar\n");
                getch();
                break;}

      }

}}
struct Stack
{
    int Top;
    int capasity;
    int *array
};
struct Stack* createstack(int cap)
{
 struct Stack *stack;
 stack=malloc(sizeof(struct Stack));
 stack->Top=-1;
 stack->capasity=cap;
 stack->array= malloc(sizeof (int)*stack->capasity);
 return(stack);
}
void push(struct Stack *stack)
{
    int item;
    if(stack->Top==stack->capasity-1)
    { printf("stack is full can't push anything");
     getch();}
    else
     {  printf("enter the element to push - ");
        scanf("%d",&item);
        stack->Top++;
        stack->array[stack->Top]=item;
     }
}
void pop(struct Stack *stack)
{
    int item;
  if(stack->Top==-1)
    printf("stack is already empty\n");
  else
  {
    item=stack->array[stack->Top];
    stack->Top--;
    printf("you poped top element %d\n",item);
    showstack(stack);
  }

  getch();
}
void showstack(struct Stack *stack)
{

int i;
printf("The stack is - \n");
for(i=stack->Top;i>=0;i--)
 {
    printf("               %d\n",stack->array[i]);
 }
 getch();
}
sortstack(struct Stack *stack)
{

    int item,temp[4],emp;

    for(int i=0;i<=3;i++)
    {
    item=stack->array[stack->Top];
    stack->Top--;
    temp[i]=item;
    }            //popped

      for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=3;j++)
        {
            if(temp[i]<temp[j])
          { emp=temp[i];
            temp[i]=temp[j];
            temp[j]=emp;
          }
        }
    }

     for(int i=0;i<=3;i++)
        {
        stack->Top++;
        stack->array[stack->Top]=temp[i];
        }







     showstack(stack);
}
reversestack(struct Stack *stack)
{

    int item,temp[4];

    for(int i=0;i<=3;i++)
    {
    item=stack->array[stack->Top];
    stack->Top--;
    temp[i]=item;
    }
    for(int j=0;j<=3;j++)
        {
        stack->Top++;
        stack->array[stack->Top]=temp[j];
        }
    printf("Reverse of ");
       showstack(stack);
}
