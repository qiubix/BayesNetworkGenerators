/*!
 * \file PclOctreeGenerator.hpp
 * \brief Component generating pcl::octree
 */

#pragma once
#ifndef PCL_OCTREE_GENERATOR_HPP_
#define PCL_OCTREE_GENERATOR_HPP_

//#define CV_NO_BACKWARD_COMPATIBILITY


#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
//#include "Property.hpp"

#include "Types/PointXYZSIFT.hpp"
//#include "Types/Octree.hpp"

namespace Generators {
namespace Network {

/*!
 * \class PclOctreeGenerator
 * \brief Component for building octree from point cloud
 * \author Karol Katerżawa
 */
class PclOctreeGenerator: public Base::Component
{
public:
  PclOctreeGenerator(const std::string & name = "PclOctreeGenerator");
  virtual ~PclOctreeGenerator();

  void prepareInterface();
//  void setPointCloud(pcl::PointCloud<PointXYZSIFT>::Ptr cloud);
//  pcl::PointCloud<PointXYZSIFT>::Ptr getPointCloud();

  void buildOctree();
//  Octree getOctree();

protected:

  /// Input data stream
//  Base::DataStreamIn< pcl::PointCloud<PointXYZSIFT>::Ptr > in_cloud;

  /// Output data stream
  Base::DataStreamOut< pcl::PointCloud<PointXYZSIFT>::Ptr > out_octree;

  bool onInit();
  bool onFinish();
  bool onStart();
  bool onStop();

  /*!
   * Event handler function.
   */
  void onNewCloud();

private:
  pcl::PointCloud<PointXYZSIFT>::Ptr cloud;
//  Octree* octree;
};

}//: namespace Network
}//: namespace Generators


/*
 * Register processor component.
 */
REGISTER_COMPONENT("PclOctreeGenerator", Generators::Network::PclOctreeGenerator)

#endif /* PCL_OCTREE_GENERATOR_HPP_ */

