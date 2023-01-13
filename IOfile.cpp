#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	int accountno;
	char name[30];
	float amount;
}s;
int main()
{
	int ch,c,acc,flag;
	ofstream OF,OF1;
	OF.open("rec.txt");
	ifstream IF;
	do
	{
		cout<<"Enter the operation you want to perform::";
		cout<<"\n1.Add record\t2.Display\t3.Delete\t4.Modify\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				do
				{
					cout<<"\nAccount no \tName\tamount\n";
					cin>>s.accountno>>s.name>>s.amount;
					OF<<"\t"<<s.accountno;
					OF<<"\t"<<s.name;
					OF<<"\t"<<s.amount;
					cout<<"\nDo you want to add more record?\n1.Yes \t2.No:: ";
					cin>>c;
				}while(c==1);
				OF.close();
				break;
			case 2:
				IF.open("rec.txt");
				while(!IF.eof())
				{
					IF>>s.accountno;
					IF>>s.name;
					IF>>s.amount;
					cout<<"\nAccount: "<<s.accountno;
					cout<<"\nName: "<<s.name;
					cout<<"\nAmount: "<<s.amount;
					cout<<"\n";
				}
				cout<<"\n";
				IF.close();
				break;
				
			case 3:
					OF1.open("Record.txt");
					IF.open("rec.txt");
					cout<<"\nEnter the account no you want to delete: ";
					cin>>acc;
					flag=0;
					while(!IF.eof())
					{	
						IF>>s.accountno;
						IF>>s.name;
						IF>>s.amount;
						if(acc==s.accountno)
						{
							flag=1;
							cout<<"\nRecord deleted!!";
						}
						else if(acc!=s.accountno)
						{
							OF1<<"\t"<<s.accountno;
							OF1<<"\t"<<s.name;
							OF1<<"\t"<<s.amount;
						}
					}
					if(flag==0)
					{
						cout<<"\nRecord not present!!";
					}
					IF.close();
					OF1.close();
					remove("rec.txt");
					rename("Record.txt","rec.txt");
					break;
				case 4:
						OF1.open("Record.txt");
						IF.open("rec.txt");
						cout<<"\nEnter the account no you want to delete: ";
						cin>>acc;
						flag=0;
						while(!IF.eof())
						{
							IF>>s.accountno;
							IF>>s.name;
							IF>>s.amount;
							if(acc==s.accountno)
							{
								cout<<"\nAccount no\t Name\t Amount\n";
								cin>>s.accountno>>s.name>>s.amount;
								OF1<<"\t"<<s.accountno;
								OF1<<"\t"<<s.name;
								OF1<<"\t"<<s.amount;
								flag=1;
							}
							else if(acc!=s.accountno)
							{
								OF1<<"\t"<<s.accountno;
								OF1<<"\t"<<s.name;
								OF1<<"\t"<<s.amount;
							}
						}
						if(flag==0)
						{
							cout<<"\nRecord not present!!";
						}
						IF.close();
						OF1.close();
						remove("rec.txt");
						rename("Record.txt","rec.txt");
						break;
					}
					cout<<"\nWant to continue 1.Yes \t 2.No::\n  ";
					cin>>c;
	}while(c==1);
return 0;
}

