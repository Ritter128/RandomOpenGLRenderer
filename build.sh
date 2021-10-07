#git commit -am "Standard build commit"
cmake -DGLFW_BUILD_DOCS=OFF -S . -B build
cd build
make

