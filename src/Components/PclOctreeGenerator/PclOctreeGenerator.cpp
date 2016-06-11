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

Octree* PclOctreeGenerator::getOctree() {
  return octree;
}

//pcl::PointCloud<PointXYZSIFT>::Ptr PclOctreeGenerator::getPointCloud() {
//  return cloud;
//}

void PclOctreeGenerator::buildOctree() {
//  double voxelSize = 0.01f;
//  octree = new OctreeWithSIFT(voxelSize);

  pcl::PointCloud<PointXYZSIFT>::Ptr cloud = getPointCloud();
  octree = new Octree(cloud);
  octree->init();

//  octree -> setInputCloud(cloud);
//  octree -> defineBoundingBox();
//  octree -> addPointsFromInputCloud();
}

pcl::PointCloud<PointXYZSIFT>::Ptr PclOctreeGenerator::getPointCloud() const {
  pcl::PointCloud<PointXYZSIFT>::Ptr cloud(new pcl::PointCloud<PointXYZSIFT>);
  cloud->width = 8;
  cloud->height = 1;
  cloud->points.resize(cloud->width * cloud->height);

  for (int j = 0; j < cloud->width; ++j) {
    cloud->points[j].pointId = j;
    cloud->points[j].x = (float) (j + 0.1);
    cloud->points[j].y = (float) (j + 0.2);
    cloud->points[j].z = (float) (j + 0.3);
    for(int i=0; i<128; i++) {
      cloud->points[j].descriptor[i] = i;
    }
  }

  return cloud;
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
