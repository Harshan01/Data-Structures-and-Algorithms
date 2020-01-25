inp_file=$1
if [ -z $inp_file ]
then
	inp_file=input10.txt
fi

num_del=$2
if [ -z $num_del ]
then
	num_del=9
fi

gcc -pg testMultiq.c multiq.c que.c -o testMultiq_gprof
./testMultiq_gprof $inp_file $num_del 1
gprof testMultiq_gprof gmon.out > prof_output
cat prof_output
