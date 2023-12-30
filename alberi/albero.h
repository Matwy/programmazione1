typedef nodo* albero;
struct nodo {
    int value;
    albero left;
    albero right;
};

void stampaAlbero(albero radice, int spazio=0);