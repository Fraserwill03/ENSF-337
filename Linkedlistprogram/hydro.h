//hydro.h
//William Fraser 30158991

#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

int readData(FlowList &list);
//Reads the data from a text file into an ordered linked list
//returns the number of items in the list
void displayHeader();
//Displays the header
int menu();
//displys the menu, takes a selection, and
//returns the value of that selection
void display(FlowList &list, int &no_items);
//displays the linked list, using the print member function
//in the FlowList object
void addData(FlowList &list, int &no_items);
//allows user to add a piece of data to the FlowList
void removeData(FlowList &list, int &no_items);
//allows user to remove a piece of data from the FlowList
double average(FlowList &list, int &no_items);
//takes the yearly average of the flow data in the list
void saveData(FlowList &list);
//writes the data from the FlowList into the text file
void pressEnter();
//prompts user to press enter, and waits till they

#endif