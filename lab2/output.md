EXPERIMENT 1:
Thread Thread 13 has x = 13Thread 15 has x = 15
Thread 1 has x = 1
Thread 8 has x = 8

Thread 11 has x = 11
Thread 9 has x = 9
Thread 12 has x = 12
Thread 6 has x = 6
Thread 2 has x = 2
Thread 7 has x = 7
Thread 3 has x = 3
Thread Thread 5 has x = 5
14 has x = 14
Thread 10 has x = 10
Thread 4 has x = 4
0 has x = 0
After parallel region, x = 5


EXPERIMENT 2:
PS D:\Belgeler\advances-in-cp\lab2> Start-Process -FilePath ".\race.exe"
PS D:\Belgeler\advances-in-cp\lab2> $env:OMP_NUM_THREADS=8
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\race_condition.cpp -o .\race.exe
PS D:\Belgeler\advances-in-cp\lab2> .\race.exe
Final sum (race) = 29175
PS D:\Belgeler\advances-in-cp\lab2> .\race.exe
Final sum (race) = 20343
PS D:\Belgeler\advances-in-cp\lab2> .\race.exe
Final sum (race) = 17085

PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\race_condition_critical.cpp -o .\race_critical.exe
>> .\race_critical.exe
Final sum (critical) = 100000
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\race_condition_atomic.cpp -o .\race_atomic.exe
>> .\race_atomic.exe
Final sum (atomic) = 100000
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\race_condition_reduction.cpp -o .\race_reduction.exe
>> .\race_reduction.exe
Final sum (reduction) = 100000


EXPERIMENT 3:
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\barrier_sections.cpp -o .\barrier_sections.exe
PS D:\Belgeler\advances-in-cp\lab2> .\barrier_sections.exe
Thread 0 is loading data...
Thread 1 is processing part A
Thread Thread 0 is processing part B
2 is processing part C
All work completed!

PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\barrier_sections.cpp -o .\barrier_sections.exe
>> .\barrier_sections.exe
>>
Thread Thread 3 is processing part A
2 is processing part C
Thread 1 is processing part B
Thread 0 is loading data...
All work completed!


EXPERIMENT 4:
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\schedule_static4.cpp -o .\sched_static4.exe
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\schedule_dynamic1.cpp -o .\sched_dynamic1.exe
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\schedule_guided.cpp   -o .\sched_guided.exe
PS D:\Belgeler\advances-in-cp\lab2> Measure-Command { .\sched_static4.exe } | Select-Object TotalSeconds

TotalSeconds
------------
   1,6357758


PS D:\Belgeler\advances-in-cp\lab2> Measure-Command { .\sched_dynamic1.exe } | Select-Object TotalSeconds

TotalSeconds
------------
   3,3110252


PS D:\Belgeler\advances-in-cp\lab2> Measure-Command { .\sched_guided.exe } | Select-Object TotalSeconds
>>

TotalSeconds
------------
   1,6445803


EXPERIMENT 5:
PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\nested_openmp.cpp -o .\nested.exe
PS D:\Belgeler\advances-in-cp\lab2> .\nested.exe
Outer thread: Outer thread: 01

  Inner thread: 0 (inside outer 1)
  Inner thread: 1 (inside outer 1)
  Inner thread: 0 (inside outer 0)
  Inner thread: 1 (inside outer 0)

PS D:\Belgeler\advances-in-cp\lab2> g++ -fopenmp .\nested_openmp.cpp -o .\nested.exe
PS D:\Belgeler\advances-in-cp\lab2> .\nested.exe
Outer thread: Outer thread: 01

  Inner thread: 0 (inside outer 1)
  Inner thread: 0 (inside outer 0)