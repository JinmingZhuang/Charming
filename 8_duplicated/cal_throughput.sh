if (( $1 == "bert" )) || (( $1 == "BERT" ))
    # M * K * N * #layer * 2
    let OPs = $(( 3072*1024*1024*4*2 + 3072*1024*4096*2*2 + 512*512*64*2*2 ));
    for ((n=1;n<=5;n++));
    do
    	read -r line
        if (( ${n} == 1 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer0_3="${Value[0]}"; 
    	elif (( ${n} == 2 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer4="${Value[0]}"; 
    	elif (( ${n} == 3 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer5="${Value[0]}"; 
    	elif (( ${n} == 4 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer6="${Value[0]}";
        elif (( ${n} == 5 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer7="${Value[0]}";
     	fi
    done < "Figure7_8_duplicate_$1.log"
    let Time = ${Layer0_3}*4 + ${Layer4} + ${Layer5} + ${Layer6} + ${Layer7};
    let Throughput = ${OPs}*100/${Time}/1000000000;
    echo "Bert on 8 Duplicate Accs: ${Throughput} GOPs";
elif (( $1 == "vit" )) || (( $1 == "VIT" )) || (( $1 == "ViT" ))
    # M * K * N * #layer * 2
    let OPs = $(( 3072*3024*1024*1*2 + 3072*1024*1024*1*2 + 3072*1024*4096*2*2 + 3072*1024*3048*1*2 + 64*64*64*2*2));
    for ((n=1;n<=6;n++));
    do
    	read -r line
        if (( ${n} == 1 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer0="${Value[0]}"; 
    	elif (( ${n} == 2 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer1="${Value[0]}"; 
    	elif (( ${n} == 3 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer2="${Value[0]}"; 
    	elif (( ${n} == 4 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer3="${Value[0]}";
        elif (( ${n} == 5 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer4="${Value[0]}";
        elif (( ${n} == 6 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer5="${Value[0]}";
     	fi
    done < "Figure7_8_duplicate_$1.log"
    let Time = ${Layer0} + ${Layer1} + ${Layer2} + ${Layer3} + ${Layer4} + ${Layer5}*2 ;
    let Throughput = ${OPs}*100/${Time}/1000000000;
    echo "ViT on 8 Duplicate Accs: ${Throughput} GOPs";
elif (( $1 == "NCF" )) || (( $1 == "ncf" ))
    # M * K * N * 2
    let OPs = $(( 3072*4096*2048*2 + 3072*2048*1024*2 + 3072*1024*512*2 + 3072*512*256*2 + 3072*256*128*2 + 3072*128*64*2 + 3072*64*32*2 + 3072*32*16*2 + 3072*32*1*2));
    for ((n=1;n<=9;n++));
    do
    	read -r line
        if (( ${n} == 1 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer0="${Value[0]}"; 
    	elif (( ${n} == 2 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer1="${Value[0]}"; 
    	elif (( ${n} == 3 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer2="${Value[0]}"; 
    	elif (( ${n} == 4 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer3="${Value[0]}";
        elif (( ${n} == 5 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer4="${Value[0]}";
        elif (( ${n} == 6 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer5="${Value[0]}";
        elif (( ${n} == 7 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer6="${Value[0]}";
        elif (( ${n} == 8 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer7="${Value[0]}";
        elif (( ${n} == 9 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer8="${Value[0]}";
     	fi
    done < "Figure7_8_duplicate_$1.log"
    let Time = ${Layer0} + ${Layer1} + ${Layer2} + ${Layer3} + ${Layer4} + ${Layer5} + ${Layer6} + ${Layer7} + ${Layer8};
    let Throughput = ${OPs}*100/${Time}/1000000000;
    echo "NCF on 8 Duplicate Accs: ${Throughput} GOPs";
elif (( $1 == "MLP" )) || (( $1 == "mlp" ))
    # M * K * N * #layer * 2
    let OPs = $(( 3072*2048*4096*1*2 + 3072*4096*4096*2*2 + 3072*4096*1024*2));
    for ((n=1;n<=4;n++));
    do
    	read -r line
        if (( ${n} == 1 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer0="${Value[0]}"; 
    	elif (( ${n} == 2 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer1="${Value[0]}"; 
    	elif (( ${n} == 3 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer2="${Value[0]}"; 
    	elif (( ${n} == 4 ))
    	then
    		IFS=':' read -ra Key <<< "$line";
    		value_temp="${Key[1]}"; 
    		unset IFS
    		IFS=';' read -ra Value <<< "$value_temp";
    		Layer3="${Value[0]}";
     	fi
    done < "Figure7_8_duplicate_$1.log"
    let Time = ${Layer0} + ${Layer1} + ${Layer2} + ${Layer3};
    let Throughput = ${OPs}*100/${Time}/1000000000;
    echo "MLP on 8 Duplicate Accs: ${Throughput} GOPs";
fi