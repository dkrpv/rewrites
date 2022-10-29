cmake_minimum_required (VERSION 2.8.11)
project (KNN)
add_subdirectory(matplotplusplus)

add_executable(KNN main.cpp)
target_link_libraries(KNN PUBLIC matplot)
