#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>
// int main(){
//     int n;
//     printf("enter any no");
//     scanf("%d",&n);
//     printf("you have entered %d",n);
//     return 0;
// }
struct node{
    int data;
    struct node *next;

};
struct queue{
    struct node *front;
    struct node *rear;
};
struct queue *createQueue(){
    struct node *temp;
    struct queue *q;
    q=malloc(sizeof(struct queue));
    if(!q)
       return NULL;
    temp= malloc(sizeof(struct node));
    q->front=q->rear=NULL;
    return q;   
}
int IsEmptyqueue(struct queue *q){
    return(q->front==NULL);
}
void Enqueue(struct queue *q, int data){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(q->rear)
       q->rear->next=newnode;
    q->rear=newnode;
    if(q->front==NULL)
       q->front=q->rear;
}
int Dequeue(struct queue *q){
    int data=0;
    struct node *temp;
    if(IsEmptyqueue(q)){
        printf("empty");
        return 0;
    }
    else{
        temp=q->front;
        data=q->front->data;
        q->front=q->front->next;
        free(temp);
    }
    return data;
}
 int search(struct queue *q,int data){
    struct node *temp =q->front;
    while(temp!=NULL){
        if(temp->data==data)
           return 1;
        
        else
        {
             temp=temp->next;
        }
        
        
    }
    return 0;
}
void print(struct queue *q){
    struct node *temp=q->front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void printPages(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

 int main()
 {
      int pages[]={2,4,3,5,6,7,5,7,4,2,1};
      int capacity=4;
      int pagefault=4;
      struct queue *q;
      q=createQueue();
      printPages(pages,11);

       for(int i=0;i<11;i++){
          if(search(q,pages[i])==1){
           print(q);
           printf("  x  \n");
           printf("----------\n");
           continue; 
          }
          else
          {
               if(i>=4){
                 Dequeue(q);
                 Enqueue(q,pages[i]);
                 ++pagefault;
               }
               else
               {
                    Enqueue(q,pages[i]);
               }
               
          }
          print(q);
          printf("  Y  \n");
          printf("----------\n");
       }
    
       printf("pagefault-->%d",pagefault);

       
     return 0;
 }
