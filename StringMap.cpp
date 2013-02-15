//
//  StringMap.cpp
//  Hash Table (Programming Assignment 1 CS130)
//
//  Created by Daniel Guimaraes on 1/26/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#include "StringMap.h"

// insert a key, value pair into the map, standard insert
void StringMap::insert(std::string key, std::string value){
    tableOffset = hashValue(key);      //  The map index
//    std::cout << tableOffset << std::endl;
    if (values[tableOffset]->insert(value))
        std::cout << INSERTSUCCESS << std::endl;
    else
        std::cout << INSERTFAIL << std::endl;
}

// Insert a key using a string pointer Used for timing runs
void StringMap::insert(std::string* empty, std::string* value){
    tableOffset = hashValue(*value);
//    std::cout << tableOffset << std::endl;
    values[tableOffset]->insert(value);  //use this insert for timing
//    if (values[tableOffset]->insert(value))
//        std::cout << INSERTSUCCESS << std::endl;
//    else
//        std::cout << INSERTFAIL << std::endl;
}

//  Remove item if it is in the map
void StringMap::deleteItem(std::string key){
    tableOffset = hashValue(key);
    if (values[tableOffset]->deleteItem(key)){
        std::cout << DELETESUCCESS << std::endl;
    }else{
        std::cout << DELETEFAIL  << std::endl;
    }
}

//  Find and return the value associated with a key
std::string* StringMap::find(std::string key){
    tableOffset = hashValue(key);
    
    returnValue = values[tableOffset]->find(key);
    
    if (returnValue != NULL)  // item is in list
        return (std::string*) &FINDSUCCESS;
    
    return returnValue; //NULL if function gets here.
}
