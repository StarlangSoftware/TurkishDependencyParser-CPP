//
// Created by Olcay Taner YILDIZ on 8.01.2021.
//

#include "catch.hpp"
#include "../src/Universal/UniversalDependencyTreeBankCorpus.h"

int wordCount(UniversalDependencyTreeBankCorpus corpus){
    int wordCount = 0;
    for (int i = 0; i < corpus.sentenceCount(); i++){
        wordCount += corpus.getSentence(i)->wordCount();
    }
    return wordCount;
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus1") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_gb-ud-test.conllu");
    REQUIRE(2880 == corpus->sentenceCount());
    REQUIRE(17177 == wordCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus2") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_imst-ud-dev.conllu");
    REQUIRE(1100 == corpus->sentenceCount());
    REQUIRE(10542 == wordCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus3") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_imst-ud-test.conllu");
    REQUIRE(1100 == corpus->sentenceCount());
    REQUIRE(10032 == wordCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus4") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_imst-ud-train.conllu");
    REQUIRE(3435 == corpus->sentenceCount());
    REQUIRE(37522 == wordCount(*corpus));
}

TEST_CASE("UniversalDependencyTreeBankCorpusTest-testDependencyCorpus5") {
    auto* corpus = new UniversalDependencyTreeBankCorpus("tr_pud-ud-test.conllu");
    REQUIRE(1000 == corpus->sentenceCount());
    REQUIRE(16881 == wordCount(*corpus));
}