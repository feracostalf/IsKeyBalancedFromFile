#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int leer_archivo(FILE*);

int main(int argc, char *argv[]) {
	
	FILE*archivo;
	leer_archivo(archivo); 
	return 0;
}

int leer_archivo(FILE* archivo){
	int opcion;
	int aux=0;
	int i;
	NODO A;	//Nodo (struct nodo)
	pila *ptr;
	pila ptr2;
	ptr=&ptr2;
	int cont=1;	//Para contar la linea en la que esta la llave
	char caracter;	//Caracter a leer
	ini_pila(&ptr2);	
	
	printf("\nArchivo Numero(?): \n");
	scanf("%d",&opcion);

	switch (opcion){
		case 1:
			printf("	Archivo 1:\n");
			archivo = fopen("1.c","r"); //Abre el archivo solo para lectura
		break;
		case 2:
			printf("	Archivo 2:\n");
			archivo = fopen("2.c","r");
		break;
		case 3:
			printf("	Archivo 3:\n");
			archivo = fopen("3.c","r");
		break;
		case 4:
			printf("	Archivo 4:\n");
			archivo = fopen("4.c","r");
		break;
		case 5:
			exit(0);
		break;
	}
	
	if (archivo == NULL){	
		printf("\nError de apertura del archivo. \n\n");
    }
	else{
	    while (caracter!=EOF)	//La funcion feof regresa 1 si llega al final "EOF"
	    {
			caracter = fgetc(archivo);	//Lee caracter a caracter
				//fseek( archivo, 0L, SEEK_CUR );
			switch (caracter){
				case '\n': cont++;
				break;
				case '(':
				case '{':
				case '[':
					A.llave=caracter;
					A.linea=cont;
					push(&ptr,A);	//Guardar las llaves que abren en la pila
				break;
				case ')':
				case '}':
				case ']':
					if(empty(*ptr)){
						printf("\nError falta llave de apertura, linea %d",cont);
						aux++;
					}
					else if(caracter==')'&& top(ptr).llave=='('||caracter=='}'&& top(ptr).llave=='{'||caracter==']'&& top(ptr).llave=='['){ 
						pop(&ptr);
						aux--;
					}
					else if(caracter==')'&& top(ptr).llave!='('||caracter=='}'&& top(ptr).llave!='{'||caracter==']'&& top(ptr).llave!='[')
					printf("\nError de tipo, linea %d",cont);
						aux++;
					break;
			}
		}
	    if(!empty(*ptr)){
						printf("\nError falta llave de cierre, linea %d", top(ptr).linea);
						aux++;
					}
					if (aux==0){
					printf("\n Todo bien :v");
				}
    }
	liberar_pila(&ptr2);
    fclose(archivo);	//Termina de leer el archivo
	
}
