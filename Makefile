all: lisrun
	
lisrun:
	g++ *.cpp -o tsp -O3

run:
	start ./tsp

clean:
	rm ./tsp