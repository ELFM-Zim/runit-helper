#!/bin/bash


if [ $# -eq 1 ]; then

    #SUPERVISE_ROOT=/run/runit

    #SUPERVISE_DIR=/run/runit/supervise.$1

    SUPERVISE_DIR=$(pwd)/teste
    
    echo $SUPERVISE_DIR

    if [ ! -d "$SUPERVISE_DIR" ]; then
        mkdir "$SUPERVISE_DIR"
        chmod 700 "$SUPERVISE_DIR"
    fi


    for i in control ok; do 
        if [ ! -p "$SUPERVISE_DIR/$i" ]; then
            mkfifo "$SUPERVISE_DIR/$i";
            chmod 600 "$SUPERVISE_DIR/$i"
        fi;
    done

    for i in lock pid stat status; do
        if [ ! -f "$SUPERVISE_DIR/$i" ]; then
            touch "$SUPERVISE_DIR/$i";
        fi;
    done

    chmod 600 "$SUPERVISE_DIR/lock"



else 
    echo "Argumento invalido"
fi


