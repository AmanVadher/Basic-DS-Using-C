#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root=NULL;
void append(void);
void addatbegin(void);
void addafter(void);
int length(void);
void display(void);
void delete(void);
void main()
{
    int ch,len;
    while(1)
    {
    	printf("Single Linked List Operations:\n");
    	printf("1.Append\n");
    	printf("2.Addatbegin\n");
    	printf("3.Addafter\n");
    	printf("4.Length\n");
    	printf("5.Display\n");
    	printf("6.Delete\n");
    	printf("7.Exit\n");
    	printf("Enter your choice:");
    	scanf("%d",&ch);
    	
    	switch(ch)
    	{
    	   case 1: append();
    	            break;
    	   case 2: addatbegin();
    	            break;
    	   case 3: addafter();
    	            break;
    	   case 4: len=length();
    	           printf("Length of link list is:%d\n",len);
    	            break;
    	   case 5: display();
    	            break;
    	   case 6: delete();
    	            break;
    	   case 7: exit(1);
    	   default: printf("Invalid Choice\n");
    	}
    }
}

void append()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link != NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}
int length()
{
    int count=0;
    struct node *temp;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp=temp->link;
    }
    return count;
}
void display()
{
    struct node *temp;
    temp=root;
    if(temp == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->link;
    }
    printf("\n");
    }
}
void addatbegin(void)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data:");
    scanf("%d",&temp->data);
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}
void addafter(void)
{
   struct node *temp,*p;
   int loc,len,i=1;
   printf("Enter Location after which node is added:");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid location\n");
        printf("Currently list is having %d nodes",len);
    }
    else
    {
        p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&temp->data);
        temp->link=NULL;
        temp->link=p->link; //right side connection
        p->link=temp; //left side connection
    }
}
void delete()
{
    struct node *temp;
    int loc;
    printf("Enter Location to Delete:");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid Location\n");
    }
    else if(loc == 1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node *p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}
