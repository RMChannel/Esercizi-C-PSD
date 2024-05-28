typedef struct car *Car;

Car newcar(char *targa,char *modello,int immatricolazione,int produzione);
void outputItem(Car car);
int cmpItem(Car car1, Car car2);
void swap(Car car1, Car car2);
int confrontoTarga(Car car1, Car car2);