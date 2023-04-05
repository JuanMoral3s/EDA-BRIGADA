#ifndef  DQUEUE_INC
#define  DQUEUE_INC


#include <stdlib.h>
// para malloc and friends

#include <assert.h>
// para assert

#include <stdbool.h>
// para bool, true and false


typedef struct
{
    int* queue;
	size_t front;
	size_t back;
	size_t len;
	size_t capacity;
} DQueue;

DQueue* DQueue_New(          size_t capacity );
void    DQueue_Delete(       DQueue** this );
void    DQueue_Enqueue(      DQueue* this, int val );
int     DQueue_Dequeue(      DQueue* this );
int     DQueue_Peek(         DQueue* this );
void    DQueue_Enqueue_prio( DQueue* this, int val );
int     DQueue_Dequeue_prio( DQueue* this );
int     DQueue_Peek_prio(    DQueue* this );
bool    DQueue_IsEmpty(      DQueue* this );
bool    DQueue_IsFull(       DQueue* this );
size_t  DQueue_Len(          DQueue* this );
size_t  DQueue_Capacity(     DQueue* this );
void    DQueue_MakeEmpty(    DQueue* this );


#endif   /* ----- #ifndef DQUEUE_INC  ----- */
