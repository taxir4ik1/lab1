#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <clocale>
#include <conio.h>
using namespace std;

string selection ();
string testing(string subject, string test);

int main () {

setlocale(LC_ALL, "Russian"); 
selection();
return 0;}



/*/
����� �������� � �����
/*/
string selection (){
	system("cls");
string subject, test, fname;
cout<<"������������ ��������"<<endl<<"1.������ �������������� ������������"<<endl<<"2.�����������"<<endl<<"3.������ ������ � ��������� ������"<<endl<<"�������� ������� ������������: ";
subject=_getch();

while (subject!="1" && subject!="2" && subject!="3"){
	cout<<"\n�� ����� �����������! ������� ������� ������ (������: '2'): ";
subject=_getch();
}
//������ �������������� ������������
if (subject=="1"){
	system("cls");
cout<<"������ �������������� ������������"<<endl<<"1.Test1"<<endl<<"2.Test2"<<endl<<"3.Test3"<<endl<<"�������� ����: ";
test=_getch();	
while (test!="1" && test!="2" && test!="3"){
	cout<<"\n�� ����� �����������! ������� ������� ������ (������: '2'): ";
	test=_getch();}
	
}


//����������
else if (subject=="2"){
	system("cls");
cout<<"�����������"<<endl<<"1.Test1"<<endl<<"2.Test2"<<endl<<"3.Test3"<<endl<<"�������� ����: ";
test=_getch();	
while (test!="1" && test!="2" && test!="3"){
	cout<<"\n�� ����� �����������! ������� ������� ������ (������: '2'): ";
test=_getch();	}
		
}

//������ ������ � ��������� ������
else if (subject=="3"){
	system("cls");
cout<<"������ ������ � ��������� ������"<<endl<<"1.Test1"<<endl<<"�������� ����: ";
test=_getch();		
while (test!="1"){
	cout<<"\n�� ����� �����������! ������� ������� ������ (������: '2'): ";
test=_getch();	}
	
	
}
testing (subject, test);
}



string testing(string subject, string test){
string pred;
ifstream t1;
//�� ������ ����� ��������� ������ ����
if (subject=="1" && test=="1"){
	t1.open("test\\oib_test1.txt"); pred="������ �������������� ������������, ���� �1";}
else if (subject=="1" && test=="2"){
	t1.open("test\\oib_test2.txt");  pred="������ �������������� ������������, ���� �2";}
else if (subject=="1" && test=="3" ){
	t1.open("test\\oib_test3.txt");  pred="������ �������������� ������������, ���� �3";}
else if (subject=="2" && test=="1"){
	t1.open("test\\infa_test1.txt"); pred="�����������, ���� �1";}  
else if (subject=="2" && test=="2"){
	t1.open("test\\infa_test2.txt");pred="�����������, ���� �2";}
else if (subject=="2" && test=="3"){
	t1.open("test\\infa_test3.txt"); pred="�����������, ���� �3";}
else if (subject=="3" && test=="1"){
	t1.open("test\\tsisa_test1.txt"); pred="������ ������ � ��������� ������, ���� �1";}
	
//���� ����� �� ����������
if (!t1.is_open()) {
cout << "���� �� ����� ���� ������!\n";
string cik;
cout<<"������ ���������� �������������? (y/n): ";
	cik=_getch();
while (cik!="y" && cik!="n"){
	cout<<"\n�� ����� �����������! ������� ������ (y/n): ";
		cik=_getch();}
if (cik=="y"){selection();}
else {exit(0);}}

//�����������
string q, a[4],b;
string q1;
int ot=0, et=0,v;
system("cls");
while (!t1.eof())
					{
						
					getline(t1, q);
					
					cout<<q<<endl<<endl;
													
						for (int u=0; u<=3; u++)
							{
								getline(t1, a[u]);
						cout<<a[u]	<<endl;
							}
							getline(t1, b);
							
							cout<<"������� �����: ";
								q1=_getch();		
while (q1!="1" && q1!="2" && q1!="3" && q1!="4"){
	cout<<"\n�� ����� �����������! ������� ����� ������(������: '2'): ";
	q1=_getch();}	
							if(int(q1[0])==int(b[0])){ot++;
							}
							else {et++;}
							system("cls");
							
					} 
					t1.close();
					
int all=ot+et;					
cout<<"���������� �������: "<<ot<<endl<<"������������ �������: "<<et<<endl;
int ochenka= ot*100/all;
int vivoc;
if (ochenka<50){cout<<"���� ������: 2"<<endl; vivoc=2;}
else if (ochenka>=50 && ochenka<70){cout<<"���� ������: 3"<<endl; vivoc=3;}
else if (ochenka>=70 && ochenka<85){cout<<"���� ������: 4"<<endl; vivoc=4;}
else if (ochenka>=85){cout<<"���� ������: 5"<<endl; vivoc=5;}


string sik;
cout<<"������ ��������� ���������� ������������? (y/n): ";
	sik=_getch();	
while (sik!="y" && sik!="n"){
	cout<<"\n�� ����� �����������! ������� ������ (y/n): ";
	sik=_getch();	}
if (sik=="y"){
string qname, sname;
cout<<endl<<"������� ���� ���: ";
getline(cin, sname);
cout<<endl<<"������� ���� �������: ";
getline(cin, qname);
	ofstream fout("log.txt", ios_base::app); 
    fout<<qname<<" "<< sname<<" - "<<pred<<", ������: "<<vivoc<<endl;
    fout.close(); }					




string cik;
cout<<"������ ���������� �������������? (y/n): ";
	cik=_getch();	
while (cik!="y" && cik!="n"){
	cout<<"\n�� ����� �����������! ������� ������ (y/n): ";
		cik=_getch();	}
if (cik=="y"){selection();}
else {exit(0);}}





