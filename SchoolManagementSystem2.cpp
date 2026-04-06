#include<iostream>
#include<string>
using namespace std;

const int Max = 100;

// ================= LOGIN CLASS =================
class Login {
public:
    int loginSystem() {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Login\n2. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if(choice == 2){
            return -1; // Exit signal
        }

        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        if(username == "admin" && password == "123"){
            cout << "Admin Login Successful!\n";
            return 1;
        }
        else if(username == "teacher" && password == "123"){
            cout << "Teacher Login Successful!\n";
            return 2;
        }
        else if(username == "student" && password == "123"){
            cout << "Student Login Successful!\n";
            return 3;
        }
        else{
            cout << "Invalid Username or Password!\n";
            return 0;
        }
    }
};

// ================= STUDENT CLASS =================
class Student{
protected:
    string name[Max];
    int roll[Max];
    int Class[Max];
    char section[Max];
    double marks[Max][5];
    int count = 0;

public:
    void addStudent(){
        if(count >= Max){ cout<<"Students limit reached!\n"; return; }

        cin.ignore();
        cout<<"Enter name : "; getline(cin, name[count]);
        cout<<"Enter Roll no. : "; cin>>roll[count];
        cout<<"Enter Class : "; cin>>Class[count];
        cout<<"Enter Section : "; cin>>section[count];
        cout<<"Enter Marks:\n";
        for(int i = 0; i < 5; i++){ cout<<"Subject "<<i+1<<" : "; cin>>marks[count][i]; }

        count++;
        cout<<"Student Added Successfully!\n";
    }

    void viewStudents(){
        if(count == 0){ cout<<"No Student Available!\n"; return; }
        for(int i = 0; i < count; i++){
            cout<<"\nName : "<<name[i]<<" | Roll No. : "<<roll[i]<<" | Class : "<<Class[i]
                <<" | Section : "<<section[i]<<" | Marks : ";
            for(int j = 0; j < 5; j++){ cout<<marks[i][j]<<" "; }
            cout<<endl;
        }
    }

    void searchStudent(){
        int search; cout<<"Enter roll no. to search : "; cin>>search;
        for(int i = 0; i < count; i++){
            if(roll[i] == search){
                cout<<"\nStudent Found!\nName : "<<name[i]<<" | Roll : "<<roll[i]
                    <<" | Class : "<<Class[i]<<" | Section : "<<section[i]<<" | Marks : ";
                for(int j = 0; j < 5; j++){ cout<<marks[i][j]<<" "; }
                cout<<endl;
                return;
            }
        }
        cout<<"Student Not Found!\n";
    }

    void upgradeStudent(){
        int update; cout<<"Enter roll no. to update : "; cin>>update;
        for(int i = 0; i < count; i++){
            if(roll[i] == update){
                cin.ignore();
                cout<<"Enter new name : "; getline(cin, name[i]);
                cout<<"Enter new Roll No. : "; cin>>roll[i];
                cout<<"Enter new Class : "; cin>>Class[i];
                cout<<"Enter new Section : "; cin>>section[i];
                cout<<"Enter new Marks:\n";
                for(int j = 0; j < 5; j++){ cout<<"Subject "<<j+1<<" : "; cin>>marks[i][j]; }
                cout<<"Student Updated Successfully!\n"; return;
            }
        }
        cout<<"Student Not Found!\n";
    }

    void deleteStudent(){
        int del; cout<<"Enter roll no. to delete : "; cin>>del;
        for(int i = 0; i < count; i++){
            if(roll[i] == del){
                for(int j = i; j < count - 1; j++){
                    name[j] = name[j+1]; roll[j] = roll[j+1]; Class[j] = Class[j+1]; section[j] = section[j+1];
                    for(int k = 0; k < 5; k++){ marks[j][k] = marks[j+1][k]; }
                }
                count--; cout<<"Student Deleted Successfully!\n"; return;
            }
        }
        cout<<"Student Not Found!\n";
    }
};

// ================= TEACHER CLASS =================
class Teacher{
protected:
    int id[Max];
    string name[Max];
    string subject[Max];
    string education[Max];
    int tcount = 0;

public:
    void addTeacher(){
        if(tcount >= Max){ cout<<"Teachers limit reached!\n"; return; }

        cout<<"Enter ID : "; cin>>id[tcount];
        cin.ignore();
        cout<<"Enter Name : "; getline(cin, name[tcount]);
        cout<<"Enter Subject : "; getline(cin, subject[tcount]);
        cout<<"Enter Education : "; getline(cin, education[tcount]);
        tcount++;
        cout<<"Teacher Added Successfully!\n";
    }

