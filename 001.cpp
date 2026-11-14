#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Item{

private:
	string ID;
	string category;
	string name;
	float price;
	int quantity;

public:

	void set_Item(string, string, string, float, int);
	void set_quantity(int);
	void set_price(float);
	void set_ID(string);

	string get_ID(void);
	string get_cateogry(void);
	string get_name(void);
	float get_price(void);
	int get_quantity(void);

	void display_item(void);

	bool operator==(Item);
	bool operator != (Item);

	
	friend bool operator == (string, Item);
	
	
};


void Item::set_ID(string U_name){
	ID = U_name;
}

void Item::set_Item(string s_ID, string s_cat, string s_name, float s_price, int s_quantity){
	ID = s_ID;
	category = s_cat;
	name = s_name;
	price = s_price;
	quantity = s_quantity;
}

void Item::set_quantity(int new_quantity){
	quantity = new_quantity;
}

void Item::set_price(float new_price){
	price = new_price;
}

string Item::get_ID(void){
	return this->ID;
}

string Item::get_cateogry(void){
	return category;
}

string Item::get_name(void){
	return name;
}

float Item::get_price(void){
	return price;
}

int Item::get_quantity(void){
	return quantity;
}

void Item::display_item(void){
	cout << "Product ID: " << ID << endl;
	cout << "Product Category: " << category << endl;
	cout << "Product Name: " << name << endl;
	cout << "Product Price: " << price << endl;
	cout << "Product Quantity: " << quantity << endl;

}


bool Item::operator==(Item to_compare){
	if (ID == to_compare.ID || name == to_compare.get_name()){
		return true;
	}

	return false;
}

bool Item::operator!=(Item to_compare){

	if (this->ID != to_compare.ID){
		return true;
	}

	return false;
}

bool operator==(string to_find, Item item){

	if (item.ID == to_find){
		return true;
	}
	else if (item.category == to_find){
		return true;
	}
	else if (item.name == to_find){
		return true;
	}

	return false;

}

class Dairy : public Item{

private:

	

public:
	


};

class Bakery : public Item{

private:

public:


};

class Beverages : public Item{

private:

public:


};

class Household : public Item{

private:

public:


};

class Health : public Item{

private:

public:

};


class Inventory{

private:
	int inventory_size;
	Item* inv_items;

public:

	void set_inventory_size(int);
	int get_inventory_size(void);

	void set_inventory(Item*);

	void add_item(Item);
	void delete_item(Item);
	void update_quantity(Item,int);
	void update_price(Item, float);

	void search(string);

	void show_inventory(void);
	void operator= (Inventory);

	Item take_item(string);

	void write_data_to_file(void);

	friend bool operator==(Item, Inventory);

	friend bool operator ==(string, Inventory);
};

bool operator==(Item to_find, Inventory in_find){

	for (int i = 0; i < in_find.get_inventory_size(); i++){
		if (to_find.get_ID() == in_find.inv_items[i].get_ID()){
			return true;
		}

	}

	return false;
}


void Inventory::set_inventory_size(int size){
	inv_items = new Item[size];
	inventory_size = size;
}

int Inventory::get_inventory_size(void){
	return inventory_size;
}

void Inventory::set_inventory(Item* items){

	for (int i = 0; i < inventory_size; i++){
		inv_items[i] = items[i];
	}
}

void Inventory::write_data_to_file(void){

	ofstream file_write;

	file_write.open("inventory.txt", ios::trunc);

	for (int i = 0; i < inventory_size; i++){

		file_write << inv_items[i].get_ID() << "\t";
		file_write << inv_items[i].get_cateogry() << "\t";
		file_write << inv_items[i].get_name() << "\t";
		file_write << inv_items[i].get_price() << "\t";
		file_write << inv_items[i].get_quantity() << "\n";

	}

	file_write.close();


}



Item Inventory::take_item(string ref_search){

	int false_count = 0;

	for (int i = 0; i < inventory_size; i++){
		if (ref_search == inv_items[i].get_ID() || ref_search == inv_items[i].get_name()){
			return inv_items[i];
		}
		else{
			false_count++;
		}
	}
	
	if (false_count == inventory_size){
		cout << "Product Not Found" << endl;
	}
}


