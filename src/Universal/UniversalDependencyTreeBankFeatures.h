//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#ifndef DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
#define DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H


#include <unordered_map>
#include <string>

using namespace std;

class UniversalDependencyTreeBankFeatures {
private:
    unordered_map<string, string> featureList;
    static int featureIndex(const string& featureName);
    static int dependencyIndex(const string& universalDependency);
    static int numberOfValues(const string& language, const string& featureName);
    static int featureValueIndex(const string& language, const string& featureName, const string& featureValue);
public:
    static const string universalFeatureTypes[24];
    static const vector<string> universalFeatureValues[24];
    static const vector<string> turkishFeatureValues[24];
    static const vector<string> englishFeatureValues[24];
    explicit UniversalDependencyTreeBankFeatures(const string& language, const string& features);
    string getFeatureValue(const string& feature) const;
    bool featureExists(const string& feature) const;
    string to_string() const;
};


#endif //DEPENDENCYPARSER_UNIVERSALDEPENDENCYTREEBANKFEATURES_H
