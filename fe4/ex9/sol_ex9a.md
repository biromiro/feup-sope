# Memory Issue

By having the 'gets' call after creating 'pass' in stack memory, one just needs to overflow the input buffer and the 'gets' call will overflow the memory space of the 'pass' variable. As such, one just needed to input a password greater than 15 characters and pass would be set to 1, and thus the user would have access to the priviledged stuff.