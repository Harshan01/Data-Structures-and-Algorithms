method=$1
if [ -z $method ]
then
	method=1
fi

gcc -c alloc.c "cycle${method}.c" cycle.c
gcc -o test_cycle alloc.o "cycle${method}.o" cycle.o -lm
./test_cycle 0
