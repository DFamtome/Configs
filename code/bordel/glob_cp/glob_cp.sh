#!/bin/sh

l="$@"

mv *.[!"$l"] trash
