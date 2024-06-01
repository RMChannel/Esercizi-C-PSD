typedef struct car *Car;

Car newcar(char *marca,char *modello,int immatricolazione,int prezzo);
void outputItem(Car car);
int confrontoMarca(Car car1, Car car2);
int confrontoModello(Car car1, Car car2);