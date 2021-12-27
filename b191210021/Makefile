all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/agacDugum.cpp -o ./lib/agacDugum.o
	g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
bagla:
	g++ ./lib/Dugum.o ./lib/agacDugum.o ./lib/AVLAgaci.o ./lib/Kuyruk.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program