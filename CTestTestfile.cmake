# CMake generated Testfile for 
# Source directory: C:/Users/memeo/Desktop/c++/Mygame
# Build directory: C:/Users/memeo/Desktop/c++/Mygame
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(Runs "C:/Users/memeo/Desktop/c++/Mygame/Debug/Mygame.exe" "25")
  set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;56;add_test;C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(Runs "C:/Users/memeo/Desktop/c++/Mygame/Release/Mygame.exe" "25")
  set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;56;add_test;C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(Runs "C:/Users/memeo/Desktop/c++/Mygame/MinSizeRel/Mygame.exe" "25")
  set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;56;add_test;C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(Runs "C:/Users/memeo/Desktop/c++/Mygame/RelWithDebInfo/Mygame.exe" "25")
  set_tests_properties(Runs PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;56;add_test;C:/Users/memeo/Desktop/c++/Mygame/CMakeLists.txt;0;")
else()
  add_test(Runs NOT_AVAILABLE)
endif()
subdirs("UltraEgine")
