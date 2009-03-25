#!/usr/bin/perl

use strict;

open(FP, '>>test');

#print FP "hello\n";

while(my $line = <FP>) {
    print $line;
}

print FP "foobar";
