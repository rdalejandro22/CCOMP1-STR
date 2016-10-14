#include <stdio.h>
struct node
{
    int val;
    struct node *next;
};
void crear(struct node *head, int n){
    struct node *cur;
    struct node *prev;
    prev = head;
    int i;
    for(i=2;i<=n;i++)
    {
        cur = malloc(sizeof(struct node));
        cur->val=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next= NULL;
    imprimir(head);
}
void imprimir(struct node *head)
{
    struct node *t;
    t = head;
    while(t!=NULL)
    {
        printf("%d",t->val);
        t = t->next;
    }
}
void eliminar(struct node *head, int n)
{
    struct node *prev;
    struct node *cur;
    prev = head;
    cur = head->next;
    while(cur!=NULL)
    {
        if(cur->val == n)
        {
            prev->next= cur->next;
            free(cur);
            break;
        }
        prev = cur;
        cur = cur->next;

    }
    imprimir(head);
}
void insertarinicio(struct node *lista,int n)
{
    struct node *nuevo;
    nuevo = malloc(sizeof(struct node));
    nuevo->val=n;
    nuevo->next=lista;
    lista = nuevo;
    imprimir(lista);

}
void insertarpos(struct node *lista, int pos, int n)
{
    struct node *nuevo;
    struct node *temp;
    struct node *cur;
    nuevo = malloc(sizeof(struct node));
    nuevo->val=n;
    nuevo->next=NULL;
    temp = lista;
    cur = lista->next;
    int i;
    for(i=1 ;pos>i;i++)
    {
        temp=temp->next;
        cur=cur->next;
    }
    temp->next=nuevo;
    nuevo->next=cur;
    imprimir(lista);
}

void cat(struct node *lista1, struct node *lista2,int n)
{
    struct node *temp;
    temp = lista1;
    int i;
    for(i=1 ;n>i;i++)
    {
        temp=temp->next;
    }
    temp->next=lista2;
    imprimir(lista1);


}

void orden(struct node *lista, int n)
{
    struct node *nuevo;
    struct node *prev;
    struct node *actual;
    nuevo = malloc(sizeof(struct node));
    nuevo->val=n;
    nuevo->next=NULL;
    prev = lista;
    actual = lista->next;
    int i;
    while(actual!=NULL)
    {
        if(n<=actual->val){
        prev->next=nuevo;
        nuevo->next=actual;
        break;}
        prev=actual;
        actual=actual->next;
    }
    prev -> next = nuevo;
    imprimir(lista);
}
main()
{
    struct node *head;
    head = malloc(sizeof(struct node));
    head->val=1;
    head->next=NULL;
    struct node *head2;
    head2 = malloc(sizeof(struct node));
    head2->val=1;
    head2->next=NULL;

    crear(head,5);
    printf("-------");

    insertarinicio(head,8);
    printf("-------");

    insertarpos(head,3,7);
    printf("-------");

    crear(head2,5);
    printf("-------");

    cat(head,head2,6);
    printf("-------");

    orden(head2,10);
}
