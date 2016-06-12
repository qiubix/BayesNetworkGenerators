/*!
 * \file BayesNetworkSink.hpp
 * \brief
 */

#ifndef BAYES_NETWORK_SINK_HPP_
#define BAYES_NETWORK_SINK_HPP_

//#define CV_NO_BACKWARD_COMPATIBILITY


#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"

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

//  void onNewMat();
  void display();

protected:

  /// Input data stream
//  Base::DataStreamIn<cv::Mat> in_img;

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