void Inventory::add_item(Item to_add){

	Item* temp_item = new Item[inventory_size];

	for (int i = 0; i < inventory_size; i++){
		temp_item[i] = inv_items[i];
	}

	delete[] inv_items;

	inventory_size = inventory_size + 1;

	inv_items = new Item[inventory_size];

	for (int i = 0; i < inventory_size - 1; i++){
		inv_items[i] = temp_item[i];
	}

	inv_items[inventory_size - 1] = to_add;

	delete[] temp_item;
	temp_item = NULL;

	write_data_to_file();
}

void Inventory::delete_item(Item to_remove){

	int index_to_remove = 0;

	int false_counter = 0;

	for (int i = 0; i < inventory_size; i++){

		if (inv_items[i] == to_remove){

			index_to_remove = i;
			Item* temp_item = new Item[inventory_size];

			for (int i = 0; i < inventory_size; i++){
				temp_item[i] = inv_items[i];
			}

			delete[] inv_items;
			inventory_size = inventory_size - 1;
			inv_items = new Item[inventory_size];

			Item temp = temp_item[index_to_remove];
			for (int i = 0; i < inventory_size; i++){
				if (temp_item[i] != temp){
					inv_items[i] = temp_item[i];
				}
			}
			
			delete[] temp_item;
			temp_item = NULL;
			write_data_to_file();
		}

		else{
			false_counter++;
		}
	}

	if (false_counter == inventory_size){
		cout << "Product Not Found" << endl;
	}
}

void Inventory::update_quantity(Item to_update, int new_quantity){

	int false_count = 0;

	for (int i = 0; i < inventory_size; i++){

		if (to_update == inv_items[i]){
			inv_items[i].set_quantity(new_quantity);
			write_data_to_file();
		}

		else{
			false_count++;
		}
	}
	
	if (false_count == inventory_size){
		cout << "Product Not Found" << endl;
	}

}

void Inventory::update_price(Item to_update, float new_price){

	int false_count = 0;
	for (int i = 0; i < inventory_size; i++){

		if (to_update == inv_items[i]){
			inv_items[i].set_price(new_price);
			write_data_to_file();
		}
		else{
			false_count++;
		}
	}

	if (false_count == inventory_size){
		cout << "Product Not Found " << endl;
	}
}

void Inventory::search(string to_search){

	int false_count = 0;

	for (int i = 0; i < inventory_size; i++){

		if (to_search == inv_items[i]){
			inv_items[i].display_item();
		}
		else{
			false_count++;
		}
	}

	if (false_count == inventory_size){
		cout << "Product Not Found " << endl;
	}
}

void Inventory::operator=(Inventory to_equate){

	this->inv_items = to_equate.inv_items;
	for (int i = 0; i < to_equate.inventory_size; i++){
		this->inv_items[i] = to_equate.inv_items[i];
	}

	inventory_size = to_equate.inventory_size;
}

bool operator==(string to_find, Inventory from_find){

	for (int i = 0; i < from_find.get_inventory_size(); i++){
		if (to_find == from_find.inv_items[i].get_ID()){
			return true;
		}
	}

	return false;
}

void Inventory::show_inventory(void){

	cout << "__________________________________________________________________________________________" << endl;
	cout << endl;
	cout << "Product ID" << "\t" << "Product Category" << "\t" << "Product Name" << "\t" << "Product Price" 
		<< "\t" <<"Product Quantity" << endl;
	
	for (int i = 0; i < inventory_size; i++){

		cout << inv_items[i].get_ID() << "\t" << "\t" << inv_items[i].get_cateogry() << "\t" << "\t" <<  "\t" << inv_items[i].get_name()
			<< "\t" << "\t" << inv_items[i].get_price() << "\t" << "\t" << inv_items[i].get_quantity() << endl;
	}

	cout << endl;
	cout << "__________________________________________________________________________________________" << endl;
}





class Purchase{

private:
	Inventory my_inventory;

public:

	void set_inventory(Inventory);
	void addToCart(string, int);
	//float calculate_discount(Item, float);

};

void Purchase::set_inventory(Inventory user_inventory){
	my_inventory = user_inventory;
}

void Purchase::addToCart(string to_find, int amount){
	
	int false_count = 0;

	Item purchased = my_inventory.take_item(to_find);

	for (int i = 0; i < my_inventory.get_inventory_size(); i++){

		if (purchased == my_inventory){
			int quantity_after_purchase = purchased.get_quantity() - amount;
			my_inventory.update_quantity(purchased, quantity_after_purchase);
		}

		else{
			false_count++;
		}
	}

	if (false_count == my_inventory.get_inventory_size()){
		cout << "Product Not Found" << endl;
	}
}





