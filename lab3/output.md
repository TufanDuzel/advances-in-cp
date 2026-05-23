EXPERIMENT 1:

PS D:\Belgeler\advances-in-cp\lab3> ./array_init
>> 
Thread Thread 7 set arr[7] = 14Thread 3 set arr[3] = 6
Thread 8 set arr[8] = 16
Thread 1 set arr[1] = 2
Thread 5 set arr[5] = 10
Thread 2 set arr[2] = 4

Thread 9 set arr[9] = 18
Thread 6 set arr[6] = 12
0 set arr[0] = 0
Thread 4 set arr[4] = 8


EXPERIMENT 2:

PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS = "1"
PS D:\Belgeler\advances-in-cp\lab3> .\bubble_parallel.exe
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS = "2"
PS D:\Belgeler\advances-in-cp\lab3> .\bubble_parallel.exe
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS = "8"
PS D:\Belgeler\advances-in-cp\lab3> .\bubble_parallel.exe
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3> 


EXPERIMENT 3:

PS D:\Belgeler\advances-in-cp\lab3> .\merge_parallel.exe
>> 
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="1"
PS D:\Belgeler\advances-in-cp\lab3> .\merge_parallel.exe
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="4"
PS D:\Belgeler\advances-in-cp\lab3> .\merge_parallel.exe
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="8"
PS D:\Belgeler\advances-in-cp\lab3> .\merge_parallel.exe
Sorted array: 1 2 3 4 5 7 8 9 
PS D:\Belgeler\advances-in-cp\lab3>


EXPERIMENT 4:

PS D:\Belgeler\advances-in-cp\lab3> .\scheduling_test.exe
static:  0.0320001 s
dynamic: 0.027 s
guided:  0.0240002 s
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="2"
PS D:\Belgeler\advances-in-cp\lab3> .\scheduling_test.exe 
static:  0.069 s
dynamic: 0.0699999 s
guided:  0.066 s
PS D:\Belgeler\advances-in-cp\lab3> 
>> $env:OMP_NUM_THREADS="4"
PS D:\Belgeler\advances-in-cp\lab3> .\scheduling_test.exe
static:  0.04 s
dynamic: 0.039 s
guided:  0.036 s
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="8"
PS D:\Belgeler\advances-in-cp\lab3> .\scheduling_test.exe
static:  0.0239999 s
dynamic: 0.0310001 s
guided:  0.0249999 s


EXPERIMENT 5:

PS D:\Belgeler\advances-in-cp\lab3> .\sort_with_locks.exe
>> 
Sorted with locks: 3 7 1 5 2 9 4 8 0 6 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="1"
PS D:\Belgeler\advances-in-cp\lab3> .\sort_with_locks.exe
Sorted with locks: 3 7 1 5 2 8 4 6 0 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="4"
PS D:\Belgeler\advances-in-cp\lab3> .\sort_with_locks.exe   
Sorted with locks: 3 7 1 5 2 8 4 6 0 9 
PS D:\Belgeler\advances-in-cp\lab3> $env:OMP_NUM_THREADS="8"
PS D:\Belgeler\advances-in-cp\lab3> .\sort_with_locks.exe   
Sorted with locks: 3 7 1 5 2 9 4 6 0 8