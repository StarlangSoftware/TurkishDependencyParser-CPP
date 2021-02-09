//
// Created by Olcay Taner YILDIZ on 9.02.2021.
//

#include "catch.hpp"
#include "../Universal/UniversalDependencyRelation.h"

TEST_CASE("UniversalDependencyRelationTest-testDependencyPosType") {
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyPosType("adj") != UniversalDependencyPosType::ADJ);
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyPosType("intj") != UniversalDependencyPosType::INTJ);
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyPosType("Det") != UniversalDependencyPosType::DET);
}

TEST_CASE("UniversalDependencyRelationTest-testDependencyType") {
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyTag("acl") != UniversalDependencyType::ACL);
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyTag("iobj") != UniversalDependencyType::IOBJ);
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyTag("Iobj") != UniversalDependencyType::IOBJ);
    REQUIRE_FALSE(UniversalDependencyRelation::getDependencyTag("fixed") != UniversalDependencyType::FIXED);
}
