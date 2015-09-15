//
//  main.cpp
//  Laser_Tag
//
//  Created by Zachary Bubrosky on 8/24/15.
//  Copyright (c) 2015 Zachary Bubrosky. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include "Highverb.h"

using namespace std;

void printResults(ifstream &, ifstream &, ifstream &);


int main() {
    
    //reading in team A file
    ifstream teama ( "SampleA.txt" );


    //safety check
    if( !teama.is_open() ){
        cerr<< "File could not be opened"<< endl;
        exit(EXIT_FAILURE);
    }
    
    
    //reading in team B file
    ifstream teamb ( "Sampleb.txt" );
    
    
    //safety check
    if( !teamb.is_open() ){
        cerr<< "File could not be opened"<< endl;
        exit(EXIT_FAILURE);
    }
    
    
    //reading in match file
    ifstream match ( "Samplematch.txt" );
    
    
    //safety check
    if( !match.is_open() ){
        cerr<< "File could not be opened"<< endl;
        exit(EXIT_FAILURE);
    }

    
    printResults(teama , teamb , match);
    
    //CLOSE ALL FILES
    //teama.close();
    //teamb.close();
    //match.close();
    
    
    
    //end of program check
    cout<<"It worked!"<<endl;
    


//put all data in a vector

//make a constructor for each verbosity
    
//use polymorphism to print each output file

//consider using overloaded operator, although may not work under these circumstances
    
};


void printResults(ifstream &teama, ifstream &teamb, ifstream &match){
    

//Part 1: set team names and sizes
    
    //Team A: initialize name and size
    string teamnamea = " ";
    int sizea = 0;
    
    //Team A: read-in name and size
    getline( teama, teamnamea);
    teama >> sizea;
    
    //Team B: initialize name and size
    string teamnameb = " ";
    int sizeb = 0;
 
    //Team B: read-in name and size
    getline( teamb, teamnameb);
    teamb >> sizeb;
    

//Part 2: fill a vector with the names of players by id number
    
    //variables solely used to provide data from files to vector
    int id = 0;
    string player = " ";
    int sizec = sizea + sizeb;
    
    //use vector to store players name by id number
    vector<string> names;
    
    //add player's name for team A to vector
    for (int a = 0; a < sizea; a++){
        
        teama >> id;
        teama >> player;
        names.push_back(player);
        
    }
    
    //add player's name for team B to vector
    for (int b = sizea-1; b < sizec; b++){
        
        teamb >> id;
        teamb >> player;
        names.push_back(player);
        
    }
 
    
//Part 3: fill a vector with tagger id | id of player tagged | location
    
    int hits = 0; //used to determine limit of for loop
    int tagger = 0;
    int ptagged = 0;
    int seconds = 0; //seconds will be discarded
    int location = 0;
    
    vector<int> stats;
    
    match >> hits;
    
    for (int s = 0; s < hits; s++){
        
        match >> tagger;
        stats.push_back(tagger);
        
        match >> ptagged;
        stats.push_back(ptagged);
        
        match >> seconds;
        
        match >> location;
        stats.push_back(location);
        
    }

    //base class constructor
    HighV highv (teamnamea, sizea, teamnameb, sizeb, stats, hits, names);
    
    highv.printFilel();
    highv.PlayerScores();
    highv.ScoreSheet();

}







