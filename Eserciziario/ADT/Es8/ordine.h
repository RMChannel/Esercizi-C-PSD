typedef struct ordine *Ordine;
typedef struct ordini *Ordini;

Ordini newOrdini();
Ordine newOrdine(int ID, int prod, float prezzo, int giorno, int mese, int anno);
void addOrdine(Ordini orders, Ordine ord);
void removeOrdine(Ordini orders, Ordine ord);
float total(Ordini orders);
void showOrders(Ordini orders);