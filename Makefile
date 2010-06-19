all:
	cd build && cmake .. && make

run:
	build/source/wmail.wt --http-address vickev.fr --http-port 8080 --docroot .
