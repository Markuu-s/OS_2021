#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void init_node(struct node **current)
{
    (*current) = malloc(sizeof(current));
    (*current)->next = NULL;
    (*current)->prev = NULL;
}

struct double_linked_list
{
    int size;
    struct node *head;
    struct node *tail;
};

void init_list(struct double_linked_list **l)
{
    (*l) = malloc(sizeof(struct double_linked_list));
    (*l)->size = 0;
    init_node(&(*l)->head);
    init_node(&(*l)->tail);

    (*l)->head->next = (*l)->tail;
    (*l)->tail->prev = (*l)->head;
}

void delete_node(struct double_linked_list *list, struct node *current)
{
    struct node *next = current->next;
    struct node *prev = current->prev;

    if (next != NULL)
    {
        next->prev = prev;
    }
    if (prev != NULL)
    {
        prev->next = next;
    }
    free(current);

    list->size--;
}

void insert_node_afterNode(struct double_linked_list *list, struct node *afterNode, struct node *newNode)
{
    if (afterNode == list->tail)
    {
        printf("\nError. Not allow to insert after tail\n");
        return;
    }

    newNode->next = afterNode->next;
    newNode->prev = afterNode;
    afterNode->next = newNode;

    struct node *t = afterNode->next;
    if (t != NULL)
    {
        t = t->next;
        if (t != NULL)
        {
            t->prev = newNode;
        }
    }

    list->size++;
}

void insert_node_beforeNode(struct double_linked_list *list, struct node *beforeNode, struct node *newNode)
{
    if (beforeNode == list->head)
    {
        printf("\nError. Not allow to insert before head");
        return;
    }

    newNode->prev = beforeNode->prev;
    newNode->next = beforeNode;
    beforeNode->prev = newNode;

    struct node *t = beforeNode->prev;
    if (t != NULL)
    {
        t = t->prev;
        if (t != NULL)
        {
            t->next = newNode;
        }
    }

    list->size++;
}

void print_list(struct double_linked_list *l)
{
    struct node *current = l->head;
    current = current->next;
    for (int i = 0; i < l->size; ++i)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n = 10;
    struct double_linked_list *list;
    init_list(&list);

    for (int i = n - 1; i >= 0; --i)
    {
        struct node *cur = NULL;
        init_node(&cur);
        cur->data = i;
        insert_node_afterNode(list, list->head, cur);
    }

    printf("Fill the double linked list with elem 0..9: \n");
    print_list(list);

    struct node *elem_122 = NULL;
    init_node(&elem_122);
    elem_122->data = 122;
    insert_node_afterNode(list, list->head, elem_122);
    printf("Insert the element with data 122 in head: \n");
    print_list(list);

    struct node *elem_345 = NULL;
    init_node(&elem_345);
    elem_345->data = 345;
    insert_node_afterNode(list, elem_122, elem_345);
    printf("Insert after node with data 122 node with data 345: \n");
    print_list(list);

    struct node *elem_546 = NULL;
    init_node(&elem_546);
    elem_546->data = 546;
    insert_node_beforeNode(list, elem_345, elem_546);
    printf("Insert before node with data 345 node with data 546: \n");
    print_list(list);
    return 0;
}
