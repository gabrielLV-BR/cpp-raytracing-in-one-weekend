folder:
	ls out || mkdir out

build: folder
	g++ ./src/*.cpp ./src/*.hpp -o out/out

run: build
	out/out | convert - out/out.png

clean:
	rm out/*