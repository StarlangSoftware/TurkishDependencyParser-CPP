//
// Created by Olcay Taner YILDIZ on 9.02.2021.
//

#include "catch.hpp"
#include "../Stanford/StanfordDependencyRelation.h"

TEST_CASE("StanfordDependencyRelationTest-testDependencyType") {
    REQUIRE_FALSE(StanfordDependencyRelation::getDependencyTag("ACOMP") != StanfordDependencyType::ACOMP);
    REQUIRE_FALSE(StanfordDependencyRelation::getDependencyTag("DISCOURSE") != StanfordDependencyType::DISCOURSE);
    REQUIRE_FALSE(StanfordDependencyRelation::getDependencyTag("Iobj") != StanfordDependencyType::IOBJ);
    REQUIRE_FALSE(StanfordDependencyRelation::getDependencyTag("IOBJ") != StanfordDependencyType::IOBJ);
}
