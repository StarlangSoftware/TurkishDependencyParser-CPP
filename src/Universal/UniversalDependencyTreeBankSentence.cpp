//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include "Dictionary/Word.h"
#include <iostream>
#include <regex>
#include "UniversalDependencyTreeBankSentence.h"

#include <StringUtils.h>

#include "UniversalDependencyTreeBankWord.h"

/**
 * Empty constructor for the UniversalDependencyTreeBankSentence. Initializes comments.
 */
UniversalDependencyTreeBankSentence::UniversalDependencyTreeBankSentence() : Sentence(){

}

/**
 * Constructor for the UniversalDependencyTreeBankSentence.  Get a line as input and splits the line wrt tab
 * character. The number of items should be 10. The items are id, surfaceForm, lemma, upos, xpos, feature list,
 * head word index, dependency type, external dependencies and miscellaneous things for one word.
 * @param language Language name. Currently, 'en' and 'tr' languages are supported.
 * @param sentence Sentence string to be processed.
 */
UniversalDependencyTreeBankSentence::UniversalDependencyTreeBankSentence(const string& language, const string& sentence) : Sentence(){
    UniversalDependencyRelation* relation;
    vector<string> lines = StringUtils::split(sentence, "\n");
    for (const string& line : lines){
        if (line.empty()){
            continue;
        }
        if (StringUtils::startsWith(line, "#")){
            addComment(StringUtils::trim(line));
        } else {
            vector<string> items = StringUtils::split(line, "\t");
            if (items.size() != 10){
                cout << "Line does not contain 10 items ->" << line;
            } else {
                string id = items[0];
                if (regex_match(id, regex("\\d+"))){
                    string surfaceForm = items[1];
                    string lemma = items[2];
                    UniversalDependencyPosType upos = UniversalDependencyRelation::getDependencyPosType(items[3]);
                    string xpos = items[4];
                    auto* features = new UniversalDependencyTreeBankFeatures(language, items[5]);
                    if (items[6] != "_"){
                        int to = stoi(items[6]);
                        string dependencyType = items[7];
                        std::transform(dependencyType.begin(), dependencyType.end(), dependencyType.begin(), ::toupper);
                        relation = new UniversalDependencyRelation(to, dependencyType);
                    } else {
                        relation = nullptr;
                    }
                    string deps = items[8];
                    string misc = items[9];
                    auto* word = new UniversalDependencyTreeBankWord(stoi(id), surfaceForm,
                                                                     lemma, upos, xpos, features, relation, deps, misc);
                    addWord(word);
                }
            }
        }
    }
}

/**
 * Adds a comment string to comments array list.
 * @param comment Comment to be added.
 */
void UniversalDependencyTreeBankSentence::addComment(const string& comment) {
    comments.emplace_back(comment);
}

/**
 * Overridden toString method. Concatenates the strings of words to get the string of a sentence.
 * @return Concatenation of the strings of thw strings of words.
 */
string UniversalDependencyTreeBankSentence::to_string() const{
    string result;
    for (const string& comment : comments){
        result += comment + "\n";
    }
    for (Word* w : this->words){
        auto* word = (UniversalDependencyTreeBankWord*) w;
        result += word->to_string() + "\n";
    }
    return result;
}

/**
 * Compares the sentence with the given sentence and returns a parser evaluation score for this comparison. The result
 * is calculated by summing up the parser evaluation scores of word by word dpendency relation comparisons.
 * @param sentence Universal dependency sentence to be compared.
 * @return A parser evaluation score object.
 */
ParserEvaluationScore
UniversalDependencyTreeBankSentence::compareParses(UniversalDependencyTreeBankSentence *sentence) const{
    ParserEvaluationScore score = ParserEvaluationScore();
    for (int i = 0; i < words.size(); i++){
        UniversalDependencyRelation* relation1 = ((UniversalDependencyTreeBankWord*) words.at(i))->getRelation();
        UniversalDependencyRelation* relation2 = ((UniversalDependencyTreeBankWord*) sentence->getWord(i))->getRelation();
        if (relation1 != nullptr && relation2 != nullptr){
            score.add(relation1->compareRelations(relation2));
        }
    }
    return score;
}
