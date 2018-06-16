#!/bin/bash

set -e
PREFIX=/usr/local
headers=`ls *.h`

for h in $headers; do
	cp $h "$PREFIX/include"
done
echo "installed headers to $PREFIX/include"

cp core.c "$PREFIX/src"
echo "installed source to $PREFIX/src"

cp checkout-core "$PREFIX/bin"
echo "use 'checkout-core' script to add libcore to your project"

