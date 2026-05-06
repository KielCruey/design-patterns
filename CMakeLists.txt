cmake_minimum_required(VERSION 4.3 FATAL_ERROR)

project(design-patterns 
    VERSION 1.0
    DESCRIPTION "self learning project to understand design patterns" 
    LANGUAGES CXX)

# directories for all design patterns
add_subdirectory(behavioral)
add_subdirectory(creational)
add_subdirectory(structural)