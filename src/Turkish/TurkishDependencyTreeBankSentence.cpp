//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#include "TurkishDependencyTreeBankSentence.h"
#include "TurkishDependencyTreeBankWord.h"

/**
 * Given the parsed xml node which contains information about a sentence, the method constructs a
 * {@link TurkishDependencyTreeBankSentence} from it.
 * @param sentenceNode Xml parsed node containing information about a sentence.
 */
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

/**
 * Calculates the maximum of all word to related word distances, where the distances are calculated in terms of
 * index differences.
 * @return Maximum of all word to related word distances.
 */
int TurkishDependencyTreeBankSentence::maxDependencyLength() const{
    int max = 0;
    for (int i = 0; i < words.size(); i++){
        auto* word = (TurkishDependencyTreeBankWord*) words.at(i);
        if (word->getRelation().to() - i > max){
            max = word->getRelation().to() - i;
        }
    }
    return max;
}
