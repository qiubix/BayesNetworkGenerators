#include <gmock/gmock.h>
#include <Components/BayesNetworkSink/BayesNetworkSink.hpp>

using Sinks::Network::BayesNetworkSink;
using namespace testing;

class BayesNetworkSinkTest : public Test {
public:
  BayesNetworkSink sink;
};

TEST_F(BayesNetworkSinkTest, shouldCreateBayesNetworkSinkComponent) {
  ASSERT_THAT(sink.name(), Eq("BayesNetworkSink"));
}
