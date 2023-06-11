OBJS = obj/fecho_convexo.o obj/gaal.o obj/main.o obj/time_measure.o
HDRS = include/fecho_convexo.h include/gaal.h include/vetor.h include/par.h include/time_measure.h
entrada = entrada.txt

fecho: bin/main
	./bin/main -p $(entrada)

bin/main: $(OBJS) $(HDRS)
	g++ $(OBJS) -o bin/main -g -Iinclude -Wall

obj/%.o: src/%.cpp $(HDRS)
	g++ -c $< -o $@ -Iinclude

clean:
	rm obj/* bin/* -rf