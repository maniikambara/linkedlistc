#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

int isEmpty(node* head) {
    return head == NULL;
}

void pushDepan(node** head, int data) {
    node* nodebaru = (node*)malloc(sizeof(node));
    nodebaru->data = data;
    nodebaru->next = *head;
    *head = nodebaru;
}

void pushBelakang(node** head, int data) {
    node* nodebaru = (node*)malloc(sizeof(node));
    nodebaru->data = data;
    nodebaru->next = NULL;

    if (*head == NULL) {
        *head = nodebaru;
        return;
    }

    node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = nodebaru;
}

void pushTengah(node** head, int data, int posisi) {
    node* nodebaru = (node*)malloc(sizeof(node));
    nodebaru->data = data;

    if (*head == NULL || posisi == 0) {
        nodebaru->next = *head;
        *head = nodebaru;
        return;
    }

    node* curr = *head;
    int i = 0;
    while (i < posisi - 1 && curr->next != NULL) {
        curr = curr->next;
        i++;
    }

    nodebaru->next = curr->next;
    curr->next = nodebaru;
}

void popDepan(node** head) {
    if (*head == NULL) {
        printf("Maaf, linked list kosong.\n");
        return;
    }

    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void popBelakang(node** head) {
    if (*head == NULL) {
        printf("Maaf, linked list kosong.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    node* curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void popTengah(node** head, int posisi) {
    if (*head == NULL) {
        printf("Maaf, linked list kosong.\n");
        return;
    }

    if (posisi == 0) {
        popDepan(head);
        return;
    }

    node* curr = *head;
    int i = 0;
    while (i < posisi - 1 && curr->next != NULL) {
        curr = curr->next;
        i++;
    }

    if (curr->next == NULL) {
        printf("Posisi tidak valid.\n");
        return;
    }

    node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

void cetakList(node* head) {
    if (isEmpty(head)) {
        printf("Linked list kosong.\n");
        return;
    }

    printf("Isi linked list: ");
    node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int pilihan, data, posisi;

    while (1) {
        system("cls");
        printf("+-----------------------------------------+\n\n");
        printf("\t     TUGAS LINKED LIST\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\t1. Tambah Elemen dari Depan\n");
        printf("\t2. Tambah Elemen dari Belakang\n");
        printf("\t3. Tambah Elemen dari Tengah\n");
        printf("\t4. Hapus Elemen dari Depan\n");
        printf("\t5. Hapus Elemen dari Belakang\n");
        printf("\t6. Hapus Elemen dari Tengah\n");
        printf("\t7. Cek Apakah Linked List Kosong\n");
        printf("\t8. Tampilkan Linked List\n");
        printf("\t9. Keluar\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\tPILIHAN (1-6) : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                system("cls");
                printf("Masukkan data: ");
                scanf("%d", &data);
                pushDepan(&head, data);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Masukkan data: ");
                scanf("%d", &data);
                pushBelakang(&head, data);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Masukkan data: ");
                scanf("%d", &data);
                printf("Masukkan posisi: ");
                scanf("%d", &posisi);
                pushTengah(&head, data, posisi);
                system("pause");
                break;
            case 4:
                system("cls");
                popDepan(&head);
                system("pause");
                break;
            case 5:
                system("cls");
                popBelakang(&head);
                system("pause");
                break;
            case 6:
                system("cls");
                printf("Masukkan posisi: ");
                scanf("%d", &posisi);
                popTengah(&head, posisi);
                system("pause");
                break;
            case 7:
                system("cls");
                if (isEmpty(head)) {
                    printf("Linked list kosong.\n");
                } else {
                    printf("Linked list tidak kosong.\n");
                }
                system("pause");
                break;
            case 8:
                system("cls");
                cetakList(head);
                system("pause");
                break;
            case 9:
                printf("Terimakasih!.\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
                system("pause");
                break;
        }
    }

    return 0;
}