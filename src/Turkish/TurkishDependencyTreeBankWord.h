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
    vector<string> splitIntoInflectionalGroups(const string& IG);
    [[nodiscard]] MorphologicalParse getParse() const;
    [[nodiscard]] MorphologicalParse getOriginalParse(int index) const;
    [[nodiscard]] int size() const;
    [[nodiscard]] TurkishDependencyRelation getRelation() const;
};


#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKWORD_H
