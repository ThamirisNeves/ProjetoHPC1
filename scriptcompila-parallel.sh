#!/bin/bash

#-------------------------------------------------------
# Script para compilar o programa laplace.c em paralelo
# com a flag -Ox mais rápida do programa em serial 
# com várias threads (1,2,3,4,6,8)
#
# Versão 0.1
# 
# Autor: eu
#
#-------------------------------------------------------

for i in $(seq 1 4) 6 8
  do
     gcc -fopenmp -O2 -fexpensive-optimizations -m64 -foptimize-register-move -funroll-loops -ffast-math -mavx laplaceparalelo.c -o laplaceparalelo.x
     mkdir paralelo-thread-$i
     mv laplaceparalelo.x paralelo-thread-$i
   done
