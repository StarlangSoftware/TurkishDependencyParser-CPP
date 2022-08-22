//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H

#include "Dictionary/Word.h"
#include "MorphologicalParse.h"
#include "TurkishDependencyRelation.h"
#include "XmlElement.h"

class TurkishDependencyTreeBankWord : public Word{
private:
    MorphologicalParse parse;
    vector<MorphologicalParse> originalParses;
    TurkishDependencyRelation relation;
public:
    explicit TurkishDependencyTreeBankWord(XmlElement* wordNode);
    vector<string> splitIntoInflectionalGroups(string IG);
    MorphologicalParse getParse();
    MorphologicalParse getOriginalParse(int index);
    int size();
    TurkishDependencyRelation getRelation();
};


#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H
