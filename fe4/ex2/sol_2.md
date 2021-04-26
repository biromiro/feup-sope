## Paging Over Variable Memory Partitions in a Virtual Memory system
# Advantages
- Removes External fragmentation
- Allocating memory is easy and cheap
- Any free page is ok, OS can take first- one out of list it keeps
- Eliminates external fragmentation
- Data (page frames) can be scattered- all over PM
- Pages are mapped appropriately anyway
- Allows demand paging and prepaging
- More efficient swapping
- No need for considerations about- fragmentation
- Just swap out page least likely to be- used 

# Disadvantages
- Processes can be allocated a lot of unused memory (internal fragmentation)
- Longer memory access times (page table lookup)
- Can be improved using TLB
- Guarded page tables
- Inverted page tables
- Memory requirements (one entry per VM page)
- Improve using Multilevel page tables and variable page sizes (super-pages)
- Guarded page tables
- Page Table Length Register (PTLR) to limit virtual memory size
- Internal fragmentation 