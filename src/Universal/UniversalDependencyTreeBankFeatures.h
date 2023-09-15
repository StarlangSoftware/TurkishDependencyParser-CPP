//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H


#include <unordered_map>
#include <string>
#include "UniversalDependencyPosType.h"

using namespace std;

class UniversalDependencyTreeBankFeatures {
private:
    unordered_map<string, string> featureList;
public:
    static const string universalFeatureTypes[25];
    static const vector<string> universalFeatureValues[25];
    static const vector<string> turkishFeatureValues[25];
    static const vector<string> englishFeatureValues[25];
    explicit UniversalDependencyTreeBankFeatures(const string& language, const string& features);
    UniversalDependencyTreeBankFeatures(UniversalDependencyTreeBankFeatures& copy);
    string getFeatureValue(const string& feature) const;
    bool featureExists(const string& feature) const;
    string to_string() const;
    static int featureIndex(const string& featureName);
    static int posIndex(const string& uPos);
    static string getPosString(UniversalDependencyPosType uPos);
    static int dependencyIndex(const string& universalDependency);
    static int numberOfValues(const string& language, const string& featureName);
    static int featureValueIndex(const string& language, const string& featureName, const string& featureValue);
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
