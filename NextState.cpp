/* 
 * File:   Status.cpp
 * Author: G. De Concini
 * 
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
