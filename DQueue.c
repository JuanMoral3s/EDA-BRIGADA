//Hasta 6.2

#include "DQueue.h"
#include <stdio.h>

DQueue* DQueue_New( size_t capacity )
{
    DQueue*q=(DQueue*)malloc(sizeof(DQueue));
    if(NULL!=q){
        q->queue = (int*)malloc(capacity*sizeof(int));
        if(NULL==q->queue){
            free(q);
            q=NULL;
        }else{
            q->len=0;
            q->capacity=capacity;
        }
    }
	return q;
}

void DQueue_Delete(DQueue** this )
{
    assert(*this);
    free((*this)->queue);
    free(*this);
    *this=NULL;
}

void DQueue_Enqueue(DQueue* this, int val )
{
    this->queue[this->back]=val;
    ++this->back;
    DBG_PRINT( "Insertando el elemento %d ", val );
    ++this->len;
    DBG_PRINT( "\n .Front= %ld", this->front );
}

int DQueue_Dequeue(DQueue* this)
{
    int tmp = this->queue[this->front];
    ++this->front;
    DBG_PRINT( "Eliminando el elemento primero ");
    this->front = this->front % this->capacity;
    DBG_PRINT( "\n .Front= %ld", this->front );
    --this->len;
    return tmp;
}

void DQueue_Enqueue_prio(DQueue* this, int val)
{
    DBG_PRINT( "Insertando el elemento %d ", val );
    if(this->len > this->capacity){
        if(this->back=0){
            this->back= this->capacity;
        }
        else{
            this->front--;
            this->queue[this->front]=val;
            this->len++;
        }
    }
    DBG_PRINT( "\n .Front= %ld ", this->front );
}

int DQueue_Dequeue_prio(DQueue* this)
{
    DBG_PRINT( "Eliminando el elemento ");
    if(this->len > this->capacity){
        if(this->back=0){
            this->back= this->capacity;
        }
        else{
            this->back--;
            this->len--;
        }
    }
    DBG_PRINT( "\n .Front= %ld", this->front );
    return this->queue[this->back];
}

int DQueue_Peek( DQueue* this )
{
	int tmp;
	if(this->back==0){
	    tmp==this->capacity--;
	}else{
	    tmp=this->back--;
	}
	return this->queue[tmp];
}

int DQueue_PeekBack( DQueue* this )
{
    if(DQueue_Dequeue(this)){
        return 0;
    }
    return this->len == this->capacity;
}

bool DQueue_IsFull( DQueue* this )
{
   return this->len == this->capacity;
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
    this->back=this->capacity--;
    this->len=0;
    
}
