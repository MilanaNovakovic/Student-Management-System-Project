#include<iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

class Student{
private:
string index, name, course, address, email, phone;
bool checkEmail(string email);

public:
void main();
void insert();
void display();
void modify();
void sreach();
void deleted();



};

bool Student::checkEmail(string email){
    regex pattern("[A-Za-z0-9_\\.]+@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)+");
    return regex_match(email, pattern);
}

void Student::main(){
    int c;
    
    do{
        //system("cls");
        cout<<"____________________________________________________________\n";
        cout<<"\t\tStudent meanagement system\n";
        cout<<"____________________________________________________________\n";
        cout<<"Press 1 for insert new row\n";
        cout<<"Press 2 for display all row\n";
        cout<<"Press 3 for modify row\n";
        cout<<"Press 4 for search\n";
        cout<<"Press 5 for delete row\n";
        cout<<"Press 6 for exit:\n";
        cin>>c;
        switch (c)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;    
        case 3:
            modify();
            break;
        case 4:
            sreach();
            break;
        case 5:
            deleted();
            break;        
        default:
        system("cls");
            break;
        }
    }while(c!=6);


}

void Student::insert(){
    system("cls");
    cout<<"Insert info\n";
    cout<<"Index: ";
    cin>>index;
    cout<<"Name: ";
    cin>>name;
    cout<<"Course: ";
    getchar();
    getline(cin,course);
    cout<<"Address: ";
    getchar();
    getline(cin,address);
    cout<<"Email: ";
    cin>>email;
    while (!checkEmail(email))
    {
        cout<<"Email is not valid\n ";
        cout<<"Email: ";
        cin>>email;
    }
    
    
  
    cout<<"Phone: ";
    cin>>phone;
    while(phone.size()!=10){
        cout<<"Phone have 10 number\n";
        cout<<"Phone: ";
        cin>>phone;

    }

    ofstream f("students.txt", ios::app);
    f<<index<<" "<<name<<" "<<course<<" "<<address<<" "<<email<<" "<<phone<<"\n";
    f.close();



}

void Student::display(){
    system("cls");
    ifstream f1("students.txt");
    string line;
    while(getline(f1, line)){
        cout<<line<<endl;

    }
    f1.close();

}

void Student::deleted(){
    ofstream f1("pomoc.txt", ios::app | ios::out);
    ifstream f2("students.txt");
    string line;
    cout<<"Index of row for deleting: ";
    cin>>index;
    while(getline(f2, line)){
        if(line.find(index,0)!=0){
            f1<<line<<"\n";
        }

    }
    f1.close();
    f2.close();
    remove("students.txt");
    rename("pomoc.txt", "students.txt");


    


}


void Student::sreach(){
    system("cls");
    ifstream f2("students.txt");
    string line;
    cout<<"Index of row for sreaching: ";
    cin>>index;
    while(getline(f2, line)){
        if(line.find(index,0)==0){
            cout<<line<<endl;
            break;
        }

    }

}

void Student::modify(){
    ofstream f1("pomoc.txt", ios::app | ios::out);
    ifstream f2("students.txt");
    string line;
    cout<<"Index of row for modify: ";
    cin>>index;
    while(getline(f2, line)){
        if(line.find(index,0)==0){
            cout<<"Name: ";
            cin>>name;
            cout<<"Course: ";
            getchar();
            getline(cin,course);
            cout<<"Address: ";
            getchar();
            getline(cin,address);
            cout<<"Email: ";
            cin>>email;
            while (!checkEmail(email))
            {
                cout<<"Email is not valid\n ";
                cout<<"Email: ";
                cin>>email;
            }
    
    
  
            cout<<"Phone: ";
            cin>>phone;
            while(phone.size()!=10)
            {
                cout<<"Phone have 10 number\n";
                cout<<"Phone: ";
                cin>>phone;

            }
            f1<<index<<" "<<name<<" "<<course<<" "<<address<<" "<<email<<" "<<phone<<"\n";
        }else{
            f1<<line<<"\n";
        }

    }
    f1.close();
    f2.close();
    remove("students.txt");
    rename("pomoc.txt", "students.txt");

}

int main(){
    Student s;
    s.main();
    return 0;
}