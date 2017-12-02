#!/bin/bash

PROJ=TSP45

echo Running the tests in the background
#$PROJ tsp_example_3.txt &
$PROJ tsp_example_2.txt &
$PROJ tsp_example_1.txt &
$PROJ test-input-1.txt &
$PROJ test-input-2.txt &
$PROJ test-input-3.txt &
$PROJ test-input-4.txt &
$PROJ test-input-5.txt &
$PROJ test-input-6.txt &
$PROJ test-input-7.txt &