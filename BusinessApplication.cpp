#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;


//---------------------------------DATA STRUCTURE STARTS

int option;
string adminnameA[5];
int count_admin = 0;
string PasswordA[5];
const int MAX_RECORDS = 20;
bool salaryStatus[MAX_RECORDS] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
char attendencesheet[MAX_RECORDS];
string employeeNameA[MAX_RECORDS]; //Array of name of employee
string employeeFNameA[MAX_RECORDS]; //Array of father name of employee
string employeeCnicA[MAX_RECORDS]; //Array of CNIC of Employee
string employeeJobA[MAX_RECORDS]; //Array of Job of Employee
string employeePhoneA[MAX_RECORDS]; //Array of mobileno.of Employee
float employeeSalaryA[MAX_RECORDS]; // Array of salary of Employee
float employeedupSalaryA[MAX_RECORDS]; // duplicate Array of salary of Employee
int securitydepartment[MAX_RECORDS]; // indexes of security Guards as a Employee 
int count_security = 0;
int chefdepartment[MAX_RECORDS]; // indexes of Chef as a Employee
int count_chef = 0;
int waiterdepartment[MAX_RECORDS]; // indexes of Waiter as a Employee
int count_waiter = 0;
int count_employee = 0;
string name;
string fname;
string EmployeName = "Employees";
string Epassword = "2233";

string Menu[14] = {"CHICKEN PIZZA","PEPPERONI PIZZA","BBQ PIZZA","ZINGER BURGER","CHICKEN BURGER","SIMPLE BURGER","CHOCOLATE ICE CREAM","STAWBERRY ICE CREAM","CHOCOLATE CAKE","VANILLA CAKE","PINEAPPLE CAKE","COCA COLA","SPRITE","7 UP"}; // Array of Food items
float price[14] = {1250,1430,1350,300,180,70,120,100,550,500,530,110,100,110}; // Array of Food item price
float checksalequantity[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Array of Food item Quantity
float totalperitem[4]; 
bool discount = false;
float totalbill[MAX_RECORDS]; //Array of Total Bill of Customer
float dispriceA[MAX_RECORDS]; // Array of discount bill of Customer
float discountpercent = 0;
float discountprice = 0; 
float discountquantity = 0;
float quantityA[4];
int optionindex[4];
string customernameA[MAX_RECORDS]; // Array of Customer Name
int n = 0; 
float customerbill = 0;
int count_customer = 0;
int option1;
int quantity;
//---------------------------------DATA STRUCTURE ENDS

//---------------------------------FUNCTION PROTOTYPES STARTS
void clearscreen();
void mainHeader();

//ADMIN FUNCTIONS
bool adminlogin();
int who();
bool adminsignup();
bool adminSignin();
void putadminArray(string adminname, string password);
int adminMenu();
void addEmployee();
void putintoArray(string name,string fname,string cnic, string mobile_no,float salary, string job);
void view(string fname,string cnic,string phone,float salary, string job);
void updateEmployee();
void updateInfo(string name,string fname,string cnic, string mobile_no,float salary, string job,int field);
void checkjob(int field);
void deleteEmployee();
void delEmpinfo(int field);
void updatedupSal(int field);
void delsecurity(int field);
void updatesecuritydepartment(int field);
void delwaiter(int field);
void updatewaiterdepartment(int field);
void delchef(int field);
void updatechefdepartment(int field);
void viewEmployeeInfo();
void infoOne();
void sort();
int largest(int s);
void infoAll();
void viewwaiter();
void viewchef();
void viewsecurity();
void giveSalary();
void changeEUserpass();
void changeE();
bool countCnic(string line);
bool countMobileno(string line);
void viewattendence();
void checkattendence();
void changePassword();
void changeUserPass();
void change(int field);
void managerestaurantexpenses();
void resetEmployeestat();
void checksalesquantity();
void salesquantityprice();
void giveDiscount();
void customerbillhistory();
//EMPLOYEE FUNCTIONS
int EmployeeMenu();
void checkSalaryStatus();
void giveAttendence();
void employeelogin();
//CUSTOMER FUNCTIONS
void getcustomername();
void putintoCustArray(string line);
int customerMenu();
void viewFoodMenu();
void orderFood();
void pizza();
void burger();
void cake();
void drinks();
void icecream();
void depositBill();
void calculateBill();
void recommendation();

//SAVE AND LOAD FILE FUNCTIONS
void saveemployeefile();
void loademployeefile();
void saveadminfile();
void loadadminfile();
string parseRecord(string record, int field);
float parseRecord1(string record, int field);
void savecustomerfile();
float convertintofloat(string line);
void createattendenceSheet();
void loadattendenceSheet();
void saveattendenceSheet();
void loadcustomerfile();

//---------------------------------FUNCTION PROTOTYPES ENDS



main(){
    loadcustomerfile();
    loademployeefile();
    createattendenceSheet();
    system("CLS");
    int opt = 0;
    while (true)
    {
        opt = who();
        if (opt == 1)
        {
            //ADMIN
            system("CLS");
            bool admin = adminlogin();
            if (admin == true)
            {
                int op = 0;
                while (true)
                {
                    system("CLS");
                    op = adminMenu();
                    system("CLS");
                    if (op == 1)
                    {
                        //ADD EMPLOYEE
                        addEmployee();
                    }
                    else if (op == 2)
                    {
                        //UPDATE EMPLOYEE
                        updateEmployee();
                    }
                    else if (op == 3)
                    {
                        //DELETE EMPLOYEE
                        deleteEmployee();
                    }
                    else if (op == 4)
                    {
                        //VIEW EMPLOYEE
                        viewEmployeeInfo();
                    }
                    else if (op == 5)
                    {
                        //MANAGE RESTAURANT EXPENSE
                        managerestaurantexpenses();
                    }
                    else if (op == 6)
                    {
                        //CHECK EMPLOYEE ATTENDENCE
                        checkattendence();
                    }
                    else if (op == 7)
                    {
                        //CHANGE USERNAME AND PASSWORD
                        changePassword();
                    }
                    else if (op == 8)
                    {
                        //LOGOUT
                        break;
                    }
                    saveemployeefile();
                }
                
            }
            
            
        }//end of admin if condition
        else if (opt == 2)
        {
            system("CLS");
            employeelogin();
            int employeeoption = 0;
            //EMPLOYEE
            while (true)
            {
                system("CLS");
                employeeoption = EmployeeMenu();
                system("CLS");
                if (employeeoption == 1)
                {
                    //GIVE ATTENDENCE
                    giveAttendence();
                    saveattendenceSheet();
                }
                else if (employeeoption == 2)
                {
                    //CHECK SALARY
                    checkSalaryStatus();
                }
                else if (employeeoption == 3)
                {
                    //EXIT
                    break;
                }
                
            }//end of while loop
            
        }
        else if (opt == 3)
        {
            //CUSTOMER
            system("CLS");
            getcustomername();
            system("CLS");
            int customeroption = 0;
            while (true)
            {
                customeroption = customerMenu();
                system("CLS");
                if (customeroption == 1)
                {
                    //VIEW FOOD MENU
                    viewFoodMenu();
                }
                else if (customeroption == 2)
                {
                    //ORDER FOOD
                    orderFood();
                }
                else if (customeroption == 3)
                {
                    //DEPOSIT BILL
                    depositBill();
                }
                else if (customeroption == 4)
                {
                    //EXIT
                    n = 0;
                    customerbill = 0;
                    break;
                }
                
            }
            
        }//end of customer if condition
        else if (opt == 4)
        {
            //EXIT
            system("CLS");
            mainHeader();
            cout<<"THANKS FOR USING OUR RESTAURANT MANAGEMENT SYSTEM......."<<endl;
            cout<<"PRESS ANY KEY "<<endl;
            getch();
            system("CLS");
            break;
        }//end of exit if condition
        else{
            cout<<"YOU ENTER THE WRONG OPTION...... TRY AGAIN!"<<endl;
        }
        
        
        
    }//END OF WHILE LOOP
}


//----------------------------------------------FUNCTION DEFINATIONS START-------

void mainHeader(){
    cout<<"**************************************************************************************************"<<endl;
    cout<<"*                                RESTAURANT MANAGEMENT SYSTEM                                    *"<<endl;
    cout<<"**************************************************************************************************"<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"                                                                                                  "<<endl;
}//END OF MAINHEADER FUNCTION


bool adminlogin(){
    bool admin;
    while (true)
    {
        mainHeader();
        cout<<"                       "<<endl;
        cout<<" 1. SIGN-UP"<<endl;
        cout<<" 2. SIGN-IN"<<endl;
        cout<<"CHOOSE YOUR OPTION...."<<endl;
        cin>>option;
        if (option == 1)
        {
            //ADMIN SIGN-UP
            loadadminfile();
            system("CLS");
            adminsignup();
            saveadminfile();
        }
        else if (option == 2)
        {
            //ADMIN SIGN-IN
            loadadminfile();
            system("CLS");
            mainHeader();
            if (count_admin == 0)
            {
                cout<<" THERE IS NO ADMIN DATA FOUND...... PLEASE SIGN-UP FIRST"<<endl;
                clearscreen();    
            }
            else{
                system("CLS");
                admin = adminSignin();
                if (admin == true)
                {
                    return true;
                }
            }
            
        }
        else{
            cout<<"YOU ENTER AN INVALID INPUT...... PLEASE TRY AGAIN!.."<<endl;
            clearscreen();
        }
    }//END OF WHILE LOOP
    
}//ADMIN LOGIN FUNCTION

bool adminsignup(){
    string name ;
    string password ;
    while(true){
        mainHeader();
        cout<<"ADMIN-SIGN-UP :"<<endl;
        cout<<"------------------>"<<endl;
        cout<<" ENTER THE ADMIN NAME (WITHOUT SPACES): \t";
        cin>>name;
        cout<<" ENTER THE PASSWORD (WITHOUT SPACES): \t";
        cin>>password;
        putadminArray( name, password);
        cout<<"YOUR NAME AND PASSWORD IS SUCESSFULLY SAVED....."<<endl;
        clearscreen();
        break;
    }//END OF WHILE LOOP

}//END OF ADMIN SIGN UP

void putadminArray(string adminname, string password){
    adminnameA[count_admin] = adminname;
    PasswordA[count_admin] = password;
    count_admin ++;
}


int who(){
    while (true)
    {
        mainHeader();
        cout<<" SIGN-IN  :"<<endl;
        cout<<" ----------------> "<<endl;
        cout<<" 1. ADMIN "<<endl;
        cout<<" 2. EMPLOYEE "<<endl;
        cout<<" 3. CUSTOMER "<<endl;
        cout<<" 4. EXIT "<<endl;
        cout<<"CHOOSE YOUR OPTION ........."<<endl;
        cin>>option;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            return option;
        }
        else{
            cout<<"YOU ENTER AN INVALID INPUT"<<endl;
            clearscreen();
        }
    }//END OF WHILE LOOP
}//END OF WHO LOOP

