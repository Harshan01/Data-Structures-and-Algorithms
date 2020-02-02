file_name="logs.txt"

touch $file_name

echo "LOGS OF TEST CYCLIC METHODS:-\n\n" > $file_name
echo "-----------------------------------------------------\n\n" >> $file_name

echo "USING GPROF = NO\n" >> $file_name
echo "CYCLE TEST ALGORITHM = Hare-and-Tortoise Alg\n" >> $file_name
(sh execute_seq.sh 1) >> $file_name
echo "-----------------------------------------------------\n\n" >> $file_name

echo "USING GPROF = NO\n" >> $file_name
echo "CYCLE TEST ALGORITHM = Link-Reversal Alg\n" >> $file_name
(sh execute_seq.sh 2) >> $file_name
echo "-----------------------------------------------------\n\n" >> $file_name

echo "USING GPROF = YES\n" >> $file_name
echo "CYCLE TEST ALGORITHM = Hare-and-Tortoise Alg\n" >> $file_name
(sh execute_seq_gprof.sh 1) >> $file_name
echo "-----------------------------------------------------\n\n" >> $file_name

echo "USING GPROF = YES\n" >> $file_name
echo "CYCLE TEST ALGORITHM = Link-Reversal Alg\n" >> $file_name
(sh execute_seq_gprof.sh 2) >> $file_name
echo "-----------------------------------------------------\n\n" >> $file_name
