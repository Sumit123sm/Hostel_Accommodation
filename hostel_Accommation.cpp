#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include <windows.h>
#include <sstream>

using namespace std;

const char* HOST ="localhost";
const char* USER="root";
const char* PW ="Sum@123#";// password
const char* DB ="mydb";// database name

class Hostel{
private:
 string Name;
 int Bed,Fee;
public:
 Hostel(string name,int bed,int fee){
 	Name=name;
 	Bed=bed;
 	Fee=fee;
 }	
 
 string getName(){
 	return Name;
 }

 int getBed(){
 	return Bed;
 }

 int getFee(){
 	return Fee;
 }
};

int main() {
	MYSQL* conn;
	conn=mysql_init(NULL);// till here no value present in sql also to make connection to sql
	//	port number 3306

	if(!mysql_real_connect(conn,HOST,USER,PW,DB,3306,NULL,0)){
		cout<<"Error: "<<mysql_error(conn)<<endl;
	}
	else{
		cout<<"Logged in Database"<<endl;
	}
	Sleep(3000);
	Hostel h("3Star",5,5000);

	int intB=h.getBed();
	stringstream ss;
	ss<<intB;
	string strB=ss.str();

	int intF=h.getFee();
	stringstream as;
	as<<intF;
	string strF=as.str();
	// to put in insert all thing should be convert to string only
	string insert="INSERT INTO hostel (Name,Bed,Fee) VALUES ('"+h.getName()+"','"+strB+"','"+strF+"')";
	if(mysql_query(conn,insert.c_str())){
		cout<<"Error: "<<mysql_error(conn)<<endl;
	}
	else{
		cout<<"Data Inserted"<<endl;
	}
	//	to close first we start connection

	bool exit=false;
	while(!exit){
		system("cls");
		cout<<"Welcome To Hostel Management System"<<endl;
		cout<<"***********************************"<<endl;
		cout<<"1. Reserve Bed: "<<endl;
		cout<<"2. Exit: "<<endl;
		cout<<"Enter Your Choice:"<<endl;
		int val;
		cin>>val;
		int total;

		if(val==1){
			string n;
			cout<<"Enter Student Name: ";
			cin>>n;
			string check="SELECT Bed FROM hostel WHERE Name = '"+h.getName()+"'";
			if(mysql_query(conn,check.c_str())){
				cout<<"Error: "<<mysql_error(conn)<<endl;
			}
			else{
				MYSQL_RES* res;
				res=mysql_store_result(conn);// act like API
				if(res){
					MYSQL_ROW row=mysql_fetch_row(res);
					if(row){
						total=atoi(row[0]);// asci to integer
					}
					mysql_free_result(res);
				}	
			}

			if(total>0){
				total--;
				stringstream zs;
				zs<<total;
				string strT=zs.str();

				string update="UPDATE hostel SET Bed = '"+strT+"' WHERE Name='"+h.getName()+"'";
				if(mysql_query(conn,update.c_str())){
					cout<<"Error: "<<mysql_error(conn)<<endl;
				}
				else{
					cout<<"Bed is Reserved Successfully in "<<h.getName()<<" Hostel For Student "<<n<<endl;
					cout<<"Please Pay "<<h.getFee()<<" Rupees."<<endl;
				}
			} else if(total==0){
				cout<<"Sorry! No Bed Available"<<endl;
			}
			Sleep(8000);
		} else if(val==2){
			exit=true;
			cout<<"Good Luck"<<endl;
			Sleep(3000);
		} else{
			cout<<"Invalid Input"<<endl;
			Sleep(3000);
		}
	}

	mysql_close(conn);
	return 0;
}

