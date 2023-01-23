//hydro.cpp
//William Fraser 30158991


#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <limits>
using namespace std;

#include "hydro.h"
#include "list.h"


int main()
{
    displayHeader();
    FlowList list;
    int no_items = readData(list);
    int quit = 0;
    
    while(1)
    {
    int selection = menu();
    //if statement used to eliminate a bug when a character is entered
    //as a menu selection, as default case did not work for this.
    if (selection) switch(selection){
        case 1:
        display(list, no_items);
        pressEnter();
        break;
        case 2:
        addData(list, no_items); 
        pressEnter();
        break;
        case 3:
        saveData(list);
        pressEnter();
        break;
        case 4:
        removeData(list, no_items);
        pressEnter();
        break;
        case 5:
        cout << "\nPragram terminated!\n\n";
        quit = 1;
        break;
        default:
        cout << "\nNot a valid input.\n";
        pressEnter();
        break;
    }
    else{
        cout << "Not a valid input.\n";
        cin.clear();
        pressEnter();
    }
    if (quit == 1) break;
    } 
}

int readData(FlowList &list){
    fstream flowfile; //creates empty object
    //opens file and exits program if it fails
    flowfile.open("flow.txt", ios::in);
    if (!flowfile){
        cout << "error opening file... quitting.";
        exit(1);
    }
    int year;
    double flow;
    int i = 0;
    while(flowfile >> year >> flow){
        struct ListItem itemA = {year, flow};
        list.insert(itemA);
        i++;
    }
    flowfile.close();
    return i;
};

void displayHeader(){
    cout << "Program: Flow Studies - Fall 2022\n"
    "Version: 1.0\nLab section: B02\nProduced by: William Fraser"
    << endl;
    cout << "<<<Press Enter to Continue>>>" << endl;
    cin.get();
};

int menu(){
    cout << "Please select on the following operations\n"
    << "1. Display flow list, and the average.\n"
    << "2. Add data.\n3. Save data into the file\n"
    << "4. Remove data\n5. Quit\n"
    << "Enter your choice (1, 2, 3, 4, of 5): ";
    int choice;
    cin >> choice;
    return choice;
};

void display(FlowList &list, int &no_items){
    cout << UNDERLINE << "Year\tFlow (in billions of cubic meters)" << RESET << endl;
    list.print();
    cout << "The average of the flow is: " << average(list, no_items) << " billions of cubic meter." << endl;
};

void addData(FlowList &list, int &no_items){
    ListItem additem;
    cout << "Please enter a year: ";
    cin >> additem.year;
    //loop continues taking input if input is non numeric or negative
    while (additem.year < 0 || !additem.year){
        cout << "Invalid input, please enter another: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> additem.year;
    }

    cout << "Please enter the flow: ";
    cin >> additem.flow;
    //loop continues taking input if the input is negative or non numeric
    while (additem.flow < 0 || !additem.flow){
        cout << "Invalid input, please enter another: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> additem.flow;
    }
    //loop makes sue that the year is not already in the FlowList
    Node * first = list.get_first();
    while (first){
        if(additem.year == first->item.year){
            cout << "Error: duplicate data." << endl;
            return;
        }
        first = first->next;
    }
    cout << "New record inserted successfully." << endl;
    list.insert(additem);
    no_items++;
};

void removeData(FlowList & list, int & no_items){
    int removeitem;
    cout << "Please enter the year you want to remove: ";
    cin >> removeitem;
    //loop makes sure input is not negative or non numeric
    while(removeitem < 0 || !removeitem){
        cout << "Input is invalid. Please enter a valid year: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> removeitem;
    }
    //will only remove the value if the year exists in the list.
    //tells user if it is not.
    Node * first = list.get_first();
    while(first){
        if(removeitem == first->item.year){
            list.remove(removeitem);
            no_items--;
            cout << "Record Successfully removed." << endl;
            return;
        }  
        first = first->next;
    }
    cout << "Error: No such data. ";
            return;
};

double average(FlowList &list, int &no_items){
    double sum;
    Node * point = list.get_first();
    while(point){
        sum += point->item.flow;
        point = point->next;
    }
    return sum / no_items;
};

void saveData(FlowList &list){
    fstream flowfile;
    flowfile.open("flow.txt", ios::out);
    if (!flowfile){
        cout << "error opening file... quitting.";
        exit(1);
    }
    Node * point = list.get_first();
    while (point){
        flowfile << point->item.year << "\t" << point->item.flow << endl;
        point = point->next;
    }
    flowfile.close();
    cout << "Data Saved Successfully" << endl;
};

void pressEnter(){
    cout << "<<<Press Enter to Continue>>>" << endl;
    //used to ignore what's left in cin buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //waits for user to press enter
    cin.get();
};