bool adminSignin(){
    string name ;
    string password ;
    while(true){
        mainHeader();
        cout<<"ADMIN-SIGN-IN :"<<endl;
        cout<<"------------------>"<<endl;
        cout<<" ADMINNAME : \t";
        cin>>name;
        cout<<" PASSWORD : \t";
        cin>>password;
        for (int i = 0; i < count_admin; i++)
        {
            if (name == adminnameA[i] && password == PasswordA[i])
            {
                return true;
            }    
        }
        cout<<"YOU ENTER WRONG USERNAME OR PASSWORD..... TRY AGAIN!"<<endl;
        clearscreen();
    }//END OF WHILE LOOP
    
}//END OF ADMIN SIGN IN

int adminMenu(){
    while (true)
    {
        mainHeader();
        cout<<" ADMIN MAIN MENU :"<<endl;
        cout<<"--------------------------------->"<<endl;
        cout<<" 1. REGISTER EMPLOYEE "<<endl;
        cout<<" 2. UPDATE EMPLOYEE INFORMATION "<<endl;
        cout<<" 3. DELETE EMPLOYEE INFORMATION "<<endl;
        cout<<" 4. VIEW EMPLOYEE INFORMATION "<<endl;
        cout<<" 5. MANAGE RESTAURANT EXPENSES "<<endl;
        cout<<" 6. CHECK EMPLOYEE ATTENDENCE "<<endl;
        cout<<" 7. CHANGE USERNAME AND PASSWORD "<<endl;
        cout<<" 8. LOGOUT "<<endl;
        cout<<" CHOOSE YOUR OPTION..... "<<endl;
        cin>>option;
        if (option == 1 ||option == 2 ||option == 3 ||option == 4 ||option == 5 ||option == 6 ||option == 7 ||option == 8 )
        {
            return option;
        }
        else{
            cout<<"YOU ENTER THE INVALID INPUT......... TRY AGAIN!"<<endl;
            clearscreen();
        }
    }//END OF WHILE LOOP
    
    
}//END OF ADMIN MENU LOOP

void addEmployee(){
    bool isCnic = false;
    bool ismobileNo = false;
    string name,fname,cnic,mobile_no,job;
    float salary;
    if (count_employee < MAX_RECORDS)
    {
        while (true)
        {
            mainHeader();
            cout<<"REGISTER EMPLOYEE : "<<endl;
            cout<<"---------------------------->"<<endl;
            cout<<"ENTER THE NAME OF EMPLOYEE :";
            cin>>name;
            cout<<"ENTER THE FATHER NAME OF EMPLOYEE :";
            cin>>fname;
            while (true)
            {
                cout<<"ENTER THE CNINC OF EMPLOYEE(WITH DASHES) :";
                cin>>cnic;
                isCnic = countCnic(cnic);
                if (isCnic == true)
                {
                    break;
                }
                cout<<"YOU ENTER AN INVALID CNIC NUMBER....... PLEASE TRY AGAIN!"<<endl;
            }//end of while loop
            while (true)
            {
                cout<<"ENTER THE MOBILE-NO OF EMPLOYEE :";
                cin>>mobile_no;
                ismobileNo = countMobileno(mobile_no);
                if (ismobileNo == true)
                {
                    break;
                }
                cout<<"YOU ENTER AN INVALID MOBILE NUMBER....... PLEASE TRY AGAIN!"<<endl;
                
            }//end of while loop
            while (true)
            {
                cout<<"ENTER THE SALARY OF EMPLOYEE :";
                cin>>salary;
                if (salary > 0 && salary <= 100000)
                {
                    break;
                }
                cout<<"YOU ENTER AN INVALID VALUE................ PLEASE TRY AGAIN!"<<endl;
            }//end of while loop
            while (true)
            {
                cout<<"ENTER THE JOB OF EMPLOYEE(GUARD,WAITER,CHEF) :";
                cin>>job;
                if (job == "Guard" || job == "GUARD" || job == "guard")
                {
                    securitydepartment[count_security] = count_employee;
                    count_security = count_security + 1;
                    break;
                }
                else if (job == "WAITER" || job == "Waiter" || job == "waiter")
                {
                    waiterdepartment[count_waiter] = count_employee;
                    count_waiter = count_waiter + 1;
                    break;
                }
                else if (job == "CHEF" || job == "Chef" || job == "chef")
                {
                    chefdepartment[count_chef] = count_employee;
                    count_chef = count_chef + 1;
                    break;
                }
                cout<<"YOU ENTER AN INVALID JOB....... PLEASE TRY AGAIN!"<<endl;
            }//end of while loop
            putintoArray(name,fname,cnic,mobile_no,salary,job);
            clearscreen();
            break;
        }
        
    }
    else 
    {
        mainHeader();
        cout<<"REGISTER EMPLOYEE :"<<endl;
        cout<<"----------------------------->"<<endl;
        cout<<"                                  "<<endl;
        cout<<"THERE IS NO MORE SPACE TO ADD THE EMPLOYEE RECORDS......"<<endl;
        clearscreen();
    }
    
    
}//END OF REGISTER EMPLOYEE FUNCTION

void putintoArray(string name,string fname,string cnic, string mobile_no,float salary, string job){
    employeeNameA[count_employee] = name;
    employeeFNameA[count_employee] = fname;
    employeeCnicA[count_employee] = cnic;
    employeePhoneA[count_employee] = mobile_no;
    employeeSalaryA[count_employee] = salary;
    employeedupSalaryA[count_employee] = salary;
    employeeJobA[count_employee] = job;
    count_employee = count_employee + 1;
}//END OF PUTINTO ARRAY FUNCTION

