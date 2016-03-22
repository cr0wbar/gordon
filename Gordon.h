/* 
 * File:   Gordon.h
 * Author: G. De Concini
 *
 */

#ifndef GORDON_H
#define GORDON_H
#include <string>
#include <map>
#include <fstream>
#include <vector>

#include "NextState.h"
#include "RotatingSequence.h"

class Gordon{
public:
    Gordon(const std::string fileName,const unsigned depth);
    void writeOnFile(const std::string fileName,const int nWords);        
    virtual ~Gordon();
    
private:
    std::map< RotatingSequence, std::vector<NextState> > _probs;
    const std::string getNextWord(RotatingSequence& prev);        
    const unsigned int _depth;
};

#endif /* GORDON_H */

