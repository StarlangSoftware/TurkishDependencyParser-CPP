//
// Created by Olcay Taner Yıldız on 2019-03-16.
//

#include "TurkishDependencyTreeBankWord.h"
#include "StringUtils.h"

/**
 * Given the parsed xml node which contains information about a word and related attributes including the
 * dependencies, the method constructs a TurkishDependencyTreeBankWord from it.
 * @param wordNode Xml parsed node containing information about a word.
 */
TurkishDependencyTreeBankWord::TurkishDependencyTreeBankWord(XmlElement* wordNode) {
    string IG, relationName, dependencyType;
    int index, toWord = 0, toIG = 0;
    if (wordNode->hasAttributes()){
        name = wordNode->getPcData();
        if (!wordNode->getAttributeValue("IG").empty()){
            IG = wordNode->getAttributeValue("IG");
            parse = MorphologicalParse(splitIntoInflectionalGroups(IG));
        }
        if (!wordNode->getAttributeValue("REL").empty()){
            relationName = wordNode->getAttributeValue("REL");
            if (relationName != "[,( )]"){
                vector<string> relationParts = StringUtils::split(relationName, ",[]()");
                index = 0;
                for (const auto & relationPart : relationParts){
                    if (!relationPart.empty()){
                        index++;
                        switch (index){
                            case 1:
                                toWord = stoi(relationPart);
                                break;
                            case 2:
                                toIG = stoi(relationPart);
                                break;
                            case 3:
                                dependencyType = relationPart;
                                relation = TurkishDependencyRelation(toWord - 1, toIG - 1, dependencyType);
                                break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= 9; i++){
            if (!wordNode->getAttributeValue("ORG_IG" + std::to_string(i)).empty()){
                IG = wordNode->getAttributeValue("ORG_IG" + std::to_string(i));
                originalParses.emplace_back(splitIntoInflectionalGroups(IG));
            }
        }
    }
}

/**
 * Given the morphological parse of a word, this method splits it into inflectional groups.
 * @param IG Morphological parse of the word in string form.
 * @return An array of inflectional groups stored as strings.
 */
vector<string> TurkishDependencyTreeBankWord::splitIntoInflectionalGroups(const string& IG) {
    vector<string> inflectionalGroups;
    string ig;
    ig = StringUtils::replaceAll(IG, "(+Punc", "@");
    ig = StringUtils::replaceAll(ig, ")+Punc", "$");
    vector<string> iGs = StringUtils::split(ig, "[()]");
    for (auto IGI : iGs){
        IGI = StringUtils::replaceAll(IGI, "@", "(+Punc");
        IGI = StringUtils::replaceAll(IGI, "$", ")+Punc");
        if (!IGI.empty()){
            inflectionalGroups.emplace_back(IGI);
        }
    }
    return inflectionalGroups;
}

/**
 * Accessor for the parse attribute
 * @return Parse attribute
 */
MorphologicalParse TurkishDependencyTreeBankWord::getParse() const{
    return parse;
}

/**
 * Accessor for a specific parse.
 * @param index Index of the word.
 * @return Parse of the index'th word
 */
MorphologicalParse TurkishDependencyTreeBankWord::getOriginalParse(int index) const{
    return originalParses.at(index);
}

/**
 * Number of words in this item.
 * @return Number of words in this item.
 */
int TurkishDependencyTreeBankWord::size() const{
    return originalParses.size();
}

/**
 * Accessor for the relation attribute.
 * @return relation attribute.
 */
TurkishDependencyRelation TurkishDependencyTreeBankWord::getRelation() const{
    return relation;
}
