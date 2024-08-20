#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *insert_at_beg(struct node *head, int data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    printf("Node inserted\n");
    return head;
}

struct node *insert_at_end(struct node *head, int data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = ptr;
    printf("Node inserted\n");
    return head;
}

struct node *insert_at_pos(struct node *head, int data, int pos) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    if (pos == 1) {
        ptr->link = head;
        head = ptr;
        printf("Node inserted\n");
        return head;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(ptr);
            return head;
        }
        temp = temp->link;
    }

    ptr->link = temp->link;
    temp->link = ptr;
    printf("Node inserted\n");
    return head;
}

struct node *delete_at_beg(struct node *head) {
    if (head == NULL) {
        printf("List empty\n");
        return NULL;
    }
    struct node *temp = head;
    head = temp->link;
    free(temp);
    printf("Node deleted\n");
    return head;
}

struct node *delete_at_end(struct node *head) {
    if (head == NULL) {
        printf("List empty\n");
        return NULL;
    }

    if (head->link == NULL) {
        free(head);
        printf("Node deleted\n");
        return NULL;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
    printf("Node deleted\n");
    return head;
}

struct node *delete_at_pos(struct node *head, int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return NULL;
    }

    if (pos == 1) {
        struct node *temp = head;
        head = temp->link;
        free(temp);
        printf("Node deleted\n");
        return head;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return head;
        }
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return head;
    }

    prev->link = temp->link;
    free(temp);
    printf("Node deleted\n");
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements are:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int n, r;
    struct node *head = NULL;
    while (1) {
        printf("\nChoose from the following:\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at a certain position\n4. Delete at beginning\n5. Delete at end\n6. Delete at a certain position\n7. Display\n8. End\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &r);
                head = insert_at_beg(head, r);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &r);
                head = insert_at_end(head, r);
                break;
            case 3:
                {
                    int pos;
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    printf("Enter a value: ");
                    scanf("%d", &r);
                    head = insert_at_pos(head, r, pos);
                }
                break;
            case 4:
                head = delete_at_beg(head);
                break;
            case 5:
                head = delete_at_end(head);
                break;
            case 6:
                {
                    int pos;
                    printf("Enter the position: ");
                    scanf("%d", &pos);
                    head = delete_at_pos(head, pos);
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
