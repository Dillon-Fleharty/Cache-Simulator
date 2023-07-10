Overview:

This is a basic ``C++`` program that implements a ``cache simulator``. From a high-level view the program will read an input file that contains memory reference addresses which are all positive integers. The program will then simulate the cache behavior by printing the output results as either a ``"HIT"`` or ``"MISS"``. The program uses a user-defined number of entries and associativity for the cache. 

The working environment for the program is Linux using ``C++11`` and tested on the Zeus server at Texas State University. Included files are ``cache_sim.cpp`` and ``input1.txt``. 

The main function is in the cache_sim.cpp file which also includes the implementation for Entry and CacheMoney for ease of use by anyone running the program and grading.

The program takes three command-line arguments:

1. ``num_entries``: The total number of entries in the cache.
2. ``associativity``: The associativity of the cache.
3. ``input_file``: The name of the file containing the memory reference addresses.

Example:

***
``./cache_sim 1024 4 input_file.txt``
***

This command will run the cache simulator with 1024 entries, 4-way associativity, and use the memory reference addresses from “input_file.txt" as input. The output will be written to "cache_sim_output".


Additional Documentation 

Classes & Dependencies:      

•	``Classes``           
•  Entry           
•  CacheMoney    

•``Dependencies``               
•	iostream      
•	fstream      
•	string     
•	vector      

Function / Methods implemented in program:

1.	``main()``

The main function will parse the command line arguments for the number of entries (num_entries), associativity, and the input file (input_file.txt). It creates a CacheMoney object, opens the input file and iterates through the addresses. It will then produce an output file, “cache_sim_output”


2.	 ``bool hit_or_miss(size_t address)``

This method tries to access the memory address located in the cache and returns ‘true’ (HIT) if the address is found or false if it is not found.  If the Method returns ‘false’ (MISS) then it will update the cache by replacing the least recently used (LRU) entry with the new address. 

