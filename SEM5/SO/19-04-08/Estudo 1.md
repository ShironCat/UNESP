# Estudo 1

## History of Operating Systems

### The First Generation (1945 - 55): Vacuum Tubes

* World War II
    * stimulated an explosion of activity
* John Atamasoff and his graduate student Clifford Berry
    * built the first digital computer at Iowa State University
    * 300 vacuum tubes
* At the same time, Konrad Zuse in Berlin
    * Z3 computer
    * electromechanical relays
* 1944
    * Colossus was built and programmed
    * group of scientists (including Alan Turing)
* Mark I
    * built by Howard Aiken
    * at Harvard
* ENIAC
    * built by Willian Manchley
    * and his graduate student J. Presper Eckert
    * University of Pennsylvania

Some were binary, some used vacuum tubes, some were programmable, but all were very primitive and took seconds to perform even the simplest calculations.

* Operating systems were unheard of

### The Second Generation (1955 - 65): Transistors and Batch Systems

* **mainframes**
    * locked away in large, specially air-conditioned computer rooms
* To run a **job**
    * programmers write the program on paper (in FORTRAN or assembler)
    * then punch it on cards

Much computer time was wasted while operators were walking around the machine room.

* People quickly looked for ways to reduce the wasted time
* The solution generally adopte was the **batch system**.
    * the idea behind it was to collect a tray full of jobs
    * the cards were read onto a magnetic tape
    * the operator then loaded a special program (the ancestors of today's operating system)
    * which read the first job on tape and ran it
    * the output was written onto a second tape
    * the operating system automatically read the next job from the tape

When the whole batch was done, the operator removed the input and output tapes, replaced the input tape with the next batch, and brought the output tape to a 1401 for printing **off line** (not connected to the main computer).

* Structure of a typical input job
    * $JOB card: specifying the maximum run times in minutes, the account number to be charged, and the programmer's name
    * $FORTRAN card: telling the operating system to load the FORTRAN compiler from the system tape. Directly followed by the program to be compiled
    * $LOAD card: directing the operating system to load the object program just compiled (compiled programs were often written on scratch tapes and had to be loaded explicitly)
    * $RUN card: telling the operating system to run the program with the data following it
    * $END card: marked the end of the job

These primitive control cards were the forerunners of modern shells and command-line interpreter.

Large second-generation computers were used mostly for scientific and egineering calculations. They were largely programmed in FORTRAN and assembly language. Typical operating systems were FMS (the Fortran Monitor System) and IBSYS, IBM's operating system for the 7094.