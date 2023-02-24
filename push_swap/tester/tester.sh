TEST_DIR=test/
SEQ=$(seq 1 1 $1)
make -C ${3}
make bonus -C ${3}
for j in ${SEQ}
do
	printf 'test %s\n' "${j}"
	ARG=$(python3 gen/gen.py ${2})
	${3}/push_swap ${ARG} | wc -l
	${3}/push_swap ${ARG} | ./checker_Mac ${ARG}
	${3}/push_swap ${ARG} | ${3}/checker ${ARG}
done
make fclean -C ${3}
