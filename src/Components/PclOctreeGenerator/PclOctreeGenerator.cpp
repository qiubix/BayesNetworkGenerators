/*!
 * \file PclOctreeGenerator.cpp
 * \brief
 */

//#include <memory>
#include <string>
//#include <iostream>

#include "PclOctreeGenerator.hpp"

#include "Logger.hpp"

namespace Generators {
namespace Network {

PclOctreeGenerator::PclOctreeGenerator(const std::string & name) : Base::Component(name) {
  LOG(LTRACE)<<"Hello PclOctreeGenerator\n";
}

PclOctreeGenerator::~PclOctreeGenerator() {
  LOG(LTRACE)<<"Good bye PclOctreeGenerator\n";
}

void PclOctreeGenerator::prepareInterface() {
  LOG(LTRACE) << "PclOctreeGenerator::prepareInterface\n";
//  registerStream("in_cloud", &in_cloud);
  registerStream("out_octree", &out_octree);
  registerHandler("onNewCloud", boost::bind(&PclOctreeGenerator::onNewCloud, this));
//  addDependency("onNewCloud", &in_cloud);
}

//void PclOctreeGenerator::setPointCloud(pcl::PointCloud<PointXYZSIFT>::Ptr cloud) {
//  this -> cloud =  cloud;
//}

//pcl::PointCloud<PointXYZSIFT>::Ptr PclOctreeGenerator::getPointCloud() {
//  return cloud;
//}

void PclOctreeGenerator::buildOctree() {
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
  return true;
}

void PclOctreeGenerator::onNewCloud() {
}

}//: namespace Network
}//: namespace Generators
