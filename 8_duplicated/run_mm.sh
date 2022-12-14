export LD_LIBRARY_PATH=/mnt:/tmp:$LD_LIBRARY_PATH
export PATH=$PATH:/sbin
export XILINX_XRT=/usr

task=$1;
echo "Current task is ${task}";
if [ ${task} == "bert" ] || [ ${task} == "BERT" ]
then
	./hostexe mm_hw.xclbin 3072 1024 1024 100 0 >> 0_result_${task}_Layer0_3 &
	PID=$!;
    sleep 20;
    kill $PID;
	echo -e "\nLayer0_3 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 4096 100 0 >> 1_result_${task}_Layer4 &
	PID=$!;
    sleep 50;
    kill $PID;
	echo -e "\nLayer4 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 1024 100 0 >> 2_result_${task}_Layer5 &
	PID=$!;
    sleep 50;
    kill $PID;
	echo -e "\nLayer5 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 512 512 64 100 0 >> 3_result_${task}_Layer6 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer6 Succeed!";
	sleep 15;
	./hostexe mm_hw.xclbin 512 64 512 100 0 >> 4_result_${task}_Layer7 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer7 Succeed!";
	sleep 5;
elif [ ${task} == "vit" ] || [ ${task} == "VIT" ] || [ ${task} == "ViT" ]
then
	./hostexe mm_hw.xclbin 3072 3024 1024 100 0 >> 0_result_${task}_Layer0 &
	PID=$!;
    sleep 40;
    kill $PID;
	echo -e "\nLayer0 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 1024 100 0 >> 1_result_${task}_Layer1 &
	PID=$!;
    sleep 20;
    kill $PID;
	echo -e "\nLayer1 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 4096 100 0 >> 2_result_${task}_Layer2 &
	PID=$!;
    sleep 50;
    kill $PID;
	echo -e "\nLayer2 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 1024 100 0 >> 3_result_${task}_Layer3 &
	PID=$!;
    sleep 50;
    kill $PID;
	echo -e "\nLayer3 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 3048 100 0 >> 4_result_${task}_Layer4 &
	PID=$!;
    sleep 40;
    kill $PID;
	echo -e "\nLayer4 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 64 64 64 1000 0 >> 5_result_${task}_Layer5_6 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer5_6 Succeed!";
	sleep 5;
elif [ ${task} == "NCF" ] || [ ${task} == "ncf" ]
then
	./hostexe mm_hw.xclbin 3072 4096 2048 100 0 >> 0_result_${task}_Layer0 &
	PID=$!;
    sleep 80;
    kill $PID;
	echo -e "\nLayer0 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 2048 1024 100 0 >> 1_result_${task}_Layer1 &
	PID=$!;
    sleep 30;
    kill $PID;
	echo -e "\nLayer1 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 1024 512 100 0 >> 2_result_${task}_Layer2 &
	PID=$!;
    sleep 15;
    kill $PID;
	echo -e "\nLayer2 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 512 256 1 0 >> 3_result_${task}_Layer3 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer3 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 256 128 100 0 >> 4_result_${task}_Layer4 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer4 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 128 64 100 0 >> 5_result_${task}_Layer5 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer5 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 64 32 100 0 >> 6_result_${task}_Layer7 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer6 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 32 16 100 0 >> 7_result_ncf_Layer8 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer7 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 32 1 100 0 >> 8_result_${task}_Layer9 &
	PID=$!;
    sleep 10;
    kill $PID;
	echo -e "\nLayer8 Succeed!";
	sleep 5;
elif [ ${task} == "MLP" ] || [ ${task} == "mlp" ]
then
	./hostexe mm_hw.xclbin 3072 2048 4096 10 0 >> 0_result_${task}_Layer0 &
	PID=$!;
    sleep 30;
    kill $PID;
	echo -e "\nLayer0 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 4096 10 0 >> 1_result_${task}_Layer1 &
	PID=$!;
    sleep 30;
    kill $PID;
	echo -e "\nLayer1 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 4096 10 0 >> 2_result_${task}_Layer2 &
	PID=$!;
    sleep 30;
    kill $PID;
	echo -e "\nLayer2 Succeed!";
	sleep 5;
	./hostexe mm_hw.xclbin 3072 4096 1024 10 0 >> 3_result_${task}_Layer3 &
	PID=$!;
    sleep 30;
    kill $PID;
	echo -e "\nLayer3 Succeed!";
	sleep 5;
fi

#Parsing the results into file "Figure7_8_duplicate.log"
rm -rf Figure7_8_temp_${task}.log;
for filename in *_result_$1_*;
do
	let n=1;
	while read line; do
		if (( ${n} == 9 ))
		then
			my_str=$line;
			echo "${my_str}" >>Figure7_8_temp_${task}.log; 
		fi
		let n=${n}+1;
	done < ./$filename
done
rm -rf *_result_$1_*;

sh ./cal_throughput.sh ${task};

echo -e "\n8_duplicate Accs Test Succeed!";