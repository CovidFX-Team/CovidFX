# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CovidFX_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CovidFX_autogen.dir\\ParseCache.txt"
  "CovidFX_autogen"
  )
endif()
