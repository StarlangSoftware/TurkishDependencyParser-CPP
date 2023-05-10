//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H


#include <Corpus.h>
#include "../ParserEvaluationScore.h"

class UniversalDependencyTreeBankCorpus : public Corpus {
private:
    string language;
public:
    explicit UniversalDependencyTreeBankCorpus(const string& fileName);
    UniversalDependencyTreeBankCorpus();
    ParserEvaluationScore compareParses(const UniversalDependencyTreeBankCorpus& corpus);
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H
