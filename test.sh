#!/bin/bash

for f in $2/*.in
do
	echo $f
	./$1 < $f > my.out 2> my.err
	diff my.out ${f%in}out || break
	diff my.err ${f%in}err || break
done