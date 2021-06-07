# Virtual Memory w/ Segmentation only vs w/ Pagination only

With segmentation only VM, the usage of memory is lower, since one can define the size of alocated memory to the value that will be used, unlike paging that must define the size of its pages without taking into consideration what it will be holding. It also facilitates process comunication due to this same advantage, and internal fragmentation does not occur.

However, paging is faster than segmentation, as regular memory size pages allow for better access optimizations. Even though external fragmentation does not occur, internal fragmentation might occur, which is a disadvantage.
