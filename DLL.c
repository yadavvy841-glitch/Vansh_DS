#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * prev;
    struct node* next;
} node;
node *init(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    temp->prev=NULL;
    return temp;
}
void display(node *head)
{
    node *c = head;
    while (c)
    {
        printf("  %d  ", c->data);
        c = c->next;
    }
    printf("\n");
}
node *ins_b(node *head, int x)
{
    node *temp = init(x);
    if (head == NULL)
    {
        return temp;
    }
    temp->next = head;
    head->prev=temp;
    return temp;
}
node *ins_l(node *head, int x)
{
    node *temp = init(x);
    if (head == NULL)
    {
        return temp;
    }
    node *c = head;
    while (c->next)
    {
        c = c->next;
    }
    c->next = temp;
    temp->prev=c;
    return head;
}

node *ins_p(node *head, int x, int pos)
    {
        node *temp = init(x);
    
        if (pos == 1)
        {
            temp->next = head;
            if (head)
                head->prev = temp;
            return temp;
        }
    
        node *c = head;
        for (int i = 1; i < pos - 1 && c; i++)
            c = c->next;
    
        if (c == NULL)
            return head;
    
        temp->next = c->next;
        temp->prev = c;
    
        if (c->next)
            c->next->prev = temp;
    
        c->next = temp;
    
        return head;
    }

node *del_b(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *temp = head;
    head = head->next;
    if(head)
    head->prev=NULL;
    free(temp);
    return head;
}
node *del_l(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node *c = head;
    while (c->next)
    {
        c = c->next;
    }
    node *temp = c->next;
    c->prev->next=NULL;
    free(c);
    return head;
}
node * del_p(node *head, int pos)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (pos==1)
    {
    node*temp=head;
    head=head->next;
    if(head)
    head->prev=NULL;
    free(temp);
    return head;
    }
    node *c = head;
    for(int i=1;i<pos&&c;i++)
    {
        c=c->next;
    }
    if(c==NULL)
    {
        return head;
    }

    if (c->next)
    {
        c->next->prev = c->prev;
    }
    if (c->prev)
    {
        c->prev->next = c->next;
    }
    free(c);

    return head;
}
int main()
{
    node *head = init(10);
    node *second = init(20);
    node *third = init(30);
    node *forth = init(40);
    node *fifth = init(50);
    head->next = second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    third->next=forth;
    forth->prev=third;
    forth->next=fifth;
    fifth->prev=forth;
    
    display(head);
    head = ins_b(head, 0);
    display(head);
    head = ins_l(head, 60);
    display(head);
    head = ins_p(head, 25, 4);
    display(head);
    head = del_b(head);
    display(head);
    head = del_l(head);
    display(head);
    head = del_p(head, 4);
    display(head);
}