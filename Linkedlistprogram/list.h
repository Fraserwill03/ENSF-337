//list.h
//William Fraser 30158991

#define UNDERLINE "\033[4m"
#define RESET "\033[0m"

#ifndef LIST_H
#define LIST_H

struct ListItem {
int year;
double flow;
};

struct Node {
    ListItem item;
    Node * next;
};


class FlowList {
public:
    //Constructors
    FlowList();  //creates an empty list
    FlowList(const FlowList& source);   //Copy Constructor
    FlowList& operator = (const FlowList& rhs); //Used to copy via assignment
    ~FlowList();    //destructor

    void insert(const ListItem& itemA);
    //Will insert a ListItem structure into the FlowList
    void remove(const int& itemA);
    //Will remove a ListItem structure from the FlowList
    void print() const;
    //Will print all items in the list in rows with a column for years
    //and a column for flow
    Node *get_first();
    //returns a pointer that points where headM does

private:
    Node *headM;
    //Pointer points to first structure in FlowList, or NULL

    void destroy();
    //Helper function used to destroy the object
    void copy(const FlowList& source);
    //helper function used to copy object
};
#endif