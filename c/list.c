#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};
typedef struct node  NODE;        

struct node *head = NULL;
struct node *current = NULL;

struct tag_list
{
    int data;              
    struct tag_list* next;    
    struct tag_list* prev;     
};
typedef struct tag_list  LIST;        
typedef struct tag_list*  PLIST;       
PLIST  dlhead = NULL, dltail = NULL;  
 

/*********************************************************/
/* [1.1] Single Linked List : display the list           */
/*********************************************************/
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
    
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
    
   printf(" ] \n");
}

/*************************************************************************/
/* [1.2] Single Linked List : Frequency of a given number in Linked List */
/*************************************************************************/
int count(struct node *head, int item)
{
    struct node* curr = head;
    int count = 0;

    while (curr != NULL)
    {
        if (curr -> data == item)
            count++;
        curr = curr -> next;
    }
    return count;
}

/****************************************************************/
/* [1.3] Single Linked List : insert link at the first location */
/****************************************************************/
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
    
   link->key = key;
   link->data = data;
    
   //point it to old first node
   link->next = head;
    
   //point first to new first node
   head = link;
}

/****************************************************************/
/* [1.4] Single Linked List : delete first item                 */
/****************************************************************/
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
    
   //mark next to first link as first 
   head = head->next;
    
   //return the deleted link
   return tempLink;
}

/****************************************************************/
/* [1.4] Single Linked List : check it is empty                 */
/****************************************************************/
bool isEmpty() {
   return head == NULL;
}



/****************************************************************/
/* [1.5] Single Linked List : find a link with given key        */
/****************************************************************/
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
    
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }          
   //if data found, return the current Link
   return current;
}

/****************************************************************/
/* [1.6] Single Linked List : delete a link with given key      */
/****************************************************************/
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
    
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
   return current;
}

/****************************************************************/
/* [1.7] Single Linked List : Delete all the Linked List        */
/****************************************************************/
void deleteList(struct node** head_ref)
{
   /* deref head_ref to get the real head */
   struct node* current = *head_ref;
   struct node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}

/****************************************************************/
/* [1.8] Single Linked List : Find Loop in A Single Linked List */
/****************************************************************/
bool hasLoop(NODE *head)  
{  
  NODE *slow, *fast;  
  slow = fast = head;  

  while (slow && fast )  
  {  
    slow = slow->next;  
    fast = fast->next;  
    
    if (fast)  
      fast = fast->next;  
    else  
      return false;  //dead end  
    
    if (slow == fast)  //loop detected  
      return true;  
  }  
  return false;  
}

/****************************************************************/
/* [1.9] Single Linked List : Rotate Linked List by K nodes    */
/*   Given linked list   : 1 2 3 4 5                            */
/*   Rotated Linked list : 3 4 5 1 2                            */
/* 1) Traverse the list by k nodes.
   2) Keep kth node in temp.
   3) Travese till end of list and set last node pointer to start.
   4) Set temp nodes next to head.
   5) Point kth node next to NULL.
/****************************************************************/
rotate(struct node **head, int k)
{
    if (k == 0) 
        return;

    struct node * curr = *head;
    while (count < k && current != NULL)
    { 
        curr = curr->next;
        count++;
    }   

    if (curr == NULL)
        return;
    struct node *kthNode = curr;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
}

/**********************************************************************************/
/* [1.10] Single Linked List: Insert nodes into Linked List in a sorted fashion   */
/**********************************************************************************/
void listInsertSorted(struct node **head, struct node *new)
{
    // Special Case for the head end
    if (*head == NULL || (*head)->data >= new -> data) 
    {
        new->next = *head;
        *head = new;
    }
    else
    {   // locate the node before which the insertion is to happen !!
        struct node * curr = *head;
        while (curr->next != NULL && curr->next->data < new->data)
        {
            curr = curr->next;
        }
        new->next = curr->next; 
        curr=new; 
    }   
}

