cmake_minimum_required(VERSION 4.4)

project(CMS)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Release)

add_executable(
  app
  src/main.cpp
  src/BusinessContact.cpp
  src/Contact.cpp
  src/ContactManager.cpp
  src/PersonalContact.cpp
  src/utils.cpp
)
