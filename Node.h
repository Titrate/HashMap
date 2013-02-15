//
//  Node.h
//  prog1
//
//  Created by Daniel Guimaraes on 1/27/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __prog1__Node__
#define __prog1__Node__

#include <iostream>

class Node {
    Node* nextNode;
    std::string* item;

public:
    Node(std::string value){
        item = new std::string;
        *item = value;          //  Null till item is set
        nextNode = NULL;        //  Null till inserted into a non empty list
    }
    
    Node(std::string* value){
        item = value;
        nextNode = NULL;
    }
    
    ~Node(){delete item;}
    
    void insert(std::string value){item = &value;}
    void setNextNode(Node* next){nextNode = next;}
    std::string* getValue(){return item;}
    Node* getNextNode(){return nextNode;}
};

#endif /* defined(__prog1__Node__) */
