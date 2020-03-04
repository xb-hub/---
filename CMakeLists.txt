cmake_minimum_required(VERSION 2.8)
project( number_detector )

# 添加OpenCV库
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

#生成可执行文件
add_executable( data_demo demo/data_demo.cpp src/data_process.cpp)
target_link_libraries( data_demo ${OpenCV_LIBS} )

add_executable(creat_demo demo/creat_demo.cpp src/creat_template.cpp)
target_link_libraries( creat_demo ${OpenCV_LIBS} )

add_executable(detector_demo demo/detector_demo.cpp src/number_detector.cpp)
target_link_libraries( detector_demo ${OpenCV_LIBS} )