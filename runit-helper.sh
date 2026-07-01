#!/bin/bash
set -e

function create_supervise_dir {

    echo $SUPERVISE_DIR

    if [ ! -d "$SUPERVISE_DIR" ]; then
        mkdir -p "$SUPERVISE_DIR"
        chmod -v 700 "$SUPERVISE_DIR"
    fi


    for i in control ok; do 
        if [ ! -p "$SUPERVISE_DIR/$i" ]; then
            mkfifo "$SUPERVISE_DIR/$i";
            echo "$SUPERVISE_DIR/$i"
            chmod -v 600 "$SUPERVISE_DIR/$i"
        fi;
    done

    for i in lock pid stat status; do
        if [ ! -f "$SUPERVISE_DIR/$i" ]; then
            touch "$SUPERVISE_DIR/$i";
        fi;
    done

    chmod -v 600 "$SUPERVISE_DIR/lock"

}

function create_service_dir {

    mkdir -p "$SERVICE_DIR"

    echo "$SERVICE_DIR"
    
    cp -v $1 "$SERVICE_DIR/run"

    chmod -v +x "$SERVICE_DIR/run"

    ln -sv "$SUPERVISE_DIR" "$SERVICE_DIR/supervise"

}

if [ $# -eq 2 ]; then

    
    SUPERVISE_DIR=/run/runit/supervise.$1
    
    SERVICE_DIR=/etc/sv/$1

    create_supervise_dir $1

    create_service_dir $2

else 
    echo "Argumento invalido"
fi


