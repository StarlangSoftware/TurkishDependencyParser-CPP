//
// Created by olcay on 14.03.2019.
//

#include "UniversalDependencyRelation.h"
#include "UniversalDependencyPosType.h"

const string UniversalDependencyRelation::universalDependencyTypes[62] = {"acl", "advcl",
                                                                          "advmod", "amod", "appos", "aux", "case",
                                                                          "cc", "ccomp", "clf", "compound", "conj",
                                                                          "cop", "csubj", "dep", "det", "discourse",
                                                                          "dislocated", "expl", "fixed", "flat",
                                                                          "goeswith", "iobj", "list", "mark", "nmod",
                                                                          "nsubj", "nummod", "obj", "obl", "orphan",
                                                                          "parataxis", "punct", "reparandum", "root",
                                                                          "vocative", "xcomp", "acl:relcl", "aux:pass",
                                                                          "cc:preconj", "compound:prt", "det:predet", "flat:foreign",
                                                                          "nsubj:pass", "csubj:pass", "nmod:npmod", "nmod:poss",
                                                                          "nmod:tmod", "avdmod:emph", "aux:q", "compound:lvc",
                                                                          "compound:redup", "csubj:cop", "nmod:comp", "nmod:part",
                                                                          "nsubj:cop", "obl:agent", "obl:tmod", "obl:npmod", "nsubj:outer",
                                                                          "csubj:outer", "advcl:relcl"};

const UniversalDependencyType UniversalDependencyRelation::universalDependencyTags[62] = {UniversalDependencyType::ACL, UniversalDependencyType::ADVCL,
                                                                                          UniversalDependencyType::ADVMOD, UniversalDependencyType::AMOD, UniversalDependencyType::APPOS, UniversalDependencyType::AUX, UniversalDependencyType::CASE,
                                                                                          UniversalDependencyType::CC, UniversalDependencyType::CCOMP, UniversalDependencyType::CLF, UniversalDependencyType::COMPOUND, UniversalDependencyType::CONJ,
                                                                                          UniversalDependencyType::COP, UniversalDependencyType::CSUBJ, UniversalDependencyType::DEP, UniversalDependencyType::DET, UniversalDependencyType::DISCOURSE,
                                                                                          UniversalDependencyType::DISLOCATED, UniversalDependencyType::EXPL, UniversalDependencyType::FIXED, UniversalDependencyType::FLAT,
                                                                                          UniversalDependencyType::GOESWITH, UniversalDependencyType::IOBJ, UniversalDependencyType::LIST, UniversalDependencyType::MARK, UniversalDependencyType::NMOD,
                                                                                          UniversalDependencyType::NSUBJ, UniversalDependencyType::NUMMOD, UniversalDependencyType::OBJ, UniversalDependencyType::OBL, UniversalDependencyType::ORPHAN,
                                                                                          UniversalDependencyType::PARATAXIS, UniversalDependencyType::PUNCT, UniversalDependencyType::REPARANDUM, UniversalDependencyType::ROOT,
                                                                                          UniversalDependencyType::VOCATIVE, UniversalDependencyType::XCOMP, UniversalDependencyType::ACL_RELCL, UniversalDependencyType::AUX_PASS,
                                                                                          UniversalDependencyType::CC_PRECONJ, UniversalDependencyType::COMPOUND_PRT, UniversalDependencyType::DET_PREDET, UniversalDependencyType::FLAT_FOREIGN,
                                                                                          UniversalDependencyType::NSUBJ_PASS, UniversalDependencyType::CSUBJ_PASS, UniversalDependencyType::NMOD_NPMOD, UniversalDependencyType::NMOD_POSS,
                                                                                          UniversalDependencyType::NMOD_TMOD, UniversalDependencyType::ADVMOD_EMPH, UniversalDependencyType::AUX_Q, UniversalDependencyType::COMPOUND_LVC,
                                                                                          UniversalDependencyType::COMPOUND_REDUP, UniversalDependencyType::CSUBJ_COP, UniversalDependencyType::NMOD_COMP, UniversalDependencyType::NMOD_PART,UniversalDependencyType::NSUBJ_COP,
                                                                                          UniversalDependencyType::OBL_AGENT, UniversalDependencyType::OBL_TMOD, UniversalDependencyType::OBL_NPMOD, UniversalDependencyType::NSUBJ_OUTER,
                                                                                          UniversalDependencyType::CSUBJ_OUTER, UniversalDependencyType::ADVCL_RELCL};

const string UniversalDependencyRelation::universalDependencyPosTypes[17] = {"ADJ", "ADV", "INTJ", "NOUN", "PROPN", "VERB", "ADP", "AUX", "CCONJ",
                                                            "DET", "NUM", "PART", "PRON", "SCONJ", "PUNCT", "SYM", "X"};

