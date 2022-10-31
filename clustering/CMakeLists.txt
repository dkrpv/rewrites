cmake_minimum_required (VERSION 2.8.11)
project (Clustering)
add_subdirectory(matplotplusplus)

add_executable(Clustering main.cpp)
target_link_libraries(Clustering PUBLIC matplot)
