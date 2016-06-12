/*!
 * \file BayesNetworkSink.hpp
 * \brief
 */

#pragma once
#ifndef BAYES_NETWORK_SINK_HPP_
#define BAYES_NETWORK_SINK_HPP_

//#define CV_NO_BACKWARD_COMPATIBILITY


#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"

namespace Processors {
namespace Network {

class BayesNetwork;

}
}

namespace Sinks {
namespace Network {

/*!
 * \class CvMatSink
 * \brief
 * \author Karol Katerżawa
 */
class BayesNetworkSink : public Base::Component
{
public:
  BayesNetworkSink(const std::string & name = "BayesNetworkSink");
  virtual ~BayesNetworkSink();

  void prepareInterface();

//  const cv::Mat &getImg() const {
//    return img;
//  }

//  void setImg(const cv::Mat & img) {
//    this -> img = img;
//  }

  void onNewNetwork();
  void display();

protected:

  /// Input data stream
  Base::DataStreamIn<Processors::Network::BayesNetwork> in_network;

  bool onInit();
  bool onFinish();
  bool onStart();
  bool onStop();

private:
};

}//: namespace Network
}//: namespace Sinks


/*
 * Register processor component.
 */
REGISTER_COMPONENT("BayesNetworkSink", Sinks::Network::BayesNetworkSink)

#endif /* BAYES_NETWORK_SINK_HPP_ */

