typedef struct Punto *Punto;

Punto creaPunto(float x, float y);
float ascissa(Punto p);
float ordinata(Punto p);
float distanza(Punto p1, Punto p2);
void MovePunto(Punto p, float deltax, float deltay);
Punto Centroide(Punto pAll[],int npunti);
int Coppie(Punto pAll[],int npunti, float d);
float MaxDist(Punto Pall[], int npunti);