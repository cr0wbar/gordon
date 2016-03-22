/* 
 * File:   RotatingSequence.h
 * Author: G. De Concini
 *
 */

#ifndef ROTATINGSEQUENCE_H
#define ROTATINGSEQUENCE_H
#include<deque>
#include<iterator>


class RotatingSequence {
public:
    RotatingSequence(const size_t maxSize): _maxSize(maxSize){}
    
    void push(const std::string& newElem);
    
    std::deque<std::string> getSequence(void) const;
    
    void clear(void);
    
    bool operator<(const RotatingSequence& other) const;
    
    std::string reduce(void) const;
    
    virtual ~RotatingSequence(){
        _elems.clear();
    }
    
private:   
        
    const size_t _maxSize;
    std::deque<std::string> _elems;
};

#endif /* ROTATINGSEQUENCE_H*/

