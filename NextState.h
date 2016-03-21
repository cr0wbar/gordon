/* 
 * File:   Status.h
 * Author: crowbar
 *
 * Created on 10 February 2016, 00:07
 */

#ifndef STATUS_H
#define STATUS_H
#include <string>

class NextState {
public:
    NextState(std::string nextWord, double prob ) : _nextWord(nextWord),_cumulativeProbability(prob){}

    virtual ~NextState();
    
    double getCumulativeProbability();
    
    std::string getWord();
    
private:
    const double _cumulativeProbability;
    const std::string _nextWord;
};

#endif /* STATUS_H */

