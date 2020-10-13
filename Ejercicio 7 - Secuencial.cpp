#include <iostream>
#include <stdlib.h>
using namespace std;

class Cola{
	private:
		int *items;
		int max;
		int pr;
		int ul;
		int cant;
	
	public:
		Cola(int max = 10);
		bool vacia();
		int insertar(int dat);
		int suprimir();
		void recorrer();
		~Cola();
};

Cola::Cola(int xmax){
	pr = 0;
	ul = 0;
	cant = 0;
	max = xmax;
	items = new int[max];
}


bool Cola::vacia(){
	return (cant == 0);
}

int Cola::insertar(int dat){
	int aux;
	if (cant < max){
		items[ul] = dat;
		ul = (ul + 1) % max;
		cant++;
		return (dat);
	}
	else return (0);
}

int Cola::suprimir(){
	int x;
	if (vacia()){
		printf("%s", "Pila vacia");
		return (0);
	}
	else{
		x = items[pr];
		pr = (pr + 1) % max;
		cant--;
		return (x);
	}
}

void Cola::recorrer(){
	int i,j;
	if (!vacia()){
		i = pr;
		j = 0;
		for(i; j<cant; i = (i+1)%max, j++){
			cout<<items[i]<<endl;
		}
	}
}

Cola::~Cola(){
	delete[]items;
}

int main(){
	int Reloj, TMS, X, Y, Cajero, TEC, TEMax, i;
	float arreglo[20]={0.1, 0.9, 0.2, 0.8, 0.3, 0.7, 0.4, 0.6, 0.5, 0.5, 0.6, 0.4, 0.7, 0.3, 0.8, 0.2, 0.9, 0.1, 0.1, 0.9};
	float TEP;
	
	printf("Ingrese el tiempo de atencion del cajero: ");
	scanf("%d", &Y);
	printf("Ingrese la frecuencia de llegada de los clientes: ");
	scanf("%d", &X);
	
	Cola unaCola(50);
	TMS = 20; 			//tiempo maximo de simulación
	Reloj = 0;
	Cajero = 0;			//contador que lleva la cuenta del tiempo que esta ocupado
	TEC = 0;			//tiempo de espera del cliente en la cola
	TEMax = 0;			//tiempo de espera maximo de un cliente en la cola
	
	
	i = 0;
	while (Reloj != TMS){
		if (arreglo[i] >= 0 && arreglo[i] <= (1.0/float(X))){
			unaCola.insertar(Reloj);
		}
		if (Cajero == 0){
			if (!unaCola.vacia()){
				TEC = Reloj - unaCola.suprimir();
				Cajero = Y;
				if (TEC > TEMax){
					TEMax = TEC;
				}
			}
		}
		Reloj++;
		i++;
		if (Cajero > 0){
			Cajero = Cajero - 1;
		}
	}
	printf("El tiempo maximo de espera de los clientes en la cola es de: %d min\n", TEMax);
		
}
