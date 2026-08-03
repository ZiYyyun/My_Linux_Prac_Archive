#!bin/bash

for fruit in apple bnana peach
do
    echo "$fruit"
done

##########################

for arg in "$@"
do
    echo "$arg"
done