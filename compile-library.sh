cd lib/obj
gcc -c ../../src/*.c
cd ..
ar -rc libpowerconsole.a obj/*.o
ranlib libpowerconsole.a
ar -t libpowerconsole.a
nm libpowerconsole.a