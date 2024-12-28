/*Q2. Write a C/C++ program to implement stack data structure using
array. Implement below metioned functions.
a) push b) pop c) peep d) displayStack e)isStackFull
f) isStackEmpty*/

#include<stdio.h>
#include<stdlib.h>
void push(int *,int *,int);
int pop (int* , int*);
void peek(int *,int);
void displayStack(int*,int);
void isStackFull(int );

#define SIZE 10
int main(void)
{

int arr[SIZE];
int top=-1;
int choice ,ele;int ret;
while(1){
printf("ENTER 1->push 2->pop 3->display 4->exit 5->peek 6-->isstackfull\n");
scanf("%d",&choice);
 
 switch (choice){
 
    case 1:printf("Element to push\n");
           scanf("%d",&ele);
           push(arr,&top,ele);
           break;
           
           
    case 2:ret=pop(arr,&top);
           if(ret!=-77){printf("poped item =%d\n",ret);}
           break;
           
    case 3:
           displayStack(arr,top);
           break;
           
     case 4:
            printf("exiting\n");
            exit(0);
	
    case 5:
	   peek(arr,top);
	   break;
	   
    case 6:
    	   isStackFull(top);	
    	   break;   
      }
}
     } 
void push(int *arr,int *t,int ele){
  if(*t==SIZE-1)
  {
  printf("Stack Full\n");
  return;
  }
  *t=*t+1;
  arr[*t]=ele;
}

int pop(int*arr,int *t){

  if(*t==-1){
  printf("Stack is Empty\n");
  return -77;
  }
  
  int temp=arr[*t];
  arr[*t]=-99;
  *t=*t-1;
  return temp;
  }
  
  void displayStack(int *arr,int t){
  if(t==-1){
  printf("Stack is Empty\n");
  return;
  }
  
  for(int i=0;i<SIZE;i++){
  printf("  ___\n");
  printf(" ||%d||\n",arr[i]);
  printf("  ___\n");
  }
  }
void peek(int *arr,int top)
  {	
  
  if(top==-1)
  {
  printf("stack is empty");
  }
  else
  {
  	printf("%d",arr[top]);
  }
  }
void isStackFull(int top)  
  {
   
  if(top == SIZE - 1){
  printf("stack Overflow! cannot push more elements.\n");
  }
  else if(top == -1){
  printf("stack is empty\n");
  }
  else
  {
   printf("stack is fill upto %d element\n",top+1);
  }}
  















         
    
