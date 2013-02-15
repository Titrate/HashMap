//
//  LinkedList.cpp
//  prog1
//
//  Created by Daniel Guimaraes on 1/27/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include "LinkedList.h"

bool LinkedList::insert(std::string item){
    // Two cases, list is empty, list is not empty
    // all inserts occur at head of list
    
    if (count < 1){
        head = new Node(item);
        currentNode = head;
    }else{
        //Make sure item is not already in list
        std::string* inList = find(item);
        if (inList != NULL)  //  Null means not in list
            return FAIL;
        currentNode = head;
        head = new Node(item);
        head->setNextNode(currentNode);
    }
    count += 1;
    return SUCCESS;
}

bool LinkedList::insert(std::string* item){
    // Two cases, list is empty, list is not empty
    // all inserts occur at head of list
    
    if (count < 1){
        head = new Node(item);
        currentNode = head;
    }else{
        //Make sure item is not already in list
        std::string* inList = find(*item);
        if (inList != NULL)  //  Null means not in list
            return FAIL;
        currentNode = head;
        head = new Node(item);
        head->setNextNode(currentNode);
    }
    count += 1;
    return SUCCESS;
}

bool LinkedList::deleteItem(std::string item){
    //Three cases: Empty List, One item in list, More than one item in list
    //case 1, empty list
    if (count == 0)
        return FAIL;
    Node* tempNode;  //A temp node for the delete
    
    find(item); //this call sets current to the node that contains item or NULL if the item is not found
    
    //  If the itme is not in the list
    if (currentNode == NULL)
        return FAIL;
    
    //  At this point we know the list is not empty and the item is in the list
    //  The first case is that there is only one item in the list
    if (count == 1){
        currentNode = NULL;     //make current point to null
        delete head;            //Free memeory
        head = NULL;            //make head point to null
    }else{
        //  The second case is that there is more than one item
        if (previousNode == head){ //if deleting head node
            head = head->getNextNode();
            tempNode = currentNode;
            delete tempNode;
        }else{  //  if deleting other than head
            tempNode = currentNode;
            currentNode = currentNode->getNextNode();
            previousNode->setNextNode(currentNode);
            delete tempNode;
        }
    }
    
    count -= 1;
    return SUCCESS;
}

std::string* LinkedList::find(std::string item){
    currentNode = head; //Start at front of list

    while (currentNode != NULL){
        previousNode = currentNode; // Keep a ref to node before current
        if (currentNode->getValue()->compare(item) == 0)
        {
//            std::cout << "You are here" << std::endl;
            return currentNode->getValue();
        }
        currentNode = currentNode->getNextNode();
    }
    
    return NOTFOUND; //  Return
}