#!/bin/bash

#-------------------------------------------------------------
# Script para rodar o programa laplaceparalelo.x em serial em 
# diferentes pastas gerando um arquivo time para cada 
# e rodando usando threads diferentes (1 2 3 4 6 8)
#
# Versão 0.1
# 
# Autor: eu
#
#-------------------------------------------------------------

for i in $(seq 1 4) 6 8
  do
     cd paralelo-thread-$i
     export OMP_NUM_THREADS=$i
     ./laplaceparalelo.x
     cd ..
   done

