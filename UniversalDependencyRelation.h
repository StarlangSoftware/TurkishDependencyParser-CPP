//
// Created by olcay on 14.03.2019.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H


#include <string>
#include "DependencyRelation.h"
#include "UniversalDependencyType.h"

using namespace std;

class UniversalDependencyRelation : public DependencyRelation {
private:
    UniversalDependencyType universalDependencyType;
public:
    static const string universalDependencyTypes[37];
    static const UniversalDependencyType universalDependencyTags[37];
    explicit UniversalDependencyRelation(int toWord);
    static UniversalDependencyType getDependencyTag(string tag);
    UniversalDependencyRelation(int toWord, string dependencyType);
    string to_string();
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYRELATION_H
