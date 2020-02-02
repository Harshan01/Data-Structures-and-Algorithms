method=$1
if [ -z $method ]
then
	method=1
fi

gcc -pg alloc.c "cycle${method}.c" cycle.c -o test_cycle_gprof -lm
./test_cycle_gprof 1
gprof test_cycle_gprof gmon.out > prof_output
cat prof_output
