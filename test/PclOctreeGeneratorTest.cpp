#include <gmock/gmock.h>
#include <Components/PclOctreeGenerator/PclOctreeGenerator.hpp>

using Generators::Network::PclOctreeGenerator;
using namespace testing;

class PclOctreeGeneratorTest : public Test {
public:
  PclOctreeGenerator generator;
};

TEST_F(PclOctreeGeneratorTest, shouldCreatePclOctreeGeneratorComponent) {
  ASSERT_THAT(generator.name(), Eq("PclOctreeGenerator"));
}
