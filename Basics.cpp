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

//All functions will return the front of the list that they were working with.
//Since functions are recursive this is super useful and the first function call you made should always return the front of the list at the end.
//By returning the front of the list we can change the front of the list ;)
//Every call should be "front = functionName(front, ...)

//O(1)
node * createNode(info * i, node * next = NULL) {
    //remember "new" returns a pointer.  Pointers use -> not .
    node * n = new node();
    n->var = i;
    n->next = next;
    
    return n;
}

//O(n)
void deleteList(node * front) {
    if (front != NULL) {
        deleteList(front->next);
        delete front;       
    }    
}

//O(n)
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

//O(n)
node * popList(node * front) {
    if (front == NULL || front->next == NULL) {
        //If the list is empty (front == NULL) or is of length 1 (front->next == NULL) return the empty list (NULL).
        deleteList(front);
        return NULL;
    } else {
        //Otherwise set the next item in the list equal to the result of popping an item off the list starting at front->next instead.
        front->next = popList(front->next); 
        return front;
    }
}

//O(1) unless next wasn't a single node in which case it's O(m) where "m" is the size of next and "n" is the size of front.
node * pushStack(node * front, node * next) {
    if (front == NULL) {
        return next;
    } else {
        //Assuming next is a single node (list of length 1) otherwise more recursion is needed.
        //At least I nicely delete the left over if there were any rather than letting the pointers dangle.
        //deleteList was changed to check for front being NULL (originally always deleted front but checked for NULL front->next) due to this case.
        //Since most times next is a single node, I would waste an operation deleting the NULL front and still checked if front->next was null which had null pointer issues.
        deleteList(next->next);
        next->next = front;
        return next;
    }
}

//O(1)
node * popStack(node * front) {
    if (front == NULL) {
        return NULL;   
    } else {
        node * next = front->next;
        //Saving "next" is important here as we'll detach it from "front" and deleteList front (detached "next" to prevent it being deleted)
        front->next = NULL;
        deleteList(front);
        return next; //We don't care if we return a NULL next as that just means the list is empty.
    }
}

node * pushQueue(node * front, node * next) {
    return pushList(front, next); //Most standard linked list implementations are just queues.
}

node * popQueue(node * front) {
    return popList(front);
}

int main() {
    
}