void updateEmployee(){
    bool isCnic = false;
    bool ismobileNo = false;
    bool check = false;
    string ename,efname,ecnic,emobile_no,ejob;
    float esalary;
    int index = 0;
    if (count_employee != 0)
    {
        mainHeader();
        cout<<"UPDATE EMPLOYEE INFORMATION : "<<endl;
        cout<<"----------------------------------->"<<endl;
        cout<<"ENTER THE NAME OF EMPLOYEE :"<<endl;
        cin>>ename;
        cout<<"ENTER THE FATHER NAME OF EMPLOYEE :"<<endl;
        cin>>efname;
        for (int i = 0; i < count_employee; i++)
        {
            if (ename == employeeNameA[i] && efname == employeeFNameA[i])
            {
                view(employeeFNameA[i],employeeCnicA[i],employeePhoneA[i],employeeSalaryA[i],employeeJobA[i]);
                cout<<"---------------------------------------------------->"<<endl;
                cout<<"NOW UPDATE THE INFORMATION :"<<endl;
                index = i;
                cout<<"ENTER THE NAME OF EMPLOYEE :";
                cin>>ename;
                cout<<"ENTER THE FATHER NAME OF EMPLOYEE :";
                cin>>efname;
                while (true)
                {
                    cout<<"ENTER THE CNIC OF EMPLOYEE :";
                    cin>>ecnic;
                    isCnic = countCnic(ecnic);
                    if (isCnic == true)
                    {
                        break;
                    }
                    cout<<"YOU ENTER AN INVALID CNIC NUMBER...... PLEASE TRY AGAIN!"<<endl;
                    
                }//end of while loop
                while (true)
                {
                    cout<<"ENTER THE MOBILE-NO OF EMPLOYEE :";
                    cin>>emobile_no;
                    ismobileNo = countMobileno(emobile_no);
                    if (ismobileNo == true)
                    {
                        break;
                    }
                    cout<<"YOU ENTER AN INVALID MOBILE NUMBER..... PLEASE TRY AGAIN!"<<endl;
                }//end of while loop
                while (true)
                {
                    cout<<"ENTER THE SALARY OF EMPLOYEE :";
                    cin>>esalary;
                    if (esalary > 0 && esalary <= 100000)
                    {
                        break;
                    }
                    cout<<"YOU ENTER AN INVALID VALUE...... PLEASE TRY AGAIN!"<<endl;
                }//end of while loop
                checkjob(index);
                while (true)
                {
                    cout<<"ENTER THE JOB OF EMPLOYEE :";
                    cin>>ejob;
                    if (ejob == "Guard" || ejob == "GUARD" || ejob == "guard")
                    {
                        securitydepartment[count_security] = index;
                        count_security = count_security + 1;
                        break;
                    }
                    else if (ejob == "WAITER" || ejob == "Waiter" || ejob == "waiter")
                    {
                        waiterdepartment[count_waiter] = index;
                        count_waiter = count_waiter + 1;
                        break;
                    }
                    else if (ejob == "CHEF" || ejob == "Chef" || ejob == "chef")
                    {
                        chefdepartment[count_chef] = index;
                        count_chef = count_chef + 1;
                        break;
                    }
                    cout<<"YOU ENTER AN INVALID JOB....... PLEASE TRY AGAIN!"<<endl;
                }//end of while loop
                check = true;
                updateInfo(ename,efname,ecnic,emobile_no,esalary,ejob,index);
                clearscreen();
                break;            
            }

            
        }//END OF FOR LOOP
        if (check == false)
        {
            cout<<"YOU ENTER WRONG NAME OR FATHER NAME....."<<endl;
            clearscreen();
        }
        
    }
    else{
        mainHeader();
        cout<<"UPDATE EMPLOYEE INFORMATION :"<<endl;
        cout<<"------------------------------------>"<<endl;
        cout<<"                                              "<<endl;
        cout<<"SORRY THERE IS NO RECORD FOUND......."<<endl;
        clearscreen();
    }
    
}//END OF UPDATE EMPLOYEE INFORMATION FUNCTION

void checkjob(int field){
    int index = field;
    if (employeeJobA[field] == "Guard" || employeeJobA[field] == "GUARD" || employeeJobA[field] == "guard")
    {
        delsecurity(index);
    }
    else if (employeeJobA[field] == "Chef" || employeeJobA[field] == "CHEF" || employeeJobA[field] == "chef")
    {
        delchef(index);
    }
    else if (employeeJobA[field] == "Waiter" || employeeJobA[field] == "WAITER" || employeeJobA[field] == "waiter")
    {
        delwaiter(index);
    }
    
    
}//END OF CHECKJOB FUNCTION 


void view(string fname,string cnic,string phone,float salary, string job){
    cout<<"FATHER NAME OF EMPLOYEE :\t"<<fname<<endl;
    cout<<"CNIC OF EMPLOYEE :\t"<<cnic<<endl;
    cout<<"MOBILE-NO OF EMPLOYEE :\t"<<phone<<endl;
    cout<<"SALARY OF EMPLOYEE :\t"<<salary<<endl;
    cout<<"JOB OF EMPLOYEE :\t"<<job<<endl;
    cout<<"                                                 "<<endl;
}//END OF VIEW EMPLOYEE INFO FUNCTION

void updateInfo(string name,string fname,string cnic, string mobile_no,float salary, string job,int field){
    employeeNameA[field] = name;
    employeeFNameA[field] = fname;
    employeeCnicA[field] = cnic;
    employeePhoneA[field] = mobile_no;
    for (int i = 0; i < count_employee; i++)
    {
        if (employeeSalaryA[field] == employeedupSalaryA[i])
        {
            employeedupSalaryA[i] = salary;
            break;
        }
        
    }
    employeeSalaryA[field] = salary;
    employeeJobA[field] = job;
}//END OF UPDATEINFO FUNCTION



void deleteEmployee(){
    string ename,efname;
    bool check = false;
    if (count_employee != 0)
    {
        mainHeader();
        cout<<"DELETE EMPLOYEE INFORMATION : "<<endl;
        cout<<"------------------------------------>"<<endl;
        cout<<"ENTER THE NAME OF EMPLOYEE : ";
        cin>>ename;
        cout<<"ENTER THE FATHER NAME OF EMPLOYEE :";
        cin>>efname;
        for (int i = 0; i < count_employee; i++)
        {
            if (ename == employeeNameA[i] && efname == employeeFNameA[i])
            {
                int index = i;
                view(employeeFNameA[i],employeeCnicA[i],employeePhoneA[i],employeeSalaryA[i],employeeJobA[i]);
                delEmpinfo(index);
                cout<<"THE INFORMATION OF EMPLOYEE HAVE BEEN DELETED SUCCESSFULLY....."<<endl;
                check = true;
                getch();
                system("CLS");
                break;
            }
            
        }
        if (check = false)
        {
            cout<<"YOU ENTER WRONG NAME OR FATHER NAME....."<<endl;
            getch();
            system("CLS");    
        }
        
        
    }
    else{
        mainHeader();
        cout<<"DELETE EMPLOYEE INFORMATION : "<<endl;
        cout<<"------------------------------------>"<<endl;
        cout<<"                           "<<endl;
        cout<<"SORRY THERE IS NO RECORD FOUND........"<<endl;
        clearscreen();
    }
    
}//END OF DELETE EMPLOYEE INFORMATION FUNCTION

void delEmpinfo(int field){
    int p = 0;
    for (int i = field; i < count_employee; i++)
    {
        employeeNameA[i] = employeeNameA[i+1];
        employeeFNameA[i] = employeeFNameA[i+1];
        employeeCnicA[i] = employeeCnicA[i+1];
        employeePhoneA[i] = employeePhoneA[i+1];
        for (int j = 0; j < count_employee; j++)
        {
            if (p == 1)
            {
                break;
            }
            if (employeeSalaryA[i] == employeedupSalaryA[j])
            {
                int index = j;
                updatedupSal(index);
                p = 1;
                break;
            }
            
        }
        employeeSalaryA[i] = employeeSalaryA[i+1];
        checkjob(i);
        employeeJobA[i] = employeeJobA[i+1];
    }
    count_employee = count_employee - 1;
}//END OF DELEMPINFO FUNCTION 

void updatedupSal(int field){
    for (int i = field; i < count_employee; i++)
    {
        employeedupSalaryA[i] = employeedupSalaryA[i+1];
    }
    
}




void delchef(int field){
    for (int i = 0; i < count_chef; i++)
    {
        if (field == chefdepartment[i])
        {
            int value = i;
            updatechefdepartment(value);
            break;
        }
        
    }
    
}//END OF DELCHEF FUNCTION

void delwaiter(int field){
    for (int i = 0; i < count_waiter; i++)
    {
        if (field == waiterdepartment[i])
        {
            int value = i;
            updatewaiterdepartment(value);
            break;
        }
        
    }
    
}//END OF DELWAITER FUNCTION

void delsecurity(int field){
    for (int i = 0; i < count_security; i++)
    {
        if (field == securitydepartment[i])
        {
            int value = i;
            updatesecuritydepartment(value);
            break;
        }
        
    }
    
}//END OF DELSECURITY FUNCTION



void updatechefdepartment(int field){
    for (int i = field; i < count_chef; i++)
    {
        chefdepartment[i] = chefdepartment[i+1];
    }
    count_chef = count_chef - 1;
}//END OF UPDATE CHEFDEPARTMENT FUNCTION

void updatewaiterdepartment(int field){
    for (int i = field; i < count_waiter; i++)
    {
        waiterdepartment[i] = waiterdepartment[i+1];
    }
    count_waiter = count_waiter - 1;
}//END OF UPDATE CHEFDEPARTMENT FUNCTION

void updatesecuritydepartment(int field){
    for (int i = field; i < count_security; i++)
    {
        securitydepartment[i] = securitydepartment[i+1];
    }
    count_security = count_security - 1;
}//END OF UPDATE CHEFDEPARTMENT FUNCTION

