//
//  Highverb.cpp
//  Laser_Tag
//
//  Created by Zachary Bubrosky on 8/25/15.
//  Copyright (c) 2015 Zachary Bubrosky. All rights reserved.
//


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
#include <sstream>
#include "Highverb.h"


using namespace std;

HighV :: HighV(string aname, int ateamsize, string bname, int bteamsize, vector<int> allstats, int hits, vector<string> pnames)
{
    setTeamA(aname);
    setAsize(ateamsize);
    setTeamB(bname);
    setBsize(bteamsize);
    setStats(allstats);
    setTags(hits);
    setNames(pnames);
}


//Team A: name getter and setter
void HighV:: setTeamA(string &aname)
{
    
    teamaname = aname;
    
}

string HighV:: getTeamA() const
{
    
    return teamaname;
    
}

//Team A: team size getter and setter
void HighV:: setAsize(int ateamsize)
{
    asize = ateamsize;
}

int HighV:: getAsize() const
{
    
    return asize;
    
}


//Team B: name getter and setter
void HighV:: setTeamB(string &bname)
{
    
    teambname = bname;
    
}

string HighV:: getTeamB() const
{
    
    return teambname;
    
}


//Team B: team size getter and setter
void HighV:: setBsize(int bteamsize)
{
    
    bsize = bteamsize;
    
}

int HighV:: getBsize() const
{
    
    return bsize;
    
}


//Statistics for all players allocated into a vector
void HighV:: setStats(vector<int> &allstats)
{
    stats = allstats;
}

vector<int> HighV:: getStats() const
{
    return stats;
}

//set and get number of tags
void HighV:: setTags(int hits)
{
    tags = hits;
}

int HighV:: getTags() const
{
    return tags;
}

//set and get player names
void HighV:: setNames(vector<string> &pnames)
{
    names = pnames;
}

vector<string> HighV:: getNames() const
{
    return names;
}

//Organizing the statistics in a 2d array
void HighV:: setStatOrganizer()
{
    int sizec = asize + bsize+2;
    int sized = sizec;
    int tagger = 0;
    int playertagged = 0;
    int location = 0;
    int totaltags = tags*3;
    
    //initialize number of rows
    for (int x = 0; x < sized; x++)
    {
        scoreparameter.push_back(0);
    }
    
    for (int y = 0; y < sizec; y++)
    {
        score.push_back(scoreparameter);
    }
    
    
    
    //input players statistics into a 2d array
    //first add hit to player tagged, then add location value to players total
    //row was used in second part because it matches where total would be in array
    for (int i = 0; i < totaltags; i+=3)
    {
        tagger = stats[i];
        playertagged = stats[i+1];
        location = stats[i+2];
        
        score[tagger-1][playertagged-1] += 1;
        score[tagger-1][sizec-2] += 1;
        
        if (location == 1)
        {
            score[tagger-1][sized-1] += 5;
        }
        else if (location == 2)
        {
            score[tagger-1][sized-1] += 8;
        }
        else if (location == 3)
        {
            score[tagger-1][sized-1] += 10;
        }
        else if (location == 4)
        {
            score[tagger-1][sized-1] += 15;
        }
        
    }
    
    
    
}

// problem arrising when calculating team score

int HighV:: calculateTeamAScore()
{
    int teamatotal = 0;
    int sizec = asize+bsize;
    //cout << "pscores size is " << score.size() << endl;
    //cout << "pscores [0] size is " << score[0].size() << endl;
    for (int i = 0; i < asize; i++)
    {
        teamatotal= teamatotal + score[i][sizec+1];
    }
    return teamatotal;
}

int HighV:: calculateTeamBScore()
{
    int teambtotal = 0;
    int sizec = asize+bsize;
    
    for (int i = asize; i < (sizec); i++)
    {
        teambtotal= teambtotal + score[i][sizec+1];
    }
    return teambtotal;
}

string HighV:: WinningTeam()
{
    int teama = 0;
    int teamb = 0;
    int totalsize = asize + bsize + 1;
    string tie = "TIE";
    string winner = " ";
    
    for (int i = 0; i < asize; i++)
    {
        teama += score[i][totalsize];
    }
    
    for (int i = asize; i < totalsize; i++)
    {
        teamb += score[i][totalsize];
    }
    
    if (teama > teamb)
    {
        winner = teamaname;
    }
    
    else if (teama == teamb)
    {
        winner = tie;
    }
    
    else
    {
        winner = teambname;
    }
    
    ateamscore = teama;
    bteamscore = teamb;
    //winningteam = winner;
    return winner;
    
}

int HighV:: getTeamAScore() const
{
    return ateamscore;
}

int HighV:: getTeamBScore() const
{
    return bteamscore;
}

//hits are scored in 6


