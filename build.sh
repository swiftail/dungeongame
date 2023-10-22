set -euxo pipefail

CMAKE_BUILD_PROGRAM="$(which ninja)"

mkdir -p cmake-build-release

cmake -G Ninja -S . -B cmake-build-release/ -D CMAKE_BUILD_TYPE=Release
cmake --build cmake-build-release/

realpath cmake-build-release/artifacts
ls -al cmake-build-release/