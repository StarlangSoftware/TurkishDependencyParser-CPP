//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKSENTENCE_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKSENTENCE_H

#include <Sentence.h>
#include <XmlElement.h>

class TurkishDependencyTreeBankSentence : public Sentence {
public:
    explicit TurkishDependencyTreeBankSentence(XmlElement* sentenceNode);
    int maxDependencyLength();
};


#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKSENTENCE_H
