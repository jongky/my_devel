#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/******************************************************************
/* Sites for Top 10 Algorithms 
   1. http://www.programcreek.com/2012/11/top-10-algorithms-for-coding-interview/
*******************************************************************/
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
 

/*********************************************************
 * SingleLinkedList API list :
 *========================================================
1. printList
2. Count
3. isEmpty
4. find
5. insertFirst
6. deleteFirst
7. deleteWithKey
8. deleteList
9. hasLoop
10. sort
11. rotate
12. reverse
13. recursiveReverse
14. moveToFront 
15. listInsertSorted
16. cloneListWithRandomPointer
17. rearrange
18. Reverse alternate K nodes
19. detectAndRemoveLoop
20. mergeTwoSortedLists
21. blineMergeTwoLinkedList
22. mergeAtAlternatePositions
23. sortLInkedList
*********************************************************/

/*********************************************************
 * DoubleLinkedList API list :
 *========================================================
1. printList
2. Count
3. isEmpty
4. find
5. insertFirst
6. deleteFirst
7. node_swap
*********************************************************/

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
/* [1.3] Single Linked List : check it is empty                 */
/****************************************************************/
bool isEmpty() {
   return head == NULL;
}

/****************************************************************/
/* [1.4] Single Linked List : find a link with given key        */
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
/* [1.5] Single Linked List : insert link at the first location */
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
/* [1.6] Single Linked List : delete first item                 */
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
/* [1.7] Single Linked List : delete a link with given key      */
/****************************************************************/
struct node* deleteWithKey(int key) {

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
/* [1.8] Single Linked List : Delete all the Linked List        */
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
/* [1.9] Single Linked List : Find Loop in A Single Linked List */
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
/* [1.10] Single Linked List : Rotate Linked List by K nodes    */
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

/****************************************************************/
/* [1.11] Single Linked List : Reverse a Linked List            */
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
/* [1.12] Single Linked List : Recursive Reverse a Linked List  */
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
/* [1.13] Single Linked List : Move last node to front in linked list  */
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

/**********************************************************************************/
/* [1.14] Single Linked List: Insert nodes into Linked List in a sorted fashion   */
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
/* [1.15] Single Linked List : Sort a Linked List               */
/****************************************************************/
NODE* sort(NODE *s)//to place elements in increasing order
{
  NODE *t1,*t2;
  int temp;

  for(t1 = s;t1->next != NULL;t1=t1->next)
  {
    for(t2 = t1->next;t2 != NULL;t2=t2->next)
    {
      if(t1->data > t2->data)
      {
        temp = t1->data;
        t1->data = t2->data;
        t2->data =temp;
      }
    } 
  }
  return s;
}

/************************************************************************/
/* [1.16] Single Linked List : Clone Linked List with Random Pointer  */
/*
1) Create the copy of every node in the list and insert it in original 
   list between current and next node.
    create the copy of A and insert it between A & B..
    create the copy of B and insert it between B & C..
    Continue in this fashion, add the copy of N to Nth node.

As a result of this exercise, we will get a list like shown below:
AABBCCDDEEFF

2) Now copy the randomrary link in this fashion

    original->next->random = original->random->next;
    Traverse two nodes in every iteration
This works because original->next is nothing but copy of original and 
Original->random->next is nothing but copy of random.

3) Now restore the original and copy linked lists in this fashion in a single loop.
original->next = original->next->next;
copy->next = copy->next->next;

While doing this, take care of end of list (NULL pointer) and NULL pointer dereference.

So in this manner, we are copying the list in O(n) time and O(1) space complexity.
Code:
/************************************************************************/
list* cloneListWithRandomPointer(list* root)
{
    list *res;
    
    list* cur = root;
    list *next, *tmp;
    
    //Create the copy of every node in the list and insert 
    //it in original list between current and next node. 
    while(cur)
    {
        tmp = new(list);
        tmp->val = cur->val;
        tmp->random = NULL;
        tmp->next = cur->next;
        next = cur->next;
        cur->next = tmp;
        cur = next;        
    }
      
    //save result pointer    
    res = root->next;
    
    //Copy the randomrary link for result
    cur = root;    
    while(cur)
    {
        cur->next->random = cur->random->next;
        cur = cur->next->next;  //move 2 nodes at a time
    }
    
    //restore the original and copy linked lists
    cur = root;    
    tmp = root->next;
    while(cur && tmp)
    {
        cur->next = cur->next->next;
        cur = cur->next;
        if (tmp->next){
            tmp->next = tmp->next->next;
            tmp = tmp->next;
        }        
    }    
    return res;
}

/*******************************************************************/
/* [1.17] Single Linked List : rearrange Linked List                
   reverse alternate nodes and append at the end                   */
/* Example:
    Input List:  1->2->3->4->5->6
    Output List: 1->3->5->6->4->2
    Input List:  12->14->16->18->20
    Output List: 12->16->20->18->14

  The idea is to maintain two linked lists, one list of all odd 
  positioned nodes (1, 3, 5 in above example) and other list of 
  all even positioned nodes (6, 4 and 2 in above example). 
  Following are detailed steps.
  1) Traverse the given linked list which is considered as odd list. 
      Do following for every visited node.  
      a) If the node is even node, remove it from odd list and 
         add it to the front of even node list. 
         Nodes are added at front to keep the reverse order.
  2) Append the even node list at the end of odd node list. 
/*******************************************************************/
void rearrange(struct node *odd)
{
    // If linked list has less than 3 nodes, no change is required
    if (odd == NULL || odd->next == NULL || odd->next->next == NULL)
        return;
 
    // even points to the beginning of even list
    struct node *even = odd->next;
 
    // Remove the first even node
    odd->next = odd->next->next; 
    // odd points to next node in odd list
    odd = odd->next;
    // Set terminator for even list
    even->next = NULL;
 
    // Traverse the  list
    while (odd && odd->next)
    {
       // Store the next node in odd list 
       struct node *temp = odd->next->next;
 
       // Link the next even node at the beginning of even list
       odd->next->next = even;
       even = odd->next; 
       // Remove the even node from middle
       odd->next = temp;
 
       // Move odd to the next odd node
       if (temp != NULL)
         odd = temp;
    }
 
    // Append the even list at the end of odd list
    odd->next = even;
}

/*******************************************************************/
/* [1.18] Single Linked List : Reverse alternate K nodes           */
/* Example:
   Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
   Output:   3->2->1->4->5->6->9->8->7->NULL. 
   Method 1 (Process 2k nodes and recursively call for rest of the list)

kAltReverse(struct node *head, int k)
  1)  Reverse first k nodes.
  2)  In the modified list head points to the kth node.  So change next 
       of head to (k+1)th node
  3)  Move the current pointer to skip next k nodes.
  4)  Call the kAltReverse() recursively for rest of the n - 2k nodes.
  5)  Return new head of the list.
/*******************************************************************/
struct node *kAltReverse(struct node *head, int k)
{
    struct node* current = head;
    struct node* next;
    struct node* prev = NULL;
    int count = 0;   
 
