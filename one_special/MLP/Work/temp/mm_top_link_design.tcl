set_param project.enableUnifiedAIEFlow true
add_files ././Work/temp/mm_top_aie_full_netlist.aiexn
add_files ././Work/temp/mm_top_aie_constraints_for_placer.aiecst
add_files ././Work/temp/mm_top_aie_routed.aiesol
link_design -part xcvc1902-vsva2197-2MP-e-S
