// Example program
#include <iostream>
#include <string>

using namespace std;


struct info {
    public:
        char identifier;
        int balance;
};

struct node {
    public:
        info * var;
        node * next;
};

//Create Node(info, node)
//push(node, nextNode)
//pop(node)
//remove(=

//All functions will return the front of the list that they were working with.
//Since functions are recursive this is super useful and the first function call you made should always return the front of the list at the end.
//By returning the front of the list we can change the front of the list ;)
//Every call should be "front = functionName(front, ...)

node * createNode(info * i, node * next = NULL) {
    //remember "new" returns a pointer.  Pointers use -> not .
    node * n = new node();
    n->var = i;
    n->next = next;
    
    return n;
}

node * pushList(node * front, node * next) {
    if (front == NULL) {
        return next; //Allows you to pass in a "NULL" node as front which is an empty list, and add next to the empty list.   
    } else {
        //pushList thinks front->next is the front of the list, so no matter the number of recursive calls we expect to get front->next back.
        //Unless front->next is null, but that's what makes this so cool.  It saves you having to check if "front->next == NULL" and then assigning "front->next = next".
        front->next = pushList(front->next, next);
        return front;
    }
}

node * popList(node * front) {
    if (front == NULL || front->next == NULL) {
        //If the list is empty (front == NULL) or is of length 1 (front->next == NULL) return the empty list (NULL).
        return NULL;
    } else {
        //Otherwise set the next item in the list equal to the result of popping an item off the list starting at front->next instead.
        front->next = popList(front->next); 
        return front;
    }
}

int main()
{
  std::string name;
  std::cout << "What is your name? ";
  getline (std::cin, name);
  std::cout << "Hello, " << name << "!\n";
}

