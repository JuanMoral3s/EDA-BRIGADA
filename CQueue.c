#include <stdio.h>
#include "CQueue.h"
#define DBG_HELP 1
#if DBG_HELP > 0
#define DBG_PRINT( ... ) do{ fprintf( stderr, "DBG:" __VA_ARGS__ ); } while( 0 )
#else
#define DBG_PRINT( ... ) ;
#endif


CQueue* CQueue_New( size_t capacity )
{
    CQueue* q = (CQueue*) malloc (sizeof(CQueue));
    if(q){
        q->front = 0;
        q->back = 0;
        q->capacity = capacity; 
        q->queue = (int*) malloc(capacity * sizeof(int));
    }
	return q;
}

void CQueue_Delete( CQueue** this )
{
    assert(*this);
    free((*this)->queue);
    free(*this);
    *this = NULL;
}

void CQueue_Enqueue( CQueue* this, int val )
{   
    DBG_PRINT( "Insertando el elemento %d", val );
    
    this->queue[this->back] = val;
    
    ++this->back;
    
    DBG_PRINT( ".BACK = %ld", this->back );
    
    ++this->len;
}

int CQueue_Dequeue( CQueue* this )
{
    DBG_PRINT( "Quitando el primer elemento");
    
    int tmp = this->queue[this->front];
    
    ++this -> front; 
    this -> front = this-> front % this->capacity;
    
    DBG_PRINT( ".FRONT = %ld", this->front );
    
    --this->len;
    
	return tmp;
	
}

int CQueue_Peek( CQueue* this )
{
    int tmp;
    if(this->back == 0){
        tmp = this -> capacity - 1; 
    }
    else{
        tmp = this -> back - 1;
    }
    return this->queue[tmp];
}

bool CQueue_IsFull( CQueue* this )
{
    return this->len == this->capacity;
}
bool CQueue_IsEmpty( CQueue* this )
{
   return this->len == 0;
}

size_t CQueue_Len( CQueue* this )
{   
   return this->len;
}

size_t CQueue_Capacity( CQueue* this )
{
   return this->capacity;
}

void CQueue_MakeEmpty( CQueue* this )
{
    this -> back = this -> front = 0; 
}

void debug_helper (const CQueue * q) 
{
  
fprintf (stderr, "Queue()::Front = %ld\n", q->front);
  
fprintf (stderr, "Queue()::Back = %ld\n", q->back);
  
fprintf (stderr, "Queue()::Lenght = %ld\n", q->len);

fprintf (stderr, "Queue()::Elements = ");

for(int i = 0; i <= q->len; i++)
{

fprintf (stderr, "  %ld  ", q->len-i);

}
    
  
fprintf (stderr, "\nQueue()::Capacity = %ld\n", q->capacity);


}
