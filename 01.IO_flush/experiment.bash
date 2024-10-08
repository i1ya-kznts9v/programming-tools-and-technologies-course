#!/bin/bash

make

for ((i = 0; i < 8; i++)); do
  args=""

  if ((i & 4)); then
    args="${args}-r "
  fi

  if ((i & 2)); then
    args="${args}-n "
  fi

  if ((i & 1)); then
    args="${args}-f "
  fi

  echo "./experiment $args"
  ./experiment "$args"

  if ((i & 4)); then
    cat result.txt
    mv result.txt "result ${args}.txt"
  fi

  echo
  echo "------------------------"
done
