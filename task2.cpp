#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <direct.h>
#include <windows.h>
using namespace std;

fstream file;
fstream file1,file2;
class file_handling{
    public:
    void view_files(string file_name);
    void copy_file(string file_name1,string file_name2);
    void move_file(string file_name1,string file_name2);
    void create_directories();
    void navigate_directories();
};


//Read the content from a file
void file_handling::view_files(string file_name){
    file.open(file_name, ios::in);
    if(file.is_open()){
        string line;
        cout<<"\n>>File Opened Successfully"<<endl;
        cout<<"\n>>CONTENT IN THE FILE"<<endl;
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
        cout<<"\n\n>>File Closed Successfully"<<endl;
    }
    else{
        cout<<">>File not found"<<endl;
    }
}


//copy the file conntent to another one
void file_handling::copy_file(string file_name1,string file_name2){
    file1.open(file_name1,ios::in);
    file2.open(file_name2,ios::app);
    if(file1.is_open() && file2.is_open()){
        cout<<"\nFile opened Successfully"<<endl;
        string line;
        while(getline(file1,line)){
            file2<<line<<endl;
        }
        cout<<"File content is copied Successfully\n"<<endl;
        file1.close();
        file2.close();
    }
    else{
        cout<<">>File not found"<<endl;
    }
}


//Moving a file from one location to another
void file_handling::move_file(string file_name1,string file_name2){
    copy_file(file_name1,file_name2);
    remove(file_name1.c_str());
    cout<<"File is moved Successfully"<<endl;
}


//creating a directory
void file_handling::create_directories(){
    cout<<"\n\n>>Enter the name of the directory you want to create: ";
    string dir_name;
    cin>>dir_name;
    if(_mkdir(dir_name.c_str())==0){
        cout<<"\n\n>>Directory created successfully"<<endl;
    }
    else{
        perror(">>Error creating directory");
    }
}


//Navigating the directory
void file_handling::navigate_directories(){
    cout<<"\n\n>>Enter the name of the directory you want to navigate: ";
    string dir;
    cin>>dir;
    if(_chdir(dir.c_str())==0){
        cout<<"\n\n>> Successfully navigated to directory: "<<dir<<endl;
    }
    else{
        perror(">>Error Navigating to directory");
    }
}


int main(){
    string file_name;
    string file_name1,file_name2;
    string ch;
    do{
    system("cls");
    cout<<"\n\n1:View_file_content\n2:copy_file(or)Move_file\n3:Create_directories\n4:Navigate_directories\n>>";
    int choice;
    cin>>choice;
    file_handling f1,f2,f3,f4;
    switch(choice){
        case 1:
            cout <<"\n\nEnter the name of the file/path: ";
            cin.ignore(); 
            getline(cin,file_name);
            file_name.erase(std::remove(file_name.begin(), file_name.end(), '"'), file_name.end());
            cout<<"FILE LOCAITON: "<<file_name<<endl;
            f1.view_files(file_name);
            break;
        case 2:
            cout<<"\n\nEnter the current file name/path: ";
            cin.ignore();
            getline(cin,file_name1);
            file_name1.erase(std::remove(file_name1.begin(), file_name1.end(), '"'), file_name1.end());
            cout<<"File Location: "<<file_name1<<endl;
            cout<<"\n\nEnter the new file name/path: ";
            cin.ignore();
            getline(cin,file_name2);
            file_name2.erase(std::remove(file_name2.begin(), file_name2.end(), '"'), file_name2.end());
            cout<<"File Location: "<<file_name2<<endl;

            cout<<"\n\n1:Copy\n2:Move"<<endl;
            int choice1;
            cin>>choice1;
            if(choice1==1)
                f2.copy_file(file_name1,file_name2);
            else if(choice==2)
                f2.move_file(file_name1,file_name2);
            break;
        case 3:
            f3.create_directories();
            break;
        case 4:
            f4.navigate_directories();
            break;
        default:
            cout<<"Invalid Input"<<endl;
    }
    cout<<"\n\nContinue[yes/no]?? "<<endl;
    cin>>ch;
    }while(ch=="yes");
    return 0;
}



