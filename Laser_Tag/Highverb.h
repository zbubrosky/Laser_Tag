//
//  Highverb.h
//  Laser_Tag
//
//  Created by Zachary Bubrosky on 8/25/15.
//  Copyright (c) 2015 Zachary Bubrosky. All rights reserved.
//

#ifndef __Laser_Tag__Highverb__
#define __Laser_Tag__Highverb__

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

//USE AS BASE CLASS, ALL OTHER CLASSES CAN INHERIT DATA

//file needs:
//      1) Team A name
//      2) Team A Player | # of times they killed each team B players | Total tags
//      3) Team A total
//      4) Repeat step 1-3 for team B
//      5) Declare winner

class HighV{
    
public:
    
    HighV (string = " ", int = 0,string = " ", int = 0, vector<int> = {}, int = 0, vector<string> = {});
    
    void setTeamA(string &);
    string getTeamA() const;
    
    void setAsize(int);
    int getAsize() const;
    
    void setTeamB(string &);
    string getTeamB() const;
    
    void setBsize(int);
    int getBsize() const;
    
    void setStats(vector<int> &);
    vector<int> getStats() const;
    
    void setTags(int);
    int getTags() const;
    
    void setNames(vector<string> &);
    vector<string> getNames() const;
    
    void setStatOrganizer();
    
    int calculateTeamAScore();
    int calculateTeamBScore();
    
    string WinningTeam();
    int getTeamAScore() const;
    int getTeamBScore() const;
    
    void PlayerScores();
    
    
    
    void ScoreSheet();

    void printFilel();
    
    
private:
    
    string teamaname;
    int asize;
    string teambname;
    int bsize;
    vector<int> stats;
    int tags;
    vector<string> names;
    vector<int> scoreparameter;
    vector<vector<int>> score;
    int ateamscore;
    int bteamscore;
    vector<int> descendinga;
    vector<int> descendingb;
    
};


#endif /* defined(__Laser_Tag__Highverb__) */
