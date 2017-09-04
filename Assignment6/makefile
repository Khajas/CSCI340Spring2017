compile: assignment5.cc assignment5.h
	g++ -Wall -g -std=c++11 assignment5.cc assignment6.cc assignment6main.cc -o assignment6main.exe
run:
	./assignment6main.exe
copy_sample_output:
	#create a link to sample outout
	ln -s /home/turing/mhou/public/csci340spring2017/assignment$N.out sampleOutput.out
compare: sampleOutput.out
	#run the program and write the output to file 'myOutput.out'
	./assignment6main.exe > myOutput.out
	#find the difference between sample output and my output, ignoring whitespaces(-w)
	diff -w myOutput.out sampleOutput.out
clean:
	-rm *.exe *.out
