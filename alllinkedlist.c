//Author sahilkhan-19
//linkedin - https://www.linkedin.com/in/sahilkhan-19s?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BJd6ryoKwTKiYQNuVqSZHNg%3D%3D

#include <stdio.h>
#include <stdlib.h>

struct stu *new(int a);
void addnode_FIFO(struct stu *p);
void addnode_LIFO(struct stu *p);
void traverse(int FL);

void addnode_before(int element, int prev);
void addnode_after(int element, int after);
void delete_first(void);
void delete_last(void);
void delete_anynode(int element);
void delete_node_after(int element);
void delete_node_before(int element);

struct stu{
    int info;
    struct stu *next;
}*head=NULL;

void main(void){
    int a,ch,FL;
    char choice='Y';
    printf("*****Linked List*****\n");
    printf("Choose a option:-\n");
    printf("1. Linked List FIFO(Queue)\n");
    printf("2. Linked List LIFO(Stack)\n");
    printf("0. End\n\n");
    scanf("%d",&ch);
    if(ch==1){
        while(choice!='N' && choice!='n'){
        printf("\nEnter Element: ");
        scanf("%d",&a);
        FL=1;

        struct stu *p = new(a);
        addnode_FIFO(p);

        printf("Want to add more ?? (Y/N)\n");
        scanf(" %c",&choice);

        }
        printf("\nLinked List: ");
        traverse(FL);

        int operation_choice,element,prev,after;
        printf("\n**Want to perform any operation ??**\n");
        printf("1. Add Node Before\n");
        printf("2. Add Node After\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete Any Node\n");
        printf("6. Delete Node After\n");
        printf("7. Delete Node Before\n");
        printf("0. End\n");
        scanf("%d", &operation_choice);

        switch (operation_choice)
        {
        case 1:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &element);
            printf("\nEnter Previous element: ");
            scanf("%d", &prev);

            addnode_before(element,prev);

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        
        case 2:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &element);
            printf("\nEnter After element: ");
            scanf("%d", &after);

            addnode_after(element,after);

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        
        case 3:
            delete_first();

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        case 4:
            delete_last();

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        case 5:
            printf("\nEnter Element to be deleted: ");
            scanf("%d",&element);
            delete_anynode(element);

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        case 6:
            printf("\nEnter Element: ");
            scanf("%d",&element);
            delete_node_after(element);

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        case 7:
            printf("\nEnter Element: ");
            scanf("%d",&element);
            delete_node_before(element);

            printf("\nUpdated Linked List: ");
            traverse(FL);
            break;
        
        default:
            break;
        }
        printf("\n\t*****Thanks*****");
    }
    else if(ch==2){
        while(choice!='N' && choice!='n'){
        printf("\nEnter Element: ");
        scanf("%d",&a);
        FL=2;

        struct stu *p = new(a);
        addnode_LIFO(p);

        printf("Want to add more ?? (Y/N)\n");
        scanf(" %c",&choice);

        }
        printf("\nLinked List: \n");
        traverse(FL);

        int operation_choice,element,prev,after;
        printf("\n**Want to perform any operation ??**\n");
        printf("1. Add Node Before\n");
        printf("2. Add Node After\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete Any Node\n");
        printf("6. Delete Node After\n");
        printf("7. Delete Node Before\n");
        printf("0. End\n");
        scanf("%d", &operation_choice);

        switch (operation_choice)
        {
        case 1:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &element);
            printf("\nEnter Previous element: ");
            scanf("%d", &prev);

            addnode_before(element,prev);

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        
        case 2:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &element);
            printf("\nEnter After element: ");
            scanf("%d", &after);

            addnode_after(element,after);

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        
        case 3:
            delete_first();

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        case 4:
            delete_last();

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        case 5:
            printf("\nEnter Element to be deleted: ");
            scanf("%d",&element);
            delete_anynode(element);

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        case 6:
            printf("\nEnter Element: ");
            scanf("%d",&element);
            delete_node_after(element);

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        case 7:
            printf("\nEnter Element: ");
            scanf("%d",&element);
            delete_node_before(element);

            printf("\nUpdated Linked List: \n");
            traverse(FL);
            break;
        
        default:
            break;
        }
        printf("\n\t*****Thanks*****");
    }
    else{
        printf("End..");
        exit(1);
    }
}
//MAIN END

