#!/bin/bash

make

./memory_overcommit 32768 read
./memory_overcommit 32768 write