void viewEmployeeInfo(){
    if (count_employee != 0)
    {
        while (true)
        {
            mainHeader();
            cout<<"VIEW EMPLOYEE INFORMATION :"<<endl;
            cout<<"----------------------------------->"<<endl;
            cout<<" 1. VIEW ONE EMPLOYEE INFORMATION "<<endl;
            cout<<" 2. VIEW ALL EMPLOYEES INFORMATION "<<endl;
            cout<<" 3. VIEW SECURITY GUARD DEPARTMENT INFORMATION "<<endl;
            cout<<" 4. VIEW WAITER DEAPARTMENT INFORMATION "<<endl;
            cout<<" 5. VIEW CHEF DEPARTMENT INFORMATION "<<endl;
            cout<<" 6. EXIT "<<endl;
            cout<<"CHOOSE YOUR OPTION....."<<endl;
            cin>>option;
            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
            {
                if (option == 1)
                {
                    //VIEW ONE EMPLOYEE INFO
                    infoOne();
                }
                else if (option == 2)
                {
                    //VIEW ALL EMPLOYEES INFO
                    infoAll();
                }
                else if (option == 3)
                {
                    //VIEW SECURITY DEPARTMENT INFO
                    viewsecurity();
                }
                else if (option == 4)
                {
                    //VIEW WAITER DEPARTMENT INFO
                    viewwaiter();
                }
                else if (option == 5)
                {
                    //VIEW CHIEF DEPARTMENT INFO
                    viewchef();
                }
                else if (option == 6)
                {
                    //EXIT
                    break;
                }
            }
            else
            {
                cout<<"YOU ENTER THE INVALID OPTION....... PLEASE TRY AGAIN!"<<endl;
                clearscreen();
            }
                
        }//end of while loop    
    }
    else{
        mainHeader();
        cout<<"THERE IS NO RECORD FOUND..........."<<endl;
        clearscreen();
    }
   
    
}//END OF VIEW EMPLOYEE INFO FUNCTION


