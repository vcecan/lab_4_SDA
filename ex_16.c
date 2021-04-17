#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dataa;
    struct node *next;
}*front,*rear,*temp,*front1,*front2;
struct node *head;

int frontelement();
void enq(int data);
void deq();
void empty();
void display();
int cmd();
void create();
void queuesize();
int gcd();
void manipulare();
void push_2 ();

int count = 0;

void main()
{
    int no, ch, e;

    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size");
    printf("\n 8 - exercise continuation");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            cmd();
            break;
        case 7:
            queuesize();
            break;
        case 8:
            manipulare();
            break;
        default:
            printf("Error;  ");
            break;
            display();
        }
    }
}

/* Create an empty queue */
void create()
{
    front = rear = NULL;
}

/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}

/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->next = NULL;
        rear->dataa = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->next = temp;
        temp->dataa = data;
        temp->next = NULL;

        rear = temp;
    }
    count++;
}

/* Displaying the queue elements */
void display()
{
    front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d\n", front1->dataa);
        front1 = front1->next;
    }
    if (front1 == rear)
        printf("%d\n", front1->dataa);
}
int gcd(int a,int b) {
   int temp;
   while(b > 0) {
      temp = b;
      b = a % b;
      a = temp;
   }
   return a;
}
int cmd()
{
    front1 = front;
    int min= front->dataa;
    int min_1,min_2,cmd;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {   min_2=front1->dataa;
       // printf("%d ", front1->dataa);
        front1 = front1->next;
        min_1=front1->dataa;
        if(min_2>min_1){
            min=min_1;
        }
    }
    if (front1 == rear)
        {
            if(min_2>rear->dataa)
            min=rear->dataa;
        }
      //  printf("%d", front1->dataa);
        printf("\n\nThe smallest element: %d\n",min);
        cmd=front->dataa;
        front2=front->next;
        while (front2 != rear)
    {
     cmd = gcd(front2->dataa, cmd);
        front2 = front2->next;
        }
        printf("\n\nThe greatest comon divisor: %d\n",cmd);
}

/* Dequeing the queue */
void deq()
{
    front1 = front;

    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->next != NULL)
        {
            front1 = front1->next;
            printf(" Dequed value : %d\n", front->dataa);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->dataa);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}

/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->dataa);
    else
        return 0;
}

/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
void manipulare()
{
    int n,i,numar,count_2;
    printf("\nGive a value for n:\n");
    scanf("%d",&n);
    int array[20];
    printf("\nGive number Value :\n");
    scanf("%d",&numar);
     front1 = front;

    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    front1=front;
    count_2=count;
    int j;
    for(i=0;i<count_2;i++)
    {
        array[i]=front1->dataa;
        if(i==n)
            enq(numar);
             if(i==n*2)
            enq(numar);
            if(i==n*3)
            enq(numar);
            if(i==n*4)
            enq(numar);
            if(i==n*5)
            enq(numar);
            if(i==n*6)
            enq(numar);
        enq(array[i]);
        front1=front1->next;
    }
     for(i=0;i<count_2;i++)
    {
        deq();
    }
    //printf("Elementele introduse in stiva:\n");
        for(i=0;i<count_2;i++)
            push_2 (array[i]);
            display_stack();
printf("Queue elemnts after modification:\n");
    while (front1 != rear)
    {
        printf("%d\n", front1->dataa);
        front1 = front1->next;
    }
    if (front1 == rear)
        printf("%d\n", front1->dataa);
}

void push ()
{
    int dataa;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        printf("Enter the value");
        scanf("%d",&dataa);
        if(head==NULL)
        {
            ptr->dataa = dataa;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->dataa = dataa;
            ptr->next = head;
            head=ptr;

        }
        printf("Item pushed");

    }
}
void push_2 (int dataa)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        if(head==NULL)
        {
            ptr->dataa = dataa;
            ptr -> next = NULL;
            head=ptr;
        }
        else
        {
            ptr->dataa = dataa;
            ptr->next = head;
            head=ptr;
        }
    }
}
void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        item = head->dataa;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped");

    }
}
void display_stack()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->dataa);
            ptr = ptr->next;
        }
    }
}



