/*!
 * \file BayesNetworkSink.cpp
 * \brief
 */

//#include <memory>
//#include <string>
//#include <iostream>
//#include <opencv2/highgui/highgui.hpp>

#include "BayesNetworkSink.hpp"

#include "Logger.hpp"
#include <Types/BayesNetwork.hpp>

namespace Sinks {
namespace Network {

BayesNetworkSink::BayesNetworkSink(const std::string & name) :
    Base::Component(name)
{
  LOG(LTRACE)<<"Hello BayesNetworkSink\n";
}

BayesNetworkSink::~BayesNetworkSink() {
  LOG(LTRACE)<<"Good bye BayesNetworkSink\n";
}

void BayesNetworkSink::prepareInterface() {
  LOG(LTRACE) << "BayesNetworkSink::prepareInterface\n";
  registerStream("in_network", &in_network);
  registerHandler("onNewNetwork", boost::bind(&BayesNetworkSink::onNewNetwork, this));
  addDependency("onNewNetwork", &in_network);
}

bool BayesNetworkSink::onInit() {
  LOG(LTRACE) << "BayesNetworkSink::initialize\n";
  return true;
}

bool BayesNetworkSink::onFinish() {
  LOG(LTRACE) << "BayesNetworkSink::finish\n";
  return true;
}

bool BayesNetworkSink::onStop() {
  LOG(LTRACE) << "BayesNetworkSink::onStop\n";
  return true;
}

bool BayesNetworkSink::onStart() {
  LOG(LTRACE) << "BayesNetworkSink::onStart\n";
  return true;
}

void BayesNetworkSink::onNewNetwork() {

}

//void BayesNetworkSink::onNewMat() {
//  img = in_img.read();
//  display();
//}

//void BayesNetworkSink::display() {
//  cout << img << endl;
//  LOG(LWARNING) << "END OF SEQUENCE\n";
//}

}//: namespace Network
}//: namespace Sinks