struct stu *new(int a){
    struct stu *p = (struct stu *)malloc(sizeof(struct stu));
    if(p==NULL){
        printf("\nMemory Allocation Failed!!");
        exit(1);
    }
    p->info=a;
    p->next=NULL;
    return p;
}

void addnode_FIFO(struct stu *p){
    struct stu *temp=head;
    if(head==NULL){
        head=p;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
}

void addnode_LIFO(struct stu *p){
    p->next=head;
    head=p;
}

void traverse(int FL){
    struct stu *temp = head;
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    if(FL==1){
        while(temp!=NULL){
            printf("%d ",temp->info);
            temp=temp->next;
        }
    }
    else if(FL==2){
        while(temp!=NULL){
            printf("%d\n",temp->info);
            temp=temp->next;
        }
    }
}

void addnode_before(int element, int prev){
    struct stu *new_node=new(element);
    if(head==NULL){
        printf("\nList is Empty, No insertion is made!");
        return;
    }
    if(head->info==prev){
            new_node->next=head;
            head=new_node;
        }
        struct stu *temp = head;
        while(temp->next!=NULL && temp->next->info!=prev){
            temp=temp->next;
        }
        if(temp->next!=NULL && temp->next->info!=prev){
            printf("\nNode Not Found!!");
            free(new_node);
            return;
        }
        new_node->next=temp->next;
        temp->next=new_node;
}

void addnode_after(int element, int after){
    struct stu *new_node=new(element);
    if(head==NULL){
        printf("\nList is Empty, No insertion is made!");
        return;
    }
    struct stu *temp = head;
    while(temp!=NULL && temp->info!=after){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Node Not Found!!");
        return;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void delete_first(){
    if(head==NULL){
        printf("\nList is Empty, No deletion is made!");
        return;
    }
    struct stu *temp = head;
    head=head->next;
    printf("Deleting node with value %d ",temp->info);
    free(temp);
    temp=NULL;
}

void delete_last(){
    if(head==NULL){
        printf("\nList is Empty, No deletion is made!");
        return;
    }
    if(head->next==NULL){
        printf("Deleting the only node with value %d ",head->info);
        free(head);
        head=NULL;
        return;
    }
    struct stu *temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    printf("Deleting the Last Node with value %d\n",temp->next->info);
    free(temp->next);
    temp->next=NULL;
}

void delete_anynode(int element){
    if(head==NULL){
        printf("\nList is Empty, No deletion is made!");
        return;
    }
    if(head->info==element){
        struct stu *temp = head;
        head=head->next;
        printf("Deleting the node with value %d ",temp->info);
        free(temp);
        return;
    }
    struct stu *temp=head;
    struct stu *prev=NULL;
    while(temp!=NULL && temp->info!=element){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nNode Not Found");
        return;
    }
    prev->next=temp->next;
    printf("deleting the node with value %d ", temp->info);
    free(temp);
}

void delete_node_after(int element){
    if(head==NULL){
        printf("\nList is Empty,No deletion is made!");
        return;
    }
    if(head->next==NULL){
        printf("Only one node Exits, can't perform the operation!");
        return;
    }
    struct stu *temp=head;
    while(temp!=NULL && temp->info!=element){
        temp=temp->next;
    }
    if(temp==NULL||temp->next==NULL){
        printf("Element not found! ");
        return;
    }
    struct stu *node_to_delete=temp->next;
    temp->next=node_to_delete->next;
    printf("Deleted! ");
    free(node_to_delete);
}

void delete_node_before(int element){
    if(head==NULL || head->next == NULL){
        printf("\nList is Empty,No deletion is made!");
        return;
    }
    if(head->next->info == element) {
        struct stu *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted the first node before the element!");
        return;
    }
    struct stu *prev=NULL;
    struct stu *current=head;
    while(current->next!=NULL && current->next->info != element){
        prev=current;
        current=current->next;
    }
    if(current==NULL){
        printf("Element Not Found!!");
        return;
    }
    struct stu *to_delete = current;
    prev->next = current->next;
    free(to_delete);
    printf("Deleted the node before the element!");
}