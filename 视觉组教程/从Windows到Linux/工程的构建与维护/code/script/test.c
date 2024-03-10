#include <stdio.h>
#include <stdlib.h>

// void GotoXY(int x, int y) {
//     printf("\033[%d;%dH", y, x);
//     return;
// }

#define MALLOC_N(ptr, n) (typeof(ptr))malloc(n * sizeof(*ptr))

struct ListNodeInt {
    struct ListNodeInt* next;
    int data;
};

struct ListNodeInt* CreateListNode(int data) {
    struct ListNodeInt* node = MALLOC_N(node, 1);
    node->data = data;
    node->next = NULL;
    return node;
}

int ListPushFrontNewNode(struct ListNodeInt** head, int data) {
    if (!*head) return -1;
    struct ListNodeInt* new_head = CreateListNode(data);
    new_head->next = *head;
    *head = new_head;
    return 0;
}

int ListPushFrontNode(struct ListNodeInt** head, struct ListNodeInt* new_head) {
    if (!*head) return -1;
    new_head->next = *head;
    *head = new_head;
    return 0;
}

int ListPushNextNewNode(struct ListNodeInt* node, int data) {
    if (!node) return -1;
    struct ListNodeInt* next_node = CreateListNode(data);
    node->next = next_node;
    return 0;
}

int ListPushNextNode(struct ListNodeInt* node, struct ListNodeInt* next_node) {
    if (!node) return -1;
    node->next = next_node;
    return 0;
}

int ListRemoveNode(struct ListNodeInt** head) {
    if (!*head) return -1;
    struct ListNodeInt* new_head = (*head)->next;
    free(*head);
    *head = new_head;
    return 0;
}

int ListRemoveNextNode(struct ListNodeInt* head) {
    if (!head) return -1;
    struct ListNodeInt* new_next = head->next->next;
    free(head->next);
    head->next = new_next;
    return 0;
}

void ListForEach(struct ListNodeInt* head,
                 void (*func)(struct ListNodeInt* head)) {
    struct ListNodeInt* ptr = head;
    while (ptr) {
        func(ptr);
        ptr = ptr->next;
    }
    return;
}

void FreeList(struct ListNodeInt** head_ptr) {
    struct ListNodeInt* ptr = *head_ptr;
    while (ptr) {
        struct ListNodeInt* next_node = ptr->next;
        free(ptr);
        ptr = next_node;
    }
    *head_ptr = NULL;
    return;
}

void PrintListNodeInfo(struct ListNodeInt* node) {
    if (node) printf("[%p|%d]->", node, node->data);
    if (!node->next) printf("%p", node->next);
    return;
}

void Display(struct ListNodeInt* head, const char* promt) {
    system("clear");
    puts(promt);
    ListForEach(head, PrintListNodeInfo);
    getchar();
}

int main() {
    struct ListNodeInt* head = NULL;
    struct ListNodeInt* last_head = CreateListNode(10);
    struct ListNodeInt* last_next = CreateListNode(11);

    head = CreateListNode(1);
    Display(head, "Create list head node");

    ListPushNextNewNode(head, 2);
    Display(head, "Push next new node");
    ListPushNextNewNode(head->next, 3);
    Display(head, "Push next new node");

    ListPushFrontNewNode(&head, 4);
    Display(head, "Push front new node");
    ListPushFrontNewNode(&head, 5);
    Display(head, "Push front new node");

    ListRemoveNextNode(head);
    Display(head, "Remove head next node");

    ListRemoveNode(&head);
    Display(head, "Remove head node");

    last_next->next = head->next;
    ListPushNextNode(head, last_next);
    //  ListPushNextNode(last_next, head); /* this is loop */
    Display(head, "Push next node");

    ListPushFrontNode(&head, last_head);
    Display(head, "Push front node");

    FreeList(&head);
    Display(head, "Free list");

    return 0;
}