const UniversalDependencyPosType UniversalDependencyRelation::universalDependencyPosTags[17] = {UniversalDependencyPosType::ADJ, UniversalDependencyPosType::ADV, UniversalDependencyPosType::INTJ, UniversalDependencyPosType::NOUN, UniversalDependencyPosType::PROPN,
                                                                               UniversalDependencyPosType::VERB, UniversalDependencyPosType::ADP, UniversalDependencyPosType::AUX, UniversalDependencyPosType::CCONJ, UniversalDependencyPosType::DET, UniversalDependencyPosType::NUM, UniversalDependencyPosType::PART,
                                                                               UniversalDependencyPosType::PRON, UniversalDependencyPosType::SCONJ, UniversalDependencyPosType::PUNCT, UniversalDependencyPosType::SYM, UniversalDependencyPosType::X};

/**
 * Overriden Universal Dependency Relation constructor. Gets toWord as input and calls it super class's constructor
 * @param toWord Index of the word in the sentence that dependency relation is related
 */
UniversalDependencyRelation::UniversalDependencyRelation(int toWord) : DependencyRelation(toWord) {
}

/**
 * Another constructor for UniversalDependencyRelation. Gets input toWord and dependencyType as arguments and
 * calls the super class's constructor and sets the dependency type.
 * @param toWord Index of the word in the sentence that dependency relation is related
 * @param dependencyType Type of the dependency relation in string form
 */
UniversalDependencyRelation::UniversalDependencyRelation(int toWord, const string& dependencyType) : DependencyRelation(toWord){
    this->universalDependencyType = getDependencyTag(dependencyType);
}

/**
 * The getDependencyTag method takes an dependency tag as string and returns the UniversalDependencyType
 * form of it.
 *
 * @param tag  Type of the dependency tag in string form
 * @return Type of the dependency in UniversalDependencyType form
 */
UniversalDependencyType UniversalDependencyRelation::getDependencyTag(const string& tag) {
    string _tag = tag;
    transform(_tag.begin(),
              _tag.end(),
              _tag.begin(),
              ::tolower);
    for (int j = 0; j < 62; j++) {
        if (_tag == UniversalDependencyRelation::universalDependencyTypes[j]) {
            return UniversalDependencyRelation::universalDependencyTags[j];
        }
    }
}

/**
 * The getDependencyTag method takes a dependency pos type as string and returns the {@link UniversalDependencyPosType}
 * form of it.
 * @param tag Dependency pos type in string form
 * @return Dependency pos type for a given dependency pos string
 */
UniversalDependencyPosType UniversalDependencyRelation::getDependencyPosType(const string& tag){
    string _tag = tag;
    transform(_tag.begin(),
                   _tag.end(),
                   _tag.begin(),
                   ::toupper);
    for (int i = 0; i < 17; i++) {
        if (_tag == universalDependencyPosTypes[i]) {
            return universalDependencyPosTags[i];
        }
    }
}

string UniversalDependencyRelation::to_string() const{
    return UniversalDependencyRelation::universalDependencyTypes[static_cast<int>(universalDependencyType)];
}

string UniversalDependencyRelation::to_string(UniversalDependencyPosType posType) {
    return UniversalDependencyRelation::universalDependencyPosTypes[static_cast<int>(posType)];
}

/**
 * Compares the relation with the given universal dependency relation and returns a parser evaluation score for this
 * comparison. If toWord fields are equal for both relation UAS is 1, otherwise it is 0. If both toWord and
 * dependency types are the same, LAS is 1, otherwise it is 0. If only dependency types of both relations are
 * the same, LS is 1, otherwise it is 0.
 * @param relation Universal dependency relation to be compared.
 * @return A parser evaluation score object with (i) LAS = 1, if to and dependency types are same; LAS = 0,
 * otherwise, (ii) UAS = 1, if to is the same; UAS = 0, otherwise, (iii) LS = 1, if dependency types are the same;
 * LS = 0, otherwise.
 */
ParserEvaluationScore UniversalDependencyRelation::compareRelations(UniversalDependencyRelation* relation) const{
    double LS = 0.0, LAS = 0.0, UAS = 0.0;
    if (to_string() == relation->to_string()){
        LS = 1.0;
        if (toWord == relation->to()){
            LAS = 1.0;
        }
    }
    if (toWord == relation->to()){
        UAS = 1.0;
    }
    return {LAS, UAS, LS, 1};
}

UniversalDependencyRelation::UniversalDependencyRelation() {

}

UniversalDependencyRelation::UniversalDependencyRelation(UniversalDependencyRelation& copy) {
    this->toWord = copy.toWord;
    this->universalDependencyType = copy.universalDependencyType;
}
