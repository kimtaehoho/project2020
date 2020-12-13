pet_manager: pet2.o
	gcc -o pet_manager pet2.o
pet2.o: pet2.c
	gcc -c pet2.c
