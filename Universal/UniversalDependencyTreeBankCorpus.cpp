//
// Created by Olcay Taner YILDIZ on 1.11.2020.
//

#include <fstream>
#include <iostream>
#include <regex>
#include "UniversalDependencyTreeBankCorpus.h"
#include "UniversalDependencyRelation.h"
#include "UniversalDependencyTreeBankSentence.h"
#include "UniversalDependencyTreeBankFeatures.h"
#include "UniversalDependencyTreeBankWord.h"

using namespace std;

void to_upper(char& ch) {
    ch = toupper(static_cast<unsigned char>(ch));
}

UniversalDependencyTreeBankCorpus::UniversalDependencyTreeBankCorpus(string fileName) {
    UniversalDependencyTreeBankSentence* sentence = nullptr;
    UniversalDependencyRelation* relation;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = move(fileName);
    string line;
    while (inputStream.good()){
        getline(inputStream, line);
        if (line.empty()){
            if (sentence != nullptr){
                addSentence(sentence);
            }
            sentence = nullptr;
        } else {
            if (Word::startsWith(line, "#")){
                if (sentence == nullptr){
                    sentence = new UniversalDependencyTreeBankSentence();
                }
                sentence->addComment(Word::trim(line));
            } else {
                vector<string> items = Word::split(line, "\t");
                if (items.size() != 10){
                    cout << "Line does not contain 10 items ->" << line;
                } else {
                    string id = items[0];
                    if (regex_match(id, regex("\\d+"))){
                        string surfaceForm = items[1];
                        string lemma = items[2];
                        UniversalDependencyPosType upos = UniversalDependencyRelation::getDependencyPosType(items[3]);
                        string xpos = items[4];
                        auto* features = new UniversalDependencyTreeBankFeatures(items[5]);
                        if (items[6] != "_"){
                            int to = stoi(items[6]);
                            string dependencyType = items[7];
                            std::for_each(dependencyType.begin(), dependencyType.end(), to_upper);
                            relation = new UniversalDependencyRelation(to, dependencyType);
                        } else {
                            relation = nullptr;
                        }
                        string deps = items[8];
                        string misc = items[9];
                        auto* word = new UniversalDependencyTreeBankWord(stoi(id), surfaceForm,
                                                                                                   lemma, upos, xpos, features, relation, deps, misc);
                        sentence->addWord(word);
                    }
                }
            }
        }
    }
}
