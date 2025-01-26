//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <vector>
#include <iostream>
#include "Dictionary/Word.h"
#include "UniversalDependencyTreeBankFeatures.h"
#include <StringUtils.h>
#include "UniversalDependencyRelation.h"

const string UniversalDependencyTreeBankFeatures::universalFeatureTypes[25] =
        {"PronType", "NumType", "Poss", "Reflex", "Foreign",
         "Abbr", "Typo", "Gender", "Animacy", "NounClass",
         "Number", "Case", "Definite", "Degree", "VerbForm",
         "Mood", "Tense", "Aspect", "Voice", "Evident",
         "Polarity", "Person", "Polite", "Clusivity", "NumForm"};

const vector<string> UniversalDependencyTreeBankFeatures::universalFeatureValues[25] = {
        {"Art",    "Dem",    "Emp",    "Exc",    "Ind",    "Int",    "Neg",    "Prs",    "Rcp",    "Rel",     "Tot"},
        {"Card",   "Dist",   "Frac",   "Mult",   "Ord",    "Range",  "Sets"},
        {"Yes"},
        {"Yes"},
        {"Yes"},

        {"Yes"},
        {"Yes"},
        {"Com",    "Fem",    "Masc",   "Neut"},
        {"Anim",   "Hum",    "Inan",   "Nhum"},
        {"Bantu1", "Bantu2", "Bantu3", "Bantu4", "Bantu5", "Bantu6", "Bantu7", "Bantu8", "Bantu9", "Bantu10", "Bantu11", "Bantu12", "Bantu13", "Bantu14", "Bantu15", "Bantu16", "Bantu17", "Bantu18", "Bantu19", "Bantu20", "Bantu21", "Bantu22", "Bantu23", "Wol1", "Wol2", "Wol3", "Wol4", "Wol5", "Wol6", "Wol7", "Wol8", "Wol9", "Wol10", "Wol11", "Wol12"},

        {"Coll",   "Count",  "Dual",   "Grpa",   "Grpl",   "Inv",    "Pauc",   "Plur",   "Ptan",   "Sing",    "Tri"},
        {"Abs",    "Acc",    "Erg",    "Nom",    "Abe",    "Ben",    "Cau",    "Cmp",    "Cns",    "Com",     "Dat",     "Dis",     "Equ",     "Gen",     "Ins",     "Par",     "Tem",     "Tra",     "Voc",     "Abl",     "Add",     "Ade",     "All",     "Del",  "Ela",  "Ess",  "Ill",  "Ine",  "Lat",  "Loc",  "Per",  "Sbe",  "Sbl",   "Spl",   "Sub", "Sup", "Ter"},
        {"Com",    "Cons",   "Def",    "Ind",    "Spec"},
        {"Abs",    "Aug",    "Cmp",    "Dim",    "Equ",    "Pos",    "Sup"},
        {"Conv",   "Fin",    "Gdv",    "Ger",    "Inf",    "Part",   "Sup",    "Vnoun"},

        {"Adm",    "Cnd",    "Des",    "Imp",    "Ind",    "Int",    "Irr",    "Jus",    "Nec",    "Opt",     "Pot",     "Prp",     "Qot",     "Sub"},
        {"Fut",    "Imp",    "Past",   "Pqp",    "Pres"},
        {"Hab",    "Imp",    "Iter",   "Perf",   "Prog",   "Prosp"},
        {"Act",    "Antip",  "Bfoc",   "Cau",    "Dir",    "Inv",    "Lfoc",   "Mid",    "Pass",   "Rcp"},
        {"Fh",     "Nfh"},

        {"Neg",    "Pos"},
        {"0",      "1",      "2",      "3",      "4"},
        {"Elev",   "Form",   "Humb",   "Infm"},
        {"Ex",     "In"},
        {"Word", "Digit", "Roman"}
};

const vector<string> UniversalDependencyTreeBankFeatures::turkishFeatureValues[25] = {
        {"Art",  "Dem",  "Ind",  "Int",   "Neg",    "Prs",        "Rcp",     "Rel",        "Tot"},
        {"Card", "Dist", "Ord"},
        {},
        {"Yes"},
        {"Yes"},

        {"Yes"},
        {"Yes"},
        {},
        {},
        {},

        {"Plur", "Sing"},
        {"Acc",  "Nom",  "Dat",  "Equ",   "Gen",    "Ins",        "Abl",     "Loc"},
        {"Def",  "Ind"},
        {"Cmp",  "Sup"},
        {"Conv", "Fin",  "Part", "Vnoun"},

        {"Cnd",  "Des",  "Gen",  "Imp",   "Ind",    "Nec",        "Opt",     "Pot",        "DesPot", "CndPot",   "CndGen",  "CndGenPot", "GenPot", "PotPot", "GenNecPot", "GenNec", "NecPot", "GenPotPot", "ImpPot"},
        {"Fut",  "Past", "Pqp",  "Pres",  "Aor"},
        {"Imp",  "Perf", "Prog", "Prosp", "Hab",    "Rapid"},
        {"Cau",  "Pass", "Rcp",  "Rfl",   "CauCau", "CauCauPass", "CauPass", "CauPassRcp", "CauRcp", "PassPass", "PassRfl", "PassRcp"},
        {"Fh",   "Nfh"},

        {"Neg",  "Pos"},
        {"1",    "2",    "3"},
        {"Form", "Infm"},
        {},
        {}
};

