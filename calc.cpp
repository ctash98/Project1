/*
	Name: Christopher Melendez
	Instructor: Anoop
	Course: CSCI 135
	Assignment: Project 1B
*/

#include <iostream>
#include <string>
using namespace std;
 
//Initialize array for handling inputs
const int capacity = 100;
int current_size = 0;
string inputted_values[capacity];

//Variables
int i = 0, j = 0;
string c;
double total;
double current_number = 0;
string operation;


//Handle Input: While loop takes in all inputs one by one and fills array with numbers & operations.
//NOTE: Only accepts format (Number Space Operation Space Number ..)
void handle_input() {
	while(cin >> c) {
		inputted_values[i] = c;
		i++;
		current_size++;
	}
}

//Calculator Logic
void calculate() {
	
	total = stod(inputted_values[0]); //Initialize total with the first value
	
	for(j=1;j<current_size;j++) {	//Loop through array with inputted values
		if (j%2 == 0) { //If it's an even index (All numbers are even index in correct format) then do math
			
			current_number = stod(inputted_values[j]); //Store current number and convert from string to double
			
			//Perform math based on operation
			if(operation == "add") {
				total+=current_number;
			}
			if(operation == "subtract") {
				total-=current_number;
			}
			
		}
		else { //If it's an odd index (All operators are odd index in correct format) then assign operation
			if(inputted_values[j] == "+") {
				operation = "add";
			}
			else if(inputted_values[j] =="-") {
				operation = "subtract";
			}
			else {
				cout<<"ERROR: Follow Correct Input Format (Number Space Operation Space Number ..)"<<endl;
			}
		}
	}
}

//Main Function
int main() {
	//Call functions
	handle_input(); //read in text file
	calculate();	//do calculations
	
	//Output Total
	cout<<"The total is: "<<total<<endl;
}