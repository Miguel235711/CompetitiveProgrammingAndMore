#!/bin/bash
#c++,python,java
if [[ $2 = "C++" ]] ; then
    g++ -Wall -std=c++17 ./$2/main.cpp -o ./$2/a.out
    echo "C++ code compiled successfully!"
elif [[ $2 = "Java" ]] ; then
    javac ./Java/Main.java --release 8 -s ./Java  
    echo "Java code compiled successfully!"
elif [[ $2 != "Python" ]] ; then
    echo "Language Specifier is missing!!v:"
    exit 1
fi
#Java bug patch begin
if [[ $2 = "Java" ]] ; then
    cd Java
fi
#Java bug patch end
for ((i=0;i<=$1;i++))
do
    if [[ $2 = "C++" ]] ; then
        ./$2/a.out < $i.in > ./$2/r$i.out
    elif [[ $2 = "Java" ]] ; then
        java Main < ../$i.in > r$i.out
    elif [[ $2 = "Python" ]] ; then
        python3 ./$2/main.py < $i.in > ./$2/r$i.out
    fi
done
#Java bug patch begin
if [[ $2 = "Java" ]] ; then
    cd ..
fi
#Java bug patch end
for ((i=0;i<=$1;i++))
do
    echo "Case $i diff:"
    diff $i.out ./$2/r$i.out
done
exit 0