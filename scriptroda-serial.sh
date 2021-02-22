#!/bin/bash

#----------------------------------------------------
# Script para rodar o programa laplace.x em serial em 
# diferentes pastas gerando um arquivo time para cada 
#
# Versão 0.1
# 
# Autor: eu
#
#----------------------------------------------------

for i in $(seq 0 3)
  do
     cd serial-$i
     ./laplace.x
     cd ..
   done

