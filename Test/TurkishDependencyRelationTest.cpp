//
// Created by Olcay Taner YILDIZ on 9.02.2021.
//

#include "catch.hpp"
#include "../Turkish/TurkishDependencyRelation.h"

TEST_CASE("TurkishDependencyRelationTest-testDependencyType") {
    REQUIRE_FALSE(TurkishDependencyRelation::getDependencyTag("subject") != TurkishDependencyType::SUBJECT);
    REQUIRE_FALSE(TurkishDependencyRelation::getDependencyTag("vocative") != TurkishDependencyType::VOCATIVE);
    REQUIRE_FALSE(TurkishDependencyRelation::getDependencyTag("Relativizer") != TurkishDependencyType::RELATIVIZER);
}
