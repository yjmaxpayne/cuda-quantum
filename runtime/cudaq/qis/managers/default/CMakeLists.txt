# ============================================================================ #
# Copyright (c) 2022 - 2025 NVIDIA Corporation & Affiliates.                   #
# All rights reserved.                                                         #
#                                                                              #
# This source code and the accompanying materials are made available under     #
# the terms of the Apache License 2.0 which accompanies this distribution.     #
# ============================================================================ #

set(LIBRARY_NAME cudaq-em-default)

add_library(${LIBRARY_NAME} SHARED DefaultExecutionManager.cpp ../../execution_manager.cpp)
set_property(GLOBAL APPEND PROPERTY CUDAQ_RUNTIME_LIBS ${LIBRARY_NAME})
target_include_directories(${LIBRARY_NAME} 
    PUBLIC 
       $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/runtime>
       $<INSTALL_INTERFACE:include>
    PRIVATE .)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC cudaq-operator PRIVATE nvqir cudaq-common fmt::fmt-header-only LLVMSupport)

install(TARGETS ${LIBRARY_NAME} EXPORT cudaq-em-default-targets DESTINATION lib)

install(EXPORT cudaq-em-default-targets
        FILE CUDAQEmDefaultTargets.cmake
        NAMESPACE cudaq::
        DESTINATION lib/cmake/cudaq)
