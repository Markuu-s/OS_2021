#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

void init_node(struct node **current, int data, struct node *next)
{
    (*current) = malloc(sizeof(struct node));
    (*current)->data = data;
    (*current)->next = next;
}

struct linked_list
{
    int size;
    struct node *head;
};

void init_linkedList(struct linked_list **l)
{
    *l = malloc(sizeof(struct linked_list));
    (*l)->size = 0;
    (*l)->head = NULL;
}

void print_list(struct linked_list *l)
{
    struct node *current = l->head;
    for (int i = 0; i < l->size; ++i)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void insert_node_afterIndex(struct linked_list *l, int idx, struct node *new_node)
{
    if (idx >= l->size)
    {
        printf("Idx bigger than size of list\n");
        return;
    }

    if (l->head == NULL)
    {
        l->head = new_node;
        l->size++;
        return;
    }

    struct node *current = l->head;
    for (int i = 0; i < idx; ++i)
    {
        current = current->next;
    }
    struct node *next_elem = (idx == l->size) ? NULL : (current->next);
    new_node->next = next_elem;
    current->next = new_node;

    l->size++;
}

void insert_node_afterNode(struct linked_list *l, int idx, struct node *new_node)
{
    if (idx >= l->size)
    {
        printf("Idx bigger than size of list\n");
        return;
    }

    if (l->head == NULL)
    {
        l->head = new_node;
        l->size++;
        return;
    }

    struct node *current = l->head;
    for (int i = 0; i < idx; ++i)
    {
        current = current->next;
    }
    struct node *next_elem = (idx == l->size) ? NULL : (current->next);
    new_node->next = next_elem;
    current->next = new_node;

    l->size++;
}

/**
 *
 * @param l is linked_list
 * @param current delete node after this node
 */
void delete_node_node(struct linked_list *l, struct node *current)
{
    struct node *next_elem = (current->next == NULL) ? NULL : (current->next->next);
    free(current->next);
    current->next = next_elem;

    l->size--;
}

/**
 *
 * @param l is linked_list
 * @param idx is node, which will be deleted
 */
void delete_node_idx(struct linked_list *l, int idx)
{
    struct node *current = l->head;
    for (int i = 0; i < idx; ++i)
    {
        current = current->next;
    }
    delete_node_node(l, current);
}

int main()
{
    struct linked_list *list = NULL;
    init_linkedList(&list);

    for (int i = 0; i < 10; ++i)
    {
        struct node *temp = NULL;
        init_node(&temp, i, NULL);
        insert_node_afterIndex(list, i - 1, temp);
    }
    printf("Insert 0..10 integer to end of linked_list: ");
    print_list(list);
    printf("\n");

    struct node *temp = NULL;
    init_node(&temp, 133, NULL);
    insert_node_afterIndex(list, 0, temp);

    printf("Insert node with data of 133 after 0 INDEX ( O(n) time for insert after index ): ");
    print_list(list);
    printf("\n");

    struct node *temp1 = NULL;
    init_node(&temp1, 876, NULL);
    insert_node_afterIndex(list, 1, temp1);

    printf("Insert node with data of 876 after 1 NODE ( O(1) time for insert after node): ");
    print_list(list);
    printf("\n");

    delete_node_idx(list, 1);

    printf("Delete first element with INDEX first (O(n) time for delete index): ");
    print_list(list);
    printf("\n");

    delete_node_node(list, temp);
    printf("Delete element after NODE (O(1) time for delete after node): ");
    print_list(list);
    printf("\n");
    return 0;
}
