/* 
 * File:   Gordon.cpp
 * Author: G. De Concini
 * 
 */

#include "Gordon.h"
#include "RotatingSequence.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

Gordon::Gordon(const std::string fileName,const unsigned int depth): _depth(depth) {
    std::ifstream inFile;
    std::string next;
    std::map< RotatingSequence,std::map<std::string,unsigned long> > followingWordsWithProbs;
    
    std::cout << "Starting to process " << fileName << "." << std::endl;
    
    //Open file
    inFile.open(fileName.c_str(),std::ifstream::in);
    
    try{
        RotatingSequence initialSequence = RotatingSequence(depth);
        //Fill the sequence
        for(int i = 0 ; (i < depth) && inFile >> next ;i++)
            initialSequence.push(next);      
        
        RotatingSequence seq = initialSequence;
        
        while(inFile >> next){            
            followingWordsWithProbs[seq][next]++;
            seq.push(next);
        }
        
        //Periodic boundary condition
        for(auto const &lastWord : initialSequence.getSequence()){
            followingWordsWithProbs[seq][lastWord]++;
            seq.push(lastWord);
        }
        
        
    }
    catch(std::exception ex){
        std::cerr << "Error occurred" << ex.what() << std::endl;
    }
    
    //Evaluate transition probabilities
    for(const auto &i : followingWordsWithProbs ){
        double probSum = 0.;
        for(const auto &j : i.second){
            //Normalized transition probability
            probSum += (double)j.second / (double)i.second.size();
            _probs[i.first].push_back(NextState(j.first,probSum));       
        }
    }
    
    inFile.close();
    std::cout << "Processing " << fileName << " has ended." << std::endl;
    
}

void Gordon::writeOnFile(const std::string fileName, const int nWords) {
    //Random initial sequence
    auto iter = _probs.begin();
    std::advance(iter,rand() % (int)_probs.size());
    RotatingSequence seq = (*iter).first;
    
    std::ofstream output;
    
    std::cout << "Writing " << nWords << " words on " << fileName << "." << std::endl;
        
    output.open(fileName.c_str(), std::ofstream::out);
    output << seq.reduce();

    for(int i=0;i<nWords;i++){
        output << getNextWord(seq) << " " ;
        if((i%10)==9)
            output << std::endl;
    }
    output.close();
}


const std::string Gordon::getNextWord(RotatingSequence& prev) {  
    
    std::vector<NextState> nextWords = _probs[prev];
    
    const double rr = (double)rand()/(double)(RAND_MAX);

    //This is not optimal as it costs O(n) for every lookup.
    //A BTree would be better but considering that one will
    //hardly use depths larger than 2/3, then it would be overshooting
    std::vector<NextState>::iterator iter = nextWords.begin();
    while(iter != nextWords.end() && (*iter).getCumulativeProbability() < rr)
        iter++;

    const std::string nextWord = (*iter).getWord();
    prev.push(nextWord);
    return nextWord;
}

Gordon::~Gordon() {
    _probs.clear();
}

