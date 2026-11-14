# Inventory-management-system---OOP
📦 Grocery Store Inventory Management System (C++ OOP)

A console-based Grocery Store Inventory Management System developed in C++ using Object-Oriented Programming (OOP) concepts. The project is designed to manage grocery products, maintain inventory records, update stock quantities, manage product prices, and handle product purchases.

The system uses classes, objects, inheritance, operator overloading, friend functions, dynamic memory allocation, and file handling to organize and manage inventory operations efficiently.

📌 Project Overview

Project Name: Grocery Store Inventory Management System

Programming Language: C++

Course: Object-Oriented Programming (OOP)

Application Type: Console-Based Application

Data Storage: Text File Handling

✨ Key Features

1. Inventory Management

View all available products.

Add new products to the inventory.

Delete products using their unique Product ID.

Update product prices.

Update available product quantities.

Search products using Product ID or product name.

2. Product Management

Maintain product IDs and categories.

Store product names and prices.

Manage available stock quantities.

Organize products into different categories, including:

Dairy

Bakery

Beverages

Household

Health

3. Stock Management

Check available product quantities.

Verify stock before processing purchases.

Automatically reduce inventory quantities after purchases.

Maintain updated inventory records.

4. Customer Purchase Management

Purchase products using Product IDs.

Specify the required quantity.

Check product availability.

Maintain customer purchase records.

Calculate the total purchase amount.

5. Billing and Receipt Management

Generate customer receipts.

Display purchased product details.

Calculate total bills.

Store receipt and billing information in text files.

6. Employee Management

Maintain employee records.

Store employee ID, name, designation, salary, and payment date.

Display the employee directory.

Verify cashier information during customer transactions.

🧠 Object-Oriented Programming Concepts

This project demonstrates the practical implementation of the following OOP concepts:

OOP Concept

Implementation

Classes and Objects

Item, Inventory, Customer, Employee, Purchase, Record

Encapsulation

Private data members with public getters and setters

Inheritance

Dairy, Bakery, Beverages, Household, Health, and Sale_Employee

Operator Overloading

==, !=, and = operators

Friend Functions

Accessing private members through friend functions

Dynamic Memory Allocation

Using new and delete

Composition

Customer class contains Purchase, Record, and Reciept objects

🛠️ Technologies Used

C++ – Core programming language.

iostream – Input and output operations.

fstream – File handling and data storage.

string – Product and employee information.

ctime – Date and time functionality.

cstdlib – Standard utility functions.
