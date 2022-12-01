export LD_LIBRARY_PATH=/mnt:/tmp:$LD_LIBRARY_PATH
export PATH=$PATH:/sbin
export XILINX_XRT=/usr

if (( $1 == "bert" )) || (( $1 == "BERT" ))
then
	./hostexe mm_hw.xclbin 3072 1024 1024 100 0 >> 0_result_bert_Layer0_3;
	echo -e "\nLayer0_3 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 4096 100 0 >> 1_result_bert_Layer4;
	echo -e "\nLayer4 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 1024 100 0 >> 2_result_bert_Layer5;
	echo -e "\nLayer5 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 512 512 64 100 0 >> 3_result_bert_Layer6;
	echo -e "\nLayer6 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 512 64 512 100 0 >> 4_result_bert_Layer7;
	echo -e "\nLayer7 Succeed!";
	sleep 5;
elif (( $1 == "vit" )) || (( $1 == "VIT" )) || (( $1 == "ViT" ))
then
	./hostexe mm_hw.xclbin 3072 3024 1024 100 0 >> 0_result_vit_Layer0;
	echo -e "\nLayer0 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 1024 100 0 >> 1_result_vit_Layer1;
	echo -e "\nLayer1 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 4096 100 0 >> 2_result_vit_Layer2;
	echo -e "\nLayer2 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 1024 100 0 >> 3_result_vit_Layer3;
	echo -e "\nLayer3 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 3048 100 0 >> 4_result_vit_Layer4;
	echo -e "\nLayer4 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 64 64 64 100 0 >> 5_result_Layer5_6;
	echo -e "\nLayer5_6 Succeed!";
	sleep 5;
elif (( $1 == "NCF" )) || (( $1 == "ncf" ))
then
	./hostexe mm_hw.xclbin 3072 4096 2048 100 0 >> 0_result_ncf_Layer0;
	echo -e "\nLayer0 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 2048 1024 100 0 >> 1_result_ncf_Layer1;
	echo -e "\nLayer1 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 512 100 0 >> 2_result_ncf_Layer2;
	echo -e "\nLayer2 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 512 256 100 0 >> 3_result_ncf_Layer3;
	echo -e "\nLayer3 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 256 128 100 0 >> 4_result_ncf_Layer4;
	echo -e "\nLayer4 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 128 64 100 0 >> 5_result_ncf_Layer5;
	echo -e "\nLayer5 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 64 32 100 0 >> 6_result_ncf_Layer7;
	echo -e "\nLayer6 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 32 16 100 0 >> 7_result_ncf_Layer8;
	echo -e "\nLayer7 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 32 1 100 0 >> 8_result_ncf_Layer9;
	echo -e "\nLayer8 Succeed!";
	sleep 5;
if (( $1 == "MLP" )) || (( $1 == "mlp" ))
then
	./hostexe mm_hw.xclbin 3072 2048 4096 100 0 >> 0_result_bert_Layer0;
	echo -e "\nLayer0 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 4096 100 0 >> 1_result_bert_Layer1;
	echo -e "\nLayer1 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 4096 100 0 >> 2_result_bert_Layer2;
	echo -e "\nLayer2 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 1024 100 0 >> 3_result_bert_Layer3;
	echo -e "\nLayer3 Succeed!";
	sleep 5;
fi

#Parsing the results into file "Figure7_8_duplicate.log"
rm -rf Figure7_8_duplicate.log;
for filename in *_result_$1_*;
do
	let n=1;
	while read line; do
		if (( ${n} == 7 ))
		then
			my_str=$line;
			echo "${filename}:${my_str}" >>Figure7_8_duplicate_$1.log; 
		fi
		let n=${n}+1;
	done < ./$filename
done
rm -rf *_result_$1_*;

chmod +x cal_throughput.sh;

./cal_throughput.sh $1;

echo -e "\n8_duplicate Accs Test Succeed!";