//MEDIUM VERBOSITY
void HighV:: PlayerScores()
{
    //fill these vectors by (player1 id, # of tags, player2 id, # of tags, etc...)
    vector<int> teamaplayers;
    vector<int> teambplayers;
    //use these as outside counter increasing by 1
    int countera = 0;
    int counterb = bsize;
    
    //use this number to gain access to final column containing total tags
    int totalsize = asize + bsize;
    
    //Team A: loop through total tags for each player
    for (int i = 0; i < (asize); i++)
    {
        teamaplayers.push_back(i);
        teamaplayers.push_back(score[countera][totalsize]);
        countera++;
    }
    
    //Team A: sort vector so order is descending (if tie descend by id #)
    for (int i = 1; i < (totalsize); i+=2)
    {
        
        for (int x = (totalsize-1); x > 2; x-=2)
        {
            if (teamaplayers[x] > teamaplayers[x-2])
            {
                swap(teamaplayers[x],teamaplayers[x-2]);
                swap(teamaplayers[x-1],teamaplayers[x-3]);
            }
        }
        
    }
    
    //SORTING ALGORITHM DOESN'T WORK
    //Team A: sort tied player scores by name
    string a_one = " ";
    int ida_one = 0;
    
    
    string a_two = " ";
    int ida_two = 0;
    
    
    for (int i = 1; i < (totalsize); i+=2)
    {
        
        for (int x = (totalsize-1); x > 2; x-=2)
        {
            if (teamaplayers[x] == teamaplayers[x-2])
            {
                ida_one = teamaplayers[x-1];
                a_one = names[ida_one];
                
                char arr_one[a_one.size() + 1];
                strcpy(arr_one, a_one.c_str());
                
                ida_two = teamaplayers[x-3];
                a_two = names[ida_two];
                
                char arr_two[a_two.size() + 1];
                strcpy(arr_two, a_two.c_str());
                
                for (int z = 0; z < a_one.size(); z++)
                {
                    if (arr_one[z] < arr_two[z])
                    {
                        swap(teamaplayers[x],teamaplayers[x-2]);
                        swap(teamaplayers[x-1],teamaplayers[x-3]);
                        break;
                    }
                    
                }
                
                
            }
        }
        
    }
    
    
    //Team B: loop through total tags for each player
    for (int i = 0; i < (bsize); i++)
    {
        teambplayers.push_back(i);
        teambplayers.push_back(score[counterb][totalsize]);
        counterb++;
    }
    
    //Team B: sort vector so order is descending (if tie descend by id #)
    for (int i = 1; i < (totalsize); i+=2)
    {
        
        for (int x = (totalsize-1); x > 2; x-=2)
        {
            if (teambplayers[x] > teambplayers[x-2])
            {
                swap(teambplayers[x],teambplayers[x-2]);
                swap(teambplayers[x-1],teambplayers[x-3]);
            }
        }
        
    }
    
    //SORTING ALGORITHM DOESN'T WORK
    //Team B: sort tied player scores by name
    string b_one = " ";
    int idb_one = 0;
    
    
    string b_two = " ";
    int idb_two = 0;
    
    
    for (int i = 1; i < (totalsize); i+=2)
    {
        
        for (int x = (totalsize-1); x > 2; x-=2)
        {
            if (teambplayers[x] == teambplayers[x-2])
            {
                idb_one = teambplayers[x-1];
                b_one = names[idb_one];
                
                char arr_one[b_one.size() + 1];
                strcpy(arr_one, b_one.c_str());
                
                idb_two = teambplayers[x-3];
                b_two = names[idb_two];
                
                char arr_two[b_two.size() + 1];
                strcpy(arr_two, b_two.c_str());
                
                for (int z = 0; z < b_one.size(); z++)
                {
                    if (arr_one[z] < arr_two[z])
                    {
                        swap(teambplayers[x],teambplayers[x-2]);
                        swap(teambplayers[x-1],teambplayers[x-3]);
                        break;
                    }
                    
                }
                
                
            }
        }
        
    }
    
    ofstream mverb("mverb.txt", ios::out);
    
    //Team A: print player results by id #
    int paname = 0;
    int pascore = 0;
    string planame = " ";
    
    //Team A: header
    mverb << teamaname<<endl;
    
    for (int q = 0; q < totalsize; q+=2)
    {
        paname = teamaplayers[q];
        pascore = teamaplayers[q+1];
        planame = names[paname];
        
        if (pascore == 1)
        {
            mverb << "    "<<planame << " had a total of "<< pascore<< " tag"<<endl;
        }
        else
        {
            mverb << "    "<<planame << " had a total of "<< pascore<< " tags"<<endl;
        }
    }
    
    //Team B: print player results by id #
    int pbname = 0;
    int pbscore = 0;
    string plbname = " ";
    
    //Team B: header
    mverb << teambname<<endl;
    
    for (int q = 0; q < totalsize; q+=2)
    {
        pbname = teambplayers[q];
        pbscore = teambplayers[q+1];
        plbname = names[pbname+3];
        
        if (pbscore == 1)
        {
            mverb << "    "<< plbname << " had a total of "<< pbscore<< " tag"<<endl;
        }
        else
        {
            mverb << "    "<<plbname << " had a total of "<< pbscore<< " tags"<<endl;
        }
        
    }
    
    //assign private data of players in desceding order
    descendinga = teamaplayers;
    descendingb = teambplayers;
    
    //Team A: highest score
    totalsize = asize + bsize + 1;
    int bestid = 0;
    int highestscore = score[0][totalsize];
    for (int i = 0; i < asize; i++)
    {
        int secondid = i + 1;
        int secondidscore = score[secondid][totalsize];
        if (secondidscore > highestscore)
        {
            bestid = secondid;
            highestscore = secondidscore;
        }
    }
    mverb << "Best score from "<< teamaname<< ": "<< names[bestid]<< " ("<< highestscore<< ")"<<endl;
    
    //Team B: highest score
    //int totalsize = asize + bsize + 1;
    int bbestid = asize;
    int bhighestscore = score[asize][totalsize];
    for (int i = asize; i < (asize+bsize); i++)
    {
        int secondid = i + 1;
        int secondidscore = score[secondid][totalsize];
        if (secondidscore > bhighestscore)
        {
            bbestid = secondid;
            bhighestscore = secondidscore;
        }
    }
    mverb << "Best score from "<< teambname<< ": "<< names[bbestid]<< " ("<< bhighestscore<< ")"<<endl;
    mverb << "\n"<<getTeamA()<< ": "<< calculateTeamAScore()<< " points"<<endl;
    mverb << getTeamB()<< ": "<< calculateTeamBScore()<< " points"<<endl;
    mverb << "Overall Winners: "<< WinningTeam();
    
    
    mverb.close();
    
}