class Record{

private:
	Item* purchased_items;
	int total_items_purchased = 0;

public:

	void add_purchase_item_number(void);
	int get_purchase_number(void);
	void add_to_Customer_Record(Item, int);

	friend void write_recipt(Record& passed_record);

	void display_record(void);
};

void write_recipt(Record& passed_record){

	ofstream file_write;

	file_write.open("reciept.txt", ios::trunc);

	file_write << "Name" << "\t Price" << "\t Quantity" << endl;

	for (int i = 0; i < passed_record.get_purchase_number(); i++){

		file_write << passed_record.purchased_items[i].get_name()<< "\t";
		file_write << passed_record.purchased_items[i].get_price() << "\t";
		file_write << passed_record.purchased_items[i].get_quantity() << endl;
		file_write << endl;

		file_write << "Total Bill: Rs. ";

		float total_bill = 0;

		for (int i = 0; i < passed_record.get_purchase_number(); i++){
			total_bill = passed_record.purchased_items[i].get_price() + total_bill;
		}

		file_write << total_bill << endl;

		file_write << "Date: 18/05/2023" << endl;

	}

	file_write.close();




}


void Record::add_purchase_item_number(void){
	total_items_purchased++;
}

int Record::get_purchase_number(void){
	return total_items_purchased;
}


void Record::add_to_Customer_Record(Item purchased_item, int quantity_purchased){

	if (total_items_purchased == 1){
		purchased_items = new Item[1];
		purchased_items[0].set_quantity(quantity_purchased);
		purchased_items[0] = purchased_item;
	}

	else if (total_items_purchased > 1){

		Item* temp_item = new Item[total_items_purchased - 1];

		for (int i = 0; i < total_items_purchased - 1; i++){
			temp_item[i] = purchased_items[i];
		}

		delete purchased_items;

		purchased_items = new Item[total_items_purchased];

		for (int i = 0; i < total_items_purchased - 1; i++){
			purchased_items[i] = temp_item[i];
		}
		purchased_items[total_items_purchased - 1] = purchased_item;
		purchased_items[total_items_purchased - 1].set_quantity(quantity_purchased);
	}

}

void Record::display_record(void){

	cout << "\t \t Purchased Item(s)" << endl;

	for (int i = 0; i < total_items_purchased; i++){
		cout << "\t" << purchased_items[i].get_name() << "\t" << purchased_items[i].get_cateogry() 
			<< "\t" << purchased_items[i].get_price() << "\t" << purchased_items[i].get_quantity() << endl;
	}

	cout << "Date of Purchase: ";

	/*time_t currentTime = time(nullptr);
	tm* localTime = localtime(&currentTime);

	int year = localTime->tm_year + 1900;
	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;

	cout << year << "-" << month << "-" << day << endl;*/

	cout << "19-05-2023" << endl;

	cout << "Total Bill: Rs. ";

	float total_bill = 0;

	for (int i = 0; i < total_items_purchased; i++){
		total_bill = total_bill + (purchased_items[i].get_price() * purchased_items[i].get_quantity());
	}

	cout << total_bill << endl;
}


class Employee{

private:
	string employee_ID;
	string designation;
	string name; 
	float salary;
	string date;

public:

	void set_designation(string);

	string get_designation(void);
	string get_employee_ID(void);
	string get_name(void);
	float get_salary(void);
	string get_date(void);

	void set_Employee(string, string, string, float, string);

	bool is_employee(string);


};

float Employee::get_salary(void){
	return salary;
}

string Employee::get_date(void){
	return date;
}

void Employee::set_designation(string str){
	designation = str;
}


void Employee::set_Employee(string S_employee_ID, string S_designation, string S_name, float S_salary, string S_date){
	employee_ID = S_employee_ID;
	designation = S_designation;
	name = S_name;
	salary = S_salary;
	date = S_date;
}

bool Employee::is_employee(string employee_to_check){

	if (employee_to_check == name || employee_to_check == employee_ID){
		return true;
	}

	return false;
}

string Employee::get_designation(void){
	return designation;
}

string Employee::get_employee_ID(void){
	return employee_ID;
}

string Employee::get_name(void){
	return name;
}