const vector<string> UniversalDependencyTreeBankFeatures::englishFeatureValues[25] = {
        {"Art",  "Dem",  "Emp",  "Ind", "Int", "Neg", "Prs", "Rcp", "Rel", "Tot"},
        {"Card", "Frac", "Mult", "Ord"},
        {"Yes"},
        {"Yes"},
        {"Yes"},

        {"Yes"},
        {"Yes"},
        {"Fem",  "Masc", "Neut"},
        {},
        {},

        {"Plur", "Sing"},
        {"Acc",  "Nom",  "Gen"},
        {"Def",  "Ind"},
        {"Cmp",  "Pos",  "Sup"},
        {"Fin",  "Ger",  "Inf",  "Part"},

        {"Imp",  "Ind",  "Sub"},
        {"Past", "Pres"},
        {},
        {"Pass"},
        {},

        {"Neg"},
        {"1",    "2",    "3"},
        {},
        {},
        {"Word", "Digit", "Roman"}
};

/**
 * Constructor of a UniversalDependencyTreeBankFeatures object. Given the language of the word and features of the
 * word as a string, the method splits the features with respect to pipe character. Then for each feature type and
 * value pair, their values and types are inserted into the featureList hash map. The method also check for validity
 * of the feature values for that feature type.
 * @param language Language name. Currently, 'en' and 'tr' languages are supported.
 * @param features Feature string.
 */
UniversalDependencyTreeBankFeatures::UniversalDependencyTreeBankFeatures(const string &language,
                                                                         const string &features) {
    if (features != "_") {
        vector<string> list = StringUtils::split(features, "|");
        for (const string &feature: list) {
            if (feature.find_first_of('=') != -1) {
                string featureName = feature.substr(0, feature.find_first_of('='));
                string featureValue = feature.substr(feature.find_first_of('=') + 1, feature.length() - feature.find_first_of('=') - 1);
                if (featureValueIndex(language, featureName, featureValue) != -1) {
                    featureList.emplace(featureName, featureValue);
                } else {
                    cout << "Feature does not contain = ->" << featureName << " or the value " << featureValue <<  " is wrong" << endl;
                }
            } else {
                cout << "Feature does not contain = ->" << features;
            }
        }
    }
}

/**
 * Gets the value of a given feature.
 * @param feature Name of the feature
 * @return Value of the feature
 */
string UniversalDependencyTreeBankFeatures::getFeatureValue(const string &feature) const {
    return featureList.at(feature);
}

/**
 * Overridden toString method. Returns feature with their values separated with pipe characters.
 * @return A string of feature values and their names separated with pipe character.
 */
string UniversalDependencyTreeBankFeatures::to_string() const {
    if (featureList.empty()) {
        return "_";
    }
    string result;
    for (auto &feature: featureList) {
        if (result.empty()) {
            result = feature.first + "=" + feature.second;
        } else {
            result += "|" + feature.first + "=" + feature.second;
        }
    }
    return result;
}

/**
 * Checks if the given feature exists in the feature list.
 * @param feature Name of the feature
 * @return True, if the feature list contains the feature, false otherwise.
 */
bool UniversalDependencyTreeBankFeatures::featureExists(const string &feature) const {
    return featureList.contains(feature);
}

/**
 * Returns the index of the universal feature type in the universalFeatureTypes array, given the name of the feature
 * type.
 * @param featureName Name of the feature type
 * @return Index of the universal feature type in the universalFeatureTypes array. If the name does not exist, the
 * function returns -1.
 */
int UniversalDependencyTreeBankFeatures::featureIndex(const string& featureName) {
    string tmpName = featureName;
    if (featureName.find('[') != string::npos){
        tmpName = featureName.substr(0, featureName.find('['));
    }
    for (int i = 0; i < 24; i++){
        if (universalFeatureTypes[i] == tmpName){
            return i;
        }
    }
    return -1;
}

/**
 * Returns the index of the universal dependency type in the universalDependencyTypes array, given the name of the
 * universal dependency type.
 * @param universalDependency Universal dependency type
 * @return Index of the universal dependency type in the universalDependencyTypes array. If the name does not exist,
 * the function returns -1.
 */
int UniversalDependencyTreeBankFeatures::dependencyIndex(const string &universalDependency) {
    int index = 0;
    for (const auto& dependency : UniversalDependencyRelation::universalDependencyTypes){
        if (dependency == universalDependency){
            return index;
        }
        index++;
    }
    return -1;
}

