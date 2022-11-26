#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}

// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;


// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    struct Node* ptr=PythonListHead;
    if (PythonListHead==NULL){
        PythonListHead=create_node(x);
        return;
    }
    else{
        while (ptr->next!=NULL){
        ptr=ptr->next;
        }
        ptr->next=create_node(x);
        return;
    }
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    struct Node* node=create_node(x);
    struct Node* ptr=PythonListHead;
    if (ptr==NULL){
        return;
    }
    else{
        if (position==0){
            PythonListHead=node;
            node->next=ptr;
            return;
        }
        else if (position==1){
            if (ptr->next!=NULL){
                node->next=ptr->next;
                ptr->next=node;
                return;
            }
            else{
                return;
            }
        }
        else{
            int i=1;
            while (i<position){
                if (ptr->next!=NULL){
                    ptr=ptr->next;
                    i++;
                }
                else{
                    return;
                }
            }
            if (ptr->next!=NULL){
                node->next=ptr->next;
                ptr->next=node;
                return;
            }
            else{
                return;
            }
        }
    }   
}


// Remove the item at the end of the list
void pop() {
    struct Node* ptr=PythonListHead;
    if (PythonListHead!=NULL){
        if (ptr->next==NULL){
            delete_node(ptr);
            PythonListHead=NULL;
            return;    
        }
        else{
            struct Node* prev_node;
            while (ptr->next!=NULL){
                prev_node=ptr;
                ptr=ptr->next;
            }
            prev_node->next=NULL;
            delete_node(ptr);
            return;
        }
    }
    else{
        return;
    }
}


// Remove all items from the list
void clear() {
    struct Node* ptr=PythonListHead;
    struct Node* _ptr;
    while (ptr!=NULL){
        _ptr=ptr->next;
        delete_node(ptr);
        ptr=_ptr;
    }
    PythonListHead=NULL;
    return;
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    int c=0;
    struct Node* ptr=PythonListHead;
    while (ptr!=NULL){
        if (ptr->data==x){
            c++;
        }
        ptr=ptr->next;
    }
    return c;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* ptr=PythonListHead;
    if (ptr!=NULL){
        struct Node* prev_ptr,*next_ptr;
        prev_ptr=NULL,next_ptr=NULL;
        while (ptr!=NULL){
            next_ptr=ptr->next;
            ptr->next=prev_ptr;
            prev_ptr=ptr;
            ptr=next_ptr;
        }
        PythonListHead=prev_ptr;
        return;
    }
    else{
        return;
    }
}


// Return the number of elements in the list
int len() {
    // your code goes here
    int len=0;
    struct Node* ptr=PythonListHead;
    while (ptr!=NULL){
        ptr=ptr->next;
        len++;
    }
    return len;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    struct Node* ptr=PythonListHead;
    if (position==0 && ptr=NULL){
            return;
        }
    else{
        int i=0;
    while (i<position){
        if (ptr!=NULL && ptr->next!=NULL){
            ptr=ptr->next;
            i++;
        }
        else{
            return;
        }
    }
    ptr->data=x;
    return;
    }   
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    struct Node* ptr=PythonListHead;
    if (position==0){
        if (ptr!=NULL){
            return ptr->data;
        }
        else{
            return -1;
        }
    }
    else{
        int i=1;
        while (i<=position){
            if (ptr!=NULL){
                ptr=ptr->next;
                i++;
            }
            else{
                return -1;
            }
        }
        if (ptr!=NULL){
            return (ptr->data);
        }
        else{
            return -1;
        }
    }
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* ptr=PythonListHead;
    struct Node* prev_ptr,*next_ptr;
    if (position==0){
        if (ptr!=NULL){
            prev_ptr=ptr->next;
            delete_node(ptr);
            PythonListHead=prev_ptr;
            return;
        }
        else{
            return;
        }
    }
    else{
        int i=1;
        while (i<position){
            if (ptr!=NULL){
                ptr=ptr->next;
                i++;
            }
            else{
                return;
            }
        }
        if (ptr->next!=NULL){
            prev_ptr=ptr->next;
            next_ptr=ptr->next->next;
            ptr->next=next_ptr;
            delete_node(prev_ptr);
            return;
        }
        else{
            return;
        }
    }
}


// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* index_into(int *positions, int n) {
    // your code goes here
    struct Node* new_head=NULL,*_ptr;
    struct Node* ptr=PythonListHead;
    int i;
    for (i=0;i<n;i++){
        int c=0,a=0;
        while (c<positions[i]){
            if (ptr!=NULL && ptr->next!=NULL){
                ptr=ptr->next;
                c++;
            }
            else{
                a=1;
                break;
            }
        }
        if (a!=1 && PythonListHead!=NULL){
            if (new_head==NULL){
                new_head=create_node(ptr->data);
                _ptr=new_head;
            }
            else{
                while (_ptr->next!=NULL){
                _ptr=_ptr->next;
                }
                _ptr->next=create_node(ptr->data);
            }
        }
        ptr=PythonListHead;   
    }
    return new_head;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    struct Node* ptr=PythonListHead;
    if (position==0){
        if (ptr==NULL || ptr->next==NULL){
            return;
        }
        else{
            struct Node* _ptr=ptr->next;
            ptr->next=ptr->next->next;
            PythonListHead=_ptr;
            _ptr->next=ptr;
        }
    }
    else{
        int i=1;
        struct Node* prev_ptr,*next_ptr,*next_next_ptr;
        while(i<=position){
            if (ptr==NULL || ptr->next==NULL){
                return;
            }
            else{
            prev_ptr=ptr;
            ptr=ptr->next;
            i++;
            }
        }
        if (ptr==NULL || ptr->next==NULL){
            return;
        }
        else{
            next_ptr=ptr->next;
            next_next_ptr=ptr->next->next;
            prev_ptr->next=next_ptr;
            next_ptr->next=ptr;
            ptr->next=next_next_ptr;
            return;
        }       
    }    
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    if (len()==0){
        return;
    }
    else{
        int i;
        struct Node* ptr,*_ptr=NULL;
        for (i=1;i<len();i++){
            ptr=PythonListHead;
            int c=0;
            int j=0;
            while(ptr->next!=_ptr){
                if (ptr->data > ptr->next->data){
                    swap(j);
                    c++;
                }
                else{  
                    ptr=ptr->next;
                }
                j++;
            }
            _ptr=ptr;
            if (c==0){
                break;
            }
        }
    }
}
// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}