    void viewTeachers(){
        if(tcount == 0){ cout<<"No Teacher Available!\n"; return; }
        for(int i = 0; i < tcount; i++){
            cout<<"\nID : "<<id[i]<<" | Name : "<<name[i]<<" | Subject : "<<subject[i]<<" | Education : "<<education[i]<<endl;
        }
    }

    void searchTeacher(){
        int search; cout<<"Enter ID to search : "; cin>>search;
        for(int i = 0; i < tcount; i++){
            if(id[i] == search){
                cout<<"\nTeacher Found!\nID : "<<id[i]<<" | Name : "<<name[i]
                    <<" | Subject : "<<subject[i]<<" | Education : "<<education[i]<<endl;
                return;
            }
        }
        cout<<"Teacher Not Found!\n";
    }

    void updateTeacher(){
        int update; cout<<"Enter ID to update : "; cin>>update;
        for(int i = 0; i < tcount; i++){
            if(id[i] == update){
                cout<<"Enter New ID : "; cin>>id[i];
                cin.ignore();
                cout<<"Enter New Name : "; getline(cin, name[i]);
                cout<<"Enter New Subject : "; getline(cin, subject[i]);
                cout<<"Enter New Education : "; getline(cin, education[i]);
                cout<<"Teacher Updated Successfully!\n"; return;
            }
        }
        cout<<"Teacher Not Found!\n";
    }

    void deleteTeacher(){
        int del; cout<<"Enter ID to delete : "; cin>>del;
        for(int i = 0; i < tcount; i++){
            if(id[i] == del){
                for(int j = i; j < tcount - 1; j++){
                    id[j] = id[j+1]; name[j] = name[j+1]; subject[j] = subject[j+1]; education[j] = education[j+1];
                }
                tcount--; cout<<"Teacher Deleted Successfully!\n"; return;
            }
        }
        cout<<"Teacher Not Found!\n";
    }
};

// ================= MENU CLASSES =================
class callstudent : public Student{
public:
    void studentMenu(){
        int choice;
        do{
            cout<<"\n--- Student Menu ---\n";
            cout<<"1.Add Student\n2.View Students\n3.Search Student\n4.Update Student\n5.Delete Student\n6.Back\n";
            cin>>choice;
            switch(choice){
                case 1: addStudent(); break;
                case 2: viewStudents(); break;
                case 3: searchStudent(); break;
                case 4: upgradeStudent(); break;
                case 5: deleteStudent(); break;
            }
        }while(choice != 6);
    }
};

class callTeacher : public Teacher{
public:
    void teacherMenu(){
        int choice;
        do{
            cout<<"\n--- Teacher Menu ---\n";
            cout<<"1.Add Teacher\n2.View Teachers\n3.Search Teacher\n4.Update Teacher\n5.Delete Teacher\n6.Back\n";
            cin>>choice;
            switch(choice){
                case 1: addTeacher(); break;
                case 2: viewTeachers(); break;
                case 3: searchTeacher(); break;
                case 4: updateTeacher(); break;
                case 5: deleteTeacher(); break;
            }
        }while(choice != 6);
    }
};

// ================= MAIN FUNCTION =================
int main(){
    callstudent s;
    callTeacher t;
    Login l;

    int role;
    while(true){
        role = l.loginSystem();

        if(role == -1){ // Exit program
            cout<<"Exiting Program...\n"; break;
        }

        switch(role){
            // ADMIN
            case 1:{
                int choice;
                do{
                    cout<<"\n--- Admin Panel ---\n";
                    cout<<"1.Student Menu\n2.Teacher Menu\n3.Logout\n";
                    cin>>choice;
                    if(choice == 1) s.studentMenu();
                    else if(choice == 2) t.teacherMenu();
                }while(choice != 3);
                break;
            }
            // TEACHER
            case 2:{
                int choice;
                do{
                    cout<<"\n--- Teacher Panel ---\n";
                    cout<<"1.View Students\n2.View Teachers\n3.Update Student\n4.Logout\n";
                    cin>>choice;
                    switch(choice){
                        case 1: s.viewStudents(); break;
                        case 2: t.viewTeachers(); break;
                        case 3: s.upgradeStudent(); break;
                    }
                }while(choice != 4);
                break;
            }
            // STUDENT
            case 3:{
                int choice;
                do{
                    cout<<"\n--- Student Panel ---\n";
                    cout<<"1.View Students\n2.Logout\n";
                    cin>>choice;
                    if(choice == 1) s.viewStudents();
                }while(choice != 2);
                break;
            }
        }
    }

    return 0;
}