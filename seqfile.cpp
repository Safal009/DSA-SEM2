#include <iostream>
#include<fstream>
#include<string.h>
#include<iomanip>

using namespace std;
const int MAX=20;
const int MAX1=80;
class Student{

    int rollno;
    char name[20];
    char city[80];
    char div;
    int year;
public:
    Student(){
        strcpy(name,"");
        strcpy(city,"");
        rollno=0;
        year=0;
        div=0;
    }

    Student(int rollno,char name[MAX],int year,char div,char city[MAX1]){
        strcpy(this->name,name);
        strcpy(this->city,city);
        this->rollno=rollno;
        this->year=year;
        this->div=div;
    }

    int getRollNo(){
        return rollno;
    }
 
    void displayRecord(){
        
        cout<<endl<<setw(10)<<rollno<<setw(10)<<name<<setw(10)<<year<<setw(10)<<div<<setw(10)<<city;
        cout<<endl;
 }

};

class FileOperations{
    fstream file;
public:
    FileOperations(char* filename){

        file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
    }

    void insertRecord(int rollno, char name[MAX],int year, char div,char city[MAX]){
        Student s1(rollno,name,year,div,city);
        file.seekp(0,ios::end);
        file.write((char *)&s1,sizeof(Student));
        file.clear();
    }
    void displayAll(){
        Student s1;
        file.seekg(0,ios::beg);
  
        while(file.read((char *)&s1, sizeof(Student))){
            s1.displayRecord();
        }
        file.clear();
    }

    void update(int roll){
        int rollNo,year,add2,n2,start2;
        char div;
        char name[MAX],address[MAX];
        Student s1;
        file.seekg(0,ios::beg);
        bool flag=false;
        while(file.read((char*)&s1,sizeof(Student))){
            if(s1.getRollNo()==roll){
                s1.displayRecord();
                flag=true;
                add2=file.tellg();
                file.seekg(0,ios::beg);
                start2=file.tellg();
                n2=(add2-start2)/(sizeof(s1));
                file.seekp((n2-1)*sizeof(s1),ios::beg);
                cout<<"\nEnter name : ";
                cin>>name;
                cout<<"\nEnter RollNo : ";
                cin>>rollNo;
                cout<<"\nEnter Year : ";
                cin>>year;
                cout<<"\nEnter division : ";
                cin>>div;
                cout<<"\nEnter address : ";
                cin>>address;
                Student s1(rollNo,name,year,div,address);
                file.write((char *)&s1,sizeof(Student));
                file.clear();
                break;
            }
        }
        if(flag==false){
            cout<<"\nRecord of "<<roll<<"is not present.";
        }
        file.clear();
        
    }

    void displayRecord(int rollNo){
        Student s1;
        file.seekg(0,ios::beg);
        bool flag=false;
        while(file.read((char*)&s1,sizeof(Student))){
            if(s1.getRollNo()==rollNo){
                cout<<endl<<setw(10)<<"ROLL"<<setw(10)<<"NAME"<<setw(10)<<"YEAR"<<setw(10)<<"DIV"<<setw(10)<<"CITY"<<endl;
                s1.displayRecord();
                flag=true;
                break;
            }
        }
        if(flag==false){
            cout<<"\nRecord of "<<rollNo<<" is not present.\n";
        }
        file.clear();
    }
 
    void deleteRecord(int rollno){
        ofstream outFile("new.txt",ios::binary);
        file.seekg(0,ios::beg);
        bool flag=false;
        Student s1;

        while(file.read((char *)&s1, sizeof(Student))){
            if(s1.getRollNo()==rollno){
                flag=true;
                cout<<"\n Record deleted \n";
                continue;
            }
            outFile.write((char *)&s1, sizeof(Student));
        }
        if(flag!=true){
            cout<<"\nRecord of roll no "<<rollno<<" is not present.";
        }
        file.close();
        outFile.close();
        remove("student.txt");
        rename("new.txt","student.txt");
        file.open("student.txt",ios::in|ios::out|ios::ate|ios::binary);
    }

    ~FileOperations(){
        file.close();
        cout<<"\nFile Closed.";
    }

};
int main() {
        ofstream newFile("student.txt",ios::app|ios::binary);
        newFile.close();
        FileOperations file((char*)"student.txt");
        int rollNo,year,choice=0;
        char div;
        char name[MAX],address[MAX];

     do{
        
         cout<<"\n*Student Database*\n";
         cout<<"1) Add New Record\n";
         cout<<"2) Display All Records\n";
         cout<<"3) Search record by RollNo\n";
         cout<<"4) Update record \n";
         cout<<"5) Deleting a Record\n";
         cout<<"6) Exit\n";
         cout<<"Choose your choice : ";
         cin>>choice;
         switch(choice){
             case 1: 
                    cout<<"Enter name : ";
                    cin>>name;
                    cout<<"\nEnter RollNo : ";
                    cin>>rollNo;
                    cout<<"\nEnter Year : ";
                    cin>>year;
                    cout<<"\nEnter division : ";
                    cin>>div;
                    cout<<"\nEnter address : ";
                    cin>>address;
                    file.insertRecord(rollNo,name,year,div,address);
                    cout<<"\nRecord Inserted.";
                    break;
             case 2:
                    cout<<endl<<setw(10)<<"ROLL"<<setw(10)<<"NAME"<<setw(10)<<"YEAR"<<setw(10)<<"DIV"<<setw(10)<<"CITY"<<endl;
                    file.displayAll();
                    cout<<endl<<endl;
                    break;
             case 3:
                    cout<<"Enter Roll Number : ";
                    cin>>rollNo;
                    file.displayRecord(rollNo);
                    break;
            case 4 :
                    cout<<"Enter Roll Number : ";
                    cin>>rollNo;
                    file.update(rollNo);
                    break;
             case 5:
                    cout<<"Enter rollNo : ";
                    cin>>rollNo;
                    file.deleteRecord(rollNo);
                    break;
            case 6:
                    cout<<"\nThankyou\n";
                    break;
            default:
                    cout<<"\nInvalid choice entered \n";
                    break;

         }

     }while(choice<6);

    return 0;
}
