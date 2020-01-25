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

gcc -c que.c multiq.c testMultiq.c
gcc -o testMultiq testMultiq.o multiq.o que.o
./testMultiq $inp_file $num_del 0
