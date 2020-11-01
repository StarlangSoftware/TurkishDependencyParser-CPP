//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H

#include<string>
#include<vector>
#include <Sentence.h>

using namespace std;

class UniversalDependencyTreeBankSentence : public Sentence{
private:
    vector<string> comments;
public:
    UniversalDependencyTreeBankSentence();
    void addComment(string comment);
    string to_string();
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKSENTENCE_H
