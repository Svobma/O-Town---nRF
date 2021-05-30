# Install script for directory: C:/Users/mafio/ncs/v1.5.0/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Zephyr-Kernel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/mafio/ncs/v1.5.0/toolchain/opt/bin/arm-none-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/arch/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/lib/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/soc/arm/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/boards/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/subsys/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/drivers/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/nrf/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/mcuboot/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/nrfxlib/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/tfm/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/cddl-gen/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/cmsis/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/canopennode/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/civetweb/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/fatfs/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/hal_nordic/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/st/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/libmetal/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/lvgl/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/mbedtls/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/mcumgr/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/open-amp/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/loramac-node/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/openthread/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/segger/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/tinycbor/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/tinycrypt/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/littlefs/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/mipi-sys-t/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/nrf_hw_models/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/modules/connectedhomeip/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/kernel/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/cmake/flash/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/cmake/usage/cmake_install.cmake")
  include("C:/Users/mafio/ncs/v1.5.0/zephyr/samples/bluetooth/peripheral_Otown/build/zephyr/cmake/reports/cmake_install.cmake")

endif()

