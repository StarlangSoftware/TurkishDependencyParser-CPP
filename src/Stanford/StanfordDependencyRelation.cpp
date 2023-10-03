//
// Created by olcay on 14.03.2019.
//

#include "StanfordDependencyRelation.h"

const string StanfordDependencyRelation::stanfordDependencyTypes[49] = {"acomp", "advcl", "advmod", "agent", "amod", "appos", "aux",
                                                        "auxpass", "cc", "ccomp", "conj", "cop", "csubj", "csubjpass", "dep", "det", "discourse", "dobj", "expl", "goeswith",
                                                        "iobj", "mark", "mwe", "neg", "nn", "npadvmod", "nsubj", "nsubjpass", "num", "number", "parataxis", "pcomp",
                                                        "pobj", "poss", "possessive", "preconj", "predet", "prep", "prepc", "prt", "punct", "quantmod", "rcmod", "ref",
                                                        "root", "tmod", "vmod", "xcomp", "xsubj"};

const StanfordDependencyType StanfordDependencyRelation::stanfordDependencyTags[49] = {StanfordDependencyType::ACOMP, StanfordDependencyType::ADVCL,
                                                           StanfordDependencyType::ADVMOD, StanfordDependencyType::AGENT, StanfordDependencyType::AMOD, StanfordDependencyType::APPOS, StanfordDependencyType::AUX,
                                                           StanfordDependencyType::AUXPASS, StanfordDependencyType::CC, StanfordDependencyType::CCOMP, StanfordDependencyType::CONJ, StanfordDependencyType::COP,
                                                           StanfordDependencyType::CSUBJ, StanfordDependencyType::CSUBJPASS, StanfordDependencyType::DEP, StanfordDependencyType::DET, StanfordDependencyType::DISCOURSE,
                                                           StanfordDependencyType::DOBJ, StanfordDependencyType::EXPL, StanfordDependencyType::GOESWITH, StanfordDependencyType::IOBJ, StanfordDependencyType::MARK,
                                                           StanfordDependencyType::MWE, StanfordDependencyType::NEG, StanfordDependencyType::NN, StanfordDependencyType::NPADVMOD, StanfordDependencyType::NSUBJ,
                                                           StanfordDependencyType::NSUBJPASS, StanfordDependencyType::NUM, StanfordDependencyType::NUMBER, StanfordDependencyType::PARATAXIS, StanfordDependencyType::PCOMP,
                                                           StanfordDependencyType::POBJ, StanfordDependencyType::POSS, StanfordDependencyType::POSSESSIVE, StanfordDependencyType::PRECONJ, StanfordDependencyType::PREDET,
                                                           StanfordDependencyType::PREP, StanfordDependencyType::PREPC, StanfordDependencyType::PRT, StanfordDependencyType::PUNCT, StanfordDependencyType::QUANTMOD,
                                                           StanfordDependencyType::RCMOD, StanfordDependencyType::REF, StanfordDependencyType::ROOT, StanfordDependencyType::TMOD, StanfordDependencyType::VMOD,
                                                           StanfordDependencyType::XCOMP, StanfordDependencyType::XSUBJ};

/**
 * The getDependencyTag method takes an dependency tag as string and returns the StanfordDependencyType
 * form of it.
 *
 * @param tag  Type of the dependency tag in string form
 * @return Type of the dependency in StanfordDependencyType form
 */
StanfordDependencyType StanfordDependencyRelation::getDependencyTag(const string& tag) {
    string _tag = tag;
    transform(_tag.begin(),
              _tag.end(),
              _tag.begin(),
              tolower);
    for (int j = 0; j < 49; j++) {
        if (_tag == StanfordDependencyRelation::stanfordDependencyTypes[j]) {
            return StanfordDependencyRelation::stanfordDependencyTags[j];
        }
    }
    return StanfordDependencyType::XSUBJ;
}

/**
 * Another constructor for StanfordDependencyRelation. Gets input toWord and dependencyType as arguments and
 * calls the super class's constructor and sets the dependency type.
 * @param toWord Index of the word in the sentence that dependency relation is related
 * @param dependencyType Type of the dependency relation in string form
 */
StanfordDependencyRelation::StanfordDependencyRelation(int toWord, const string& dependencyType) : DependencyRelation(toWord){
    this->stanfordDependencyType = getDependencyTag(dependencyType);
}

string StanfordDependencyRelation::to_string() const{
    return StanfordDependencyRelation::stanfordDependencyTypes[static_cast<int>(stanfordDependencyType)];
}