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

StanfordDependencyType StanfordDependencyRelation::getDependencyTag(string tag) {
    for (int j = 0; j < 49; j++) {
        if (tag == StanfordDependencyRelation::stanfordDependencyTypes[j]) {
            return StanfordDependencyRelation::stanfordDependencyTags[j];
        }
    }
    return StanfordDependencyType::XSUBJ;
}

StanfordDependencyRelation::StanfordDependencyRelation(int toWord, string dependencyType) : DependencyRelation(toWord){
    this->stanfordDependencyType = getDependencyTag(dependencyType);
}

