#!bin/bash
if [ $# -eq 0 ]
then
    echo 'few argument'
elif [ $1 -lt 18 ]
then
    echo 'minority'
elif [ $1 -lt 60 ]
then
    echo 'adult'
else
    echo 'old'
fi