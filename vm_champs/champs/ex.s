.name "zork"
.comment "just a basic living prog"
		
live:	live	%1
	zjmp	%:live		
l2:	sti	r55,%:live,%0
	and	r1,%0,r1
	and r4,-4,r4
