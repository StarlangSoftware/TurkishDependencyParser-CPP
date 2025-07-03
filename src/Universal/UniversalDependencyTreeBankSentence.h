//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H

#include<string>
#include<vector>
#include <Sentence.h>
#include "../ParserEvaluationScore.h"

using namespace std;

class UniversalDependencyTreeBankSentence : public Sentence{
private:
    vector<string> comments;
    vector<string> splits;
public:
    UniversalDependencyTreeBankSentence();
    UniversalDependencyTreeBankSentence(const string& language, const string& sentence);
    void addComment(const string& comment);
    ParserEvaluationScore compareParses(UniversalDependencyTreeBankSentence* sentence) const;
    int splitSize() const;
    string getSplit(int index) const;
    string to_string() const;
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H
