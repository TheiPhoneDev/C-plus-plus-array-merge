#include <iostream>

using namespace std;

const int dimensioneMax=100;
const int doubleDimensioneMax=dimensioneMax*2;

//prototipi
void caricaVettori(string v[], string v2[], int n);
void ordinamento(string v[], string v2[], int n);
void merge(string v[], string v2[], string v3[], int n);
void stampa(string v[], int n);
int Menu();

int main() {

  int N;
  int scelta;
  string a[dimensioneMax];
  string b[dimensioneMax];
  string c[dimensioneMax];

  do {
    scelta=Menu();
    switch(scelta) {
      case 1:
        do{
            cout<<"Inserisci il numero di animali: ";
            cin>>N;
            if (N<=0||N>dimensioneMax) {
                cout<<"Attenzione, non posso caricare il vettore!!!"<<endl;
            }
        }while(N<=0||N>dimensioneMax);
        caricaVettori(a,b,N);
      break;
      case 2:
        ordinamento(a,b,N);
        merge(a,b,c,N);
        stampa(c,N);
      break;
      case 0:
        cout<<"Esci"<<endl;
      break;
      default:
        cout<<"Attenzione, scelta sbagliata!"<<endl;
      break;
    }
  }while(scelta!=0);
  
}


int Menu() {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Inserisci il numero di animali"<<endl;
  cout<<"2-Fondi vettori"<<endl;
  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}




void caricaVettori(string v[], string v2[], int n) {
  int i=0;

  while(i<n) {
      cout<<"Inserisci il "<<i+1<<"° animale del vettore a: ";
      cin>>v[i];
      cout<<"Inserisci il "<<i+1<<"° animale del vettore b: ";
      cin>>v2[i];
      i++;
  }

  cout<<endl;
}



void ordinamento(string v[], string v2[], int n) {

  string temp, temp1;
  
  for(int i=0;i<n-1;i++) {
    for(int j=i+1;j<n;j++) {
      
      if(v[i]>v[j]) {
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
      }

      if(v2[i]>v2[j]) {
        temp1=v2[i];
        v2[i]=v2[j];
        v2[j]=temp1;
      }
      
    }
  }
}



void merge(string v[], string v2[], string v3[], int n) {
  int i=0;
  int j=0;
  int k=0;
  
  while(i<n&&j<n) {
    if(v[i]<v2[j]) {
      v3[k]=v[i];
      i++;
      k++;
    } else {
      if(v[i]>v2[j]) {
        v3[k]=v2[j];
        j++;
        k++;
      } else {
        v3[k]=v[i];
        i++;
        j++;
        k++;
      }
    }
  }

  while(i<n) {
    v3[k]=v[i];
    i++;
    k++;
  }

  while(j<n) {
    v3[k]=v2[j];
    j++;
    k++;
  }
  
}


void stampa(string v[], int n) {

  cout<<endl;


  cout<<"---------------Vettore Mergiato---------------"<<endl;
  
  for(int i=0; i<n*2; i++) {
    cout<<v[i]<<endl;
  }

  cout<<endl;

}
