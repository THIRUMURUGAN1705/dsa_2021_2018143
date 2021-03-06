#include <stdio.h>
#include <stdlib.h>

typedef struct node *ptr;
struct Node {
  int number;
  struct Node* next;
};

void insertAtBeginning(ptr* head, int new_number) {

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->number = new_number;

  new_node->next = (*head);

  *head = new_node;
}

void insertMiddle(struct Node* prev_node, int new_number) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->number = new_number;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void insertAtEnd(ptr* head, int new_number) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = head;

  new_node->number = new_number;
  new_node->next = NULL;

  if (*head == NULL) {
  *head = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}


void deleteNode(ptr* head, int key) {
  struct Node *temp = *head, *prev;

  if (temp != NULL && temp->number == key) {
  *head = temp->next;
  free(temp);
  return;
  }
  while (temp != NULL && temp->number != key) {
  prev = temp;
  temp = temp->next;
  }


  if (temp == NULL) return;


  prev->next = temp->next;

  free(temp);
}

int searchNode(ptr* head, int key) {
  struct Node* current = *head;
  int pos=0;

  while (current != NULL) {
        pos++;
  if (current->number == key) return pos;
  current = current->next;
  }
  return 0;
}


void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->number);
  node = node->next;
  }
}


int main() {
    int ch,x,a,z,i,pre;
  struct Node* head = NULL;
  struct Node* curr =NULL;
   printf("Linked list\n");
    insertAtBeginning(&head, 5);
   insertAtBeginning(&head, 4);
   insertAtBeginning(&head, 3);
   insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);
   printList(head);
   do{
    printf("\n1.Insertion\n2.deletion\n3.Search\n4.Printlist\n5.Exit\n\n");
   printf("\nEnter the choice:");
   scanf("%d",&ch);
  switch(ch)
  {
      case 1:
            printf("1.Beginning\n2.End\n3.Middle");
            printf("\nEnter choice:");
            scanf("%d",&x);
            switch(x)
                {
                    case 1:
                        {

                        printf("Enter the element");
                        scanf("%d",&a);
                        insertAtBeginning(&head, a);
                        printf("Linked list: ");
                        printList(head);
                        break;
                        }
                    case 2:
                        {
                            printf("Enter the element");
                            scanf("%d",&a);
                            insertAtEnd(&head, a);
                            printf("Linked list: ");
                            printList(head);
                            break;
                        }
                    case 3:
                        {
                            printf("Enter position after which the given element should be inserted by seeing the List: ");
                            printList(head);
                            scanf("%d",&pre);
                            printf("Enter the element");
                            scanf("%d",&a);
                            curr=head;
                            for(i=2;i<pre;i++)
                                curr=curr->next;
                            insertMiddle(curr, a);
                            printf("Linked list: ");
                            printList(head);
                            break;
                        }
                    default:
                        printf("Invalid input");


                }break;

    case 2:
            printf("1.Beginning\n2.End\n3.Middle");
            printf("\nEnter choice:");
            scanf("%d",&x);
            switch(x)
                {
                    case 1:
                        {
                        deleteNode(&head, head->number);
                        printf("\nAfter deleting an element: ");
                        printList(head);
                        break;
                        }
                    case 2:
                        {
                            curr=head;

                            while(curr->next!=NULL)
                                curr=curr->next;

                            deleteNode(&head,curr->number);
                            printf("\nAfter deleting an element: ");
                            printList(head);
                            break;
                        }
                    case 3:
                        {
                            printf("Enter which element should be deleted by seeing the List: ");
                            printList(head);
                            scanf("%d",&pre);
                            deleteNode(&head, pre);
                            printf("\nAfter deleting an element: ");
                            printList(head);
                            break;
                        }

                }break;

    case 3:
        {
            printf("1.Search by value\n2.Search by position: ");
            scanf("%d",&z);
            if(z==1)
            {
                printf("\nEnter the element:");
                scanf("%d",&a);
                int item_to_find = a;
                a=searchNode(&head, item_to_find);
                if(a!=0)
                {
                    printf("\n%d is found at position %d", item_to_find,a);
                }
                else
                {
                    printf("\n%d is not found", item_to_find);
                }
            }
            else if(z==2)
            {
                printf("Enter position: ");
                scanf("%d",&a);
                struct Node *newnode;
                newnode=(struct Node*)malloc(sizeof(struct Node));
                newnode=head;
                for(i=1;i<a;i++)
                {
                    newnode=newnode->next;
                }
                printf("Element in %d position is %d",a,newnode->number);
            }

        }

  }
}while(ch!=5);





}