class Sale_Employee : public Employee{

public:
	
	Sale_Employee(void);

};

Sale_Employee::Sale_Employee(void){
	set_designation("Cashier");
}

class Employee_Database{

private:
	Employee* employees;
	int number_of_employees = 0;

public:
	void set_employee_number(int);
	void set_employee(Employee*);
	int get_no_of_employees(void);
	Employee take_employee(string);
	bool is_employee(Employee*);

	void display_employees(void);
};

void Employee_Database::display_employees(void){

	cout << "__________________________________________________________________________________________" << endl;
	cout << endl;

	cout << "ID" << "\t" << "\t" << "Name" << "\t" << "\t" << "\t" << "Designation" << "\t" << "Salary" << "\t" << "\t" << "\t" << "Payment Date" << endl;

	for (int i = 0; i < number_of_employees; i++){

		cout << employees[i].get_employee_ID() << "\t" << "\t" << employees[i].get_name() << "\t" << "\t" << "\t" << employees[i].get_designation()
			<< "\t" << "\t" <<"Rs. "<< employees[i].get_salary() << "\t" << "\t" << employees[i].get_date() << endl;
	}

	cout << endl;
	cout << "__________________________________________________________________________________________" << endl;

}

void Employee_Database::set_employee_number(int no_of_employees){
	employees = new Employee[no_of_employees];
	number_of_employees = no_of_employees;
}

int Employee_Database::get_no_of_employees(void){
	return number_of_employees;
}

Employee Employee_Database::take_employee(string to_search){
	
	Employee null;

	for (int i = 0; i < number_of_employees; i++){
		if (to_search == employees[i].get_name() || to_search == employees[i].get_employee_ID()){
			return employees[i];
		}
	}
	
	return null;
}

void Employee_Database::set_employee(Employee* employee_ptr){

	for (int i = 0; i < number_of_employees; i++){
		employees[i] = employee_ptr[i];
	}
}

bool Employee_Database::is_employee(Employee* to_check){

	for (int i = 0; i < number_of_employees; i++){

		if (to_check->get_name() == employees[i].get_name() ||
			to_check->get_employee_ID() == employees[i].get_employee_ID()){

			if (to_check->get_designation() == "Cashier"){
				return true;
			}
		}
	}

	return false;

}

class Reciept : public Record{

public:

	Sale_Employee counter_employee;
	string date;

public:

	void print_receipt(Employee*);
};

void Reciept::print_receipt(Employee* employee){

	display_record();
}


class Customer{
	
private:
	string name;
	Purchase customer_purchase;
	Record customer_record;
	Reciept customer_reciept;

public:

	Customer(void);
	Customer(string);
	void purchase(string, Inventory, int);
	void print_reciept(Employee*);
	void print_record(void);

};

void Customer::print_record(void){
	customer_record.display_record();
}

Customer::Customer(void){
	name = "Not Available";
}

Customer::Customer(string customer_name){
	name = customer_name;
}

void Customer::purchase(string to_purchase, Inventory inventory, int amount){
	customer_record.add_purchase_item_number();
	
	customer_purchase.set_inventory(inventory);
	customer_purchase.addToCart(to_purchase, amount);

	Item purchased_item = inventory.take_item(to_purchase);

	customer_record.add_to_Customer_Record(purchased_item, amount);

}

void Customer::print_reciept(Employee* cashier){

	write_recipt(customer_record);

}

class bill {
	string catagory, date, price;
	bool paid;
public:
	bill(void){

	};

	bill(string cat, string d, string pr, bool p){
		catagory = cat;
		date = d;
		price = pr;
		paid = p;
	}
	void output(){
		cout << "Bill Catagory: " << catagory << endl;
		cout << "Date: " << date << endl;
		cout << "Price: " << price << endl;
		if (paid == true)
		{
			cout << "Status: Paid" << endl;
		}
		else
		{
			cout << "Status: Not Paid" << endl;
		}
		cout << "-----------------------------" << endl;
	}

	void setcatagory(string c){
		this->catagory = c;
	}

	void setdate(string d){
		this->date = d;
	}

	void setprice(string p){
		this->price = p;
	}

	void setpaid(bool p){
		this->paid = p;
	}
};

