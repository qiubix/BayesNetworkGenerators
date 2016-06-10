/*!
 * \file PclOctreeGenerator.cpp
 * \brief
 */

//#include <memory>
#include <string>
//#include <iostream>
#include <pcl/octree/octree.h>
#include <pcl/octree/octree_impl.h>

#include "PclOctreeGenerator.hpp"

#include "Logger.hpp"

namespace Generators {
namespace Network {

PclOctreeGenerator::PclOctreeGenerator(const std::string & name) : Base::Component(name) {
  LOG(LTRACE)<<"Hello PclOctreeGenerator\n";
  octree = NULL;
}

PclOctreeGenerator::~PclOctreeGenerator() {
  LOG(LTRACE)<<"Good bye PclOctreeGenerator\n";
}

void PclOctreeGenerator::prepareInterface() {
  LOG(LTRACE) << "PclOctreeGenerator::prepareInterface\n";
  registerStream("out_octree", &out_octree);
}

//void PclOctreeGenerator::setPointCloud(pcl::PointCloud<PointXYZSIFT>::Ptr cloud) {
//  this -> cloud =  cloud;
//}

OctreeWithSIFT* PclOctreeGenerator::getOctree() {
  return octree;
}

//pcl::PointCloud<PointXYZSIFT>::Ptr PclOctreeGenerator::getPointCloud() {
//  return cloud;
//}

void PclOctreeGenerator::buildOctree() {
  double voxelSize = 0.01f;
  octree = new OctreeWithSIFT(voxelSize);
}

bool PclOctreeGenerator::onInit() {
  LOG(LTRACE) << "PclOctreeGenerator::initialize\n";
  return true;
}

bool PclOctreeGenerator::onFinish() {
  LOG(LTRACE) << "PclOctreeGenerator::finish\n";
  return true;
}

bool PclOctreeGenerator::onStop() {
  LOG(LTRACE) << "PclOctreeGenerator::onStop\n";
  return true;
}

bool PclOctreeGenerator::onStart() {
  LOG(LTRACE) << "PclOctreeGenerator::onStart\n";
  buildOctree();
  return true;
}

}//: namespace Network
}//: namespace Generators