//HIGH VERBOSITY
void HighV:: ScoreSheet()
{
    //Team A: printed statistics
    
    int acounter = 0;
    int opponent = asize;
    int aplayer = 0;
    int scorecounter = asize;
    
    ofstream hverb("hverb.txt", ios::out);
    
    //Team A: header
    hverb << teamaname<<endl;
    
    for (int i = 0; i < bsize; i++)
    {
        aplayer = descendinga[acounter];
        
        hverb << "    "<< names[aplayer]<< " tagged "<< names[opponent]<< " "<< score[aplayer][scorecounter]<<" time"<<endl;
        hverb << "    "<< names[aplayer]<< " tagged "<< names[opponent+1]<< " "<< score[aplayer][scorecounter+1]<<" time"<<endl;
        hverb << "    "<< names[aplayer]<< " tagged "<< names[opponent+2]<< " "<< score[aplayer][scorecounter+2]<<" time"<<endl;
        hverb << "    "<< names[aplayer]<< " had a total of "<< descendinga[acounter+1]<< " tags"<<endl;
        
        acounter+=2;
    }
    
    hverb << getTeamA()<< ": "<< calculateTeamAScore()<< " points"<<endl;
    
    
    //Team B: printed statistics
    
    int bcounter = 0;
    int bopponent = 0;
    int bplayer = 0;
    int bscorecounter = 0;
    
    //Team B: header
    hverb << "\n\n"<< teambname<<endl;
    
    for (int i = 0; i < bsize; i++)
    {
        bplayer = descendingb[bcounter];
        
        hverb << "    "<< names[bplayer+3]<< " tagged "<< names[bopponent]<< " "<< score[bplayer+3][bscorecounter]<<" time"<<endl;
        hverb << "    "<< names[bplayer+3]<< " tagged "<< names[bopponent+1]<< " "<< score[bplayer+3][bscorecounter+1]<<" time"<<endl;
        hverb << "    "<< names[bplayer+3]<< " tagged "<< names[bopponent+2]<< " "<< score[bplayer+3][bscorecounter+2]<<" time"<<endl;
        hverb << "    "<< names[bplayer+3]<< " had a total of "<< descendingb[bcounter+1]<< " tags"<<endl;
        
        bcounter+=2;
    }
    
    hverb << getTeamB()<< ": "<< calculateTeamBScore()<< " points"<<endl;
    
    hverb << "\n\nWinners: "<< WinningTeam();
    
    hverb.close();
}


//LOW VERBOSITY
void HighV:: printFilel()
{
    setStatOrganizer();
    ofstream lverb("lverb.txt", ios::out);
    
    lverb << getTeamA()<< ": "<< calculateTeamAScore()<< " points"<<endl;
    lverb << getTeamB()<< ": "<< calculateTeamBScore()<< " points"<<endl;
    lverb << "Overall Winners: "<< WinningTeam();
    
    lverb.close();
    
}
















