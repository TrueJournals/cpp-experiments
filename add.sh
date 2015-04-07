#!/usr/bin/env bash
TAB=$'\t'

VALID="A-Za-z0-9_-"
if [[ "$1" =~ [^$VALID] ]]; then
    echo "Invalid character in directory name"
    exit
fi

mkdir "$1"

cat << EOF > "$1/Makefile"
SRCS := main.cpp
OBJS := \$(patsubst %.cpp,%.o,\$(SRCS))
CXXFLAGS = -std=c++11 -Wall

run: $1
${TAB}./$1

$1: \$(OBJS)
${TAB}\$(CXX) -pthread -o \$@ $<

%.o : %.cpp
${TAB}\$(CXX) -c \$(CXXFLAGS) -o \$@ $<

clean:
${TAB}rm -rf $1 \$(OBJS)
EOF

cat << EOF > "$1/main.cpp"
#include <iostream>

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    return 0;
}
EOF
