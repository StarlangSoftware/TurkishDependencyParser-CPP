//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H


#include <Corpus.h>

class UniversalDependencyTreeBankCorpus : public Corpus {
public:
    explicit UniversalDependencyTreeBankCorpus(string fileName);
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKCORPUS_H
