# Experiment
```
./experiment.bash
```

Tries to read and write `32768mb` of memory sequentually. Before running an experiment static size of swap was configured.

# Linux

## Setup

```
OS: Ubuntu 22.04.3 LTS
Compiler: GCC 11.4.0
RAM: 16384mb
Swap: 8192mb
```

## Results

If `vm.overcommit_memory = 0`, memory allocation failed. Read and write operations wasn't executed.

```
Allocation 32768mb of memory was failed.
```

If `vm.overcommit_memory = 1`, more memory was allocated than available in RAM and swap. Read operation completes, because allocated memory wasn't initialized. Write operation failed, because more memory than physically available was initialized. The proccess was killed by OOM Killer.

```
./experiment.bash: line 6: 25119 Killed ./memory_overcommit 32768 write
```

So, Linux supports memory overcommit through `vm.overcommit_memory` setting. More memory than available in RAM and swap can be allocated, but not initialized - proccess will be killed by OOM Killer.

# Windows

## Setup

```
OS: Windows 10 Pro 22H2
Compiler: GCC 11.4.0
RAM: 16384mb
Swap: 8192mb
```

## Results

Windows doesn't have analogous setting as Linux and memory allocation failed. Read and write operations wasn't executed.

```
Allocation 32768mb of memory was failed.
```

So, by default Windows doesn't support memory overcommit. More memory than available in RAM and swap can't be allocated.
