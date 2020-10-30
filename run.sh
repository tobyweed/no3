
for (( n = 3; n < 13; n+=2 )); do
	declare -i r=$n+1
	echo "$n"_"$r"
	mkdir ./results/"$n"_"$r"
	./nothree/sat-nothree-allodd "$n" "$n" "$r" | ./sat-to-dimacs > ./results/"$n"_"$r"/encoding.cnf
	./miniSAT-all/bc_minisat_all ./results/"$n"_"$r"/encoding.cnf ./results/"$n"_"$r"/result.cnf
	touch ./results/"$n"_"$r"/full.txt
	echo "key: " >> ./results/"$n"_"$r"/full.txt
	cat ./results/"$n"_"$r"/encoding.cnf >> ./results/"$n"_"$r"/full.txt
	echo "\nresultdimacs: " >> ./results/"$n"_"$r"/full.txt
	cat ./results/"$n"_"$r"/result.cnf >> ./results/"$n"_"$r"/full.txt
	cat ./results/"$n"_"$r"/full.txt | python3 translate_dimacs.py | python3 read_solns.py "$n" "$r" > ./results/"$n"_"$r"/final.txt
done


# rm 556*
# ./nothree/sat-nothree-allodd 5 5 6 | ./sat-to-dimacs > 556dimacs.txt
# ./miniSAT-all/bc_minisat_all 556dimacs.txt 556result.txt
# touch 556final.txt
# echo "key: " >> 556final.txt
# cat 556dimacs.txt >> 556final.txt
# echo "\nresultdimacs: " >> 556final.txt
# cat 556result.txt >> 556final.txt
# cat 556final.txt | python3 translate_dimacs.py | python3 read_solns.py 5 6 
