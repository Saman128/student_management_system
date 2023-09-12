#include<iostream>
#include<fstream>
using namespace std;
class s_addmission
{
	private:
          int cnic;
		public:
		int m_name, r_name,fee;
		string  name,s, f_name,g_name;
//			s_addmission()
//			{
//			}

			void menu()
				{
				int b;
				cout<<"\t\t\t******************************"<<endl;
				cout<<"\t\t\t       Addmission Portal"<<endl;
				cout<<"\t\t\t******************************"<<endl;
				cout<<"\t\t\t  1. Add student record"<<endl;
				cout<<"\t\t\t  2. display student record"<<endl;
				cout<<"\t\t\t  3. delete student record"<<endl;
				cout<<"\t\t\t  4. search student record"<<endl;
				cout<<"\t\t\t  5. back college menu"<<endl;
				cout<<"\t\t\t  6. Exit"<<endl;
				cout<<"\t\t\t******************************"<<endl;
				cout<<"enter your choice =";
				cin>>b;
				if(b==1)
				{
					add_record();
				}
				else	if(b==2)
				{
					display_record();
				}
				else	if(b==3)
				{
					delete_record();
				}
				else	if(b==4)
				{
					search();
				}
				else	if(b==5)
				{
				       //  goto p ;
				}
				else if(b==6)
				{
					exit();
				}
				else
				{
					cout<<"invalid choice"<<endl;
					menu();
				}
			}
			void exit()
			{
				cout<<"\t\t*****************"<<endl;
				cout<<"\t\t|Process is Done|"<<endl;
				cout<<"\t\t*****************"<<endl;
			}
			void add_record()
			{
				char ch='y';
				ofstream file("e:\\student record.txt",ios::app|ios::out);
				cout<<"\n\t\t===== Add student record =====\n"<<endl;
				while(ch=='y')
				{
				cout<<"enter semester=";
				cin>>s;
				cout<<"enter student Department name=";
				cin>>g_name;
				cout<<"enter student name=";
				cin>>name;
				cout<<"enter dtudent father name=";
				cin>>f_name;
				cout<<"enter student roll no=";
				cin>>r_name;
				cout<<"enter student phone no=";
				cin>>m_name;
				cout<<"enter student cnic=";
				cin>>cnic;
				file<<"semester="<<s<<endl;
				file<<"department="<<g_name<<endl;
				file<<"name="<<name<<endl;
				file<<"father name="<<f_name<<endl;
				file<<"roll no="<<r_name<<endl;
				file<<"phone no="<<m_name<<endl;
				file<<"cnic="<<cnic<<endl;
				file<<"________________________"<<endl;
				cout<<"Add another record of student y & N=";
				cin>>ch;
			}
			file.close();
		       menu();
			}
			void display_record()
			{
						cout<<"\t\t===== Display record of students =====\n"<<endl;
							ifstream fin;
							fin.open("e:\\student record.txt",ios::app|ios::in);
							fin>>s>>g_name>>name>>f_name>>r_name>>m_name>>cnic;
							while(!fin.eof())
							{
								cout<<"semester="<<s<<endl;
								cout<<"group name="<<g_name<<endl;
								cout<<"name="<<name<<endl;
								cout<<"father name="<<f_name<<endl;
								cout<<"roll no="<<r_name<<endl;
								cout<<"phone no="<<m_name<<endl;
								cout<<"cnic="<<cnic<<endl;
								cout<<"____________________"<<endl;
								fin>>s>>g_name>>name>>f_name>>r_name>>m_name>>cnic;
							}
							fin.close();
							menu();
	            }
				void delete_record()
		    	{
				cout<<"\t\t===== Delete record of students =====\n"<<endl;
				ifstream fin("e:\\student record.txt",ios::app|ios::in);
				if(!fin)
				{
					cout<<"No data is present"<<endl;
				}
				else
				{
				int r,found=0; string g;
				cout<<"enter student department name=";
				cin>>g;
				cout<<"enter student roll no=";
				cin>>r;
				ofstream file1("e:\\record.txt",ios::app|ios::out);
				fin>>s>>g_name>>name>>f_name>>r_name>>m_name>>cnic;
				while(!fin.eof())
				{
					if(g !=g_name && r !=r_name)
					{
						file1<<s<<endl;
						file1<<g_name<<endl;
				        file1<<name<<endl;
				        file1<<f_name<<endl;
				        file1<<r_name<<endl;
				        file1<<m_name<<endl;
				        file1<<cnic<<endl;
					}
					else
					{
						found++;
						cout<<"Deleted data"<<endl;
					}
					fin>>s>>g_name>>name>>f_name>>r_name>>m_name>>cnic;
				}				
				if(found==0)
				{
				   cout<<"data not found for deleting"<<endl;	
				}
				file1.close();
				fin.close();
				remove("student record.txt");
				rename("record.txt","student record.txt");
				}
				menu();
		    	}
				void search()
		    	{
		    		int r,found=0; string g, se;
		         cout<<"\t\t===== Search record of students =====\n"<<endl;
				ifstream fin("e:\\student record.txt",ios::app|ios::in);
				if(!fin)
				{
					cout<<"file is not open"<<endl;
				}
				else
				{
				cout<<"enter semester=";
				cin>>se;
				cout<<"enter student department name=";
				cin>>g;
				cout<<"enter student roll no=";
				cin>>r;
				fin>>s>>g_name>>name>>f_name>>r_name>>m_name>>cnic;
				while(!fin.eof())
				{
					if(se==s && g==g_name && r==r_name)
					{
						cout<<"semester="<<s<<endl;
						cout<<"group name="<<g_name<<endl;
						cout<<"name="<<name<<endl;
						cout<<"father name="<<f_name<<endl;
						cout<<"roll no="<<r_name<<endl;
						cout<<"phone no="<<m_name<<endl;
						cout<<"cnic="<<cnic<<endl;
						found++;
					}
					fin>>s>>g_name>>name>>f_name>>r_name>>m_name>>cnic;
				}		
				if(found==0)
				{
					cout<<"data is not found:"<<endl;
				}
			}
				fin.close();
				menu();
	        	}
};
class bookcourse:public s_addmission
{
	public:
		add_course()
		{
			cout<<"\t\t====== Select books for course ====="<<endl;
			ofstream file4("e:\\book.txt",ios::app|ios::out);
			string book;
			int k;
			cout<<"enter semester=";
			cin>>s;
			cout<<"enter student name=";
			cin>>name;
			cout<<"enter student roll no=";
			cin>>r_name;
			cout<<"enetr student department=";
			cin>>g_name;
			cout<<"enter your book no. of "<<g_name<<" department"<<endl;
			cin>>k;
			file4<<"semester="<<s<<"\t"<<"name="<<name<<"\t"<<"roll no="<<r_name<<"\t"<<"department="<<g_name<<endl;
			file4<<"Books are...."<<endl;
			for(int i=1;i<=k;i++)
			{
				cout<<i<<"=";cin>>book;
				file4<<book<<"\t";
			}
			file4<<endl;
			file4<<"_____________________________"<<endl;
			cout<<"you enroll in cs department.."<<endl;
		}
};
class fees:public bookcourse{
	public:
		fee_menu()
		{
			int m;
			cout<<"\t\t_______________________"<<endl;
			cout<<"\t\t  1. add fee"<<endl;
			cout<<"\t\t  2. display fee"<<endl;
			cout<<"\t\t  3. back college menu"<<endl;
			cout<<"\t\t_______________________"<<endl;
			cout<<"enter your choice=";
			cin>>m;
			if(m==1)
			{
				add_fees();
			}
			else if(m==2)
			{
					cout<<"\t\t===== Display fees =====\n"<<endl;
							ifstream fin("student fee.txt",ios::in);
							fin>>name>>r_name>>g_name>>s>>fee;
							while(!fin.eof())
							{
				            cout<<"name="<<name<<endl;
				            cout<<"roll no="<<r_name<<endl;
				            cout<<"department="<<g_name<<endl;
				            cout<<"semester="<<s<<endl;
				            cout<<"fees ="<<fee<<endl;
								cout<<"____________________"<<endl;
								fin>>name>>r_name>>g_name>>s>>fee;
								break;
							}
							fin.close();
							fee_menu();
			}
			else if(m==3)
			{
				//menu();
			}
			else
			{
				cout<<"invalid choice"<<endl;
			}
		}
		void add_fees()
		{
			ofstream file3("e:\\student fee.txt",ios::app|ios::out);
			cout<<"\t\t===== Deposit fee ====="<<endl;
			cout<<"enter student name=";
			cin>>name;
			cout<<"enter student roll no=";
			cin>>r_name;
			cout<<"enter student department name=";
			cin>>g_name;
			cout<<"enter student semester=";
			cin>>s;
			cout<<"Deposit fee(1st 4 semester -/5700...5,6,7,8 -/6000)=";
			cin>>fee;
			 if(fee==5700 || fee==6000)
			{
				cout<<"Welcome in "<<g_name<<" department!"<<endl;
				file3<<"name="<<name<<endl;
				file3<<"roll no="<<r_name<<endl;
				file3<<"department="<<g_name<<endl;
				file3<<"semester="<<s<<endl;
				file3<<"fees ="<<fee<<endl;
				file3<<"__________________"<<endl;
			}
			else
			{
				cout<<"fee is not deposit"<<endl;
			}
			fee_menu();
		}
};
class exam:public fees{
	public:
		float avg;
		exam()
		{
			avg=0;
		}
		void exams()
		{
			int x;
			cout<<"_______________________"<<endl;
			cout<<"  1. add result"<<endl;
			cout<<"  2. display result"<<endl;
			cout<<"  3. back college menu"<<endl;
			cout<<"_______________________"<<endl;
			cout<<"enter your choice=";
			cin>>x;
			if(x==1)
			{
				result();
			}
			else if(x==2)
			{
					cout<<"\t\t===== Display Result =====\n"<<endl;
							ifstream fin("Result.txt",ios::in);
							fin>>r_name>>name>>g_name>>avg;
							while(!fin.eof())
							{
								cout<<"roll no="<<r_name<<endl;
								cout<<"name="<<name<<endl;
								cout<<"Department="<<g_name<<endl;
								cout<<"Percentage="<<avg<<endl;
								cout<<"____________________"<<endl;
								fin>>r_name>>name>>g_name>>avg;
								break;
							}
							fin.close();
							exams();
			}
			else if(x==3)
			{
				// menu();
			}
			else
			{
				cout<<"invalid choice"<<endl;
			}
		}
		void result()
		{
			ofstream fout("e:\\Result.txt",ios::app|ios::out);
			int n,m1,sum=0; string name1;
		//	float avg=0;
	cout<<"\t\t===== Add result of student ====="<<endl;
	cout<<"enter student roll no=";
	cin>>r_name;
	cout<<"enter student name=";
	cin>>name;
	cout<<"enter student department name=";
	cin>>g_name;
	cout<<"enter semester=";
	cin>>s;
	cout<<"enter student book no=";
	cin>>n;
	cout<<"_______________________"<<endl;
	cout<<" Book name   |   marks"<<endl;
	cout<<"-----------------------"<<endl;
	for(int i=1; i<=n;i++)
	{
		cin>>name1;cout<<"\t\t";cin>>m1;
		sum=sum+m1;
	}
	avg=sum/n;
	fout<<"roll no="<<r_name<<endl;
	fout<<"name="<<name<<endl;
	fout<<"department="<<g_name<<endl;
	fout<<"semester="<<s<<endl;
	fout<<"Percentage="<<avg<<endl;
	exams();
        }
};
class attendance:public exam
{
	public:
	add_attendence()
	{
		cout<<"\t\t===== Attendance rigister ====="<<endl;
		ofstream file5("e:\\attendance rigister.txt",ios::app|ios::out);
	string A; int d,m,y;
	char ch='y';
	while(ch=='y')
	{
	cout<<"enter semester=";
	cin>>s;
	cout<<"enter student department name=";
	cin>>g_name;
	cout<<"enter student roll no=";
	cin>>r_name;
	cout<<"student present y/N =";
	cin>>A;
	cout<<"enter date : ";
	cin>>d >>m >>y;
	file5<<"semester="<<s<<endl;
	file5<<"department="<<g_name<<endl;
	file5<<"roll no="<<r_name<<endl;
	file5<<"present y/n="<<A<<endl;
	file5<<"date="<<d<<"_"<<m<<"_"<<y<<endl;
	file5<<"________________"<<endl;
	cout<<"Take another attendance y & n=";
	cin>>ch;
}
}
};
int main()
{
	attendance E;
	{
	 p:
           	int h;
           		cout<<"\t\t\t******************************"<<endl;
				cout<<"\t\t\t     Main List of college"<<endl;
				cout<<"\t\t\t******************************"<<endl;
				cout<<"\t\t\t  1. Addmission"<<endl;
				cout<<"\t\t\t  2. Enrol course"<<endl;
				cout<<"\t\t\t  3. Deposit fees"<<endl;
				cout<<"\t\t\t  4. Result"<<endl;
				cout<<"\t\t\t  5. Attendence"<<endl;
				cout<<"\t\t\t  6. Exit"<<endl;
				cout<<"\t\t\t******************************"<<endl;
				cout<<"enter your choice =";
				cin>>h;
				if(h==1)
				{
				  E.menu();
				  goto p;
				}
				else if(h==2)
				{
					E.add_course();
					goto p;
				}
				else if(h==3)
				{
					E.fee_menu();
					goto p;
				}
				else if(h==4)
				{
					E.exams();
					goto p;
				}
				else if(h==5)
				{
					E.add_attendence();
					goto p;
				}
				else if(h==6)
				{
				   E.exit();
				   goto p;
				}
				else
				{
					cout<<"invalid choice"<<endl;
				goto p;
				}
			}
}
