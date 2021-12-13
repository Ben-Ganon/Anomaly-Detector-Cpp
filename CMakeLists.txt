cmake_minimum_required(VERSION 3.20)
project(Ex1Task2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
add_executable(Ex1Task2 MainTrain.cpp Commands/sendCSV.cpp Commands/receiveCSV.cpp Detetcors/HybridAnomalyDetector.cpp Detetcors/anomaly_detection_util.cpp Detetcors/SimpleAnomalyDetector.cpp Detetcors/timeseries.cpp minCircle.cpp)
