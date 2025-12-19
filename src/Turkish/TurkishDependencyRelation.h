//
// Created by olcay on 14.03.2019.
//

#ifndef DEPENDENCYPARSER_TURKISHDEPENDENCYRELATION_H
#define DEPENDENCYPARSER_TURKISHDEPENDENCYRELATION_H


#include <string>
#include "../DependencyRelation.h"
#include "TurkishDependencyType.h"
using namespace std;

class TurkishDependencyRelation : public DependencyRelation{
private:
    int toIG;
    TurkishDependencyType turkishDependencyType;
public:
    static const string turkishDependencyTypes[23];
    static const TurkishDependencyType turkishDependencyTags[23];
    static TurkishDependencyType getDependencyTag(const string& tag);
    TurkishDependencyRelation() = default;
    TurkishDependencyRelation(int toWord, int toIG, const string& dependencyType);
    [[nodiscard]] int getToIG() const;
    [[nodiscard]] TurkishDependencyType getTurkishDependencyType() const;
    [[nodiscard]] string to_string() const;
};


#endif //DEPENDENCYPARSER_TURKISHDEPENDENCYRELATION_H
