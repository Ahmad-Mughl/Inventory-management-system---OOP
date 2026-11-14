//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//
////class Items_Grocery{
////
////private:
////
////	int ID;
////	string category;
////	float price;
////	int amount;
////
////};
////
////void readFile(Items_Grocery* items){
////
////	ifstream read_var;
////
////	read_var.open("inventory.txt");
////
////	for (Items_Grocery var : items){
////
////	}
////
////
////
////}
////
////
////
////int main(){
////
////
////
////	return 0;
////}
//
//
//
//
//class employee {
//	string employee_id, designation, name, pay, date;
//public:
//	employee()
//	{
//
//	}
//	employee(string id, string desig, string nam, string pa, string dat)
//	{
//		employee_id = id;
//		designation = desig;
//		name = nam;
//		pay = pa;
//		date = dat;
//	}
//	void setid(string id)
//	{
//		this->employee_id = id;
//	}
//	void setdesig(string d)
//	{
//		this->designation = d;
//	}
//	void setname(string n)
//	{
//		this->name = n;
//	}
//	void setpay(string p)
//	{
//		this->pay = p;
//	}
//	void setdate(string d)
//	{
//		this->date = d;
//	}
//	void output()
//	{
//		cout << "Employee ID: " << employee_id << endl;
//		cout << "Designation: " << designation << endl;
//		cout << "Name: " << name << endl;
//		cout << "Pay: " << pay << endl;
//		cout << "Date: " << date << endl;
//		cout << "-----------------------------" << endl;
//	}
//};
//
//int main() {
//
//	
//
//	int no_of_lines_e = 0;
//	file.open("employee.txt", ios::in);
//	if (file.is_open())
//	{
//		string line1;
//		while (getline(file, line1))
//		{
//			no_of_lines_e++;
//		}
//		file.close();
//	}
//	employee* employees = new employee[no_of_lines_e];
//	file.open("employee.txt", ios::in);
//	string tempid, desig, tempname, pay, tempdate;
//	int objindexe = 0;
//	if (file.is_open())
//	{
//		string line;
//		while (getline(file, line))
//		{
//			//cout << line << endl;
//			char tempid2[50];
//			char name[50];
//			char tempdate2[20];
//			char tempedsig[10];
//			char temppay[10];
//			int k = 0;
//			int i = 0;
//			for (; line[i] != '\t'; i++)
//			{
//				tempid2[k] = line[i];
//				k++;
//			}
//			tempid2[k] = '\0';
//			tempid = tempid2;
//			k = 0;
//			i++;
//			for (; line[i] != '\t'; i++)
//			{
//				tempedsig[k] = line[i];
//				k++;
//			}
//			tempedsig[k] = '\0';
//			desig = tempedsig;
//			k = 0;
//			i++;
//			for (; line[i] != '\t'; i++)
//			{
//				name[k] = line[i];
//				k++;
//			}
//			name[k] = '\0';
//			tempname = name;
//			k = 0;
//			i++;
//			for (; line[i] != '\t'; i++)
//			{
//				temppay[k] = line[i];
//				k++;
//			}
//			temppay[k] = '\0';
//			pay = temppay;
//			k = 0;
//			i++;
//			for (; line[i] != '\0'; i++)
//			{
//				tempdate2[k] = line[i];
//				k++;
//			}
//			tempdate2[k] = '\0';
//			tempdate = tempdate2;
//			employees[objindexe].setdate(tempdate);
//			employees[objindexe].setpay(pay);
//			employees[objindexe].setdesig(tempedsig);
//			employees[objindexe].setname(tempname);
//			employees[objindexe].setid(tempid);
//			objindexe++;
//		}
//		file.close();
//	}
//	objindexe = 0;
//	cout << "=================EMPLOYEES DATA===================" << endl;
//	for (int i = 0; i < no_of_lines_e; i++)
//	{
//		employees[i].output();
//	}
//
//	return 0;
//}