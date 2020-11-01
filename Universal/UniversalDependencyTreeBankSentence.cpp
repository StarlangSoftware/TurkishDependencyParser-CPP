//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <Word.h>
#include "UniversalDependencyTreeBankSentence.h"
#include "UniversalDependencyTreeBankWord.h"

UniversalDependencyTreeBankSentence::UniversalDependencyTreeBankSentence() : Sentence(){

}

void UniversalDependencyTreeBankSentence::addComment(string comment) {
    comments.emplace_back(comment);
}

string UniversalDependencyTreeBankSentence::to_string() {
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
