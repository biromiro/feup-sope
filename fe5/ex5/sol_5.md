# How does a computer keep track of the time of the day

Normally, time information is kept under the RTC controller. Upon boot, the computer may query a time server to more accurately define its time. As such, an easy way to keep the time of day would be to keep the seconds of the current day in a register and the number of ticks in the current second in another, and update them accordingly. Upon boot, the PC only needs to check its RTC/Time server to set this register properly.

With the proc/state file information, one could also calculate the time of the day via arithmetic and by keeping a register with the time since boot. An easy way to do this would be to retrive the 'btime' parameter, add in the this register and obtain the current time. 

However, it must be noted that the RTC does this job already.