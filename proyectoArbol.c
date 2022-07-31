#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct nodo{
 struct nodo *padre;
 struct nodo *izquierdo;
 struct nodo *derecho;
 int valor;
};

struct nodo *crear_nodo(struct nodo *padre, int valor);
void agregar(struct nodo *arbol, int valor);
void recorrer(struct nodo *arbol, int valor);

int main(){
//Creamos el arbol vacio
 struct nodo *arbol = calloc(sizeof(struct nodo),1);
 arbol->padre = NULL;
 arbol->valor = NULL;
 //menu
 int repetidorMenu = 1;
	int opcion; 
	while (repetidorMenu) {
		printf ("Introduzca el numero de la opcion de su preferencia: \n 1) Agregar un nodo al arbol. \n 2) Recorrer arbol hasta un nodo especifico \n 3) Finalizar operaciones \n");
		scanf("%d", &opcion);
		switch (opcion){
			case 1: ;
				int valor;
				printf("Introduzca el valor que desea guardar en el nodo \n");
				scanf("%d", &valor);
				agregar (arbol, valor);
				system("pause");
				system ("cls");
				break;
			case 2: ;
				int n;
				printf("Introduzca el valor que desea buscar en el nodo \n");
				scanf("%d", &n);
				recorrer(arbol, n);
				system("pause");
				system ("cls");
				break;
			case 3:
				repetidorMenu = 0;
				break;
			default:
				printf("Introduzca una opcion validad \n");
		system("pause");
		system ("cls");
				break;
			
		}
	}
 
 return 0;
}

struct nodo *crear_nodo(struct nodo *padre, int valor){
 struct nodo *n = calloc(sizeof(struct nodo),1);
 n->padre = padre;
 n->valor = valor;
 return n;
}

void agregar(struct nodo *arbol, int valor){
	if (!arbol->valor){
		printf("Se ha insertado %i como la raiz del arbol\n", valor);
		arbol->valor = valor;
	}
	else {
	 struct nodo *temp, *pivote;
 int derecho = 0;

  temp = arbol;
  while(temp !=NULL){
   pivote = temp;
   if(valor>temp->valor){
    temp = temp->derecho;  
    derecho = 1;    
   }else{
    temp = temp->izquierdo;
    derecho = 0;
   }
  }
  temp = crear_nodo(pivote,valor);
  if(derecho){
   printf("Insertando %i el lado derecho de %i\n",valor,pivote->valor); 
   pivote->derecho = temp;
  }else{
   printf("Insertando %i el lado izquierdo de %i\n",valor,pivote->valor);
   pivote->izquierdo = temp;
  }

	}
}

void recorrer (struct nodo *arbol, int valor){
		if (!arbol->valor){
		printf("El arbol se encuentra vacio", valor);
	}
	else {
	 struct nodo *temp;
  temp = arbol;
  int repetidor = 1;
  while(repetidor){
  	printf ("\n %i", temp->valor);
   if(valor>temp->valor){
    temp = temp->derecho;  
   }else if (valor<temp->valor){
    temp = temp->izquierdo;
   } else if (temp->valor == valor){
   	printf ("\n El recorrido ha finalizado \n");
   	repetidor = 0;
   }
  }
  
	}
}
	

