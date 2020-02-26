/*
 * testList.c
 *
 *  Created on: 28 ene. 2018
 *      Author: ipserc
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

typedef struct
{
	int id;
	char * name;
} dog_t;

void freeDog(dog_t * item)
{
	free(item->name);
}

dog_t setDog(int id, char * name)
{
	dog_t dog;

	dog.id = id;
	dog.name = malloc(strlen(name)+1);
	sprintf(dog.name, "%s", name);
	return dog;
}

void printDog(dog_t * dog)
{
	printf("PERRO %02d - %s\n", dog->id, dog->name);
}

int main(int argc, char * argv[])
{
	list_t * catList = NULL;
	list_t * dogList = NULL;

	listVersion();
	listNew(&catList);
	char cat[30] = "GATO 1 - Don Gato";
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
	sprintf(cat, "%s", "GATO 2 - Benito Bodoque");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
	sprintf(cat, "%s", "GATO 3 - Cucho");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
	sprintf(cat, "%s", "GATO 4 - Demóstenes");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
	sprintf(cat, "%s", "GATO 5 - Espanto");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
	sprintf(cat, "%s", "GATO 6 - Panza");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
		puts("*** 0 ***"); listPrint(catList, (void *)puts);
		printf("List ITEMS Count:%u\n", listItemsCount(catList));


	listNew(&dogList);
	dog_t dog = setDog(1, "Scooby-Doo");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(2, "Ayudante De Santa Claus");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(3, "Pluto");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(4, "Snoopy");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(5, "Golfo");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(6, "Odie");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
		puts("*** 1 ***"); listPrint(dogList, (void *)printDog);
		printf("dogList ITEMS Count:%u\n", listItemsCount(dogList));
		listMapPrint(dogList);

	listDrop(dogList, (void *)freeDog);
		puts("*** 2 *** listDrop(dogList, freeDog);"); listPrint(dogList, (void *)printDog);
		printf("List ITEMS Count:%u\n", listItemsCount(dogList));
	listRemoveN(dogList, 2, (void *)freeDog);
		puts("*** 3 *** listRemoveN(dogList, 2, freeDog);"); listPrint(dogList, (void *)printDog);
		listMapPrint(dogList);
		listPrint(dogList, (void *)printDog);
	listRemoveN(dogList, 3, (void *)freeDog);
		puts("*** 4.0 *** listRemoveN(dogList, 3, freeDog);"); listPrint(dogList, (void *)printDog);
	listRemoveN(dogList, 3, (void *)freeDog);
		puts("*** 4.1 *** listRemoveN(dogList, 3, freeDog);"); listPrint(dogList, (void *)printDog);
	listMapPrint(dogList);
		printf("List ITEMS Count:%u\n", listItemsCount(dogList));
	listRemoveN(dogList, 2, (void *)freeDog);
		puts("*** 4.2 *** listRemoveN(dogList, 2, freeDog);"); listPrint(dogList, (void *)printDog);
		printf("List ITEMS Count:%u\n", listItemsCount(dogList));
	listRemoveN(dogList, 0, (void *)freeDog);
		puts("*** 5 ***"); listPrint(dogList, (void *)printDog);
	listRemoveN(dogList, 0, (void *)freeDog);
		puts("DONE: listRemoveN(dogList, 0);");
		puts("*** 6 ***"); listPrint(dogList, (void *)printDog);
		puts("NOW THE LIST IS EMPTY");
		listMapPrint(dogList);	printf("List ITEMS Count:%u\n", listItemsCount(dogList));
	listDrop(dogList, (void *)freeDog);
		puts("SAFE DROP: listDrop(dogList);");
		listMapPrint(dogList);
	listRemoveN(dogList, 0, (void *)freeDog);
		puts("SAFE DROP: listRemoveN(dogList, 0);");
	listDrop(dogList, (void *)freeDog);
		puts("SAFE DROP: listDrop(dogList);");
		puts("*** 7 ***"); listPrint(dogList, (void *)printDog);
		listMapPrint(dogList);

	dog = setDog(7, "Agallas");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
		puts("*** 8 ***"); listPrint(dogList, (void *)printDog);
	listMapPrint(dogList);
	dog = setDog(8, "Patán");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(9, "Brian Griffin");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(10, "Scrappy-Doo");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
	dog = setDog(11, "Nevado");
	dogList = listAppend(dogList, &dog, sizeof(dog_t));
		puts("*** 9 ***"); listPrint(dogList, (void *)printDog);
		listMapPrint(dogList);

	node_t * listNode;
	listNode = listNodeN(catList, 3);
		puts("*** 10 ***"); listNodePrint(listNode, (void *)puts);
	listNode = listNodeN(catList, 1);
		puts("*** 11 ***"); listNodePrint(listNode, (void *)puts);
	listNode = listNodeN(catList, 4);
		puts("*** 12 ***"); listNodePrint(listNode, (void *)puts);

		puts("*** 13 ***"); listPrint(catList, (void *)puts);
	listDrop(catList, NULL);
		puts("*** 14 *** listDrop(catList, NULL)"); listPrint(catList, (void *)puts);
	listRemoveN(catList, 0, NULL);
		puts("*** 15 *** listRemoveN(catList, 0, NULL)"); listPrint(catList, (void *)puts);
	listRemoveN(catList, 4, NULL);
		puts("*** 16 *** listRemoveN(catList, 4, NULL)"); listPrint(catList, (void *)puts);
	listRemoveN(catList, 3, NULL);
		puts("*** 17 *** listRemoveN(catList, 3, NULL)"); listPrint(catList, (void *)puts);

	listDestroy(catList, NULL);
	listDestroy(dogList, (void *)freeDog);

	//check append in a new EMPTY list
	listNew(&catList);
	sprintf(cat, "%s", "GATO 1 - Benito Bodoque");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
		puts("*** 18 listAppend(catList,... ***"); listPrint(catList, (void *)puts);
	listDrop(catList, NULL);
		puts("*** 18.1 listPrint empty list***"); listPrint(catList, (void *)puts);
	sprintf(cat, "%s", "GATO 1 - Benito Bodoque");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
	sprintf(cat, "%s", "GATO 1 - Don Gato");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
		puts("*** 19 listAppend(catList,... ***"); listPrint(catList, (void *)puts);
	listDrop(catList, NULL);
	sprintf(cat, "%s", "GATO 2 - Don Gato");
	catList = listAppend(catList, cat, (strlen(cat)+1)*sizeof(char));
		puts("*** 20 listDrop(catList, NULL); listAppend(catList,... ***"); listPrint(catList, (void *)puts);

	listDestroy(catList, NULL);
		puts("EXIT_SUCCESS");
	return EXIT_SUCCESS;
}
