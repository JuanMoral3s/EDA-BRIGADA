#include "DQueue.h"


DQueue* DQueue_New( size_t capacity )
{
    DQueue* new = (DQueue*)malloc(sizeof(DQueue));
    if(new){
        new->front=0;
        new->back=0;
        new->len=0;
        new->capacity=capacity;
        new->queue=(int*)malloc(capacity * sizeof(int));
   
        if(!new->queue){
            free(new);
            new=NULL;
        }
    }
    return new;
}

void DQueue_Delete( DQueue** this )
{
    assert(*this);
   
    free((*this)->queue);
    free(*this);
    *this=NULL;
}

void DQueue_Enqueue( DQueue* this, int val )
{
    if(this->len < this->capacity){
        this->queue[this->back]=val;
        this->back+=1;
        this->len++;
        if(this->back==this->capacity)
            this->back = 0;
    }
}

int DQueue_Dequeue( DQueue* this )
{
    if(this->len > 0){
        int tmp=this->queue[this->front];
        this->front+=1;
        this->len--;
        if(this->front==this->capacity)
            this->front=0;
        return tmp;
    }
}

void DQueue_Enqueue_prio( DQueue* this, int val )
{
    if(this->len < this->capacity){
        if(this->front = 0){
            this->front = this->capacity;
        }
        else
            this->front -= 1;
        this->queue[this->front] = val;
        this->len += 1;
    }
}

int DQueue_Dequeue_prio( DQueue* this )
{
    if(this->len < this->capacity){
        if(this->back = 0){
            this->back = this->capacity;
        }
        else
            this->back -= 1;
        this->len -= 1;
        return this->queue[this->back];
    }
}

int DQueue_Peek( DQueue* this )
{
    assert( this->len > 0 );
    return this->queue[this->front];
}

int DQueue_Peek_prio( DQueue* this )
{
    int tmp;
    if(this->back = 0){
        tmp = this->capacity - 1;
    }
    else{
        tmp = this->back - 1;
    }
    return this->queue[tmp];
}

bool DQueue_IsFull( DQueue* this )
{
   return this->len==this->capacity;
}

bool DQueue_IsEmpty( DQueue* this )
{
    return this->len==0;
}

size_t DQueue_Len( DQueue* this )
{
    return this->len;
}

size_t DQueue_Capacity( DQueue* this )
{
    return this->capacity;
}

void DQueue_MakeEmpty( DQueue* this )
{
    this->front=0;
    this->back=0;
    this->len=0;
}