/****************************************************************/
/* [1.11] Single Linked List : Sort a Linked List               */
/****************************************************************/
void sort() {
   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
    
   int size = length();
   k = size ;
    
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
        
      for ( j = 1 ; j < k ; j++ ) {   
        
         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
            
         current = current->next;
         next = next->next;
      }
   }   
}

/****************************************************************/
/* [1.12] Single Linked List : Reverse a Linked List            */
/* Input : ->30->25->20->15->10->5
  Reversed : ->5->10->15->20->25->30.
  Cre­ate 3 nodes, cur­rN­ode, Pre­vN­ode and nextNode.
  Ini­tial­ize them as cur­rN­ode = head; nextN­ode = null;pre­vN­ode = null;
  Now keep revers­ing the point­ers one by one till currNode!=null.
/****************************************************************/
void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
    
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
    
   *head_ref = prev;
}

/****************************************************************/
/* [1.13] Single Linked List : Recursive Reverse a Linked List  */
/****************************************************************/
void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;  
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref; 
    rest  = first->next;
 
    /* List has only one node */
    if (rest == NULL)
       return;  
 
    /* reverse the rest list and put the first element at the end */
    recursiveReverse(&rest);
    first->next->next  = first; 
     
    /* tricky step -- see the diagram */
    first->next  = NULL;        
 
    /* fix the head pointer */
    *head_ref = rest;           
}

/***********************************************************************/
/* [1.14] Single Linked List : Move last node to front in linked list  */
/* We are using a double pointer head_ref here because we change  
   head of the linked list inside this function.*/
/***********************************************************************/
void moveToFront(struct node **head_ref)
{
  /* If linked list is empty, or it contains only one node,
    then nothing needs to be done, simply return */  
  if(*head_ref == NULL || (*head_ref)->next == NULL)
    return;
     
  /* Initialize second last and last pointers */ 
  struct node *secLast = NULL;
  struct node *last = *head_ref;
   
  /*After this loop secLast contains address of second last
  node and last contains address of last node in Linked List */
  while(last->next != NULL) 
  {
    secLast = last;
    last = last->next;
  }               
   
  /* Set the next of second last as NULL */
  secLast->next = NULL;
   
  /* Set next of last as head node */
  last->next = *head_ref;
   
  /* Change the head pointer to point to last node now */
  *head_ref = last; 
} 

/***********************************************************************/
/* [2.01] Double Linked List: Print the List                           */
/***********************************************************************/
void PrintDLL()
{
    PLIST plist = dlhead;         // 맨 앞의 링크드 리스트 위치로 설정
    while( plist )                 
    {
        printf( "%d n", plist->data );
        plist = plist->next;    // 다음 리스트의 번지값으로 plist의 값을 변경
    }
    // 맨 뒤의 구조체부터 맨 앞의 구조체로 순회
    PLIST plist_tail = dltail;            // 맨 뒤의 링크드 리스트 위치로 설정
    while( plist_tail )                  // while( plist != NULL )
    {
        printf( "%d n", plist_tail->data );
        plist_tail = plist_tail->prev;     // 이전 리스트의 번지값으로 plist의 값을 변경
    }
}

