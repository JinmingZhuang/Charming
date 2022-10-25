# export LD_LIBRARY_PATH=/mnt:/tmp:$LD_LIBRARY_PATH
# export PATH=$PATH:/sbin
# export XILINX_XRT=/usr

# if (( $1 == "BERT" ))
# then
# ./hostexe mm_hw.xclbin 3072 1024 1024 100 >> 0_result_Layer0_3;
# echo -e "\nLayer0_3 Succeed!";
# sleep 5;
# ./hostexe mm_hw.xclbin 3072 1024 4096 100 >> 1_result_Layer4;
# echo -e "\nLayer4 Succeed!";
# sleep 5;
# ./hostexe mm_hw.xclbin 3072 4096 1024 100 >> 2_result_Layer5;
# echo -e "\nLayer5 Succeed!";
# sleep 5;
# ./hostexe mm_hw.xclbin 512 512 64 100 >> 3_result_Layer6;
# echo -e "\nLayer6 Succeed!";
# sleep 5;
# ./hostexe mm_hw.xclbin 512 64 512 100 >> 4_result_Layer7;
# echo -e "\nLayer7 Succeed!";
# sleep 5;
# fi

# #Parsing the results into file "Figure7_8_duplicate.log"
# rm -rf Figure7_8_duplicate.log;
# for filename in *_result_*;
# do
# 	let n=1;
# 	while read line; do
# 		if (( ${n} == 1 ))
# 		then
# 			my_str=$line;
# 			echo "${filename}:${my_str}" >>Figure7_8_duplicate.log; 
# 		fi
# 		let n=${n}+1;
# 	done < ./$filename
# done
# rm -rf *_result_*;

# echo -e "\n8_duplicate Accs Test Succeed!";
# echo -e "\nPlease See On-board Results in Figure7_8_duplicate.log ";
for filename in *_result_*;
do
	let n=1;
	while read line; do
		if (( ${n} == 1 ))
		then
			my_str=$line;
			A =`echo $my_str \*2 | bc`;
			echo "${filename}:${A}";
			#let k = ${my_str}*3;
			#echo "${filename}:${k}"; 
		fi
		let n=${n}+1;
	done < ./$filename
done