/**
 * Returns the number of distinct values for a feature in a given language
 * @param language Language name. Currently, 'en' and 'tr' languages are supported.
 * @param featureName Name of the feature type.
 * @return The number of distinct values for a feature in a given language
 */
int UniversalDependencyTreeBankFeatures::numberOfValues(const string& language, const string& featureName) {
    int index = featureIndex(featureName);
    if (index != -1) {
        if (language == "en") {
            return englishFeatureValues[index].size();
        } else {
            if (language == "tr"){
                return turkishFeatureValues[index].size();
            }
        }
    }
    return -1;
}

/**
 * Returns the index of the given value in the feature value array for the given feature in the given
 * language.
 * @param language Language name. Currently, 'en' and 'tr' languages are supported.
 * @param featureName Name of the feature.
 * @param featureValue Value of the feature.
 * @return The index of the given feature value in the feature value array for the given feature in the given
 * language.
 */
int UniversalDependencyTreeBankFeatures::featureValueIndex(const string &language, const string &featureName,
                                                           const string &featureValue) {
    vector<string> *searchArray;
    int index = featureIndex(featureName);
    if (index != -1) {
        if (language == "en") {
            searchArray = const_cast<vector<std::string> *>(englishFeatureValues);
        } else {
            if (language == "tr") {
                searchArray = const_cast<vector<std::string> *>(turkishFeatureValues);
            } else {
                searchArray = const_cast<vector<std::string> *>(universalFeatureValues);
            }
        }
        int featureValueIndex = -1;
        for (int i = 0; i < searchArray[index].size(); i++){
            if (searchArray[index][i] == featureValue){
                featureValueIndex = i;
            }
        }
        return featureValueIndex;
    }
    return -1;
}

UniversalDependencyTreeBankFeatures::UniversalDependencyTreeBankFeatures(UniversalDependencyTreeBankFeatures &copy) {
    string features = copy.to_string();
    if (features != "_") {
        vector<string> list = StringUtils::split(features, "|");
        for (const string &feature: list) {
            if (feature.find_first_of('=') != -1) {
                string featureName = feature.substr(0, feature.find_first_of('=') - 1);
                string featureValue = feature.substr(feature.find_first_of('=') + 1);
                if (featureValueIndex("u", featureName, featureValue) != -1) {
                    featureList.emplace(featureName, featureValue);
                }
            }
        }
    }
}

/**
 * Returns the index of the given universal dependency pos.
 * @param uPos Given universal dependency part of speech tag.
 * @return The index of the universal dependency pos.
 */
int UniversalDependencyTreeBankFeatures::posIndex(const string &uPos) {
    int index = 0;
    for (const string& posType : UniversalDependencyRelation::universalDependencyPosTypes){
        if (posType == uPos){
            return index;
        }
        index++;
    }
    return -1;
}

string UniversalDependencyTreeBankFeatures::getPosString(UniversalDependencyPosType uPos) {
    switch (uPos) {
        case UniversalDependencyPosType::ADJ:
            return UniversalDependencyRelation::universalDependencyPosTypes[0];
        case UniversalDependencyPosType::ADV:
            return UniversalDependencyRelation::universalDependencyPosTypes[1];
        case UniversalDependencyPosType::INTJ:
            return UniversalDependencyRelation::universalDependencyPosTypes[2];
        case UniversalDependencyPosType::NOUN:
            return UniversalDependencyRelation::universalDependencyPosTypes[3];
        case UniversalDependencyPosType::PROPN:
            return UniversalDependencyRelation::universalDependencyPosTypes[4];
        case UniversalDependencyPosType::VERB:
            return UniversalDependencyRelation::universalDependencyPosTypes[5];
        case UniversalDependencyPosType::ADP:
            return UniversalDependencyRelation::universalDependencyPosTypes[6];
        case UniversalDependencyPosType::AUX:
            return UniversalDependencyRelation::universalDependencyPosTypes[7];
        case UniversalDependencyPosType::CCONJ:
            return UniversalDependencyRelation::universalDependencyPosTypes[8];
        case UniversalDependencyPosType::DET:
            return UniversalDependencyRelation::universalDependencyPosTypes[9];
        case UniversalDependencyPosType::NUM:
            return UniversalDependencyRelation::universalDependencyPosTypes[10];
        case UniversalDependencyPosType::PART:
            return UniversalDependencyRelation::universalDependencyPosTypes[11];
        case UniversalDependencyPosType::PRON:
            return UniversalDependencyRelation::universalDependencyPosTypes[12];
        case UniversalDependencyPosType::SCONJ:
            return UniversalDependencyRelation::universalDependencyPosTypes[13];
        case UniversalDependencyPosType::PUNCT:
            return UniversalDependencyRelation::universalDependencyPosTypes[14];
        case UniversalDependencyPosType::SYM:
            return UniversalDependencyRelation::universalDependencyPosTypes[15];
        case UniversalDependencyPosType::X:
            return UniversalDependencyRelation::universalDependencyPosTypes[16];
    }
}
