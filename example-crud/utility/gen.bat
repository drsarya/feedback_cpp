@echo off

rmdir /s /q tmp 2>nul
mkdir tmp
cd tmp


git clone --depth=1 https://github.com/oatpp/oatpp
cd oatpp
mkdir build
cd build
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
cmake --build .   --target install
cd ..
cd ..


git clone --depth=1 https://github.com/oatpp/oatpp-swagger
cd oatpp-swagger
mkdir build
cd build
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
cmake --build .   --target install
cd ..
cd ..


git clone --depth=1 https://github.com/oatpp/oatpp-postgresql
cd oatpp-postgresql
mkdir build
cd build
cmake -DOATPP_DISABLE_ENV_OBJECT_COUNTERS=ON -DCMAKE_BUILD_TYPE=$BUILD_TYPE -DOATPP_BUILD_TESTS=OFF ..
cmake --build .   --target install
cd ..
cd ..


