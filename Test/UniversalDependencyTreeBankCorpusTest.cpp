//
// Created by Olcay Taner YILDIZ on 8.01.2021.
//

#include "catch.hpp"
#include "../src/Universal/UniversalDependencyTreeBankCorpus.h"
#include "../src/Universal/UniversalDependencyTreeBankSentence.h"

int wordCount(const UniversalDependencyTreeBankCorpus& corpus){
    int wordCount = 0;
    for (int i = 0; i < corpus.sentenceCount(); i++){
        wordCount += corpus.getSentence(i)->wordCount();
    }
    return wordCount;
}

int splitCount(const UniversalDependencyTreeBankCorpus& corpus){
    int splitCount = 0;
    for (int i = 0; i < corpus.sentenceCount(); i++){
        splitCount += ((UniversalDependencyTreeBankSentence*)corpus.getSentence(i))->splitSize();
    }
    return splitCount;
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus1") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_gb-ud-test.conllu");
    REQUIRE(2880 == corpus->sentenceCount());
    REQUIRE(17177 == wordCount(*corpus));
    REQUIRE(371 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus2") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_imst2-ud-dev.conllu");
    REQUIRE(1100 == corpus->sentenceCount());
    REQUIRE(10542 == wordCount(*corpus));
    REQUIRE(279 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus3") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_imst2-ud-test.conllu");
    REQUIRE(1100 == corpus->sentenceCount());
    REQUIRE(10032 == wordCount(*corpus));
    REQUIRE(278 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus4") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_imst2-ud-train.conllu");
    REQUIRE(3435 == corpus->sentenceCount());
    REQUIRE(37522 == wordCount(*corpus));
    REQUIRE(1082 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus5") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_pud-ud-test.conllu");
    REQUIRE(1000 == corpus->sentenceCount());
    REQUIRE(16881 == wordCount(*corpus));
    REQUIRE(346 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus6") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_boun-ud-dev.conllu");
    REQUIRE(979 == corpus->sentenceCount());
    REQUIRE(12289 == wordCount(*corpus));
    REQUIRE(266 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus7") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_boun-ud-test.conllu");
    REQUIRE(979 == corpus->sentenceCount());
    REQUIRE(12210 == wordCount(*corpus));
    REQUIRE(194 == splitCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus8") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_boun-ud-train.conllu");
    REQUIRE(7803 == corpus->sentenceCount());
    REQUIRE(100713 == wordCount(*corpus));
    REQUIRE(2914 == splitCount(*corpus));
}