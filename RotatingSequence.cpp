#include "RotatingSequence.h"
#include <numeric>
#include <iostream>

void RotatingSequence::push(const std::string& newElem){
    _elems.push_back(newElem);
    if(_elems.size() > _maxSize)
        _elems.pop_front();
    
}

std::deque<std::string> RotatingSequence::getSequence(void) const {
    return _elems;
}

void RotatingSequence::clear(void) {
    _elems.clear();
}

bool RotatingSequence::operator<(const RotatingSequence& other) const {
    
    return _elems < other._elems;
}

std::string RotatingSequence::reduce(void) const{
    std::string tmp;
    for(const auto &elem: _elems)
        tmp += elem + " ";
    return tmp;
}