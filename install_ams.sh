#!/usr/bin/sh

INSTALL_DIR=`pwd`/build/_deps/systemc-ams/

if [ -d "$INSTALL_DIR" ]; then
    echo "Skip building SystemC-AMS"
else
    mkdir -p $INSTALL_DIR
    SYSTEMC_INCLUDES=`pwd`/build/_deps/systemc-src/src/
    CXX_STANDARD=17
    AMS_VERSION="systemc-ams-2.3.4"

    mkdir tmp
    cd tmp
    wget https://www.coseda-tech.com/files/Files/Proof-of-Concepts/$AMS_VERSION.tar.gz
    tar xfv $AMS_VERSION.tar.gz
    cd $AMS_VERSION

    mkdir build
    cd build 
    cmake .. -D CMAKE_CXX_STANDARD=$CXX_STANDARD -D CMAKE_INSTALL_PREFIX=$INSTALL_DIR -D CMAKE_CXX_FLAGS=-I\ $SYSTEMC_INCLUDES
    make -j
    make install
    cd ..
    cd ..
    cd ..
    rm -rf tmp
fi