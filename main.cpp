#include <iostream>
#include <cstdlib>
#include <sstream>  

using namespace std;

string username, reg_number,msgs,grade;
int userpassword;
float cat1,cat2,cat3,assingment,exam,ass_total,Total;

void  makeMove(void (*func)(),string msg);//function to clear the terminal before  calling  other functions
void homepage();
void createAccount();
void login();
void main_menu();
void update_results();
void grader();
int checker(float a, float b);


int main(){
    makeMove(homepage,"");
    return 0;
}


void makeMove(void (*func)(),string msg) {
#ifdef _WIN32
    system("cls");  
#else
    system("clear");
#endif
    cout<<msg<<endl;
    func(); 
}

void homepage(){
    cout << "Welcome to OOP Exam Grader" << endl;
    cout << endl << "Select an Option;" << endl;
    cout << "1. Create account" << endl;
    cout << "2. Login" << endl;
    cout << "-->:";
    int mv;
    cin >> mv;
    if (mv == 1){
        makeMove(createAccount,"");
    } else if (mv == 2) {
        makeMove(login,"");
    } else {
        cout << "Invalid option!" << endl;
    }
}

void createAccount(){
    cout << "Welcome to OOP Exam Grader" << endl;
    cout << "Create Account:" << endl;
    cout << "\nEnter your Name: "<<endl;
    cout << "-->:";
    cin >> username;
    cout<<"Enter your Registration number:"<<endl;
    cout << "-->:";
    cin >> reg_number;
    int c_password;
    cout<<"Enter your Password"<<endl;
    cout << "-->:";
    cin>>c_password;
    cout<<"Confirm your Password"<<endl;
    cout << "-->:";
    cin>>userpassword;

    if(c_password == userpassword){
        stringstream ss;
        ss << "Account Successfully Created for: " << username << ", Registration number: " << reg_number << ". Login now\n";
        msgs = ss.str(); 
        makeMove(homepage,msgs);
    }
    else{
        msgs = "Password don't match Kindly try again.";
        makeMove(createAccount,msgs);
    }
}

void login(){
    cout << "Welcome to OOP Exam Grader" << endl;
    cout << "Login:" << endl;
    cout<<"Enter your Name:"<<endl;
    cout << "-->:";
    string log_name;
    int log_password;
    cin>>log_name;
    cout<<"Enter your Password:"<<endl;
    cout << "-->:";
    cin>>log_password;
    if((log_password == userpassword) && (log_name == username)){
       makeMove(main_menu,"");
    }
    else{
        msgs = "Wrong Username or password, Kindly try again.";
        makeMove(login,msgs);
    }
}


void main_menu(){
    cout << "Welcome to OOP Exam Grader" << endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Name        :"<<username<<endl;
    cout<<"RegNO       :"<<reg_number<<endl;
    cout<<"\nRESULTS;"<<endl;
    cout<<"CAT 1       :"<<cat1<<endl;
    cout<<"CAT 2       :"<<cat2<<endl;
    cout<<"Assingment  :"<<assingment<<endl;
    cout<<"Exam        :"<<exam<<endl;
    cout<<"Grade       :"<<grade<<endl;
    cout<<"---------------------------------"<<endl;
    int mv;
    cout<<"\nSelect 0 to update your results"<<endl;
    cout<<"\n0.\n1.Home"<<endl;
    cout<<"2.Back"<<endl;
    cout<<"3.Exit"<<endl;
    cout << "-->:";
    cin>>mv;
    if(mv== 0){
        makeMove(update_results,"");
    }
    else if(mv == 1){
        makeMove(login,"");
    }else if(mv == 2){
        makeMove(main_menu,"");
    }else if(mv == 3){
        cout<<"CLosed...";
    }else{
        msgs = "\nInvalid input,Kindly try agin.\n";
    }
}


void update_results(){
    cout << "Welcome to OOP Exam Grader" << endl;
    cout<< "Update your Results,"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Name:"<<username<<endl;
    cout<<"RegNO:"<<reg_number<<endl;
    cout<<"\nEnter CAT1 out of 30,"<<endl;
    cout << "-->:";
    cin>>cat1;
    cat1 = checker(cat1,30);
    cout<<"\nEnter CAT2 out of 30,"<<endl;
    cout << "-->:";
    cin>>cat2;
    cat2 = checker(cat2,30);
    cout<<"\nEnter Assingment out of 30,"<<endl;
    cout << "-->:";
    cin>>assingment;
    assingment = checker(assingment,30);
    cout<<"\nEnter Exam out of 70,"<<endl;
    cout << "-->:";
    cin>>exam;
    exam = checker(exam,70);
    makeMove(grader,"");
}


/*function to check the limits of cat and exam wheather they fall under the required limit i.e not less than zero and greater than .../
/* a is the input value and b is the limit*/
int checker(float a,float b){
    if(a<=b && a>=0){
        return a;
    }
    else{
        msgs = "invalid marks, kindly try again,\n";
        makeMove(update_results,msgs);
        return 0;
    }
}


void grader(){
    ass_total = (cat1+cat2+assingment)/3;
    Total = ass_total + exam;
    Total = checker(Total,100);
    if (Total >= 0 && Total < 40) {
        grade = "FAIL";
    } else if (Total >= 40 && Total < 50) {
        grade = "PASS";
    } else if (Total >= 50 && Total < 60) {
        grade = "CREDIT";
    } else if (Total >= 60 && Total < 70) {
        grade = "MERIT";
    } else if (Total >= 70 && Total <= 100) {
        grade = "DISTINCTION";
    } else {
        grade = "INVALID!!";
    }

   makeMove(main_menu,"");
}