    /*1) reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
   
    /* 2) Now head points to the kth node.  So change next 
       of head to (k+1)th node*/
    if(head != NULL)
      head->next = current;   
 
    /* 3) We do not want to reverse next k nodes. So move the current 
        pointer to skip next k nodes */
    count = 0;
    while(count < k-1 && current != NULL )
    {
      current = current->next;
      count++;
    }
 
    /* 4) Recursively call for the list starting from current->next.
       And make rest of the list as next of first node */
    if(current !=  NULL)
       current->next = kAltReverse(current->next, k); 
 
    /* 5) prev is new head of the input list */
    return prev;
}

/*******************************************************************/
/* [1.19] Single Linked List : Detect and removes loop Linked List */
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0                                              */
/*******************************************************************/
int detectAndRemoveLoop(struct node *list)
{
    struct node  *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p)
        {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    } 
    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(struct node *loop_node, struct node *head)
{
   struct node *p1;
   struct node *p2;
 
   /* Set a pointer to the beging of the Linked List and
      move it one by one to find the first node which is
      part of the Linked List */
   p1 = head;
   while (1)
   {
      /* Now start a pointer from loop_node and check if it ever
       reaches p2 */
      p2 = loop_node;
      while (p2->next != loop_node && p2->next != p1)
        p2 = p2->next;
 
      /* If p2 reahced p1 then there is a loop. So break the
        loop */
      if (p2->next == p1)
        break;
 
      /* If p2 did't reach p1 then try the next node after p1 */
      p1 = p1->next;
   }
 
   /* After the end of loop p2 is the last node of the loop. So
     make next of p2 as NULL */
   p2->next = NULL;
}

void detectAndRemoveLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
 
