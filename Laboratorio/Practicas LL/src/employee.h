typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nameStr,char* hoursWorkedStr, char* salary);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setHoursWorked(Employee* this,int hoursWorked);
int employee_getHoursWorked(Employee* this,int* hoursWorked);

int employee_setSalary(Employee* this,int salary);
int employee_getSalary(Employee* this,int* salary);

int ordenarXSueldo(void* emp1, void* emp2);
int compareByName(void* emp1, void* emp2);
int employee_isValidEmp(Employee* emp);
int print_Employee(Employee* this);
int compareById(void* emp1, void* emp2);
int menu();
int menuSort();
int menuModify();
