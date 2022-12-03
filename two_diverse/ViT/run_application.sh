export LD_LIBRARY_PATH=/mnt:/tmp:$LD_LIBRARY_PATH
export PATH=$PATH:/sbin
export XILINX_XRT=/usr

#Running One-Monolithic design for BERT, ViT, NCF and MLP
StringVal="vit"

let k=0;
for i in $StringVal;
do
    echo "Run ${i} for 20 iterations";
    ./hostexe mm_hw.xclbin 20 0 >> ${k}_app_result_${i} &
    PID=$!;
    sleep 20;
    kill $PID;
    echo "${i} Finished";
    echo " ";
    let k=${k}+1;
    sleep 5;
done


#Parsing the results into file "Figure7_One_Spe.log"
rm -rf Figure7_One_Spe.log;
for filename in *_app_result_*;
do  
	let n=1;
    let judge=23;
	while read line; do
		if (( ${n} == ${judge} ))
		then
			my_str=$line;
			echo "${filename}:${my_str}" >>Figure7_One_Spe.log; 
		fi
		let n=${n}+1;
	done < ./$filename
done
rm -rf *_result_*;

echo -e "\nViT Test Succeed!";
echo -e "\nPlease See On-board Results of One-specialized design of ViT in Figure7_One_Spe.log ";