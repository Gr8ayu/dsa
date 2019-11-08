 #include<stdio.h>
 #define MAX 100
 
 typedef struct heap{
        int data[MAX];
        int size;
 } Heap;
 
 
 Heap createHeap(){
        int i;
        Heap heap;
        for (i = 0; i < MAX; i += 1)
        {
                heap.data[i] = 0;
        }
        heap.size = 0;
        return heap;
 
 
 }
 
 int leftc(int i){return 2*i+1;}
 int rightc(int i){return 2*i+2;}
 int parent(int i){return (i-1)/2;}
 
 void swap(int* a, int* b){ 
        int c = *a;
        *a = *b ;
        *b = c;
}
 
 void insert(Heap* heapAddr, int value){
        int index = heapAddr->size;
        
        
        if( index == MAX){
                printf("Heap Full");       
                return ; 
        }
        
        heapAddr->data[index] = value;
        while( index>0 && heapAddr->data[parent(index)] < value ){        
                swap( &heapAddr->data[parent(index)] , &heapAddr->data[index]  );
                index = parent(index);
                
        
        }
        heapAddr->size++;
        
        
        
        
        
 }
 
 void display(Heap* heap){
 
        int i ;
        if (heap->size == 0){
                printf("empty heap");
                return;
                
                
        }
        else{
        for (i = 0; i < heap->size; i += 1)
        {
                printf(" %d - ",heap->data[i]);
        }
        }
        
        
 
 }
 
 void delete(Heap* heap){
        if(heap->size==0)return;
        
        printf("\n%d deleted",heap->data[0]);
        
        heap->size--;
        heap->data[0] = heap->data[heap->size];
        heap->data[heap->size] = 0;
        
        int index = 0, greaterChild = 0;
        while(1){
                
                if( heap->data[index] < heap->data[leftc(index)]   ) {greaterChild = leftc(index);}
                if(heap->data[leftc(index)] < heap->data[rightc(index)]) {greaterChild = rightc(index);}
                if(index == greaterChild){break;}
                
                swap( &heap->data[index], &heap->data[greaterChild] );
                
                index = greaterChild;
                
        }
        
 display(heap);
 }
 
 int main(){
 
        Heap heap = createHeap();
        
        int i , n;
        printf("nos : ");
        scanf("%d",&n);
        
        for (i = 0; i < n; i += 1)
        {
                int a;
                printf("\n >>");
                scanf("%d",&a);
                insert(&heap, a);
                display(&heap);
                
        }
        
        while(1){
        int a;
                printf("\n >>");
                scanf("%d",&a);
                delete(&heap);
                display(&heap);
        
        }
        
        
        
 
 
 
 
 
 
 }
