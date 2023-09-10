//Student data base

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int ID;                 //global variable by default has zero

class student
{
public:
    int id;
    string name;
    int age;
    string stream;

    void addStudent()
    {
        cout<<"Enter your name"<<endl;
        cin.get();                      //takes one character same as getch()
        getline(cin,name);
        cout<<"Enter your age"<<endl;
        cin>>age;
        cout<<"Enter your stream"<<endl;
        cin>>stream;
        ID++;

        ofstream fout;
        fout.open("E:/PROJECTS/student.txt",ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        fout.open("E:/PROJECTS/ID.txt",ios::app);
        fout<<"\n"<<ID;
        fout.close();

        cout<<"\nRecord Added Succesfully\n";
    }
    void printAllStudent()
    {
        ifstream fin;
        fin.open("E:/PROJECTS/student.txt");
        student s;
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);
            fin>>s.age;
            fin>>s.stream;

            s.print();
        }
        fin.close();
    }

    void print()
    {
        cout<<"\nID     : "<<id<<endl;
        cout<<"Name   : "<<name<<endl;
        cout<<"Age    : "<<age<<endl;
        cout<<"stream : "<<stream<<endl;
        cout<<"##########################################"<<endl<<endl;
    }

    void searchStudent(int id)
    {
       ifstream fin;
       fin.open("E:/PROJECTS/student.txt");
       student s;
       while(!fin.eof())
       {
           fin>>s.id;
           fin.ignore();
           getline(fin,s.name);
           fin>>s.age;
           fin>>s.stream;

           if(s.id==id)
           {
               s.print();
               break;
           }
       }
       fin.close();
    }
    void deleteStudent(int id)
    {
        ifstream fin;
        fin.open("E:/PROJECTS/student.txt");

        ofstream fout;
        fout.open("E:/PROJECTS/temp.txt",ios::app);
        student s;
        while(!fin.eof())
        {
         fin>>s.id;
         fin.ignore();
         getline(fin,s.name);
         fin>>s.age;
         fin>>s.stream;
         if(s.id!=id)
         {
            fout<<"\n"<<s.id;
            fout<<"\n"<<s.name;
            fout<<"\n"<<s.age;
            fout<<"\n"<<s.stream;
         }
        }
        fin.close();
        fout.close();
        remove("E:/PROJECTS/student.txt");
        rename("E:/PROJECTS/temp.txt","E:/PROJECTS/student.txt");
        cout<<"\nDeleted succesfully\n";
    }
    void updateStudent(int id)
    {
      deleteStudent(id);

      cout<<"\nEnter Name:\n";
      cin.get();
      getline(cin,name);
      cout<<"Enter Age:";
      cin>>age;
      cout<<"Enter stream: ";
      cin>>stream;
     // ID++;

      ofstream fout;
      fout.open("E:/PROJECTS/student.txt",ios::app);
      fout<<"\n"<<id;
      fout<<"\n"<<name;
      fout<<"\n"<<age;
      fout<<"\n"<<stream;
      fout.close();
      cout<<"\nRecord Updated succesfully\n";
    }
    void Restrat()
    {
       remove("E:/PROJECTS/student.txt");
       remove("E:/PROJECTS/ID.txt");
       ID=0;
    }

};

int main()
{
    int choice;

    while(true)
    {
        ifstream fin;
        fin.open("E:/PROJECTS/ID.txt");
        if(!fin)
        {
            if(ID==0)
                cout<<"\n  \"Let's Start\"\n";
            else
                cout<<"File Not Found"<<endl;
        }
        else
        {
             while(!fin.eof())
              {
                fin>>ID;
              }
        }
        fin.close();
        cout<<"ID = "<<ID<<endl;   // to get Last ID



        cout<<"Enter your choice: "<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Print All the students"<<endl;
        cout<<"3. Search a student"<<endl;
        cout<<"4. Update a student"<<endl;
        cout<<"5. Delete a Student"<<endl;
        cout<<"6. Restart"<<endl;

        cin>>choice;

        student s;
        int id;

        switch(choice)
        {
            case 1: s.addStudent();
                    break;
            case 2: s.printAllStudent();
                    break;
            case 3:
                    cout<<"\nEnter Student id :";
                    cin>>id;
                    s.searchStudent(id);
                    break;
            case 4:
                    cout<<"\nEnter Student id :";
                    cin>>id;
                    s.updateStudent(id);
                    break;
            case 5: cout<<"\nEnter Student id :";
                    cin>>id;
                    s.deleteStudent(id);
                    break;
            case 6:
                    s.Restrat();
                    break;
            default: return 0;
        }
    }


    return 0;
}
