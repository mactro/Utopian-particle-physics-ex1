cmake_minimum_required(VERSION 3.5)
project(MadAnalysis5job)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        $ENV{MA5_BASE}/tools
        ./)

message(STATUS $ENV{MA5_BASE}/tools/SampleAnalyzer/Lib)
message(STATUS $ENV{MA5_BASE}/tools/SampleAnalyzer/ExternalSymLink/Lib)

link_directories(
        $ENV{MA5_BASE}/tools/SampleAnalyzer/Lib
        $ENV{MA5_BASE}/tools/SampleAnalyzer/ExternalSymLink/Lib
)

add_executable(MadAnalysis5job
        Main/main.cpp
        SampleAnalyzer/User/Analyzer/analysisList.h
        SampleAnalyzer/User/Analyzer/test_analysis.cpp
        SampleAnalyzer/User/Analyzer/test_analysis.h
        )

target_link_libraries(MadAnalysis5job
        process_for_ma5
        commons_for_ma5
        )
