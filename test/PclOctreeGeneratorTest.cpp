#include <gmock/gmock.h>
#include <Components/PclOctreeGenerator/PclOctreeGenerator.hpp>
#include <vector>

using Generators::Network::PclOctreeGenerator;
using namespace testing;

class PclOctreeGeneratorTest : public Test {
public:
  PclOctreeGenerator generator;
};

MATCHER_P(hasSpecificNumberOfPoints, numberOfPoints, "") {
  if ( arg -> getInputCloud() == NULL)
    return false;
  else if (arg -> getInputCloud() -> size() != numberOfPoints)
    return false;
  else if (arg -> getNumberOfPoints() != numberOfPoints)
    return false;
  return true;
}

MATCHER(hasEveryPointWithUniqueIndex, "") {
  for (int i=0; i < arg -> size() - 1; i++) {
    int firstPointId = arg -> points[i].pointId;

    for (int j = i + 1; j < arg -> size(); ++j) {
      int secondPointId = arg -> points[j].pointId;
      if (firstPointId == secondPointId)
        return false;
    }

  }
  return true;
}

TEST_F(PclOctreeGeneratorTest, shouldCreatePclOctreeGeneratorComponent) {
  ASSERT_THAT(generator.name(), Eq("PclOctreeGenerator"));
}

TEST_F(PclOctreeGeneratorTest, shouldInitializeStreams) {
  generator.prepareInterface();

  ASSERT_THAT(generator.getStream("out_octree"), NotNull());
}

TEST_F(PclOctreeGeneratorTest, shouldCreatePclOctreeOnStart) {
  ASSERT_THAT(generator.getOctree(), IsNull());

  generator.onStart();

  ASSERT_THAT(generator.getOctree(), NotNull());
}

TEST_F(PclOctreeGeneratorTest, shouldCreateOctreeWith8Points) {
  generator.buildOctree();

//  ASSERT_THAT(generator.getOctree()->getInputCloud(), NotNull());
//  size_t pointCloudSize = generator.getOctree()->getInputCloud()->size();
//  ASSERT_THAT(pointCloudSize, Eq(8));
  ASSERT_THAT(generator.getOctree(), hasSpecificNumberOfPoints(8));
}

TEST_F(PclOctreeGeneratorTest, shouldCreateOctreeWithUniqueIndices) {
  generator.buildOctree();

  ASSERT_THAT(generator.getOctree()->getInputCloud(), hasEveryPointWithUniqueIndex());
}
