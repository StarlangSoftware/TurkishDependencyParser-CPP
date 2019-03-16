//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#include "TurkishDependencyTreeBankSentence.h"
#include "TurkishDependencyTreeBankWord.h"

TurkishDependencyTreeBankSentence::TurkishDependencyTreeBankSentence(XmlElement* sentenceNode) {
    XmlElement* wordNode;
    TurkishDependencyTreeBankWord* word;
    wordNode = sentenceNode->getFirstChild();
    while (wordNode != nullptr){
        word = new TurkishDependencyTreeBankWord(wordNode);
        words.emplace_back(word);
        wordNode = wordNode->getNextSibling();
    }
}

int TurkishDependencyTreeBankSentence::maxDependencyLength() {
    int max = 0;
    for (int i = 0; i < words.size(); i++){
        auto* word = (TurkishDependencyTreeBankWord*) words.at(i);
        if (word->getRelation().to() - i > max){
            max = word->getRelation().to() - i;
        }
    }
    return max;
}
