.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r, %:live, %1
		and r1, %0, r1

live:	live 
		zjmp %:liv
