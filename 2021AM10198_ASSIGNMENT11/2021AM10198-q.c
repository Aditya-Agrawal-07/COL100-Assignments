#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d ", ceo->emp_id);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------

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


// helper function that returns pointer to `Node` at `position`
// if there is no such position, it returns NULL
struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        if(pos == position) return cur;
        pos++;
        cur = cur->next;
    }
    return NULL;
}


// Return the number of elements in the list
int len() {
    int length = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        length++;
        cur = cur->next;
    }
    return length;
}


// Add an item to the end of the list
void append(int x) {
    struct Node* cur = PythonListHead;
    if(cur == NULL) {
        // no list exists, we have to create one
        PythonListHead = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

struct Helper{
    int size;
    int checker;
};

struct Helper5{
    int checker;
    struct Employee* ptr;
};

struct Helper5 Emp_ptr(int emp_id,struct Employee* ptr,struct Helper5 helper){
    if (helper.checker==1){
        return helper;
    }
    struct Helper5 _helper;
    if (ptr->emp_id==emp_id){
        helper.ptr=ptr;
        helper.checker=1;
        return helper;
    }
    else{
        if (ptr->subordinate_1!=NULL){
            _helper=Emp_ptr(emp_id,ptr->subordinate_1,helper);
        }
        if (_helper.checker!=1){
            if (ptr->subordinate_2!=NULL){
                _helper=Emp_ptr(emp_id,ptr->subordinate_2,helper);
            }
        }
    }
    return _helper;
}

/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */
void _EmployeesAtSameLevel(struct Employee* ptr, int i){
    if (i==1){
        int left,right;
        if(ptr->subordinate_1!=NULL && ptr->subordinate_2!=NULL){
            left=ptr->subordinate_1->emp_id;
            right=ptr->subordinate_2->emp_id;
            printf("%d %d ",left,right);
        }
        else if (ptr->subordinate_1!=NULL){
            left=ptr->subordinate_1->emp_id;
            printf("%d ",left);
        }
        else if (ptr->subordinate_2!=NULL){
            right=ptr->subordinate_2->emp_id;
            printf("%d ",right);
        }
    return;
    }
    else{
        if (ptr->subordinate_1!=NULL || ptr->subordinate_2!=NULL){
            i=i-1;
            if (ptr->subordinate_1!=NULL){
            _EmployeesAtSameLevel(ptr->subordinate_1,i);
            }
            if (ptr->subordinate_2!=NULL){
            _EmployeesAtSameLevel(ptr->subordinate_2,i);
            }
        }
    }    
}

void EmployeesAtSameLevel(int level) {
    // The level may be any integer
    struct Employee* ptr=CEO;
    if (level==0){
        if (ptr!=NULL){
            printf("%d",ptr->emp_id);
        }
        return;
    }
    _EmployeesAtSameLevel(ptr, level);
    return;
}

// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers
void _get_employees(struct Employee* ptr){
    printf("%d ",ptr->emp_id);
    if (ptr->subordinate_1!=NULL){
        _get_employees(ptr->subordinate_1);
    }
    if (ptr->subordinate_2!=NULL){
        _get_employees(ptr->subordinate_2);
    }
    return;
}
void get_employees() {
    struct Employee* ptr=CEO;
    if (ptr!=NULL){
        _get_employees(ptr);
    }
    return;
}

/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */
void _ImmediateTeam(struct Employee* _boss_ptr,struct Employee* _emp_ptr, int emp_id){
    struct Employee* boss_ptr=_boss_ptr,* emp_ptr=_emp_ptr;
    if (emp_ptr->emp_id==emp_id){
        if (emp_ptr->subordinate_1!=NULL && emp_ptr->subordinate_2!=NULL){
            printf("%d %d %d ",boss_ptr->emp_id,emp_ptr->subordinate_1->emp_id,emp_ptr->subordinate_2->emp_id);
        }
        else if (emp_ptr->subordinate_1!=NULL){
            printf("%d %d ",boss_ptr->emp_id,emp_ptr->subordinate_1->emp_id);
        }
        else if (emp_ptr->subordinate_2!=NULL){
            printf("%d %d ",boss_ptr->emp_id,emp_ptr->subordinate_2->emp_id);
        }
        else {
            printf("%d ",boss_ptr->emp_id);
        }
        return;
    }
    else{
        if (emp_ptr->subordinate_1!=NULL){
            _ImmediateTeam(emp_ptr,emp_ptr->subordinate_1,emp_id);
        }
        if (emp_ptr->subordinate_2!=NULL){
            _ImmediateTeam(emp_ptr,emp_ptr->subordinate_2,emp_id);
        }
    }
}

void ImmediateTeam(int emp_id) {
    struct Employee* ptr=CEO;
    if (emp_id==CEO->emp_id){
        if (CEO->subordinate_1!=NULL && CEO->subordinate_2!=NULL){
            printf("%d %d ", CEO->subordinate_1->emp_id,CEO->subordinate_2->emp_id);
        }
        else if (CEO->subordinate_1!=NULL){
            printf("%d ",CEO->subordinate_1->emp_id);
        }
        else if (CEO->subordinate_2!=NULL){
            printf("%d",CEO->subordinate_2->emp_id);
        }
        return;
    }
    else{
        _ImmediateTeam(CEO,CEO->subordinate_1,emp_id);
        _ImmediateTeam(CEO,CEO->subordinate_2,emp_id);
        return;
    }
}

int lvl_h(int emp_id, struct Employee* emp, int lvl){
    if(!emp)
        return -1;
    if(emp->emp_id == emp_id)
        return lvl;
    int v1 = lvl_h(emp_id, emp->subordinate_1, lvl+1);
    int v2 = lvl_h(emp_id, emp->subordinate_2, lvl+1);
    if(v1 == -1)
        return v2;
    else if(v2 == -1)
        return v1;
}

int Level(int emp_id) {
    // Note that ceo has level 0
    struct Employee* ptr=CEO;
    if (ptr->emp_id==emp_id){
        return 0;
    }
    return lvl_h(emp_id,CEO,0);
}

int boss(int emp_id, struct Employee* emp){
    if(!emp)
        return -100;
    if(emp_id == CEO->emp_id)
        return -1;
    if(emp->subordinate_1 == NULL && emp->subordinate_2 == NULL)
        return -100;
    else if(emp->subordinate_1 == NULL){
        if(emp->subordinate_2->emp_id == emp_id)
            return emp->emp_id;
        else
            return boss(emp_id, emp->subordinate_2);
    }
    else if(emp->subordinate_2 == NULL){
        if(emp->subordinate_1->emp_id == emp_id)
            return emp->emp_id;
        else
            return boss(emp_id, emp->subordinate_1);
    }
    else{
        if(emp->subordinate_1->emp_id == emp_id || emp->subordinate_2->emp_id == emp_id)
            return emp->emp_id;
        else{
            int sub1 = boss(emp_id, emp->subordinate_1);
            int sub2 = boss(emp_id, emp->subordinate_2);
            if(sub1 == -100)
                return sub2;
            else if(sub2 == -100)
                return sub1;
        }
    }
}

int Boss(int emp_id) {
    return boss(emp_id, CEO);
}

int checker(struct Employee* ptr, int emp_id){
    if(ptr == NULL)
        return 0;
    if(ptr->emp_id == emp_id)
        return 1;
    return checker(ptr->subordinate_1, emp_id)||checker(ptr->subordinate_2, emp_id);
}


struct Helper_Distance{
    int emp_left;
    int emp_right;
    int checker;
};

struct Helper_Distance Distance1(struct Employee* ptr,int emp_id1,int emp_id2,struct Helper_Distance helper){
    struct Helper_Distance _helper=helper;
    if (helper.checker==1){
        return helper;
    }
    if (ptr->emp_id==emp_id1){
        _helper.emp_left=emp_id1;
        _helper.emp_right=emp_id2;
        _helper.checker=1;
    }
    else if (ptr->emp_id==emp_id2){
        _helper.emp_left=emp_id2;
        _helper.emp_right=emp_id1;
        _helper.checker=1;
    }
    else{
        if (ptr->subordinate_1!=NULL){
            _helper=Distance1(ptr->subordinate_1,emp_id1,emp_id2,helper);
        }
        if (_helper.checker!=1){
            if (ptr->subordinate_2!=NULL){
                _helper=Distance1(ptr->subordinate_2,emp_id1,emp_id2,helper);
            }
        }
    }
    return _helper;
}

int first_c_boss(int emp_id1, int emp_id2){
    if(emp_id1 == CEO->emp_id || emp_id2 == CEO->emp_id)
        return CEO->emp_id;
    struct Helper5 help;
    help.checker = 0;
    help.ptr = CEO;
    struct Helper5 h1;
    h1 = Emp_ptr(emp_id1, CEO, help);
    if(checker(h1.ptr, emp_id2))
        return (h1.ptr)->emp_id;
    int b = Boss(emp_id1);
    return first_c_boss(b, emp_id2);
    
}

int Distance(int emp_id1, int emp_id2){
    int v1 = Level(emp_id1);
    int v2 = Level(emp_id2);
    int cmb = first_c_boss(emp_id1,emp_id2);
    int v3 = Level(cmb);
    return (v1+v2-2*v3);

}
/* The following function returns the diameter of a Organisation - 
a diameter is the maximum distance between any two emp_ids in the organisation. You can use the distance function implemented above */
void diameter_helper(struct Employee* ptr){
    if (ptr->subordinate_1==NULL && ptr->subordinate_2==NULL){
        append(ptr->emp_id);
        return;
    }
    if (ptr->subordinate_1!=NULL){
        diameter_helper(ptr->subordinate_1);
    }
    if (ptr->subordinate_2!=NULL){
        diameter_helper(ptr->subordinate_2);
    }
}

int Diameter() {
    struct Employee* ptr=CEO;
    diameter_helper(ptr);
    int length=len();
    int max=0;
    int i;
    struct Node* node1=PythonListHead;
    struct Node* node2=node1;
    for (i=0;i<=length-1;i++){
        int j;
        for (j=i;j<=length-1;j++){
            if (max<Distance(node1->data,node2->data)){
                max=Distance(node1->data,node2->data);
            }
            node2=node2->next;
        }
        node1=node1->next;
        node2 = node1;
    }
    return max;
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */
struct Helper _TeamSize(struct Employee* _boss_ptr,struct Employee* _emp_ptr, int emp_id,struct Helper helper){
    if (helper.checker==0){
    struct Employee* boss_ptr=_boss_ptr,* emp_ptr=_emp_ptr;
    struct Helper helper1;
    if (emp_ptr->emp_id==emp_id){
        if (emp_ptr->subordinate_1!=NULL && emp_ptr->subordinate_2!=NULL){
            helper.size=3;
            helper.checker=1;
        }
        else if (emp_ptr->subordinate_1!=NULL){
            helper.size=2;
            helper.checker=1;
        }
        else if (emp_ptr->subordinate_2!=NULL){
            helper.size=2;
            helper.checker=1;
        }
        else {
            helper.size=1;
            helper.checker=1;
        }
        helper1=helper;
    }
    else{
        if (emp_ptr->subordinate_1!=NULL){
            helper1=_TeamSize(emp_ptr,emp_ptr->subordinate_1,emp_id,helper);
        }
        if (helper1.checker==0){
            if (emp_ptr->subordinate_2!=NULL){
                helper1=_TeamSize(emp_ptr,emp_ptr->subordinate_2,emp_id,helper);
            }
        }
    }
    return helper1;
    }
}

int TeamSize(int emp_id) {
    struct Employee* ptr=CEO;
    struct Helper helper={0,0},_helper;
    if (emp_id==CEO->emp_id){
        if (CEO->subordinate_1!=NULL && CEO->subordinate_2!=NULL){
            return 2;
        }
        else if (CEO->subordinate_1!=NULL){
            return 1;
        }
        else if (CEO->subordinate_2!=NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        _helper=_TeamSize(CEO,CEO->subordinate_1,emp_id,helper);
        if (_helper.checker==0){
            _helper=_TeamSize(CEO,CEO->subordinate_2,emp_id,helper);
        }
    return _helper.size;
    }
}


// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[20];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "level") == 0) {
            int x;
            scanf("%d", &x);
            int d = Level(x);
            printf("%d\n", d);
        } 

        if(strcmp(operation_type, "distance") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int d = Distance(x, y);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "employees_at_same_level") == 0) {
            int x;
            scanf("%d", &x);
            EmployeesAtSameLevel(x);
            printf("\n");
        }

        if(strcmp(operation_type, "get_employees") == 0) {
            get_employees();
            printf("\n");
        }

        if(strcmp(operation_type, "boss") == 0) {
            int x;
            scanf("%d", &x);
            int d = Boss(x);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "diameter") == 0) {
            int d = Diameter();
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "immediate_team") == 0) {
            int x;
            scanf("%d", &x);
            ImmediateTeam(x);
            printf("\n");
        }

        if(strcmp(operation_type, "team_size") == 0) {
            int x;
            scanf("%d", &x);
            int d = TeamSize(x);
            printf("%d\n", d);
        }
    }

    return 0;
}