void readBILL(void){

	fstream file;
	int no_of_lines = 0;

	file.open("bill.txt", ios::in);


	if (file.is_open()){
		string line1;
		while (getline(file, line1)){
			no_of_lines++;
		}
		file.close();
	}


	bill* objarr = new bill[no_of_lines];

	file.open("bill.txt", ios::in);
	string tempcat, date, price;
	bool paid;
	int objindex = 0;
	if (file.is_open())
	{
		string line;
		while (getline(file, line))	{
	
			char tempcat2[50];
			char tempdate[20];
			char tempcost[10];
			char temppaid[2];
			int k = 0;
			int i = 0;
			for (; line[i] != '\t'; i++)
			{
				tempcat2[k] = line[i];
				k++;
			}
			tempcat2[k] = '\0';
			tempcat = tempcat2;
			
			k = 0;
			i++;
			for (; line[i] != '\t'; i++)
			{
				tempdate[k] = line[i];
				k++;
			}
			tempdate[k] = '\0';
			date = tempdate;
			
			k = 0;
			i++;
			for (; line[i] != '\t'; i++){
				tempcost[k] = line[i];
				k++;
			}

			tempcost[k] = '\0';
			price = tempcost;
			
			k = 0;
			i++;
			for (; line[i] != '\0'; i++){
				temppaid[k] = line[i];
				k++;
			}

			temppaid[k] = '\0';
			if (temppaid[0] == '0')	{
				paid = false;
			}
			else{
				paid = true;
			}
			objarr[objindex].setcatagory(tempcat);
			objarr[objindex].setdate(date);
			objarr[objindex].setpaid(paid);
			objarr[objindex].setprice(price);
			objindex++;
		}

		file.close();
	}
	objindex = 0;

	cout << "=================BILLS DATA===================" << endl;
	for (int i = 0; i < no_of_lines; i++){
		objarr[i].output();
	}

}

void inventory_functionality(int user_option, Inventory grocery_inventory){

	if (user_option == 1){
		grocery_inventory.show_inventory();
	}

	if (user_option == 2){
		Item to_add;

		string ID;
		string category;
		string name;
		float price;
		int quantity;

		cout << "Please Enter New Product ID: ";
		cin >> ID;
		cout << "Please Enter New Product Category: ";
		cin >> category;
		cout << "Please Enter New Product Name: ";
		cin >> name;
		cout << "Please Enter New Product Price: ";
		cin >> price;
		cout << "Please Enter New Product Quantity: ";
		cin >> quantity;


		to_add.set_Item(ID, category, name, price, quantity);

		grocery_inventory.add_item(to_add);
	}

	else if (user_option == 3){

		Item to_delete;
		string ID;

		cout << "Please Enter Product ID: ";
		cin >> ID;

		to_delete.set_ID(ID);

		grocery_inventory.delete_item(to_delete);
	}

	else if (user_option == 4){

		Item to_update;
		string ID;
		int new_quantity = 0;

		cout << "Please Enter Product ID: ";
		cin >> ID;

		cout << endl;

		cout << "Please Enter New Quantity: ";
		cin >> new_quantity;

		to_update.set_ID(ID);

		grocery_inventory.update_quantity(to_update, new_quantity);
	}

	else if (user_option == 5){

		Item to_update;
		string ID;
		float new_price = 0;

		cout << "Please Enter Product ID: ";
		cin >> ID;

		cout << endl;

		cout << "Please Enter New Quantity: ";
		cin >> new_price;

		to_update.set_ID(ID);

		grocery_inventory.update_price(to_update, new_price);
	}
}




