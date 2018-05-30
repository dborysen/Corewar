.name "Super Pivnik"
.comment "Co-Co-Co"

add r1, r1, r2
add r2, r2, r2
add r2, r2, r3
add r3, r3, r3
add r3, r3, r3
add r3, r3, r3
live %1
lfork %2000
lfork %3000
live %1

ld %-1, r2
sti r2, r3, r3
