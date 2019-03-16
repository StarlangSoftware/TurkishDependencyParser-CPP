//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKCORPUS_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKCORPUS_H

#include <Corpus.h>

class TurkishDependencyTreeBankCorpus : public Corpus {
public:
    TurkishDependencyTreeBankCorpus emptyCopy();
    explicit TurkishDependencyTreeBankCorpus(string fileName);
    TurkishDependencyTreeBankCorpus() = default;
};


#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYTREEBANKCORPUS_H
