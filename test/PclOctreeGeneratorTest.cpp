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

TEST_F(PclOctreeGeneratorTest, shouldInitializeStreams) {
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_octree"), NotNull());
}

TEST_F(PclOctreeGeneratorTest, shouldCreatePclOctreeOnStart) {
  ASSERT_THAT(generator.getOctree(), IsNull());
}