void interface (Inventory grocery_inventory, Employee_Database database){

	system("CLS");
	cout << endl;
	cout << "\t \t WELCOME TO AL MADINAH GROCERY STORE" << endl;

	cout << endl;

	cout << "   Please Choose your desired Functionality" << endl;

	cout << endl;

	cout << "\t \t 1. Inventory Management" << endl;
	cout << "\t \t 2. Customer Management" << endl;
	cout << "\t \t 3. Bill Management" << endl;
	cout << "\t \t 4. Employee Management" << endl;

	int user_option = 0;

	cout << "  User Choice: ";
	cin >> user_option;

	if (user_option == 1){
		system("CLS");
		cout << endl;

		cout << "\t \t 1. View Store Invwntory" << endl;
		cout << "\t \t 2. Add Item to Inventory" << endl;
		cout << "\t \t 3. Delete Item from Invwntory" << endl;
		cout << "\t \t 4. Update Item Quantity" << endl;
		cout << "\t \t 5. Update Item Price" << endl;

		cout << "  User Choice: ";
		cin >> user_option;

		inventory_functionality(user_option, grocery_inventory);

	}

	else if (user_option == 2){
		system("CLS");
		cout << endl;

		cout << "\t \t 1. Purchase Item" << endl;
		cout << "\t \t 2. Generate Reciept" << endl;
		cout << "\t \t 3. View Record" << endl;

		cout << "  User Choice: ";
		cin >> user_option;

		Customer general_customer;
		Employee* to_check;
		to_check = new Employee;

		

		if (user_option == 1 || user_option == 2){

			string ID;
			string name;

			cout << "Enter Cashier ID: ";
			cin >> ID;

			if (ID == database.take_employee(ID).get_employee_ID()){
				*to_check = database.take_employee(ID);
				if (database.is_employee(to_check) == true){

					if (user_option == 1){

						string ID;
						int quantity = 0;

						cout << "Please Enter Poduct ID";
						cin >> ID;

						cout << "Please Enter Quantity";
						cin >> quantity;

						if (quantity > grocery_inventory.take_item(ID).get_quantity()){
							cout << "Not Enough Stock" << endl;
						}

						else if (quantity < grocery_inventory.take_item(ID).get_quantity() && quantity > 0){

							general_customer.purchase(ID, grocery_inventory, quantity);
						}
					}

					else if (user_option == 2){
						general_customer.print_reciept(to_check);
					}
				}
			}
		}

		if (user_option == 3){

			general_customer.print_record();
		}
		
	}

	else if (user_option == 3){
		system("CLS");
		cout << endl;

		cout << "\t \t 1. View Bill Directory" << endl;
		cout << "  User Choice: ";
		cin >> user_option;

		if (user_option == 1){
			readBILL();
		}

	}

	else if (user_option == 4){
		system("CLS");
		cout << endl;

		cout << "\t \t 1. View Employee Directory" << endl;
		cout << "  User Choice: ";
		cin >> user_option;

		if (user_option == 1){

			database.display_employees();
		}
	}
	
} 

int count_file_data(string file_name){

	ifstream read_data;
	string file_line;

	int counter = 0;

	read_data.open(file_name);

	while (!read_data.eof()){

		getline(read_data, file_line, '\n');

		if (file_line.length() > 0){
			counter++;
		}
	}

	read_data.close();

	return counter;

}

void ReadFile_Employee(Employee* employee, int total_items){

	ifstream read_file;

	read_file.open("employee.txt");

	string ID;
	string designation;
	string name;
	float salary;
	string date;

	for (int i = 0; i < total_items; i++){

		getline(read_file, ID, '\t');
		getline(read_file, designation, '\t');
		getline(read_file, name, '\t');
		read_file >> salary;
		getline(read_file, date, '\n');
		read_file.ignore();

		employee[i].set_Employee(ID, designation, name, salary, date);
	}



}



void ReadFile_Item(string file_name, Item* items, int total_items){

	ifstream read_data;

	read_data.open(file_name);

	string R_ID;
	string R_category;
	string R_name;
	float R_price;
	int R_quantity;

	for (int i = 0; i < total_items; i++){

		getline(read_data, R_ID, '\t');
		getline(read_data, R_category, '\t');
		getline(read_data, R_name, '\t');
		read_data >> R_price;
		read_data >> R_quantity;
		read_data.ignore();

		items[i].set_Item(R_ID, R_category, R_name, R_price, R_quantity);
	}

	read_data.close();

}





int main(){

	const string file_name = "inventory.txt";
	int grocery_items_in_inventory = count_file_data(file_name);

	Item* grocery_items = new Item[grocery_items_in_inventory];

	ReadFile_Item(file_name, grocery_items, grocery_items_in_inventory);

	Inventory grocery_store_inventory;
	grocery_store_inventory.set_inventory_size(grocery_items_in_inventory);
	grocery_store_inventory.set_inventory(grocery_items);

	const string emp_file = "employee.txt";
	int no_of_employees = count_file_data(emp_file);

	Employee* total_employees = new Employee[no_of_employees];

	ReadFile_Employee(total_employees, no_of_employees);

	Employee_Database database;
	database.set_employee_number(no_of_employees);
	database.set_employee(total_employees);


	interface(grocery_store_inventory, database);

	
	return 0;
}