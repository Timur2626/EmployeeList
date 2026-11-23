# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EmployeesList_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EmployeesList_autogen.dir\\ParseCache.txt"
  "EmployeesList_autogen"
  )
endif()
