#include <gmock/gmock.h>
#include <Components/BayesNetworkSink/BayesNetworkSink.hpp>
#include <Types/BayesNetwork.hpp>

using Sinks::Network::BayesNetworkSink;
using Processors::Network::BayesNetwork;
using namespace testing;

class BayesNetworkSinkTest : public Test {
public:
  BayesNetworkSink sink;
};

TEST_F(BayesNetworkSinkTest, shouldCreateBayesNetworkSinkComponent) {
  ASSERT_THAT(sink.name(), Eq("BayesNetworkSink"));
}

TEST_F(BayesNetworkSinkTest, shouldInitializeStreams) {
  sink.prepareInterface();

  ASSERT_THAT(sink.getStream("in_network"), NotNull());
}

TEST_F(BayesNetworkSinkTest, shouldInitializeHandlers) {
  sink.prepareInterface();

  ASSERT_THAT(sink.getHandler("onNewNetwork"), NotNull());
}

TEST_F(BayesNetworkSinkTest, shouldDisplayNetworkOnNewNetwork) {
//  cv::Mat img;
//  img = cv::Mat::ones(3, 4, CV_32S);
//  sink.setNetwork(img);
  BayesNetwork network;
  network.addVoxelNode(0);
  network.addVoxelNode(1);
  network.addVoxelNode(2);
  network.addFeatureNode(0);
  network.addFeatureNode(1);
  network.connectNodes("F_0", "V_1");
  network.connectNodes("F_1", "V_2");
  network.connectNodes("V_1", "V_0");
  network.connectNodes("V_2", "V_0");
  sink.setNetwork(&network);

  internal::CaptureStdout();
  sink.display();

  string output = internal::GetCapturedStdout();
  ASSERT_THAT(output, HasSubstr("Number of feature nodes: 2"));
//  ASSERT_THAT(output, Eq("[1, 1, 1, 1;\n  1, 1, 1, 1;\n  1, 1, 1, 1]\n"));
}