/***********************************************************************/
/* [2.03] Double Linked List: insert a node at the beginging           */
/***********************************************************************/
void pushDLL(struct tag_list** head_ref, int new_data)
{
    /* allocate node */
    struct tag_list* new_node =
            (struct tag_list*) malloc(sizeof(struct node));
  
    /* put in the data  */
    new_node->data  = new_data;
     
    /* since we are adding at the begining,
      prev is always NULL */
    new_node->prev = NULL;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ; 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/***********************************************************************/
/* [2.04] Double Linked List: insert a node at the Head                */
/***********************************************************************/
void AddHeadDLL( PLIST plist )
{
    plist->next = NULL;
    plist->prev = NULL;
 
    if( !dlhead )
    {
        dlhead = dltail = plist;
        return;
    }
 
    dlhead->prev = plist;   // 이전(prev) 포인터 설정
    plist->next = dlhead;   // 다음(next) 포인터 설정
    dlhead = plist;
}

/***********************************************************************/
/* [2.05] Double Linked List: insert a node at the Tail                */
/***********************************************************************/
void AddTailDLL( PLIST plist )
{
    plist->next = NULL;    // NULL로 초기화
    plist->prev = NULL;    // NULL로 초기화
   
    if( !dlhead )                 // head 포인터가 아직 아무 것도 가리키지 않으면, if( head == NULL )과 동일
    {
        dlhead = dltail = plist;
        return;
    }
    dltail->next = plist;       // 다음(next) 포인터 설정
    plist->prev = dltail;       // 이전(prev) 포인터 설정
    dltail = plist;
}

/***********************************************************************/
/* [2.06] Double Linked List: reverse a Doubly Linked List             */
/***********************************************************************/
void reverseDLL(struct tag_list **head)
{
    struct tag_list *temp = NULL; 
    struct tag_list *current = *head;
      
    /* swap next and prev for all nodes of doubly linked list */
    while (current !=  NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;            
        current = current->prev;
    }    
      
    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if(temp != NULL )
        *head = temp->prev;
}   

/***********************************************************************/
/* [2.02] Double Linked List: Free the List                            */
/***********************************************************************/
void FreeDoubleLinked()
{
    PLIST tail;
    PLIST plist = dlhead;
    while( plist )
    {
        dlhead = plist->next;
        free( plist );           // 할당한 메모리 해제
        plist = dlhead;
    }
    dlhead = dltail = NULL;      // 포인터 초기화, 재 사용 시 필요
}


/***********************************************************************/
/* [1] Main for Single Linked List :                                   */
/* We are using a double pointer head_ref here because we change  
   head of the linked list inside this function.*/
/***********************************************************************/
main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
    
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
    
   printf("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
    
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   printList();
   printf("\n");
   foundLink = find(4);
    
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
    
   printf("\n");
   sort();
    
   printf("List after sorting the data: ");
   printList();
    
   reverse(&head);
   printf("\nList after reversing the data: ");
   printList();
}

#if 0
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node *next;
}*head;
 
void append(int num)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    right=(struct node *)head;
    while(right->next != NULL)
        right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}
 
void add( int num )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if (head== NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
        left=right;
        right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}
 
void insert(int num)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
        add(num);
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data<num)
            c++;
            temp=temp->next;
        }
        if(c==0)
            add(num);
        else if(c<count())
            addafter(num,++c);
        else
            append(num);
    }
}
 
int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            if(temp==head)
            {
            head=temp->next;
            free(temp);
            return 1;
            }
            else
            {
            prev->next=temp->next;
            free(temp);
            return 1;
            }
        }
        else
        {
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}
 
void  display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
        return;
    }
    while(r!=NULL)
    {
        printf("%d ",r->data);
        r=r->next;
    }
    printf("\n");
}
 
int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    return c;
}
 
int  main()
{
    int i,num;
    struct node *n;
    head=NULL;
    while(1)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Size\n");
    printf("4.Delete\n");
    printf("5.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } 
    else {
        switch(i)
        {
        case 1:      
            printf("Enter the number to insert : ");
            scanf("%d",&num);
            insert(num);
            break;
        
        case 2:     
            if(head==NULL)
            {
               printf("List is Empty\n");
            }
            else
            {
               printf("Element(s) in the list are : ");
            }
            display(n);
            break;
        
        case 3:     
            printf("Size of the list is %d\n",count());
            break;
        
        case 4:     
            if(head==NULL)
                printf("List is Empty\n");
            else{
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                if(delete(num))
                    printf("%d deleted successfully\n",num);
                else
                    printf("%d not found in the list\n",num);
            }
            break;
        
        case 5:    return 0;
        
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}
#endif