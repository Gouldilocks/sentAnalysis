cmake_minimum_required(VERSION 3.14)
project(S20-PA01-SentimentAnalysis)
set (EXE_NAME SentimentAnalyzer)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "IMDB Dataset.csv")
set (input02 "training_Data.csv")
set (input03 "testing_Data.csv")
set (input04 "outPut01.txt")
set (input05 "blackList.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04 input05)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp Stringy.h Stringy.cpp review.h review.cpp machine.h machine.cpp word.h word.cpp testerReview.h testerReview.cpp Test.cpp catch.hpp)

