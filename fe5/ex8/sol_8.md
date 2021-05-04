# Hard Disk Repartitioning

Disk /dev/sda: 500.1 GB, 500107862016 bytes; 255 heads, 63 sectors/track, 60801 cylinders

## i - What is the size of the sector, in bytes?

500107862016/255/63/60801 = 512.003 Bytes

## ii -  The geometry of the disk appears to be well defined and uniform. Probably, a disk driver could be built capable of controlling even the physical movement and positioning of the reading heads in order to be able to read a specific sector. Is this statement correct?

It is true. In fact, before LBA was the common technology on HDD, this was the process taken by the drivers.