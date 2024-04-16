typedef struct Auto *Auto;

Auto initAuto(char *targa, int annoI, int annoP, char *modello);
char *targa(Auto car);
char *modello(Auto car);
int annoI(Auto car);
int annoP(Auto car);