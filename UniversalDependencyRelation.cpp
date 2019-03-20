//
// Created by olcay on 14.03.2019.
//

#include "UniversalDependencyRelation.h"

const string UniversalDependencyRelation::universalDependencyTypes[37] = {"acl", "advcl", "advmod", "amod", "appos", "aux",
                                                                         "case", "cc", "ccomp", "clf", "compound", "conj", "cop", "csubj", "dep", "det", "discourse", "dislocated",
                                                                         "expl", "fixed", "flat", "goeswith", "iobj", "list", "mark", "nmod", "nsubj", "nummod", "obj", "obl", "orphan",
                                                                         "parataxis", "punct", "reparandum", "root", "vocative", "xcomp"};

const UniversalDependencyType UniversalDependencyRelation::universalDependencyTags[37] = {UniversalDependencyType::ACL, UniversalDependencyType::ADVCL,
                                                                                          UniversalDependencyType::ADVMOD, UniversalDependencyType::AMOD, UniversalDependencyType::APPOS, UniversalDependencyType::AUX, UniversalDependencyType::CASE,
                                                                                          UniversalDependencyType::CC, UniversalDependencyType::CCOMP, UniversalDependencyType::CLF, UniversalDependencyType::COMPOUND, UniversalDependencyType::CONJ,
                                                                                          UniversalDependencyType::COP, UniversalDependencyType::CSUBJ, UniversalDependencyType::DEP, UniversalDependencyType::DET, UniversalDependencyType::DISCOURSE,
                                                                                          UniversalDependencyType::DISLOCATED, UniversalDependencyType::EXPL, UniversalDependencyType::FIXED, UniversalDependencyType::FLAT,
                                                                                          UniversalDependencyType::GOESWITH, UniversalDependencyType::IOBJ, UniversalDependencyType::LIST, UniversalDependencyType::MARK, UniversalDependencyType::NMOD,
                                                                                          UniversalDependencyType::NSUBJ, UniversalDependencyType::NUMMOD, UniversalDependencyType::OBJ, UniversalDependencyType::OBL, UniversalDependencyType::ORPHAN,
                                                                                          UniversalDependencyType::PARATAXIS, UniversalDependencyType::PUNCT, UniversalDependencyType::REPARANDUM, UniversalDependencyType::ROOT,
                                                                                          UniversalDependencyType::VOCATIVE, UniversalDependencyType::XCOMP};

UniversalDependencyRelation::UniversalDependencyRelation(int toWord) : DependencyRelation(toWord) {
}

UniversalDependencyRelation::UniversalDependencyRelation(int toWord, string dependencyType) : DependencyRelation(toWord){
    this->universalDependencyType = getDependencyTag(move(dependencyType));
}

UniversalDependencyType UniversalDependencyRelation::getDependencyTag(string tag) {
    for (int j = 0; j < 37; j++) {
        if (tag == UniversalDependencyRelation::universalDependencyTypes[j]) {
            return UniversalDependencyRelation::universalDependencyTags[j];
        }
    }
}

string UniversalDependencyRelation::to_string(){
    return UniversalDependencyRelation::universalDependencyTypes[static_cast<int>(universalDependencyType)];
}