export LD_LIBRARY_PATH=/mnt:/tmp:$LD_LIBRARY_PATH
export PATH=$PATH:/sbin
export XILINX_XRT=/usr

#Running on-board experiment with different MM sizes
let k=0;
for i in 64 128 256 512 1024 1536 2048 3072 4096 6144
do	
	let iter=20;
	if [ ${i} -gt 6000 ]
	then
		wait_time=40;
	else
		wait_time=10;
	fi
	echo "Run square matrix multiply with size ${i} for ${iter} iterations";
    ./hostexe mm_hw.xclbin ${i} ${i} ${i} ${iter} 0 >> ${k}_result_${i} &
	PID=$!;
    sleep ${wait_time};
    kill $PID;
	echo "Size ${i} Finished";
	echo " ";
    let k=${k}+1;
    sleep 5;
done

#Parsing the results into file "Table2.log"
rm -rf Table2.log;
for filename in *_result_*;
do
	let n=1;
	while read line; do
		if (( ${n} == 8 ))
		then
			my_str=$line;
			echo "${filename}:${my_str}" >>Table2.log; 
		fi
		let n=${n}+1;
	done < ./$filename
done
rm -rf *_result_*;

echo -e "\nSingle MM Kernel Test Succeed!";
echo -e "\nPlease See On-board Results of Table2 in Table2.log ";