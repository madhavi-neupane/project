#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include <ctime>
#include<fstream>
class vehicle
{
	public:
	int vno;
	float count;
	char  dname[15],vn;
	void input()
	{
		system("CLS");

			int e;
			time_t now = time(0);
		  char* et = ctime(&now);

		cout<<"\n\n\t\tEnter the name of driver : ";
		cin>>dname;
		cout<<"\n\n\t\tEnter your vehicle type : bike/car/truck =\t b/c/t \n\t\t\t\t";
		cin>>vn;
		cout<<"\n\n\t\tEnter the vehicle no : ";
		cin>>vno;
		cout<<"\n\n\t\tEnter the no of hours of stay : ";
		cin>>count;
		cout<<"\n\n\t\t Your entry time is :"<<et<<endl;

		if(e<20&&count<8)
   			{
   				cout<<"\n\n\t\tParking Available! You can park your vehicle. ";
   			cout<<"\n\n\t\t vehicle got parked!!";
   			}
   			else
   				cout<<"\n\n\t\t Parking not possible!!";


	}
	void cal()
	{
        if(vn=='b')
		{


				system("CLS");
				cout<<"\n\t\n\tThe total expenses during parking  ";
				cout<<count*30<<" rupees";

		}

		else if(vn=='c')
		{

				system("CLS");
				cout<<"\n\t\n\tThe total expenses during parking  ";
				cout<<count*40<<" rupees";

		}

		else if(vn=='t')
		{

				system("CLS");
				cout<<"\n\t\n\tThe total expenses during parking  ";
				cout<<count*50<<" rupees";

		}

		else
		{
			cout<<"\n\n\t\n\tSorry!!!\nSuch vehicle does not exist.";
		}


	}


	void output()
	{

		cout<<"\n\n\t\tThe Driver Name : "<<dname<<endl;
		cout<<"\n\n\t\tYour vehicle type :bike/car/truck \n\t\t\t"<<vn<<endl;
		cout<<"\n\n\t\tThe vehicle No : "<<vno<<endl;
		cout<<"\n\n\t\tThe Hours Of Stay : " <<count;

	}



}a,a1;

void delete_record()
{



	int n;
	system("CLS");

	int d;
    time_t now = time(0);
    char* dt = ctime(&now);

	cout<<"\n\n\t\tEnter the vehicle no you want to get depart : ";
	cin>>n;

	cout<<"\n\n\t Your departure time is :"<<dt<<endl;

	ifstream inFile;
    inFile.open("parking.txt", ios::binary);
	ofstream outFile;
    outFile.open("temp.txt", ios::out | ios::binary);
    while(inFile.read((char*)&a, sizeof(a)))
    {
        if(a.vno!= n)
        {

            outFile.write((char*)&a, sizeof(a));
        }

    }
    cout<<"\n\n\t\t Parking Record Deleted";

    inFile.close();
    outFile.close();

    remove("parking.txt");
    rename("temp.txt", "parking.txt");
}

int login(){
   string pass ="";
   char ch;


   cout <<"\n\n\n\t\t\t\t\t Parking Management System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
        system("Color 20");
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");

   }else{
        system("Color 40");
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
   return 0;
}

int developers()
{
    ifstream infile;
	fstream myfile;
	infile.open("developers.txt", ios::in);
	if(myfile.is_open())
    {
        string line;
        while(getline(myfile,line)){
            cout<<line<<endl;
        }
        myfile.close();
    }
    else cout<<"\t\t\t unable to open the developer's file\n\n";
    system("pause");
    return 0;
}

int main()
{

  developers();
    login();

	int choice,vno1,d;

	while(1) {
	system("CLS");
	system("Color 7C");

     cout << "\n\n\t\t ====== PARKING MANAGEMENT SYSTEM ======";
     cout <<"\n\n                                          ";
     cout<<" \n\t\t\t======================";
     cout << "\n\n\t\t\t  1. Arrival of a vehicle";
     cout << "\n\n\t\t\t  2. Total no of vehicles Arrived";
     cout << "\n\n\t\t\t  3. Total parking charges of all vehicles with details";
     cout << "\n\n\t\t\t  4. Departure of the vehicle";
     cout << "\n\n\t\t\t  5. Exit Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {
        		char f;
        		cout<<"\n\n\t\t==Do You Want to continue==y/n ";
        		cin>>f;
        		if(f=='y')
        		{

				ofstream f1("parking.txt",ios::binary|ios::out|ios::app);
                a.input();
                f1.write((char*)&a,sizeof(a));
        }
            	break;
        }
       case 2 :
           {
           	system("CLS");
  		   cout << "\n\n\t\t=== View the Records in the Parking Database ===";
           cout << "\n";
           ifstream infile("parking.txt",ios::in);
           int d=1;
           while (infile.read((char *)&a,sizeof (a)))
		   {
		system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe vehicle position in parking lot : "<<d;
           d++;
           a.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
       	   }

           break;
       	   }
       	case 4:
		   {

		   delete_record();
		   break;
	}
    	case 3:
		{
				ifstream infile("parking.txt",ios::binary|ios::in);
           while (infile.read((char *)&a,sizeof (a)))
		   {
             cout << "\n";
			 a.cal();
			 a.output();
			 cout<<"\n";
			 cout<<endl;

       		}
       		break;
   }

   		case 5:
		   {
		   	system("CLS");
		   	cout<<"\n\n\n\t\t\tThank you!!! \n";
		   exit(0);
   			break;
   		}
   		default :
		   {
		   cout<<"\n\n\t\t Invalid input";
			cout<<"\n\n\t\tPress Enter to continue";


   	}
   }
getch();
}}