    // Search for loop using slow and fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
 
    /* If loop exists */
    if (slow == fast)
    {
        slow = head;
        while (slow != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
}

/*******************************************************************/
/* [1.20] Single Linked List : Merge two sorted Linked List        */
/* Given 2 Linked Lists sorted in Ascending Orider, 
   merge lists into a single sorted list withou Copying the list 
   contents.
   Linked list p1 is : 1 3 5 9
   Linked list p2 is : 2 4 5 6 10
   Merged Linked list p3 is : 1 2 3 4 5 5 6 9 10
/*******************************************************************/
ListNode* mergeTwoSortedLists(ListNode* p1, ListNode* p2)
{
    if(p1 == NULL)
        return p2;
    else if(p2 == NULL)
        return p1;

    ListNode* p3 = NULL;
    if(p1->data < p2->data)
    {
        p3 = p1;
        p3->next = mergeTwoSortedLists(p1->next, p2);
    }
    else
    {
        p3 = p2;
        p3->next = mergeTwoSortedLists(p1, p2->next);
    }
    return p3;
}

/*******************************************************************/
/* [1.21] Single Linked List : Merge two Linked List w/o Sort      */
/* output of code:
    23 3 78 51 90
    15 30 88
    ===> 23 3 78 51 90 15 30 88                                    */
/*******************************************************************/
void blindMerge(struct node **p1,struct node **p2,struct node **p3)
{
    struct node *temp;
    if(*p2==NULL && p1!=NULL)   // if second list dosent exist
    {
        *p3=*p1;
        return;
    } 
    else if(*p1==NULL && p2!=NULL)    // if first list dosent exist
    {
        *p3=*p2;
        return ;
    }

    *p3=*p1;
    temp=*p1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=*p2;
    *p3 = temp;
}

/*******************************************************************/
/* [1.22] Single Linked List : Merge a list into another at 
          alternate position    */
/* output of code:
    L1 = 3->4->6->7->NULL
    L2 = 1->8->10->NULL
    Result = 3->1->4->8->6->10->7->NULL                                     */
/*******************************************************************/
Node * mergeAtAlternatePositions(Node *a, Node *b)
{
    Node *aCurr = a;
    Node *bCurr = b;
 
    while (aCurr && bCurr) {
        Node *aNext = aCurr->next;
        Node *bNext = bCurr->next;
 
        //Point next pointer of list a to node in list b
        bCurr->next = aCurr->next;
        //Point next pointer of list b to node in list a
        aCurr->next = bCurr;
 
        //Now advance pointers to next nodes
        aCurr = aNext;
        bCurr = bNext;
    }
    return a;
}

/*******************************************************************/
/* [1.23] Single Linked List : Merge two Linked List w/o Sort      */
/* output of code:
    1 3 5 7
    2 4 6 
    ===> 1 2 3 4 5 6 7                                             */
/*******************************************************************/
void merge()
{
    //Function to merge the two input linked list
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    //Use a new pointer variable temp1 and temp2

    struct node *holder1 = NULL;
    struct node *holder2 = NULL;

    while(temp1!=NULL && temp2!=NULL) 
    {
        //Executes until both temp1 and temp2 are not NULL
        holder1=temp1->next;
        //Storing the address of next node of first linked list
        temp1->next=temp2;
        //Making the first node of first linked list point to first node of second linked list

        if(holder1!=NULL)     
        {
            //Making the first node of second linked list point to second node of first linked list
            holder2=temp2->next;
            temp2->next=holder1;
        }             
        temp1=holder1;
        temp2=holder2;  
        //Updating the address location of two pointer variables temp1 and temp2
    }
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
/* [2.02] Double Linked List: insert a node at the beginging           */
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
/* [2.03] Double Linked List: insert a node at the Head                */
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
/* [2.04] Double Linked List: insert a node at the Tail                */
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
/* [2.05] Double Linked List: reverse a Doubly Linked List             */
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
/* [2.06] Double Linked List: Free the List                            */
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
/* [2.07] Double Linked List: Swap 2 variables in a doubly linked list */                          
/***********************************************************************/
void node_swap(struct s_node *left, struct s_node *right)
{
    struct s_node *tmp;

    tmp = left->prev;
    if (tmp)
        tmp->next = right;
    right->prev = tmp;

    left->prev = right;
    left->next = right->next;
    right->next = left;
    if(left->next != null)
        left->next(which is X)->prev = left
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