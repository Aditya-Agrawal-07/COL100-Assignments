#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

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
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
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

struct Node* Head = NULL;

void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = Head;
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
    struct Node* cur = Head;
    while(cur) {
        length++;
        cur = cur->next;
    }
    return length;
}

void append(int x) {
    struct Node* cur = Head;
    if(cur == NULL) {
        // no list exists, we have to create one
        Head = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}

struct Node* reverse_helper(struct Node* cur_node) {
    if(cur_node == NULL) return NULL;

    if(cur_node->next == NULL) {
        // this is the first node of the reversed list
        Head = cur_node;
        return cur_node;
    }

    // recursively solve for the next node
    struct Node* next_node = reverse_helper(cur_node->next);

    // set the next of next_node to cur_node
    next_node->next = cur_node;

    // also make the cur_node->next as NULL, since cur_node is the last node of the list
    cur_node->next = NULL;

    return cur_node;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* last_node = reverse_helper(Head);
}

void swap(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    struct Node* next_node = get_node_at_pos(position+1);
    if(!node_at_pos || !next_node) return;

    // 2 cases 
    if(node_at_pos == Head) {
        Head = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
    else {
        struct Node* prev_node = get_node_at_pos(position-1);
        prev_node->next = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
}

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

// The below function returns the employee id of the first common boss
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

int checker(struct Employee* ptr, int emp_id){
    if(ptr == NULL)
        return 0;
    if(ptr->emp_id == emp_id)
        return 1;
    return checker(ptr->subordinate_1, emp_id)||checker(ptr->subordinate_2, emp_id);
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

int get_first_common_boss(int emp_id1,int emp_id2){
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
    return get_first_common_boss(b, emp_id2);
}

struct Helper2{
    int check;
    char* name;
};

//Print the employees with the same last name sperated by a space in the order of their level
struct Helper2 Name_help(struct Employee* ptr, int emp_id, struct Helper2 helper){
    if (helper.check==1){
        return helper;
    }
    struct Helper2 _helper;
    if (ptr->emp_id==emp_id){
        _helper.name=ptr->emp_name;
        _helper.check=1;
    }
    else{
        if (ptr->subordinate_1!=NULL){
            _helper=Name_help(ptr->subordinate_1,emp_id,helper);
        }
        if (_helper.check!=1){
            if (ptr->subordinate_2!=NULL){
                _helper=Name_help(ptr->subordinate_2,emp_id,helper);
            }
        }
    }
    return _helper;
}

void _Name(struct Employee* ptr,char* name){
    if (strcmp(name,ptr->emp_name)==0){
        append(ptr->emp_id);
    }
    if (ptr->subordinate_1!=NULL){
        _Name(ptr->subordinate_1,name);
    }
    if (ptr->subordinate_2!=NULL){
        _Name(ptr->subordinate_2,name);
    }
}

void swap_names(){
    int i;
    for (i=0;i<len()-1;i++){
        struct Node* _node=Head;
        int j,c=0;
        for (j=0;j<len()-1;j++){
            if (Level(_node->data)>Level(_node->next->data)){
                swap(j);
                c++;
            }
            if(c==0){
            _node=_node->next;
            c=0;
            }
        }
    }
}

void same_last_names(int emp_id){
    struct Employee* ptr=CEO;
    struct Helper2 helper={0,""};
    struct Helper2 helper1=Name_help(ptr,emp_id,helper);
    _Name(ptr,helper1.name);
    swap_names();
    print_list(Head);
    Head=NULL;
    return;
}

// Print the bosses of the given employee in the order from CEO to immediate boss

void Bosses(int emp_id,int ceo_id){
    int id=emp_id;
    while(id!=ceo_id){
        append(Boss(id));
        id=Boss(id);
    }
    reverse();
    print_list(Head);
    Head=NULL;
}

void get_all_bosses(int emp_id){
    struct Employee* ptr=CEO;
    if (ptr->emp_id==emp_id){
        printf("%d ",-1);
        return;
    }
    else{
        Bosses(emp_id,ptr->emp_id);
    }
    return;
}

// Return the average salary of the team with the given employee as head
struct Salary{
    double total_salary;
    double employees;
};

struct Salary Salary_Helper1(struct Employee* ptr,struct Salary salary){
    struct Salary _salary=salary;
    if (ptr->subordinate_1!=NULL){
        _salary.employees++;
        _salary.total_salary+=ptr->subordinate_1->emp_salary;
        _salary=Salary_Helper1(ptr->subordinate_1,_salary);
    }
    if (ptr->subordinate_2!=NULL){
        _salary.employees++;
        _salary.total_salary+=ptr->subordinate_2->emp_salary;
        _salary=Salary_Helper1(ptr->subordinate_2,_salary);
    }
    return _salary;
}

struct Salary Salary_Helper(struct Employee* ptr,int emp_id) {
    struct Salary salary,_salary={0,0};
    if (ptr->emp_id==emp_id){
        salary.employees=1;
        salary.total_salary=ptr->emp_salary;
        _salary=Salary_Helper1(ptr,salary);
        return _salary;
    }
    else{
        if (ptr->subordinate_1!=NULL){
            _salary=Salary_Helper(ptr->subordinate_1,emp_id);
        }
        if (_salary.employees==0){
            if (ptr->subordinate_2!=NULL){
                _salary=Salary_Helper(ptr->subordinate_2,emp_id);
            }
        }
    }
    return _salary;
}

double get_average_salary(int emp_id){
    struct Employee* ptr=CEO;
    struct Salary salary=Salary_Helper(ptr,emp_id);
    return (salary.total_salary/salary.employees);
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

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}
