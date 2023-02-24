TEST_DIR=test/
SEQ=$(seq 5 5 $1)
make -C ${3}
rm -rf ${TEST_DIR}
mkdir ${TEST_DIR}
for j in ${SEQ}
do
	touch ${TEST_DIR}/test_push_swap${j}.txt
	SEQ2=$(seq 1 1 $2)
	for i in ${SEQ2}
	do
		ARG=$(python3 gen/gen.py ${j})
		 ${3}/push_swap ${ARG} | wc -l >> ${TEST_DIR}/test_push_swap${j}.txt
	done
	perc=$((j * 100 / $1))
	printf  'Writing: %i%%\033[K\r' "${perc}"
done
make fclean -C ${3}
printf 'Finish writing\n'
python3 plot.py $1
