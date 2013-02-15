//
//  LinkedList.h
//  prog1
//
//  Created by Daniel Guimaraes on 1/27/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __prog1__LinkedList__
#define __prog1__LinkedList__

#include <iostream>

#include "Node.h"

const bool SUCCESS = true;
const bool FAIL = false;
std::string* const NOTFOUND = NULL;

class LinkedList {
    Node* head;
    Node* currentNode;      //  Points to current node for iteration and find purposes
    Node* previousNode;     //  Points to the node before current for delete method purposes
    int count;

public:
    LinkedList(){
        head = NULL;
        currentNode = NULL;
        previousNode = NULL;
        count = 0;
    }
    
    int getCount(){return count;}  //  For testing purposes
    
    bool insert(std::string item);
    bool insert(std::string* item);
    bool deleteItem(std::string item);
    std::string* find(std::string item);
};

#endif /* defined(__prog1__LinkedList__) */
