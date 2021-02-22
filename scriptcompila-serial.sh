#!/bin/bash

#----------------------------------------------------
# Script para compilar o programa laplace.c em serial
# 
# Versão 0.1
# 
# Autor: eu
#
#----------------------------------------------------

for i in $(seq 0 3)
  do
     gcc -pg -g -O$i -ffast-math -mavx laplace.c -o laplace.x
     rm -r serial-$i
     mkdir serial-$i
     mv laplace.x serial-$i
   done
