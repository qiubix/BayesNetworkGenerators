#!/usr/bin/env sh

mkdir -p ~/src/DCL
if [ ! -d ~/src/DCL/BayesNetworkTypes ]; then
  git clone https://github.com/qiubix/BayesNetworkTypes.git ~/src/DCL/BayesNetworkTypes
  cd ~/src/DCL/BayesNetworkTypes && mkdir build && cd build
  cmake .. && make -j3 && make install
fi
