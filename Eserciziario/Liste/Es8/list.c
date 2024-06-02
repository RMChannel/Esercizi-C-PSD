#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"

struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};

List newList() {
    List list = malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    return list;
}

int isEmpty(List list) {
    return list->size == 0;
}

void addHead(List list, Item item) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Item removeHead(List list) {
    if (isEmpty(list)) return NULL;
    struct node *temp = list->head;
    list->head = temp->next;
    Item item = temp->value;
    free(temp);
    list->size--;
    return item;
}

Item getHead(List list) {
    if (isEmpty(list)) return NULL;
    return list->head->value;
}

int sizeList(List list) {
    return list->size;
}

void printList(List list) {
    struct node *p;
    for (p = list->head; p != NULL; p = p->next)
        outputItem(p->value);
}

Item searchListItem(List list, Item item, int *pos) {
    struct node *p;
    *pos = 0;
    for (p = list->head; p != NULL; p = p->next) {
        if (cmpItem(item, p->value) == 0) {
            return p->value;
        }
        (*pos)++;
    }
    *pos = -1;
    return NULL;
}

Item removeListItem(List list, Item item) {
    Item temp;
    if (isEmpty(list))
        return NULL;
    struct node *p, *prev = NULL;
    for (p = list->head; p != NULL; prev = p, p = p->next) {
        if (cmpItem(item, p->value) == 0) {
            if (p == list->head)
                return removeHead(list);
            prev->next = p->next;
            temp = p->value;
            free(p);
            list->size--;
            return temp;
        }
    }
    return NULL;
}

Item removeListPos(List list, int pos) {
    Item temp;
    int cont = 0;
    if (isEmpty(list) || pos < 0 || pos >= sizeList(list))
        return NULL;
    struct node *p, *prev = NULL;
    for (p = list->head; p != NULL; prev = p, p = p->next) {
        if (pos == cont) {
            if (p == list->head)
                return removeHead(list);
            prev->next = p->next;
            temp = p->value;
            free(p);
            list->size--;
            return temp;
        }
        cont++;
    }
    return NULL;
}

int addListPos(List list, Item item, int pos) {
    if (pos < 0 || pos > sizeList(list)) {
        return 0;
    }

    if (pos == 0) {
        addHead(list, item);
        return 1;
    }

    struct node *p, *newNode;
    int i = 0;
    for (p = list->head; p != NULL && i < pos - 1; p = p->next, i++);
    newNode = malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = p->next;
    p->next = newNode;
    list->size++;
    return 1;
}

int addListTail(List list, Item item) {
    return addListPos(list, item, sizeList(list));
}

void reverseList(List list) {
    struct node *p, *prev = NULL, *temp;
    for (p = list->head; p != NULL; prev = p, p = temp) {
        temp = p->next;
        p->next = prev;
    }
    list->head = prev;
}

List cloneList(List list) {
    List clone = newList();
    struct node *p;
    for (p = list->head; p != NULL; p = p->next) {
        addListTail(clone, p->value);
    }
    return clone;
}

void swap(struct node *i1, struct node *i2) {
    Item temp = i1->value;
    i1->value = i2->value;
    i2->value = temp;
}

void selectionSort(List list) {
    struct node *i = list->head;
    for (; (i->next) != NULL; i = i->next) {
        struct node *min = i;
        for (struct node *n = i; n != NULL; n = n->next) {
            if (cmpItem(min->value, n->value) > 0) min = n;
        }
        swap(min, i);
    }
}

void bubbleSort(List list) {
    for (struct node *i = list->head->next; i != NULL; i = i->next) {
        for (struct node *j = list->head; (j->next) != NULL; j = j->next) {
            if (cmpItem(j->value, j->next->value) > 0) swap(j, j->next);
        }
    }
}

void recursiveSort(struct node *i) {
    if (i->next != NULL) {
        struct node *min = i;
        for (struct node *n = i; n != NULL; n = n->next) {
            if (cmpItem(min->value, n->value) > 0) min = n;
        }
        swap(min, i);
        recursiveSort(i->next);
    }
}

void selectionRSort(List list) {
    recursiveSort(list->head);
}

struct node* merge(struct node* l1, struct node* l2) {
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (cmpItem(l1->value, l2->value) <= 0) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;

    return dummy.next;
}

void split(struct node* source, struct node** frontRef, struct node** backRef) {
    struct node* fast;
    struct node* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

struct node* mergeSort(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct node* a;
    struct node* b;
    split(head, &a, &b);
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a, b);
}

void sortList(List list) {
    list->head = mergeSort(list->head);
}

