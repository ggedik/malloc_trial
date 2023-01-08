#!/bin/bash

valgrind --tool=massif --time-unit=B ./example_malloc 
