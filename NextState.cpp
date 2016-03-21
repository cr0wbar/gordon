/* 
 * File:   Status.cpp
 * Author: crowbar
 * 
 * Created on 10 February 2016, 00:07
 */

#include "NextState.h"

NextState::~NextState() {
}

double NextState::getCumulativeProbability() {
    return _cumulativeProbability;
}

std::string NextState::getWord() {
    return _nextWord;
}
