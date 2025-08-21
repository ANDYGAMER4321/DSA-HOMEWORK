void display(NODE *aux)
{
    while(aux!=NULL)
    {
        printf("\n%d->",aux->data);
        aux=aux->link;
    }
    printf("\n");
}

void insert_front(NODE **temp,int ele)
{
    NODE *newNode;
    newNode=getnode(ele);
    newNode->link=*temp;
    *temp=newNode;
}
void insert_rear(NODE **temp,int ele)
{
    NODE *newNode,*aux;
    newNode=getnode(ele);
    aux=*temp;
    while(aux->link!=NULL)
        aux=aux->link;

    aux->link=newNode;
}
void delete_front(NODE **temp)
{
    if(*temp==NULL)
    {
        printf("empty list");
        return;
    }
    NODE *aux;
    aux=*temp;
    *temp=(*temp)->link;
    free(aux);  
}
void delete_rear(NODE **temp)
{
    NODE *cur,*prev;
    if(*temp==NULL)
    {
        printf("empty list");
        return;
    }
    prev=NULL;
    cur=*temp;
    while(cur->link!=NULL)  
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=NULL;            //problem as it will become NULL=NULL at a point which is invalid.
    free(cur);
}

int main()
{
    NODE *first;
    first=getnode(20);
    display(first);
    insert_front(&first,10);
    display(first);
    // insert_front(&first,30);
    // display(first);
    // insert_front(&first,40);
    // display(first);
    // insert_front(&first,100);
    // display(first);

}

