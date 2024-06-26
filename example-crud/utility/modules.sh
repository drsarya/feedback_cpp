#!/bin/sh

BUILD_TYPE=$1

if [ -z "$BUILD_TYPE" ]; then
    BUILD_TYPE="Debug"
fi

rm -rf tmp

mkdir tmp
cd tmp

##########################################################
## install oatpp module

function install_module () {

BUILD_TYPE=$1
MODULE_NAME=$2
NPROC=$(nproc)

if [ -z "$NPROC" ]; then
    NPROC=1
fi

echo "\n\nINSTALLING MODULE '$MODULE_NAME' ($BUILD_TYPE) using $NPROC threads ...\n\n"

git clone --depth=1 https://github.com/oatpp/$MODULE_NAME

cd $MODULE_NAME
mkdir build
cd build

############################################################################
############################################################################
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
make install -j $NPROC

cd ../../

}

function install_module2 () {

BUILD_TYPE=$1
MODULE_NAME=$2
NPROC=$(nproc)

if [ -z "$NPROC" ]; then
    NPROC=1
fi

echo "\n\nINSTALLING MODULE '$MODULE_NAME' ($BUILD_TYPE) using $NPROC threads ...\n\n"

git clone --depth=1 https://github.com/oatpp/$MODULE_NAME
cd $MODULE_NAME
git fetch --tags
git checkout 1.3.0-latest --
mkdir build
cd build

############################################################################
############################################################################
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
make install -j $NPROC
#
#cd ../../

}

##########################################################

install_module2 $BUILD_TYPE oatpp RELEASE
install_module $BUILD_TYPE oatpp-swagger RELEASE
install_module $BUILD_TYPE oatpp-postgresql RELEASE

cd ../
rm -rf tmp