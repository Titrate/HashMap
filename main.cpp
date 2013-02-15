//
//  main.cpp
//  prog1
//
//  Created by Daniel Guimaraes on 1/27/13.
//  Copyright (c) 2013 Daniel Guimaraes. All rights reserved.
//

// The following code fragment will read from the command line
/*
 //    for (int i = 1; i < argc; i+=2){
 //        command = argv[i];          //  Says which command to execute
 //        input = argv[i+1];          //  The value to pass into the command
 //
 //        //  Logic for handling commands
 //        if (command.compare(INSERT) == 0){
 //            myMap.insert(input, input);
 //        }else if (command.compare(DELETE) == 0){
 //            myMap.deleteItem(input);
 //        }else{
 //            if (myMap.find(input))
 //                std::cout << FINDSUCCESS << std::endl;
 //            else
 //                std::cout << FINDFAIL << std::endl;
 //        }
 //    }
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/time.h>
#include "StringMap.h"

std::string const INSERT = "insert";
std::string const DELETE = "delete";
std::string const FIND = "find";

const unsigned int RANDOM = 100;
const unsigned int BIGLIST = 5000000;

//This funtion loads our string** with the big list of strings
//it also loads our map with the same values
void loadBigFile(std::string** stringAry, StringMap* map){
    std::string* line;
    std::ifstream file;
    
    file.open("/Users/titrate/Workspace/cpp/prog1/prog1/testfiles/testfile_5m"); // A read file object
    
    for (int i = 0; i < BIGLIST; i++) {
        line = new std::string;
        getline(file, *line);
        map->insert(NULL, line);
        stringAry[i] = line; // THIS MOTHERFUCKER BREAKS MY CODE..... WTF!!!!!
    }
}


// This loads our random strings for serach times.
void loadRandAry(std::string** stringAry){
    std::string* line;
    std::ifstream file;
    file.open("/Users/titrate/Workspace/cpp/prog1/prog1/testfiles/100str_5m"); // A read file object
    
    for (int i = 0; i < RANDOM; i++) {
        line = new std::string;
        getline(file, *line);
        stringAry[i] = line; // THIS MOTHERFUCKER BREAKS MY CODE..... WTF!!!!! Fixed you BITCH!!!
    }
}

//Find random strings in the map
void timeMapFind(StringMap* map, std::string** randStrings){
    timeval tStart, tEnd;
    double elapsedTime;
//    int count = 0;
    
    gettimeofday(&tStart, NULL);
    for (int i = 0; i < RANDOM; i++)
        map->find(*randStrings[i]);
    
    
//        if(map->find(*randStrings[i]) != NULL)
//            count += 1;
    gettimeofday(&tEnd, NULL);
    
//    std::cout << count << std::endl;
    elapsedTime = ((double)tEnd.tv_sec - (double)tStart.tv_sec);                    //Time in seconds
    elapsedTime += (((double)tEnd.tv_usec - (double)tStart.tv_usec)) / 1000000;     //us to s
    std::cout << elapsedTime << std::endl;
}


// Find string in big list
bool find(std::string* findMe, std::string** bigList){
    for (int i = 0; i < BIGLIST; i++)
        if (findMe->compare(*bigList[i]) == 0)
            return true;
    
    return false;
}

//Find random strings in the array
void timeAryFind(std::string** allStrings, std::string** randStrings){
    timeval tStart, tEnd;               //keep track of find
    double elapsedTime;                 //total time
//    int count = 0;                      //count finds, make sure == 100
    
    //Time find
    gettimeofday(&tStart, NULL);
    for (int i = 0; i < RANDOM; i++)
        find(randStrings[i], allStrings);
             
//        if (find(randStrings[i], allStrings))
//            count += 1;
             
    gettimeofday(&tEnd, NULL);
    
//    std::cout << count << std::endl;
    //Print time of day
    elapsedTime = ((double)tEnd.tv_sec - (double)tStart.tv_sec);                    //Time in seconds
    elapsedTime += (((double)tEnd.tv_usec - (double)tStart.tv_usec)) / 1000000;     //us to s
    std::cout << elapsedTime << std::endl;
}



// Main for timing purposes
//int main(int argc, const char * argv[]){
//    StringMap myMap;
//    std::string** stringAry = new std::string *[BIGLIST]; //This big list
//    std::string** randAry = new std::string *[RANDOM];
//    
//    loadBigFile(stringAry, &myMap);
//    loadRandAry(randAry);
//    
//    timeAryFind(stringAry, randAry);
//    timeMapFind(&myMap, randAry);
//    
//    return EXIT_SUCCESS;
//}


//Main for part 1, code turnin.
int main(int argc, const char * argv[])
{
    StringMap myMap;                            //  Test this shit!!!
    std::string inputLine;                      //This holds the data passed in the in stream
    std::string command;                        //This is the parsed command
    std::string input;                          //This is the parsed string to act on
    
    //do shit till EOF
    while (getline(std::cin, inputLine)){
        std::istringstream in(inputLine);   //treat string as a stream
        getline(in, command, ' ');          //read in first string to command,drop whitespace
        getline(in, input, ' ');    //read second to input
        
        if (command.compare(INSERT) == 0){
            myMap.insert(input, input);
        }else if (command.compare(DELETE) == 0){
            myMap.deleteItem(input);
        }else if (command.compare(FIND) == 0){
            if (myMap.find(input))
                std::cout << FINDSUCCESS << std::endl;
            else
                std::cout << FINDFAIL << std::endl;
        }
        
    }
    return EXIT_SUCCESS;
}
