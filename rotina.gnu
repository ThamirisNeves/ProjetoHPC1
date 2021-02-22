set pm3d map interpolate 0,0
set title "Mapa de Calor (EDP)"
set xlabel "x"
set ylabel "y"
set cblabel "V(x,y)"
splot "dados.dat" matrix
set terminal pngcairo size 1024,768
set output "mapadecalor-serial.png"
rep 
set output