void infoOne(){
    system("CLS");
    while (true)
    {
        mainHeader();
        cout<<"VIEW ONE EMPLOYEE INFORMATION :"<<endl;
        cout<<"--------------------------------------->"<<endl;
        cout<<"ENTER THE NAME OF EMPLOYEE :\t";
        cin>>name;
        int count = 0;
        for (int i = 0; i < count_employee; i++)
        {
            if (name == employeeNameA[i])
            {
                cout<<"FATHER NAME OF EMPLOYEE :\t"<<employeeFNameA[i]<<endl;
                cout<<"                                        "<<endl;
                cout<<"CNIC OF EMPLOYEE :\t"<<employeeCnicA[i]<<endl;
                cout<<"                                        "<<endl;
                cout<<"MOBILE-NO OF EMPLOYEE :\t"<<employeePhoneA[i]<<endl;
                cout<<"                                        "<<endl;
                cout<<"SALARY OF EMPLOYEE :\t"<<employeeSalaryA[i]<<endl;
                cout<<"                                        "<<endl;
                cout<<"JOB OF EMPLOYEE :\t"<<employeeJobA[i]<<endl;
                count++;
                cout<<"                     "<<endl;
            }
        
        }
        if (count == 1)
        {
            clearscreen();
            break;
        }
        else{
            cout<<"YOU ENTER  WRONG NAME OF THE EMPLOYEE..... PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }
        
    }//end of while loop
    
}//END OF VIEW ONE EMPLOYEE INFO FUNCTION

void sort(){
    int largest_idx;
    int temp;
    for (int idx = 0; idx < count_employee; idx = idx + 1)
    {
        largest_idx = largest(idx);
        temp = employeedupSalaryA[largest_idx];
        employeedupSalaryA[largest_idx] = employeedupSalaryA[idx];
        employeedupSalaryA[idx] = temp;
    }
}//END OF SORT FUNCTION

int largest(int s){
    int large = -1;
    int large_index;
    for (int idx = s; idx < count_employee; idx = idx + 1)
    {
        if (large < employeedupSalaryA[idx])
        {
            large = employeedupSalaryA[idx];
            large_index = idx;
        }
    }
    return large_index;
}


void infoAll(){
    system("CLS");
    sort();
    mainHeader();
    cout<<"VIEW ALL EMPLOYEE INFORMATION :"<<endl;
    cout<<"----------------------------------------->"<<endl;
    cout<<"NAME \t\tFATHER NAME\t\t CNIC\t\t PHONE_NO\tSALARY\t\tJOB"<<endl;
    for (int i = 0; i < count_employee; i++)
    {
        for (int j = 0; j < count_employee; j++)
        {
            if (employeeSalaryA[j] == employeedupSalaryA[i])
            {
                cout<<employeeNameA[j]<<"\t\t"<<employeeFNameA[j]<<"\t\t"<<employeeCnicA[j]<<"\t\t"<<employeePhoneA[j]<<"\t"<<employeeSalaryA[j]<<"\t\t"<<employeeJobA[j]<<endl;
            }
            
        }
        
    }
    cout<<"                     "<<endl;
    clearscreen();
}//END OF VIEW ALL EMPLOYEE INFO FUNCTION

void viewchef(){
    system("CLS");
    mainHeader();    
    if (count_chef != 0)
    {
        int index ;
        cout<<"NAME \t\t\tFATHER NAME \t\t\tCNIC\t\t\tPHONE_NO\t\tSALARY\t\tJOB"<<endl;
        for (int i = 0; i < count_chef; i++)
        {
            index = chefdepartment[i];
            cout<<employeeNameA[index]<<"\t\t\t"<<employeeFNameA[index]<<"\t\t\t"<<employeeCnicA[index]<<"\t\t\t"<<employeePhoneA[index]<<"\t\t"<<employeeSalaryA[index]<<"\t\t"<<employeeJobA[index]<<endl;
            
        }
        cout<<"                     "<<endl;
        clearscreen();    
    }
    else{
        cout<<"SORRY THERE IS NO RECORD FOUND........"<<endl;
        clearscreen();
    }
        
}//END OF VIEW CHIEF DEPARTMENT INFO FUNCTION

void viewsecurity(){
    system("CLS");
    mainHeader();
    if (count_security != 0)
    {
        int index ;
        cout<<"NAME\t\t\tFATHER NAME\t\t\t CNIC\t\t\tPHONE_NO\t\t SALARY\t\tJOB"<<endl;
        for (int i = 0; i < count_security; i++)
        {
            index = securitydepartment[i];
            cout<<employeeNameA[index]<<"\t\t\t"<<employeeFNameA[index]<<"\t\t\t"<<employeeCnicA[index]<<"\t\t\t"<<employeePhoneA[index]<<"\t\t"<<employeeSalaryA[index]<<"\t\t"<<employeeJobA[index]<<endl;
               
        }
        cout<<"                     "<<endl;
        clearscreen();    
    }
    else{
        cout<<"SORRY THERE IS NO RECORD FOUND......."<<endl;
        clearscreen();
    }
        
}//END OF VIEW SECURITY DEPARTMENT INFO FUNCTION

void viewwaiter(){
    system("CLS");
    mainHeader();
    if (count_waiter != 0)
    {
        int index ;
        cout<<"NAME \t\t\tFATHER NAME \t\t\tCNIC\t\t\tPHONE_NO \t\tSALARY\t\tJOB"<<endl;
        for (int i = 0; i < count_waiter; i++)
        {
            index = waiterdepartment[i];  
            cout<<employeeNameA[index]<<"\t\t\t"<<employeeFNameA[index]<<"\t\t\t"<<employeeCnicA[index]<<"\t\t\t"<<employeePhoneA[index]<<"\t\t"<<employeeSalaryA[index]<<"\t\t"<<employeeJobA[index]<<endl;

        }
        cout<<"                     "<<endl;
        clearscreen();
    }
    else{
        cout<<"SORRY THERE IS NO RECORD FOUND......."<<endl;
        clearscreen();
    }
        
}//END OF VIEW WAITER DEPARTMENT INFO FUNCTION

void checkattendence(){
    while (true)
    {
        mainHeader();
        cout<<"CHECK EMPLOYEE ATTENDENCE :"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<" 1. VIEW ATTENDENCE"<<endl;
        cout<<" 2. RESET ATTENDENCE"<<endl;
        cout<<" 3. EXIT"<<endl;
        cout<<"CHOOSE YOUR OPTION........"<<endl;
        cin>>option;
        if (option == 1 || option == 2 || option == 3)
        {
            if (option == 1)
            {
                //VIEW ATTENDENCE
                loadattendenceSheet();
                viewattendence();
            }
            else if (option == 2)
            {
                //RESET ATTENDENCE
                system("CLS");
                mainHeader();
                createattendenceSheet();
                saveattendenceSheet();
                cout<<"THE ATTENDENCE SHEET HAS BEEN RESET SUCCESSFULLY...."<<endl;
                clearscreen();
            }
            else if (option == 3)
            {
                //EXIT
                break;
            }
            
            
            
        }
        else{
            cout<<" YOU ENTER AN INVALID OPTION...... PLEASE TRY AGAIN!"<<endl;
        }
    }
    
    
}//END OF CHECK ATTENDANCE FUNCTION

void viewattendence(){
    system("CLS");
    int absent = 0,leave = 0,present = 0;
    mainHeader();
    cout<<"VIEW EMPLOYEE ATTENDENCE :"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<" EMPLOYEE NAME\t\t\tATTENDENCE"<<endl;
    for (int i = 0; i < count_employee; i++)
    {
        cout<<employeeNameA[i]<<"\t\t\t\t"<<attendencesheet[i]<<endl;
        if (attendencesheet[i] == 'P' || attendencesheet[i] == 'p')
        {
            present++;
        }
        if (attendencesheet[i] == 'L' || attendencesheet[i] == 'l')
        {
            leave++;
        }
        if (attendencesheet[i] == '*')
        {
            absent++;
        }
        
    }
    cout<<"                            "<<endl;
    cout<<"\t\t\tTOTAL PRESENT EMPLOYEE IS :"<<present<<endl;
    cout<<"\t\t\tTOTAL ABSENT EMPLOYEE IS :"<<absent<<endl;
    cout<<"\t\t\tTOTAL LEAVE EMPLOYEE IS :"<<leave<<endl;
    clearscreen();
}//END OF VIEW ATTENDANCE FUNCTION

void changePassword(){
    while (true)
    {
        mainHeader();
        cout<<"CHANGE PASSWORDS :"<<endl;
        cout<<"------------------------------>"<<endl;
        cout<<" 1. CHANGE ADMIN USERNAME AND PASSWORD "<<endl;
        cout<<" 2. CHANGE EMPLOYEE USERNAME AND PASSWORD "<<endl;
        cout<<" 3. EXIT "<<endl;
        cout<<"CHOOSE YOUR OPTION...."<<endl;
        cin>>option;
        if (option == 1 || option == 2 || option == 3)
        {
            if (option == 1)
            {
                //CHANGE ADMIN USERNAME AND PASSWORD
                changeUserPass();
            }
            else if (option == 2)
            {
                //CHANGE EMPLOYEE USERNAME AND PASSWORD
                changeEUserpass();
            }
            else if (option == 3)
            {
                //EXIT
                break;
            }
        }
        else{
            cout<<"YOU ENTER AN INVALD INPUT.........PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }
    }
}//END OF CHANGE USERNAME AND PASSWORD

void changeUserPass(){
    int k = 0;
    string name,password;
    while (true)
    {
        system("CLS");
        mainHeader();
        cout<<"CHANGE ADMINNAME AND PASSWORD :"<<endl;
        cout<<"----------------------------------->"<<endl;
        cout<<"ENTER THE PERIVOUS ADMINNAME :"<<endl;
        cin>>name;
        cout<<"ENTER THE PERIVOUS PASSWORD :"<<endl;
        cin>>password;
        for (int i = 0; i < count_admin; i++)
        {
            if (name == adminnameA[i] && password == PasswordA[i])
            {
                system("CLS");
                k++;
                change(i);
                break;
            }    
        }
        if (k == 1)
        {
            break;
        }
        else{
            cout<<"YOU ENTER AN INVALID ADMINNAME OR PASSWORD..... PLEASE TRY AGAIN!"<<endl;
            clearscreen();    
        }    
    }//end of while loop
    

}//END OF USER AND PASSWORD CHANGE FUNCTION



void change(int field){
    system("CLS");
    mainHeader();
    cout<<"CHANGE ADMINNAME AND PASSWORD :"<<endl;
    cout<<"----------------------------------->"<<endl;
    cout<<"ENTER THE NEW ADMINNAME :"<<endl;
    cin >> adminnameA[field];
    cout<<"ENTER THE NEW PASSWORD  :"<<endl;
    cin >> PasswordA[field];
    cout<<"                           "<<endl;
    saveadminfile();
    cout<<"ADMINNAME AND PASSWORD IS SUCCESSFULLY CHANGED...."<<endl;
    clearscreen();
}


void changeEUserpass(){
    int k = 0;
    string name,password;
    while (true)
    {
        system("CLS");
        mainHeader();
        cout<<"CHANGE EMPLOYEE USERNAME AND PASSWORD :"<<endl;
        cout<<"----------------------------------->"<<endl;
        cout<<"ENTER THE PERIVOUS USERNAME :"<<endl;
        cin>>name;
        cout<<"ENTER THE PERIVOUS PASSWORD :"<<endl;
        cin>>password;
        if (name == EmployeName && password == Epassword)
        {
            system("CLS");
            k++;
            //Change Employee Username and Password
            changeE();
            break;
        }    
        if (k == 1)
        {
            break;
        }
        else{
            cout<<"YOU ENTER AN INVALID ADMINNAME OR PASSWORD..... PLEASE TRY AGAIN!"<<endl;
            clearscreen();    
        }    
    }//end of while loop
}//END OF EMPLOYEE USERNAME AND PASSWORD

void changeE(){
    system("CLS");
    mainHeader();
    cout<<"ENTER THE NEW USERNAME :"<<endl;
    cin>>EmployeName;
    cout<<"ENTER THE NEW PASSWORD : "<<endl;
    cin>>Epassword;
    cout<<"THE EMPLOYEE USERNAME AND PASSWORD HAS BEEN SUCCESSFULLY CHANGED...."<<endl;
    clearscreen(); 
}

void managerestaurantexpenses(){
    while (true)
    {
        system("CLS");
        mainHeader();
        cout<<"MANAGE RESTAURANT EXPENSES"<<endl;
        cout<<"------------------------------->"<<endl;
        cout<<" 1. CHECK TOTAL SALES OF FOOD ITEM "<<endl;
        cout<<" 2. CHECK SALE QUANTITY OF FOOD ITEM "<<endl;
        cout<<" 3. GIVE DISCOUNT "<<endl;
        cout<<" 4. VIEW CUSTOMER BILL HISTORY "<<endl;
        cout<<" 5. GIVE EMPLOYEE SALARY "<<endl;
        cout<<" 6. RESET EMPLOYEE SALARY STATUS "<<endl;
        cout<<" 7. EXIT"<<endl;
        cout<<"CHOOSE YOUR OPTION......."<<endl;
        cin>>option;
        if (option == 1 || option == 2 || option == 3 || option == 4 ||option == 5 ||option == 6 ||option == 7)
        {
            if (option == 1)
            {
                //TOTAL SALES OF TODAY
                salesquantityprice();
            }
            else if (option == 2)
            {
                //SALE QUANTITY
                checksalesquantity();
            }
            else if (option == 3)
            {
                //GIVE DISCOUNT
                giveDiscount();
            }
            else if (option == 4)
            {
                //view customer bill history
                customerbillhistory();
            }
            else if (option == 5)
            {
                //GIVE SALARY
                giveSalary();
            }
            else if (option == 6)
            {
                //RESET EMPLOYEE SALARY STATUS
                resetEmployeestat();
            }
            
            else if (option == 7)
            {
                //EXIT
                break;
            }
            
        }
        else{
            cout<<"YOU ENTER AN INAVALID INPUT...... PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }    
    }
    
}//END OF MANAGE EXPENSES FUNCTION



void resetEmployeestat(){
    mainHeader();
    cout<<"RESET EMPLOYEE SALARY STATUS :"<<endl;
    cout<<"------------------------------------->"<<endl;
    for (int i = 0; i < MAX_RECORDS; i++)
    {
        salaryStatus[i] = false;
    }
    cout<<"                               "<<endl;
    cout<<"THE EMPLOYEE SALARY STATUS HAS BEEN RESET SUCCESSFULLY "<<endl;
    getch();
    system("CLS");
}//END OF RESET EMPLOYEE STATUS FUNCTION

void customerbillhistory(){
    system("CLS");
    mainHeader();
    if (count_customer != 0)
    { 
        cout<<"CUSTOMER BILL HISTORY :"<<endl;
        cout<<"------------------------->"<<endl;
        cout<<"NAME \t\tTOTAL BILL"<<endl;
        for (int i = 0; i < count_customer; i++)
        {
            cout<<customernameA[i] <<" \t\t\t" <<totalbill[i]<<endl;
        }
        clearscreen();
    }
    else{
        cout<<"SORRY THERE IS NO RECORD FOUND......"<<endl;
        clearscreen();
    }
    
}//END OF CUSTOMER BILL HISTORY FUNCTION



void checksalesquantity(){
    system("CLS");
    mainHeader();
    cout<<"CHECK SALES QUANTITY :"<<endl;
    cout<<"------------------------->"<<endl;
    cout<<"ITEM NAME\t\tQUANTITY_SALE"<<endl;
    for (int i = 0; i < 14; i++)
    {
        if ( i != 2 && i != 9 && i != 11 && i != 12 && i != 13)
        {
            cout<<i<<". "<<Menu[i]<<"\t\t"<<checksalequantity[i]<<endl;
        }
        if ( i == 2 || i == 9 || i == 11 || i == 12 || i == 13)
        {
            cout<<i<<". "<<Menu[i]<<"\t\t\t"<<checksalequantity[i]<<endl;
        }
            
    }
    cout<<"                       "<<endl;
    clearscreen();
}//END OF CHECK SALES QUANTITY FUNCTION

void salesquantityprice(){
    system("CLS");
    mainHeader();
    cout<<"CHECK SALES QUANTITY :"<<endl;
    cout<<"------------------------->"<<endl;
    cout<<"ITEM NAME\t\tQUANTITY_SALE\t\tPRICE"<<endl;
    for (int i = 0; i < 14; i++)
    {
        if (i != 2 && i != 9 && i != 11 && i != 12 && i != 13)
        {
            cout<<i<<". "<<Menu[i]<<"\t\t"<<checksalequantity[i]<<"\t\t"<<price[i]*checksalequantity[i]<<endl;    
        }
        if (i == 2 || i == 9 || i == 11 || i == 12 || i == 13)
        {
            cout<<i<<". "<<Menu[i]<<"\t\t\t"<<checksalequantity[i]<<"\t\t"<<price[i]*checksalequantity[i]<<endl;
        }
        
    }
    cout<<"                       "<<endl;
    clearscreen();
}//END OF SALES QUANTITY FUNCTION 



void giveDiscount(){

    system("CLS");
    mainHeader();
    cout<<"GIVE DISCOUNT :"<<endl;
    cout<<"------------------------->"<<endl;
    cout<<"ENTER DISCOUNT PERCENTAGE :"<<endl;
    cin >> discountpercent;
    cout<<"ENTER THE QUANTITY ON WHICH DISCOUNT APPLY :"<<endl;
    cin >> discountquantity;
    discount = true;
    clearscreen();    
    
    
}//END OF GIVE DISCOUNT FUNCTION


void giveSalary(){
    string ename, fthname;
    int p = 0;
    system("CLS");
    mainHeader();
    while (true)
    {
        cout<<"GIVE EMPLOYEE SALARY :"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"ENTER THE NAME OF THE EMPLOYEE :"<<endl;
        cin>>ename;
        cout<<"ENTER THE FATHER NAME OF EMPLOYEE : "<<endl;
        cin>>fthname;
        for (int i = 0; i < count_employee; i++)
        {
            if (ename == employeeNameA[i] && fthname == employeeFNameA[i])
            {
                salaryStatus[i] = true;
                p++;
                cout<<"EMPLOYEE SALARY HAS BEEN TRANSFERED SUCCESSFULLY....."<<endl;
                clearscreen();
            }
        
        }
        if (p == 0)
        {
            cout<<"YOU ENTER AN INVALID EMPLOYEE NAME OR FATHER NAME.... PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }
        else if (p == 1)
        {
            break;
        }
        
    }
    
    
}


void employeelogin(){
    while (true)
    {
        string ename,epassword;
        mainHeader();
        cout<<"EMPLOYEE LOGIN :"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"ENTER USERNAME :\t";
        cin>>ename;
        cout<<"ENTER PASSWORD :\t";
        cin>>epassword;
        if (ename == EmployeName && epassword == Epassword)
        {
            break;
        }
        else{
            cout<<"YOU ENTER AN INVALID PASSWORD ......"<<endl;
            clearscreen();
        }
    }
}//END OF EMPLOYEE LOGIN


int EmployeeMenu(){
    mainHeader();
    while (true)
    {
        cout<<"EMPLOYEE MAIN MENU :"<<endl;
        cout<<"---------------------------------->"<<endl;
        cout<<" 1. GIVE ATTENDENCE"<<endl;
        cout<<" 2. CHECK SALARY STATUS"<<endl;
        cout<<" 3. EXIT"<<endl;
        cout<<"CHOOSE YOUR OPTION......"<<endl;
        cin>>option;
        if (option == 1 || option == 2 || option == 3)
        {
            return option;
        }
        else{
            cout<<"YOU ENTER AN INVALID INPUT...... PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }
    } 
}//END OF EMPLOYEE MAIN MENU

void giveAttendence(){
    string ename,fthname;
    int  p = 0 ,index;
    char options = ' ';
    mainHeader();
    cout<<" GIVE ATTENDENCE : "<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"ENTER YOUR NAME :"<<endl;
    cin>>ename;
    cout<<"ENTER YOUR FATHER NAME :"<<endl;
    cin>>fthname;
    for (int i = 0; i < count_employee; i++)
    {
        if (employeeNameA[i] == ename && employeeFNameA[i] == fthname)
        {
            if (attendencesheet[i] != 'P' && attendencesheet[i] != 'P' && attendencesheet[i] != 'L')
            {
                while (true)
                {
                    index = i;    
                    cout<<"PRESS 'P' FOR PRESENT OR 'L' FOR LEAVE ......"<<endl;
                    cin>>options;
                    if (options == 'P' || options == 'p')
                    {
                        attendencesheet[index] = 'P';
                        p++;
                        clearscreen();
                        break;
                    }
                    else if (options == 'L')
                    {
                        attendencesheet[index] = 'L';
                        p++;
                        clearscreen();
                        break;
                    }
                    else{
                        cout<<"YOU ENTER AN INVALID INPUT"<<endl;
                    }
                }//end of while loop
            }
            else{
                cout<<"YOU HAVE ALREADY GIVE YOUR ATTENDENCE....."<<endl;
                getch();
                system("CLS");
                break;
            }
            
            
        }
        
    }
    if (p == 0)
    {
        cout<<"YOUR NAME DOES NOT EXIST IN ATTENDENCE SHEET....."<<endl;
        clearscreen();
    }
    if (p == 1)
    {
        cout<<"YOUR ATTENDENCE HAVE BEEN MARKED"<<endl;
        clearscreen();
    }
    
}//END OF GIVE ATTENDANCE FUNCTION

void checkSalaryStatus(){
    string ename,fthname;
    mainHeader();
    cout<<"CHECK SALARY STATUS : "<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"ENTER YOUR NAME :"<<endl;
    cin>>ename;
    cout<<"ENTER YOUR FATHER NAME :"<<endl;
    cin>>fthname;
    for (int i = 0; i < count_employee; i++)
    {
        if (ename == employeeNameA[i] && fthname == employeeFNameA[i])
        {
            if (salaryStatus[i] == true)
            {
                cout<<"YOUR SALARY HAS BEEN TRANSFERED INTO YOUR BANK ACCOUNT..."<<endl;
                clearscreen();
            }
            else if (salaryStatus[i] == false)
            {
                cout<<"YOUR SALARY HAS NOT BEEN GIVEN BY THE OWNER...."<<endl;
                clearscreen();
            }
            
        }
        
    }
    
}//END OF CHECK SALARY STATUS


int customerMenu(){
    while (true)
    {
        mainHeader();
        cout<<"CUSTOMER MAIN MENU :"<<endl;
        cout<<"___________________________________________"<<endl;
        recommendation();
        cout<<"                                                                                                  "<<endl;
        cout<<" 1. VIEW FOOD MENU "<<endl;
        cout<<" 2. ORDER FOOD"<<endl;
        cout<<" 3. DEPOSIT BILL"<<endl;
        cout<<" 4. EXIT"<<endl;
        cout<<"CHOOSE YOUR OPTION......."<<endl;
        cin>>option;
        if (option == 1 || option == 2 || option == 3 || option == 4)
        {
            return option;
        }
        else{
            cout<<"YOU ENTER AN INVALID INPUT....... PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }    
    }//end of while loop
}//END OF CUSTOMER MAIN MENU FUNCTION

void viewFoodMenu(){
    mainHeader();
    cout<<"VIEW FOOD ITEM MENU :"<<endl;
    cout<<"----------------------------->"<<endl;
    cout<<" 1. PIZZA"<<endl;
    cout<<"\t\t 1. "<<Menu[0]<<endl;
    cout<<"\t\t 2. "<<Menu[1]<<endl;
    cout<<"\t\t 3. "<<Menu[2]<<endl;
    cout<<" 2. BURGER"<<endl;
    cout<<"\t\t 1. "<<Menu[3]<<endl;
    cout<<"\t\t 2. "<<Menu[4]<<endl;
    cout<<"\t\t 3. "<<Menu[5]<<endl;
    cout<<" 3. ICE CREAM"<<endl;
    cout<<"\t\t 1. "<<Menu[6]<<endl;
    cout<<"\t\t 2. "<<Menu[7]<<endl;
    cout<<" 4. CAKE"<<endl;
    cout<<"\t\t 1. "<<Menu[8]<<endl;
    cout<<"\t\t 2. "<<Menu[9]<<endl;
    cout<<"\t\t 3. "<<Menu[10]<<endl;
    cout<<" 5. DRINKS"<<endl;
    cout<<"\t\t 1. "<<Menu[11]<<endl;
    cout<<"\t\t 2. "<<Menu[12]<<endl;
    cout<<"\t\t 3. "<<Menu[13]<<endl;
    cout<<"                  "<<endl;
    clearscreen();
              
}//END OF VIEW FOOD MENU FUNCTION

void getcustomername(){
    mainHeader();
    string line;
    cout<<"PLEASE ENTER YOUR NAME(WITHOUT SPACE) :"<<endl;
    cin >> line;
    putintoCustArray(line);
}

void putintoCustArray(string line){
    if (count_customer < MAX_RECORDS)
    {
        customernameA[count_customer] = line;
        count_customer = count_customer + 1;
    }
    else{
        cout<<"RESTAURANT IS CLOSED........."<<endl;
        clearscreen();
    }
}//END OF GET CUSTOMER NAME FUNCTION

void orderFood(){
    while (true)
    {
        system("CLS");
        if (n < 4)
        {
            mainHeader();
            cout<<"ORDER FOOD :"<<endl;
            cout<<"----------------------->"<<endl;
            cout<<" 1. PIZZA"<<endl;
            cout<<" 2. BURGER"<<endl;
            cout<<" 3. ICE CREAM"<<endl;
            cout<<" 4. CAKE"<<endl;
            cout<<" 5. DRINKS"<<endl;
            cout<<" 6. EXIT"<<endl;
            cout<<"CHOOSE YOUR OPTION......"<<endl;
            cin>>option;
            if (option == 1)
            {
                //PIZZA
                pizza();
            }
            else if (option == 2)
            {
                //BURGER
                burger();
            }
            else if (option == 3)
            {
                //ICE CREAM
                icecream();
            }
            else if (option == 4)
            {   
                //CAKE
                cake();
            }
            else if (option == 5)
            {   
                //DRINKS
                drinks();
            }
            else if (option == 6)
            {   
                //EXIT
                system("CLS");
                break;
            }
            else{
                cout<<"YOU ENTER AN INVALID INPUT........ TRY AGAIN!"<<endl;
                clearscreen();
            }
        }
        else{
            mainHeader();
            cout<<"NOW, YOU CAN'T ORDER MORE THINGS......"<<endl;
            clearscreen();
            break;
        }
        
    }//end of while loop
    
}//END OF ORDER FOOD FUNCTION

void pizza(){
        system("CLS");
        mainHeader();
        cout<<"PIZZA :"<<endl;
        cout<<"------------>"<<endl;
        cout<<"   FOOD NAME\t\t PRICE"<<endl;
        cout<<" 1."<< Menu[0]<<"          "<<price[0]<<endl;
        cout<<" 2."<< Menu[1]<<"        "<<price[1]<<endl;
        cout<<" 3."<< Menu[2]<<"              "<<price[2]<<endl;
        cout<<"CHOOSE YOUR OPTION"<<endl;
        cin>>option1;
        if (option1 == 1)
        {
            while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 1;
                    n++;
                    checksalequantity[0] = checksalequantity[0] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
            
        }
        else if (option1 == 2)
        {
            while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 2;
                    n++;
                    checksalequantity[1] = checksalequantity[1] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
        }
        else if (option1 == 3)
        {
            while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 3;
                    n++;
                    checksalequantity[2] = checksalequantity[2] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
        }
        else{
            cout<<"YOU ENTER AN INVALID INPUT.... PLEASE TRY AGAIN!"<<endl;
            clearscreen();
        }
    
    
}//END OF ORDER PIZZA FUNCTION

void burger(){
    system("CLS");
    mainHeader();
    cout<<"BURGER"<<endl;
    cout<<"------------>"<<endl;
    cout<<"   FOOD NAME\t\t PRICE"<<endl;
    cout<<" 1."<< Menu[3]<<"          "<<price[3]<<endl;
    cout<<" 2."<< Menu[4]<<"         "<<price[4]<<endl;
    cout<<" 3."<< Menu[5]<<"          "<<price[5]<<endl;
    cout<<"CHOOSE YOUR OPTION"<<endl;
    cin>>option1;
    if (option1 == 1)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 4;
                    n++;
                    checksalequantity[3] = checksalequantity[3] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else if (option1 == 2)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 5;
                    n++;
                    checksalequantity[4] = checksalequantity[4] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else if (option1 == 3)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 6;
                    n++;
                    checksalequantity[5] = checksalequantity[5] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else{
        cout<<"YOU ENTER AN INVALID INPUT.... PLEASE TRY AGAIN!"<<endl;
        clearscreen();
    }
}//END OF ORDER BURGER FUNCTION

void drinks(){
    system("CLS");
    mainHeader();
    cout<<"DRINKS"<<endl;
    cout<<"------------->"<<endl;
    cout<<"   FOOD NAME\t\t PRICE"<<endl;
    cout<<" 1."<< Menu[11]<<"              "<<price[11]<<endl;
    cout<<" 2."<< Menu[12]<<"                 "<<price[12]<<endl;
    cout<<" 3."<< Menu[13]<<"                   "<<price[13]<<endl;
    cout<<"CHOOSE YOUR OPTION"<<endl;
    cin>>option1;
    if (option1 == 1)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 12;
                    n++;
                    checksalequantity[11] = checksalequantity[11] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else if (option1 == 2)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 13;
                    n++;
                    checksalequantity[12] = checksalequantity[12] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else if (option1 == 3)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 14;
                    n++;
                    checksalequantity[13] = checksalequantity[13] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else{
        cout<<"YOU ENTER AN INVALID INPUT.... PLEASE TRY AGAIN!"<<endl;
        clearscreen();
    }
}//END OF ORDER DRINKS FUNCTION

void icecream(){
    system("CLS");
    mainHeader();
    cout<<"ICE CREAM"<<endl;
    cout<<"------------->"<<endl;
    cout<<"   FOOD NAME\t\t\t PRICE"<<endl;
    cout<<" 1."<< Menu[6]<<"            "<<price[6]<<endl;
    cout<<" 2."<< Menu[7]<<"            "<<price[7]<<endl;
    cout<<"CHOOSE YOUR OPTION"<<endl;
    cin>>option1;
    if (option1 == 1)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 7;
                    n++;
                    checksalequantity[6] = checksalequantity[6] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else if (option1 == 2)
    {
        while (true)
            {
                cout<<"ENTER THE QUANTITY :";
                cin>>quantity;
                if (quantity >= 0)
                {
                    quantityA[n] = quantity;
                    optionindex[n] = 8;
                    n++;
                    checksalequantity[7] = checksalequantity[7] + quantity;
                    break;    
                }
                else{
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
                }
                
            }
    }
    else{
        cout<<"YOU ENTER AN INVALID INPUT.... PLEASE TRY AGAIN!"<<endl;
        clearscreen();
    }
}//END OF ORDER ICE CREAM FUNCTION 

void cake(){
    system("CLS");
    mainHeader();
    cout<<"CAKE"<<endl;
    cout<<"------------->"<<endl;
    cout<<"   FOOD NAME\t\t PRICE"<<endl;
    cout<<" 1."<< Menu[8]<<"         "<<price[8]<<endl;
    cout<<" 2."<< Menu[9]<<"           "<<price[9]<<endl;
    cout<<" 3."<< Menu[10]<<"         "<<price[10]<<endl;
    cout<<"CHOOSE YOUR OPTION"<<endl;
    cin>>option1;
    if (option1 == 1)
    {
        while (true)
        {
            cout<<"ENTER THE QUANTITY :";
            cin>>quantity;
            if (quantity >= 0)
            {
                quantityA[n] = quantity;
                optionindex[n] = 9;
                n++;
                checksalequantity[8] = checksalequantity[8] + quantity;
                break;    
            }
            else
            {
                    cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
            }
        }
        
        
        
    }
    else if (option1 == 2)
    {
        while (true)
        {
            cout<<"ENTER THE QUANTITY :";
            cin>>quantity;
            if (quantity >= 0)
            {
                quantityA[n] = quantity;
                optionindex[n] = 10;
                n++;
                checksalequantity[9] = checksalequantity[9] + quantity;
                break;
            }
            else{
                cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
            }
        
        
        }
        
    }
    else if (option1 == 3)
    {
        while (true)
        {
            cout<<"ENTER THE QUANTITY :";
            cin>>quantity;
            if (quantity >= 0)
            {
                quantityA[n] = quantity;
                optionindex[n] = 11;
                n++;
                checksalequantity[10] = checksalequantity[10] + quantity;
                break;    
            }
            else{
                cout<<"YOU ENTER AN INVALID INPUT......"<<endl;
            }    
        }
        
        
        
    }
    else{
        cout<<"YOU ENTER AN INVALID INPUT.... PLEASE TRY AGAIN!"<<endl;
        clearscreen();
    }
}//END OF ORDER CAKE FUNCTION


void depositBill(){
    system("CLS");
    mainHeader();
    calculateBill();
    if (totalperitem[0] != 0)
    {
        cout<<"DEPOSIT BILL"<<endl;
        cout<<"---------------------->"<<endl;
        cout<<"YOUR NAME :\t"<<customernameA[count_customer-1]<<endl;
        cout<<"YOUR ORDER LIST IS BELOW:"<<endl;
        cout<<"---------------------------------------"<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<i+1<<". "<<Menu[optionindex[i]-1] <<"\t\t"<<totalperitem[i]<<endl;
        }
        cout<<"---------------------------------------"<<endl;
        cout<<"\t\tYOUR TOTAL BILL IS "<<customerbill<<endl;
        if (discount == true)
        {
            if (dispriceA[count_customer-1] != 0)
            {
                cout<<"\t\tYOUR TOTAL BILL AFTER DISCOUNT IS "<<dispriceA[count_customer-1]<<endl;    
            }
            
        }
        totalbill[count_customer -1] = customerbill ;
        savecustomerfile();
        cout<<"                                             "<<endl;
        cout<<"THANKS FOR VISITING OUR RESTAURANT....."<<endl;
        clearscreen();
    }
    else{
        cout<<"YOU DON'T BUY ANYTHING YET......."<<endl;
        clearscreen();
    }
    
}//END OF DEPOSIT BILL FUNCTION

void calculateBill(){
    float dis1,dis2,dis3,dis4;
    totalperitem[0] = price[optionindex[0]-1]*quantityA[0];
    totalperitem[1] = price[optionindex[1]-1]*quantityA[1];
    totalperitem[2] = price[optionindex[2]-1]*quantityA[2];
    totalperitem[3] = price[optionindex[3]-1]*quantityA[3];
    customerbill = totalperitem[0]+totalperitem[1]+totalperitem[2]+totalperitem[3];
    if (discountquantity != 0)
    {
        if (quantityA[0] >= discountquantity)
        {
            dis1 = (totalperitem[0]*(discountpercent/100));
            totalperitem[0] = totalperitem[0] - dis1;
        }
        else if (quantityA[1] >= discountquantity)
        {
            dis2 = (totalperitem[1]*(discountpercent/100));
            totalperitem[1] = totalperitem[1] - dis2;
        }
        else if (quantityA[2] >= discountquantity)
        {
            dis3 = (totalperitem[2]*(discountpercent/100));
            totalperitem[2] = totalperitem[2] - dis3;
        }
        else if (quantityA[3] >= discountquantity)
        {
            dis4 = (totalperitem[3]*(discountpercent/100));
            totalperitem[3] = totalperitem[3] - dis4;
        }
        dispriceA[count_customer-1] = totalperitem[0] + totalperitem[1] + totalperitem[2] + totalperitem[3];
    }
    
    
        
}//END OF CALCULATE BILL FUNCTION

void clearscreen(){
    cout<<"PRESS ANY KEY TO CONTINUE "<<endl;
    getch();
    system("CLS");
}//END OF CLEAR SCREEN FUNCTION

void recommendation(){
    if (discount == true)
    {
        cout<<"BIG OFFER......."<<endl;
        cout<<"BUY "<<discountquantity <<" QUANTITY OF ANY THING AND GET " <<discountpercent <<" PERCENT DISCOUNT"<<endl;
        cout<<"                   "<<endl;
    }
    
}//END OF RECOMMENDATION OF FUNCTION



void saveemployeefile(){
    fstream f;
    f.open("Employee.txt" ,ios :: out);
    for (int i = 0; i < count_employee; i++)
    {
        f << employeeNameA[i] <<",";
        f << employeeFNameA[i] << ",";
        f << employeeCnicA[i] <<",";
        f << employeePhoneA[i] <<",";
        f << employeeSalaryA[i] <<",";
        f << employeeJobA[i] << ",";
        if (i != count_employee - 1)
        {
            f << endl;    
        }
    }
    f.close();
}//END OF SAVE EMPLOYEE FILE FUNCTION

void loademployeefile(){
    fstream k;
    int a = 0;
    string line , salary;
    string name,fthname,cnic,phone,job;
    float salaryA;
    k.open("Employee.txt" , ios :: in);
    while (!k.eof())
    {
        getline(k, line);
        name = parseRecord(line, 1);
        fthname = parseRecord(line, 2);
        cnic = parseRecord(line , 3);
        phone = parseRecord(line , 4);
        salary = parseRecord(line, 5);
        salaryA = convertintofloat(salary);
        job = parseRecord(line , 6);
        a++;
        if (job == "Guard"||job == "guard" || job == "GUARD")
            {
                securitydepartment[count_security] = count_employee;
                count_security = count_security + 1;
            }
            else if (job == "CHEF"||job == "chef" || job == "Chef")
            {
                chefdepartment[count_chef] = count_employee;
                count_chef = count_chef + 1;
            }
            else if (job == "Waiter"||job == "waiter" || job == "WAITER")
            {
                waiterdepartment[count_waiter] = count_employee;
                count_waiter = count_waiter + 1;
            }
            putintoArray(name,fthname,cnic,phone,salaryA,job);
    }
    k.close();
}//END OF LOAD EMPLOYEE FILE FUNCTION

void saveadminfile(){
    fstream f;
    f.open("admin.txt" , ios :: out);
    for (int i = 0; i < count_admin; i++)
    {
        f << adminnameA[i] <<",";
        f << PasswordA[i] <<",";
        if (i != count_admin - 1)
        {
            f << endl;    
        }
        
    }
    f.close();
}//END OF SAVE ADMIN FILE FUNCTION

void savecustomerfile(){
    fstream f;
    f.open("customer.txt" ,ios :: out);
    for (int i = 0; i < count_customer; i++)
    {
        f << customernameA[i] <<",";
        f << totalbill[i] <<",";
        if (i != count_customer - 1)
        {
            f << endl;    
        }
    }
    f.close();    
}//END OF SAVE CUSTOMER FILE FUNCTION

void loadcustomerfile(){
    string line,name;
    string bill;
    float billA;
    fstream k;
    k.open("customer.txt" , ios :: in);
    while (!k.eof())
    {
        getline(k,line);
        name = parseRecord(line, 1);
        bill = parseRecord(line, 2);
        billA = convertintofloat(bill);
        putintoCustArray(name);
        totalbill[count_customer - 1] = billA;
    }
    k.close();
}//END OF LOAD CUSTOMER FILE FUNCTION

float convertintofloat(string line){
    float num = 0;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] - '0' >= 0 && line[i]- '0' <= 9)
        {
            num = num*10 + line[i] - '0';
        }
        
    }
    return num;
}//END OF CONVERT STRING INTO FLAOT FUNCTION





void loadadminfile(){
    string line,text;
    fstream k;
    int a = 0;
    k.open("admin.txt" , ios :: in);
    while (!k.eof())
    {
        getline(k,line);
        adminnameA[a] = parseRecord(line,1);
        PasswordA[a] = parseRecord(line,2);
        a++;
        count_admin = count_admin + 1;
    }
    k.close();
}//END OF LOAD ADMIN FILE FUNCTION

void createattendenceSheet(){
    for (int i = 0; i < MAX_RECORDS; i++)
    {
        attendencesheet[i] = '*';
    }
    
}//END OF CREATE ATTENDENCE SHEET

void saveattendenceSheet(){
    fstream f;
    f.open("sheet.txt" , ios :: out);
    for (int i = 0; i < MAX_RECORDS; i++)
    {
        f << attendencesheet[i] <<",";
    }
    f.close();
}//END OF CREATE NEW ATTENDANCE SHEET

void loadattendenceSheet(){
    fstream k;
    string line;
    k.open("sheet.txt" , ios :: in);
    while (!k.eof())
    {
        getline(k,line);
        for (int i = 0; i < MAX_RECORDS; i++)
        {
            if (line[i] != ',')
            {
                attendencesheet[i] = line[i];
            }
            
        }
        
    }
    k.close();
}




string parseRecord(string record, int field){
    int commacount = 1;
    string line;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            commacount = commacount + 1;
        }
        else if (commacount == field)
        {
            line = line + record[i];
        }
        
        
    }
    return line;
}//END OF PARSERECORD FUNCTION


bool countCnic(string line){
    int  p = 0;
    for (int i = 0; i < line.length(); i++)
    {
        p++;
    }
    if (p == 15)
    {
        return true;
    }
    return false;
    
    
}//END OF CHECKCNIC FUNCTION

bool countMobileno(string line){
    int p = 0;
    for (int i = 0; i < line.length(); i++)
    {
        p++;
    }
    if (p == 11)
    {
        return true;
    }
    return false;
    
}//END OF CHECK MOBILE NO FUNCTION

//--------------------FUNCTION DEFINATIONS ENDS 