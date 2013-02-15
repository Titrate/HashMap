//
//  StringMap.h
//  Hash Table (Programming Assignment 1 CS130)
//
//  Created by Daniel Guimaraes on 1/26/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

#ifndef __Hash_Table__Programming_Assignment_1_CS130___StringMap__
#define __Hash_Table__Programming_Assignment_1_CS130___StringMap__

#include <iostream>
#include <functional>

#include "LinkedList.h"

//insert messages
std::string const INSERTSUCCESS = "item successfully inserted";
std::string const INSERTFAIL = "item already present";

//delete messages
std::string const DELETESUCCESS = "item successfully deleted";
std::string const DELETEFAIL = "item not present in the table";

//find messages
std::string const FINDSUCCESS = "item found";
std::string const FINDFAIL = "item not found";

const unsigned int TABLESIZE = 211;             // First prime after doubling input test set
//const unsigned int TABLESIZE = 2423413;       // a prime after 2million
//const unsigned int TABLESIZE = 6061849;       // a prime after 6million
//const unsigned int TABLESIZE = 10000993;      // a prime after 10million

class StringMap {
    size_t tableOffset;                     //  Table offfset yielded by hashing key
    LinkedList** values;                    //  This stores the table of values
    std::string* returnValue;               //  This is used to return the value of a search
    
public:
    
    StringMap(){
        values = new LinkedList *[TABLESIZE];
        for (int i = 0; i < TABLESIZE; i++){
            values[i] = new LinkedList;
        }
    }
    
    ~StringMap(){
        for (int i = 0; i < TABLESIZE; i++){
            delete values[i];
        }
    delete values;
    }

    // The required thingys
    void insert(std::string* blank, std::string* value);
    void insert(std::string key, std::string value);
    void deleteItem(std::string key);
    std::string* find(std::string key);
    size_t hashValue(std::string key){return (std::hash<std::string>() (key)) % TABLESIZE;}
};



#endif /* defined(__Hash_Table__Programming_Assignment_1_CS130___StringMap__) */
