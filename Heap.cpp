//#include "Heap.h"
//template <class T>
//void Heap<T>::CresteMemoriaAlocata()
//{
//    // alocam un vector nou de dimensiune dubla si copiem elem
//    T* masivNou = new T[this->memorieAlocata * 2];
//    for (int i = 0; i < this->memorieAlocata; i++)
//    {
//        masivNou[i] = this->elemente[i];
//    }
//    // inlocuim vectorul existent cu cel nou si actualizam dim
//    delete[] this->elemente;
//    this->elemente = masivNou;
//    this->memorieAlocata = this->memorieAlocata * 2;
//}
//
//template <class T>
//void Heap<T>::ScadeMemoriaAlocata(){
//// alocam un vector nou mai mic si copiem elementele
//T* masivNou = new T[this->memorieAlocata / 2];
//for (int i = 0; i < this->memorieAlocata / 2; i++)
//{
//    masivNou[i] = this->elemente[i];
//}
//// inlocuim vectorul existent cu cel nou si actualizam dim
//delete[] this->elemente;
//this->elemente = masivNou;
//this->memorieAlocata = this->memorieAlocata / 2;
//}
//
//template <class T>
//void Heap<T>::Filtrare(int index)
//{
//    // 1. Determinam maximul dintre elemente[index],
//    // elemente[Stanga(index)] si elemente[Dreapta(index)]
//    int indexMax = index;
//    int indexStanga = this->Stanga(index);
//    int indexDreapta = this->Dreapta(index);
//    if (indexStanga < this->dimensiuneHeap && this->elemente[indexStanga] > this->elemente[indexMax])
//    {
//        indexMax = indexStanga;
//    }
//    if (indexDreapta < this->dimensiuneHeap && this->elemente[indexDreapta] > this->elemente[indexMax])
//    {
//        indexMax = indexDreapta;
//    }
//    // 2. Daca varful actual nu respecta prop de ordonare atunci
//    // coboram nodul in arbore si reapelam recursiv procedura
//    if (index != indexMax)
//    {
//        this->Interschimb(index, indexMax);
//        this->Filtrare(indexMax);
//    }
//}
//
//template <class T>
//Heap<T>::Heap(int capacitateInitiala)
//{
//    // ne asiguram ca dimensiunea initiala a structurii este
//    // cel putin dimensiunea minima
//    capacitateInitiala = max(capacitateInitiala, DimensiuneMinima);
//    // alocam memoria pentru elemente si initializam campurile
//    this->elemente = new T[capacitateInitiala];
//    this->memorieAlocata = capacitateInitiala;
//    this->dimensiuneHeap = 0;
//}
//template <class T>
//Heap<T>::Heap(T elemente[], int numarElemente)
//{
//    // initializam campurile
//    this->memorieAlocata =
//        max(numarElemente, DimensiuneMinima);
//    this->dimensiuneHeap = numarElemente;
//    // copiem elementele din vector in structura
//    this->elemente = new T[this->memorieAlocata];
//    for (int i = 0; i < numarElemente; i++)
//    {
//        this->elemente[i] = elemente[i];
//    }
//    // Rearanjam elem a.i. sa satisfaca prop de ordonare folosind
//    // metoda Filtrare pt coborarea elem in arbore (elementele din
//    // a doua jumatate a masivului respecta implicit proprietatea
//    // de heap deoarece reprezinta subarbori cu maxim un element)
//    for (int i = (numarElemente - 1) / 2; i >= 0; i--)
//    {
//        this->Filtrare(i);
//    }
//}
//template <class T> Heap<T>::Heap(Heap& heap)
//{
//    this->memorieAlocata = heap->memorieAlocata;
//    this->dimensiuneHeap = heap->dimensiuneHeap;
//    this->elemente = new T[this->memorieAlocata];
//    for (int i = 0; i < dimensiuneHeap; i++)
//    {
//        this->elemente[i] = heap->elemente[i];
//    }
//}
//
//template <class T>
//void Heap<T>::Insereaza(T element)
//{
//    // verificam faptul ca avem memorie disponibila
//    if (this->dimensiuneHeap == this->memorieAlocata)
//    {
//        this->CresteMemoriaAlocata();
//    }
//    // expandam heap-ul
//    this->dimensiuneHeap++;
//    // adaugam elementul nou la sfarsitul heap-ului
//    int index = this->dimensiuneHeap - 1;
//    this->elemente[index] = element;
//    // si il urcam in arbore atat cat este cazul
//    // pentru a pastra proprietatea de heap
//    while (this->Parinte(index) >= 0 &&
//        this->elemente[index] > this->elemente[Parinte(index)])
//    {
//        this->Interschimb(index, this->Parinte(index));
//        index = this->Parinte(index);
//    }
//}
//template <class T>
//T Heap<T>::ExtrageMaxim()
//{
//    // ne asiguram ca avem cel putin un element in heap
//    assert(this->dimensiuneHeap > 0);
//    // scadem memoria alocata daca este cazul
//    if (this->memorieAlocata > DimensiuneMinima * 2 &&
//        this->dimensiuneHeap < this->memorieAlocata / 3)
//    {
//        this->ScadeMemoriaAlocata();
//    }
//    //mutam elementul in afara heap-ului ?i refacem struct de heap
//    this->dimensiuneHeap--;
//    Interschimb(0, this->dimensiuneHeap);
//
//    this->Filtrare(0);
//    return this->elemente[this->dimensiuneHeap];
//}
//template <class T>
//T Heap<T>::CitesteMaxim()
//{
//    // ne asiguram ca avem cel putin un element in heap
//    assert(this->dimensiuneHeap > 0);
//    // si intoarcem maximul
//    return this->elemente[0];
//}
//
//template <class T>
//void Heap<T>::SorteazaHeap(T* destinatie)
//{
//    // salvam numarul de elemente din heap 
//    int dimensiuneaInitiala = this->dimensiuneHeap;
//    // sortam vectorul in cadrul structurii
//    for (int i = this->dimensiuneHeap - 1; i > 0; i--)
//    {
//        this->Interschimb(0, i);
//        this->dimensiuneHeap--;
//        this->Filtrare(0);
//    }
//    // copiem elementele sortate in vectorul destinatie
//    for (int i = 0; i < dimensiuneaInitiala; i++)
//    {
//        destinatie[i] = this->elemente[i];
//    }
//}