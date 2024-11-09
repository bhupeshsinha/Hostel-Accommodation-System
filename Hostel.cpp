#include<iostream>      //for i/o operation
#include<fstream>       //for file handling
#include<windows.h>     //we use "Sleep() function from this header file"
#include<sstream>       //to perform string operation
#include<bits/stdc++.h>

using namespace std;

class Hostel
{
    private:
            string name;
            int rent, bed;
    
    public:
            Hostel(string name, int rent, int bed)
            {
                this->name=name;
                this->rent=rent;
                this->bed=bed;
            }

            string getName()
            {
                return this->name;
            }

            int getRent()
            {
                return this->rent;
            }

            int getBed()
            {
                return this->bed;
            }

            void reserve()
            {
                ifstream in("E:/CPP(MB Academy)/Hostel-Accommodation-System/Hostel.txt");
                ofstream out("E:/CPP(MB Academy)/Hostel-Accommodation-System/Hostel Temp.txt");

                string line;

                while(getline(in, line))
                {
                    int pos = line.find("3Star");

                    if(pos != string::npos)
                    {
                        int bed = this->bed-1;  
                        this->bed = bed;

                        stringstream ss;
                        ss<<bed;
                        string strBed = ss.str();

                        int bedPos = line.find_last_of(':');
                        line.replace(bedPos+1, string::npos, strBed);
                    }
                    out<<line<<endl;
                }
                out.close();
                in.close();

                remove("E:/CPP(MB Academy)/Hostel-Accommodation-System/Hostel.txt");
                rename("E:/CPP(MB Academy)/Hostel-Accommodation-System/Hostel Temp.txt",
                "E:/CPP(MB Academy)/Hostel-Accommodation-System/Hostel.txt");
                cout<<"\tBed Reserved Successfully!!"<<endl;
            }
};


class Student
{
        private:
                string name, rollNo, address;
        
        public:
                Student(): name(""), rollNo(""), address(""){}

                void setName(string name)
                {
                    this->name=name;
                }

                void setRollNo(string rollNo)
                {
                    this->rollNo = rollNo;
                }

                void setAddress(string address)
                {
                    this->address = address;
                }

                string getName()
                {
                    return name;
                }

                string getRollNo()
                {
                    return rollNo;
                }

                string getAddress()
                {
                    return address; 
                }
};

int main()
{
    Hostel h("3Star", 5000, 2);
    ofstream out("E:/CPP(MB Academy)/Hostel-Accommodation-System/Hostel.txt");
    out<<"\t"<<h.getName()<<" : "<<h.getRent()<<" : "<<h.getBed()<<endl<<endl;
    cout<<"Hostel Data Saved in File :)"<<endl;
    out.close();

    Student s;

    bool exit = false;
    string name, rollNo, address;

    while(!exit)
    {
        system("cls");
        int val;

        cout<<"\tWelcome to Hostel Management System"<<endl;
        cout<<"\t***********************************"<<endl;
        cout<<"\t1.Reserve a Bed."<<endl;
        cout<<"\t2.Exit."<<endl;
        cout<<"\tEnter Choice: ";
        cin>>val;

        if(val == 1)
        {

            system("cls");

            cout<<"\tEnter Name of Student: ";
            cin>>name;
            s.setName(name);

            cout<<"\tEnter Roll Number of Student: ";
            cin>>rollNo;
            s.setRollNo(rollNo);

            cout<<"\tEnter Address of Student: ";
            cin>>address;
            s.setAddress(address);

            if(h.getBed()>0)
            {
                h.reserve();
            }else{
                 cout<<"\t Sorry! Bed Not Available :("<<endl;
            }

            ofstream outFile("E:/CPP(MB Academy)/Hostel-Accommodation-System/Student.txt", ios::app);
            outFile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
            Sleep(5000);
        }else if(val == 2)
        {
                system("cls");
                exit=true;
                cout<<"Thank You! Have a good day."<<endl;
                Sleep(3000);
        }
    }
}