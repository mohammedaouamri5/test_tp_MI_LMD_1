all :
	gcc  -c script/*.c script/main.c -std=c17 -g  -Wall -m64 -Iscript 
	gcc *.o -o Output/main.exe -lmingw32 
	Output/main.exe
	del *.o

# gcc main.c -o main.exe